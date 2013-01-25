# stripcc

Node.JS string module for stripping control-characters from string. Native and pure implementation.

```js
var stripcc = require('stripcc');
console.log(stripcc('he\u0001llo'));
```

Output:

    hello

## Installation

    $ npm install stripcc

## Description

Module provides single function that removes non-printable control characters from strings.
It has native and pure implementation.

## More information

It removes characters from [C0 and C1 sets](http://en.wikipedia.org/wiki/C0_and_C1_control_codes)
except for CR('\r'), LF('\n'), tab('\t') and space(' ').
