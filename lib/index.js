'use strict';

try {
    module.exports = require('./build/Release/stripcc').stripcc;
} catch (err) {
    module.exports = function (input) {
        var out = '';
        for (var i = 0; i < input.length; i++) {
            var co = input.charCodeAt(i);
            var c = input.charAt(i);
            if (co > 0x1f) {
                // Skip 0x7f (DEL) and C1 Control Codes (0x80 - 0x9f)
                if (co < 0x7f) {
                    out += c;
                }
                else if (co > 0x9f) {
                    out += c;
                }
            }
            else {
                // Skip C0 Control Codes (0x00 - 0x1f) except for CR,LF,HT
                if (c === '\n' || c === '\r' || c === '\t') {
                    out += c;
                }
            }
        }
        return out;
    };
}
