'use strict';

const internals = {};


exports.walk = function (array, visit, parentPath = []) {

    const [first, ...rest] = array;

    const newPath = parentPath.concat([first.toString()]);

    visit(array, newPath);

    for (const token of rest) {
        if (Array.isArray(token)) {
            exports.walk(token, visit, newPath);
        }
    }
};



internals.searchPathMatchesPartially = function (result, search) {

    if (result.length > search.length) {
        return false;
    }

    for (const [index, value] of result.entries()) {
        if (search[index] !== value) {
            return false;
        }
    }

    return true;
};

internals.searchPathMatchesExactly = function (result, search) {

    if (result.length !== search.length) {
        return false;
    }

    for (const [index, value] of result.entries()) {
        if (search[index] !== value) {
            return false;
        }
    }

    return true;
};


internals.filterVisitor = function (array, opts, visit, parentPath = []) {

    const rules = {};

    if (Array.isArray(opts)) {
        rules.search = opts;
    }
    else if (typeof opts === 'function') {
        rules.filter = opts;
    }
    else {
        Object.assign(rules, opts);
    }

    const [first, ...rest] = array;

    const newPath = parentPath.concat([first.toString()]);

    if (rules.search) {
        // Don't visit and don't descend any further if the search path doesn't match so far.
        // (This is really just an optimisation)
        if (!internals.searchPathMatchesPartially(newPath, rules.search)) {
            return;
        }
    }

    if (!rules.search || internals.searchPathMatchesExactly(newPath, rules.search)) {
        if (rules.filter) {
            // If there's a filter function it has to match for this to be visited.
            if (rules.filter(array, newPath)) {
                visit(array);
            }
        }
        else {
            // If there's no filter function, then everything that matches the search path will be visited
            visit(array);
        }
    }

    for (const token of rest) {
        if (Array.isArray(token)) {
            internals.filterVisitor(token, rules, visit, newPath);
        }
    }
};


exports.search = function (array, rules) {

    const results = [];

    internals.filterVisitor(array, rules, (token) => results.push(token));

    return results;
};


exports.find = function (array, search, filter) {

    const rules = (filter) ? { search, filter } : search;
    const results = exports.search(array, rules);

    if (results.length > 1) {
        console.log(results);
        throw new Error(`Found ${results.length}`);
    }

    return results[0];
};
