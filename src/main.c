#include "features.h"
#ifdef main_func

#include <stdio.h>
#include "sm3.h"

int main()
{
	// fflush(stdin);
	// fflush(stdout);

	uint8_t teststr[32] = "This is a test.\n";
	uint8_t result[SM3_DIGEST_SIZE];
	sm3_digest(teststr, 16, result);
	for (int i = 0; i < SM3_DIGEST_SIZE; i++)
		printf("%02x ", result[i]);
	putchar('\n');
	return 0;
}
#endif