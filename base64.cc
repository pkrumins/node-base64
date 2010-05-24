#include <v8.h>
#include <node.h>
#include <node_buffer.h>

using namespace v8;
using namespace node;

static const char base64_chars[] = 
  "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
  "abcdefghijklmnopqrstuvwxyz"
  "0123456789+/";

static char *
base64_encode(const unsigned char *input, int length)
{
  /* http://www.adp-gmbh.ch/cpp/common/base64.html */
  int i=0, j=0, s=0;
  unsigned char char_array_3[3], char_array_4[4];

  int b64len = (length+2 - ((length+2)%3))*4/3;
  char *b64str = new char[b64len + 1];

  while (length--) {
    char_array_3[i++] = *(input++);
    if (i == 3) {
      char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
      char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
      char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
      char_array_4[3] = char_array_3[2] & 0x3f;

      for (i = 0; i < 4; i++)
        b64str[s++] = base64_chars[char_array_4[i]];

      i = 0;
    }
  }
  if (i) {
    for (j = i; j < 3; j++)
      char_array_3[j] = '\0';

    char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
    char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
    char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
    char_array_4[3] = char_array_3[2] & 0x3f;

    for (j = 0; j < i + 1; j++)
      b64str[s++] = base64_chars[char_array_4[j]];

    while (i++ < 3)
      b64str[s++] = '=';
  }
  b64str[b64len] = '\0';

  return b64str;
}

Handle<Value>
base64_encode_binding(const Arguments& args)
{
  HandleScope scope;

  if (!Buffer::HasInstance(args[0])) {
    return ThrowException(Exception::TypeError(
        String::New("Argument should be a buffer")));
  }
  Buffer *buffer = ObjectWrap::Unwrap<Buffer>(args[0]->ToObject());
  char *str = base64_encode((unsigned char*)buffer->data(), buffer->length());
  Local<String> ret = String::New(str);
  delete str;
  return ret;
}

extern "C" void init (Handle<Object> target)
{
  HandleScope scope;
  target->Set(String::New("encode"), FunctionTemplate::New(base64_encode_binding)->GetFunction());
}

