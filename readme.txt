This is a node.js C++ module that encodes buffers to base64. And compared to
all other modules, it works. It does not provide decode functionality because
I don't currently need it.

It was written by Peteris Krumins (peter@catonmat.net).
His blog is at http://www.catonmat.net  --  good coders code, great reuse.

------------------------------------------------------------------------------

To build the module run:

    node-waf configure build

This will produce `base64.node` binary module. To use it, make sure the
module's directory is in NODE_PATH and then just do the usual:

    var base64_encode = require('base64').encode;

Now you can pass base64_encode the buffers to convert to base64.


------------------------------------------------------------------------------


SGF2ZSBmdW4hCg==


Sincerely,
Peteris Krumins
http://www.catonmat.net

