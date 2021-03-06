#ifndef MD5_H
#define MD5_H

#include <stdint.h>

#include <string>

class Md5 {
public:
    static const int OUTPUT_BYTES = 16;
    static const int BLOCK_BYTES = 64;
    static const int LENGTH_BYTES = 8;

public:
    Md5();
    void update(const void *buf, int n);
    void finalize();
    void digest(uint8_t out[OUTPUT_BYTES]); //little endian
    string digestStr();

private:
    uint32_t mH[OUTPUT_BYTES / sizeof(uint32_t)];
    uint8_t mBuf[BLOCK_BYTES];
    uint64_t mSize;
};

#endif
