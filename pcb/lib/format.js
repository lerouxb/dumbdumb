'use strict';


exports.format = function (tokens, indentLevel = 0) {

    const parts = [];

    if (indentLevel) {
        parts.push('\n');
        for (let i = 0; i < indentLevel; ++i) {
            parts.push('  ');
        }
    }

    parts.push('(');

    for (const [i, token] of tokens.entries()) {
        if (Array.isArray(token)) {
            parts.push(exports.format(token, indentLevel + 1));
        }
        else {
            if (i) {
                parts.push(' ');
            }

            parts.push(token.toString());
        }
    }

    parts.push(')');

    return parts.join('');
};
