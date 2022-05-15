#include <stdio.h>
#include <string.h>
#include "sm3.h"
#include "padding.h"

int sm3_stream(uint32_t msglen, uint8_t dgst[SM3_DIGEST_SIZE], FILE *fin)
{
	SM3_CTX ctx;	// sm3 init
	unsigned char buf[SM3_BLOCK_SIZE * SM3_GROUP_SIZE];
		
	sm3_init(&ctx);

	while (msglen > SM3_BLOCK_SIZE * SM3_GROUP_SIZE)
	{
		fread(buf, SM3_BLOCK_SIZE, SM3_GROUP_SIZE, stdin);
		sm3_update(&ctx, buf, SM3_BLOCK_SIZE * SM3_GROUP_SIZE);
		msglen -= SM3_BLOCK_SIZE * SM3_GROUP_SIZE;
	}
	fread(buf, 1, msglen & (SM3_BLOCK_SIZE * SM3_GROUP_SIZE - 1), fin);
	sm3_update(&ctx, buf, msglen & (SM3_BLOCK_SIZE * SM3_GROUP_SIZE - 1));
	sm3_finish(&ctx, dgst);
	
	return 0;
}