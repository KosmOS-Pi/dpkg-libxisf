#ifndef BSWAP_H
#define BSWAP_H

#ifdef __linux__

#include <endian.h>
#include <byteswap.h>

#define swaptole16(x) htole16(x)
#define swaptole32(x) htole32(x)
#define swaptole64(x) htole64(x)
#define swapfromle16(x) le16toh(x)
#define swapfromle32(x) le32toh(x)
#define swapfromle64(x) le64toh(x)

static inline bool needByteSwap(bool isBigEndian)
{
#if __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
    return !isBigEndian;
#else
    return isBigEndian;
#endif
}

#else // __linux__

#include <stdint.h>

static inline uint16_t bswap_16(uint16_t x)
{
    return (x & 0xff00) >> 8 | (x & 0xff) << 8;
}

static inline uint32_t bswap_32(uint32_t x)
{
    return (x & 0xff000000) >> 24 | (x & 0xff0000) >> 8 | (x & 0xff00) << 8 | (x & 0xff) << 24;
}

static inline uint64_t bswap_64(uint64_t x)
{
    return
        (x & 0xff00000000000000) >> 56 |
        (x & 0x00ff000000000000) >> 40 |
        (x & 0x0000ff0000000000) >> 24 |
        (x & 0x000000ff00000000) >>  8 |
        (x & 0x00000000ff000000) <<  8 |
        (x & 0x0000000000ff0000) << 24 |
        (x & 0x000000000000ff00) << 40 |
        (x & 0x00000000000000ff) << 56;
}

#if defined(__BYTE_ORDER__) && __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__

#define swapfromle16(x) bswap_16(x)
#define swapfromle32(x) bswap_32(x)
#define swapfromle64(x) bswap_64(x)
#define swaptole16(x) bswap_16(x)
#define swaptole32(x) bswap_32(x)
#define swaptole64(x) bswap_64(x)

static inline bool needByteSwap(bool isBigEndian)
{
    return !isBigEndian;
}

#endif // __BYTE_ORDER__

#define swaptole16(x) (x)
#define swaptole32(x) (x)
#define swaptole64(x) (x)
#define swapfromle16(x) (x)
#define swapfromle32(x) (x)
#define swapfromle64(x) (x)

static inline bool needByteSwap(bool isBigEndian)
{
    return isBigEndian;
}

#endif // __linux__

#endif // BSWAP_H
