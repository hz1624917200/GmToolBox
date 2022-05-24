#include "../include/sm3.h"
#include <stdio.h>

int main()
{
	char str[] = "abc";
	unsigned char result[SM3_DIGEST_SIZE];
	sm3_digest(str, 3, result);
	for (int i = 0; i < SM3_DIGEST_SIZE; i++)
		printf("%02x", result[i]);
	return 0;
}