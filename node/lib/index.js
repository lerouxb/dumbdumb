'use strict';

const Parse = require('./parse');
const Format = require('./format');
const Lookup = require('./lookup');
const Tokens = require('./tokens');


const modules = [Parse, Format, Lookup, Tokens];

for (const module of modules) {
    for (const [k, v] of Object.entries(module)) {
        exports[k] = v;
    }
}
