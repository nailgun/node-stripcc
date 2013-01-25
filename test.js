'use strict';

var stripcc = require('./lib');

var input = 'h\u0000e\u0005l\u0011l\u007fo\u0088\r\n\t ';
var output = 'hello\r\n\t '

var ok = stripcc(input) === output;

if (ok) {
    console.log('>>>> SUCCESS');
    process.exit(0);
} else {
    console.error('>>>> FAIL');
    process.exit(1);
}
