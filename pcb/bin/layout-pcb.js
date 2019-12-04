#!/usr/bin/env node

'use strict';

const Fs = require('fs');

// s-expressions, sexprs or sexps
const S = require('../lib');

const internals = {};

internals.keymap = [
    // esc separately
    ['1!', '2@', '3#', '4$', '5%%', '6^', '7&', '8*', '9(', '0)', '-_', '+=', '⌫'], // 13
    ['Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', '[{', ']}', '⏎'], // 13
    ['A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', ';:', 'quotes', '\\\\|'], // 12
    ['⇧', 'Z', 'X', 'C', 'V', 'B', 'N', 'M', ',<', '.>', '/?', '`~~', '⇧'], // 13
    ['ctrl', 'option', null, null, null, null, 'space', null, null, null, null, '←', '→'] // 5
];

internals.rows = [
    13,
    13,
    12,
    13,
    5
];

internals.switchFootprint = 'fiftyseven:4.5mm-switch';


// FOOTPRINT, XPOS, YPOS, REFERENCE, VALUE, LABEL
internals.switch = `
  (module FOOTPRINT (layer F.Cu) (tedit 5D250269) (tstamp 5D30EDA7)
    (at XPOS YPOS)
    (fp_text reference REFERENCE (at 0 -5.08) (layer F.SilkS) hide
      (effects (font (size 1 1) (thickness 0.15)))
    )
    (fp_text value VALUE (at 0 3.81) (layer F.Fab) hide
      (effects (font (size 1 1) (thickness 0.15)))
    )
    (fp_text user "LABEL" (at 0 -4.1) (layer F.SilkS)
      (effects (font (size 0.8 0.8) (thickness 0.15)))
    )
    (fp_line (start -2.6 3.6) (end 2.6 3.6) (layer F.CrtYd) (width 0.12))
    (fp_line (start -2.6 -3.6) (end 2.6 -3.6) (layer F.CrtYd) (width 0.12))
    (fp_line (start -2.6 3.6) (end -2.6 -3.6) (layer F.CrtYd) (width 0.12))
    (fp_line (start 2.6 -3.6) (end 2.6 3.6) (layer F.CrtYd) (width 0.12))
    (fp_line (start 2.25 -2.25) (end 2.25 2.25) (layer F.SilkS) (width 0.12))
    (fp_line (start -2.25 -2.25) (end -2.25 2.25) (layer F.SilkS) (width 0.12))
    (fp_line (start -0.9 2.25) (end 0.9 2.25) (layer F.SilkS) (width 0.12))
    (fp_line (start -0.9 -2.25) (end 0.9 -2.25) (layer F.SilkS) (width 0.12))
    (fp_circle (center 0 0) (end 1 0) (layer F.SilkS) (width 0.12))
    (model :4point5mmswitch:TL3305AFxxxxG.stp
      (at (xyz 0 0 0))
      (scale (xyz 1 1 1))
      (rotate (xyz 0 0 90))
    )
  )
`.trim();

internals.replaceTemplateVars = function (template, vars) {

    for (const [k, v] of Object.entries(vars)) {
        template = template.replace(k, v);
    }

    return template;
};

internals.bezel = 0.5;
internals.xKeySize = (76 - 2*internals.bezel)/13;
console.log(internals.xKeySize);
internals.yKeySize = 8;

internals.offsetsForPosition = function (row, col) {

    // offset the row with asdf an extra half a key
    const xOffset = 112 + internals.bezel + internals.xKeySize/2 + (row === 2 ? internals.xKeySize/2 : 0);

    const yOffset = 150 - internals.yKeySize*4.5 - internals.bezel;

    return { xOffset, yOffset };
};

internals.findAdjustedColForPosition = function (row, col) {

    if (row < 0) {
        return col;
    }

    const keys = internals.keymap[row];

    let total = -1;
    for (let i = 0; i < keys.length; ++i) {
        if (keys[i] === null) {
            continue;
        }
        ++total;
        if (total === col) {
            return i;
        }
    }
};

internals.makeSwitch = function ({ row, col, key }, kept) {

    // The \ char has to be double escaped to show up and " goes inside "" so has to be escaped too.
    key = key.replace('\\', '\\\\');
    key = key.replace('"', '\\"');

    const reference = row < 0 ? 'SW:ESC1' : `SW${row}:${col}`;

    const { xOffset, yOffset } = internals.offsetsForPosition(row, col);

    const adjustedCol = internals.findAdjustedColForPosition(row, col);

    const vars = {
        FOOTPRINT: internals.switchFootprint,
        XPOS: xOffset + adjustedCol * internals.xKeySize,
        YPOS: yOffset + row * internals.yKeySize,
        REFERENCE: reference,
        VALUE: 'SW_Push',
        LABEL: key
    };

    const node = S.parse(internals.replaceTemplateVars(internals.switch, vars));

    // add back path and all the pads
    node.push(...kept[reference]);

    return node;
};

internals.keep = function (module, kept) {

    // keep pad and path by fp_text reference

    const referenceNode = S.find(module, ['module', 'fp_text'],
        (token) => token[1].value === 'reference');

    const reference = referenceNode[2].value;

    kept[reference] = [S.find(module, ['module', 'path']), ...S.search(module, ['module', 'pad'])];
};

exports.run = function () {

    const filePath = process.argv[2];

    const text = Fs.readFileSync(filePath, 'utf8');

    const kept = {};

    const tokens = S.parse(text).filter((token) => {

        // keep simple values
        if (!Array.isArray(token)) {
            return true;
        }

        // keep everything that isn't a module
        if (token[0].toString() !== 'module') {
            return true;
        }

        // strip the switches
        if (token[1].toString() === internals.switchFootprint) {
            internals.keep(token, kept);
            return false;
        }

        // keep all other modules
        return true;
    });

    tokens.push(internals.makeSwitch({ row: -1, col: 0, key: 'ESC' }, kept));

    // loop through positions, add all the switches based on templates
    for (var row = 0; row < internals.rows.length; ++row) {
        for (var col = 0; col < internals.rows[row]; ++col) {
            // skip empty positions (gaps in the key layout)
            //if (row === 2 && col === 13) {
            //    continue;
            //}

            const key = `${row}:${col}`;

            const data = {
                row,
                col,
                key
            };

            const sw = internals.makeSwitch(data, kept);

            tokens.push(sw);
        }
    }

    //console.log(S.format(tokens));
    Fs.writeFileSync(filePath, S.format(tokens), 'utf8');
};

if (require.main === module) {
    exports.run();
}
