#!/bin/bash
#

set -e

FILES=$(find ./data -type f)

for file in $FILES; do
    perlf=${file}-perl-out
    nodef=${file}-node-out

    echo "testing $file"

    perl perl-base64.pl $file > $perlf
    node node-base64.js $file > $nodef

    cmp $perlf $nodef

    rm -rf $perlf $nodef
done

echo "all tests passed. good to go."
