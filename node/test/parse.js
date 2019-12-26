'use strict';

const Code = require('code');
const Lab = require('lab');
const Sinon = require('sinon');

const S = require('../lib');

const Parse = S.parse;
const Format = S.format;
const { Identifier, NumberLiteral, StringLiteral } = S;

const { describe, it, beforeEach, afterEach } = exports.lab = Lab.script();
const expect = Code.expect;


describe('parse-pcb', () => {

    beforeEach(() => {

        Sinon.restore();

        Sinon.stub(console, 'error');
    });

    afterEach(() => Sinon.restore());

    it('throws when the text does not start with an open brace', () => {

        const text = 'foo';
        expect(() => Parse(text)).to.throw(Error, 'Expected an open brace.');
    });

    it('throws when encountering an escape char outside of a string', () => {

        const text = '(\\)';
        expect(() => Parse(text)).to.throw(Error, 'Escaping outside of a string');
    });

    it('throws when encountering a quote inside an identifier or number', () => {

        const text = '(a")';
        expect(() => Parse(text)).to.throw(Error, 'Starting a string in the wrong place');
    });

    it('throws when encountering an open brace inside an identifier or number', () => {

        const text = '(a()';
        expect(() => Parse(text)).to.throw(Error, 'Open brace in the wrong place');
    });

    it('throws when there is extra text after the last closing brace', () => {

        const text = '(a)b';
        expect(() => Parse(text)).to.throw(Error, 'Unbalanced braces (extra text)');
    });

    it('throws when there is an unclosed brace (at end)', () => {

        const text = '(a';
        expect(() => Parse(text)).to.throw(Error, 'Unbalanced braces (unclosed)');
    });

    it('deals with escaped quotes', () => {

        const text = '(a "foo\\"")';
        const tokens = Parse(text);

        expect(tokens).to.equal([new Identifier('a'), new StringLiteral('"foo\\""')]);
    });

    it('deals with identifiers, number literals, string literals and nested arrays', () => {

        const text = '(aa 1 -2.3 \'b b"b()\' "cccc" (foo))\n';
        const tokens = Parse(text);

        expect(tokens).to.equal([
            new Identifier('aa'),
            new NumberLiteral('1'),
            new NumberLiteral('-2.3'),
            new StringLiteral('\'b b"b()\''),
            new StringLiteral('"cccc"'),
            [
                new Identifier('foo')
            ]
        ]);
    });

    it('can format what it parsed', () => {

        const text = '(a 1 "two" (b))';
        const tokens = Parse(text);
        expect(Format(tokens)).to.be.a.string();
    });
});
