#include "features.h"
#ifdef main_func

#include <stdio.h>
#include <string.h>
#include "sm3.h"
#include "padding.h"

int main()
{
	fprintf(stderr, "This is a Test for stderr");
	fprintf(stdout, "This is a test for stdout");
	return 0;
}
#endif