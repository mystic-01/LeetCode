/**
 * @param {number} n
 * @return {Function} counter
 */
var createCounter = function(n) {
    var num = n, count = -1;
    return function() {
        count++;
        return num + count;
    };
};

/** 
 * const counter = createCounter(10)
 * counter() // 10
 * counter() // 11
 * counter() // 12
 */