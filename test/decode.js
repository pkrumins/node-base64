var base64_decode = require('base64').decode;
var crypto = require('crypto');
var fs = require('fs');
var Hash = require('traverse/hash');
var hashes = JSON.parse(
    fs.readFileSync(__dirname + '/hashes.json').toString()
);

function md5sum (data) {
    return new crypto.Hash('md5').update(data).digest('hex');
}

exports.decode = function (assert) {
    Hash(hashes).forEach(function (hash, file) {
        fs.readFile(file, function (err, buf) {
            if (err) throw err;
            assert.equal(hash, md5sum(base64_decode(buf)));
        });
    });
};
