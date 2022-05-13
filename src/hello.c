#include "features.h"
#ifndef main_func
#include <stdio.h>
#include <sleep.h>

int main()
{
	char name[100];

	// setbuf(stdin, NULL);
	// setbuf(stdout, NULL);
	fflush(stdout);
	fflush(stdin);
	// while (1)
	// {
		puts("Hello world!");
		puts("This is a test.");
		puts("Whats your name?");
		scanf("%s", name);
		printf("Welcome, %s\n", name);
		// fflush(stdout);
		// fflush(stdin);
	// }
	
	return 0;
}
#endif