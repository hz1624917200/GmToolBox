#include "features.h"
#ifndef main_func
#include "sm3.h"
#include <stdio.h>
#include <sleep.h>
#include <aes.h>

int main()
{
	
	char name[100];
	memset(name, 0, sizeof(name));
	while (fread(name, sizeof(char), SM3_BLOCK_SIZE, stdin) != EOF)
	{
		puts(name);
	}
	
	// setbuf(stdin, NULL);
	// setbuf(stdout, NULL);
	// fflush(stdout);
	// fflush(stdin);
	// while (1)
	// {
		/*  IO test
		puts("Hello world!");
		puts("This is a test.");
		puts("Whats your name?");
		scanf("%s", name);
		printf("Welcome, %s\n", name);
		*/
		// fflush(stdout);
		// fflush(stdin);
	// }
	
	return 0;
}
#endif