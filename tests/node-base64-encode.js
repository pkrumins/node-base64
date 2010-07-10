var base64_encode = require('base64').encode;
var sys = require('sys');
var fs = require('fs');
var Buffer = require('buffer').Buffer;

if (!process.argv[2]) {
    sys.log('No argument specified, use `node-base64-encode.js <file>`');
    process.exit(1);
}

var file = fs.readFileSync(process.argv[2], 'binary');
var fileBuf = new Buffer(file.length);
fileBuf.write(file, 'binary');

sys.print(base64_encode(fileBuf));

