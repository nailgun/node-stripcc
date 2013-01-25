#include <node.h>
#include <v8.h>

using namespace v8;

Handle<Value> stripcc(const Arguments& args) {
    HandleScope scope;

    String::Value input(args[0]->ToString());
    uint16_t* newData = new uint16_t[input.length()];

    uint16_t* in = *input;
    uint16_t* end = in + input.length();
    uint16_t* out = newData;
    while (in < end) {
        if (*in > 0x1f) {
            // Skip 0x7f (DEL) and C1 Control Codes (0x80 - 0x9f)
            if (*in < 0x7f) {
                *out++ = *in;
            }
            else if (*in > 0x9f) {
                *out++ = *in;
            }
        }
        else {
            // Skip C0 Control Codes (0x00 - 0x1f) except for CR,LF,HT
            if (*in == '\n' || *in == '\r' || *in == '\t') {
                *out++ = *in;
            }
        }
        in++;
    }

    int newLength = out - newData;

    Local<String> ret = String::New(newData, newLength);
    delete[] newData;

    return scope.Close(ret);
}

void init(Handle<Object> target) {
    target->Set(String::NewSymbol("stripcc"), FunctionTemplate::New(stripcc)->GetFunction());
}
NODE_MODULE(stripcc, init)
