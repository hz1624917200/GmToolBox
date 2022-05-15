#ifndef PADDING_H
#define PADDING_H

#include <stdint.h>

// padding msg with pkcs5, return block count
inline uint32_t pkcs7_padding(uint8_t *msg, uint32_t msglen, uint8_t blocksize);

#endif