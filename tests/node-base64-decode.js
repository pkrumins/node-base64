var base64_decode = require('base64').decode;
var sys = require('sys');
var fs = require('fs');
var Buffer = require('buffer').Buffer;

if (!process.argv[2]) {
    sys.log('No argument specified, use `node-base64-decode.js <file>`');
    process.exit(1);
}

var file = fs.readFileSync(process.argv[2], 'ascii');
var fileBuf = new Buffer(file.length);
fileBuf.write(file, 'ascii');

process.stdout.write(base64_decode(fileBuf), 'binary');

