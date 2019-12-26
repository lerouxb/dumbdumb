'use strict';

class Identifier {
    constructor(value) {

        this.value = value;
    }

    toString() {

        return this.value;
    }
}

exports.Identifier = Identifier;


class NumberLiteral {
    constructor(value) {

        this.value = value;
    }

    toString() {

        return this.value;
    }
}

exports.NumberLiteral = NumberLiteral;


class StringLiteral {
    constructor(value) {

        this.value = value;
    }

    toString() {

        return this.value;
    }
}

exports.StringLiteral = StringLiteral;
