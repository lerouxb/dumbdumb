'use strict';

const Hoek = require('hoek');

const { Identifier, NumberLiteral, StringLiteral } = require('./tokens');


const internals = {
    escapeChar: '\\',
    quotes: ['"', '\''],
    spaceChars: [' ', '\t', '\r', '\n']
};


internals.makeString = function (token) {

    return new StringLiteral(token);
};


internals.makeNumber = function (token) {

    return new NumberLiteral(token);
};


internals.makeIdentifier = function (token) {

    return new Identifier(token);
};


internals.clearState = function (state) {

    return Object.assign(state, {
        isEscaped: false,
        quote: undefined,
        currentType: undefined,
        currentToken: undefined
    });
};


internals.endToken = function (tokens, state) {

    Hoek.assert(['string', 'identifier'].includes(state.currentType), 'string or identifier only');

    if (state.currentType === 'string') {
        tokens.push(internals.makeString(state.currentToken));
    }
    else {
        if (isNaN(parseInt(state.currentToken, 10))) {
            tokens.push(internals.makeIdentifier(state.currentToken));
        }
        else {
            tokens.push(internals.makeNumber(state.currentToken));
        }
    }

    internals.clearState(state);
};


internals.parseChar = function (state, char) {

    if (!state.stack.length && !internals.spaceChars.includes(char)) {
        console.error({ char });
        throw new Error('Unbalanced braces (extra text)');
    }

    //console.error({char});

    if (char === '(') {
        if (!state.foundOpen) {
            state.foundOpen = true;
            return;
        }
    }
    else {
        if (!state.foundOpen) {
            console.error(state);
            throw new Error('Expected an open brace.');
        }
    }

    if (state.isEscaped) {
        state.isEscaped = false;
        state.currentToken += `${internals.escapeChar}${char}`;
        return;
    }

    if (char === internals.escapeChar) {
        if (state.currentType === 'string') {
            state.isEscaped = true;
            return;
        }

        console.error(state);
        // TODO: this should be OK, actually
        throw new Error('Escaping outside of a string');
    }

    if (internals.spaceChars.includes(char)) {
        if (['number', 'identifier'].includes(state.currentType)) {
            internals.endToken(state.latestTokens, state);
            return;
        }

        if (state.currentType === 'string') {
            state.currentToken += char;
            return;
        }

        // ignore whitespace between stuff
        return;
    }

    if (internals.quotes.includes(char)) {
        if (state.currentType === 'string') {
            state.currentToken += char;

            if (char === state.quote) {
                internals.endToken(state.latestTokens, state);
            }

            return;
        }

        if (!state.currentType) {
            state.currentType = 'string';
            state.quote = char;
            state.currentToken = char;
            return;
        }

        console.error(state);
        throw new Error('Starting a string in the wrong place');
    }

    if (char === '(') {
        if (state.currentType === 'string') {
            state.currentToken += char;
            return;
        }

        if (state.currentType) {
            console.error(state);
            throw new Error('Open brace in the wrong place');
        }

        // push a new array onto the stack and onto the end of the current array
        const newTokens = [];
        state.latestTokens.push(newTokens);
        state.stack.push(newTokens);
        internals.clearState(state);

        state.latestTokens = newTokens;

        return;
    }

    if (char === ')') {
        if (state.currentType === 'string') {
            state.currentToken += char;
            return;
        }

        if (state.currentType) {
            internals.endToken(state.latestTokens, state);
        }

        // pop off one level from the depth and go back up to the previous one
        state.stack.pop();
        state.latestTokens = state.stack[state.stack.length - 1];

        return;
    }

    // now it has to be a Number, inside a String or an Identifier
    if (state.currentType) {
        state.currentToken += char;
    }
    else {
        state.currentType = 'identifier'; // for now. might be a number
        state.currentToken = char;
    }
};

exports.parse = function (text) {

    const tokens = [];

    const state = internals.clearState({
        foundOpen: false,
        latestTokens: tokens,
        stack: [tokens]
    });

    for (const char of text) {
        internals.parseChar(state, char);
    }

    if (state.stack.length) {
        console.error(Object.assign({}, state, {
            latestTokens: 'redacted',
            stack: 'redacted',
            currentToken: state.currentToken.slice(0, 100)
        }));
        //console.error(Object.keys(state));
        throw new Error('Unbalanced braces (unclosed)');
    }

    return tokens;
};

