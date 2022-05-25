#include "../include/sm3.h"
#include <stdio.h>
#include <string.h>

int main()
{
	uint8_t teststr[1025] = "This is a test. My name is Zheng.";
	uint8_t result[SM3_DIGEST_SIZE];
	uint32_t msglen;
	printf("%s\n", teststr);

	scanf("%d%*c%*c", &msglen);
	memset(teststr, 0x61, sizeof(teststr));
	// fread(teststr, 1, msglen, stdin);
	sm3_digest(teststr, msglen, result);
	for (int i = 0; i < SM3_DIGEST_SIZE; i++)
		printf("%02x ", result[i]);
	putchar('\n');
	
	sm3_stream(msglen, result, stdin);
	for (int i = 0; i < SM3_DIGEST_SIZE; i++)
		printf("%02x ", result[i]);
	putchar('\n');
	return 0;
}