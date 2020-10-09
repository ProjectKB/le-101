#include "md5.h"

const uint32_t g_BUF[4] = {
    0x67452301,
    0xEFCDAB89,
    0x98BADCFE,
    0x10325476
};

const uint32_t g_SHIFT[64] = {
    7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22,
    5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20,
    4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23,
    6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21,
};

const unsigned char g_WI[64] = {
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, // i
    1, 6, 11, 0, 5, 10, 15, 4, 9, 14, 3, 8, 13, 2, 7, 12, // (i * 5 + 1) % 16
    5, 8, 11, 14, 1, 4, 7, 10, 13, 0, 3, 6, 9, 12, 15, 2, // (i * 3 + 5) % 16
    0, 7, 14, 5, 12, 3, 10, 1, 8, 15, 6, 13, 4, 11, 2, 9  // (i * 7) % 16 
};

const uint32_t g_SIN[64] = {
    0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
    0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
    0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
    0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
    0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
    0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
    0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
    0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
    0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
    0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
    0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
    0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
    0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
    0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
    0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
    0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391
};

uint32_t rotl(uint32_t x, uint32_t n)
{
	return (x << n) | (x >> (32 - n));
}

uint32_t F(uint32_t x, uint32_t y, uint32_t z){
	return (x & y) | (~x & z);
}

uint32_t G(uint32_t x, uint32_t y, uint32_t z)
{
    return (x & z) | (y & ~z);
}

uint32_t H(uint32_t x, uint32_t y, uint32_t z)
{
    return x ^ y ^ z;
}

uint32_t I(uint32_t x, uint32_t y, uint32_t z)
{
    return y ^ (x | ~z);
}

uint32_t(*g_ROUND_FUNCTIONS[4])(uint32_t x, uint32_t y, uint32_t z) = {
    F, G, H, I
};

void init_md5(t_md5 *md5)
{
    md5->nb_bits = 0;
    md5->buf[0] = M0;
    md5->buf[1] = M1;
    md5->buf[2] = M2;
    md5->buf[3] = M3;
}
