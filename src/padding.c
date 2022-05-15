#include "padding.h"
#include <stdint.h>
#include <string.h>

uint32_t pkcs7_padding(uint8_t *msg, uint32_t msglen, uint8_t blocksize)
{
	uint32_t blockCount = msglen / blocksize + 1;
	if (msglen % blocksize)
	{
		int padding_count = blocksize - msglen % blocksize;
		memset(&msg[msglen], 0, padding_count);
	}
	return blockCount;
}