#!/usr/bin/perl

use MIME::Base64 qw(encode_base64);

my $filename = shift || die "no filename, use me as `$0 <filename>`";

open my $file, '<', $filename or die "$!";
while (read($file, $buf, 60*57)) {
    print encode_base64($buf, '');
}

