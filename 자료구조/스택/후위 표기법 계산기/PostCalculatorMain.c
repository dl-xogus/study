#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "PostCalculator.h"

int main()
{
	char postExp1[] = "42*8+";
	char postExp2[] = "123+*4/";

	printf("%s = %d \n", postExp1, EvalRPNExp(postExp1));
	printf("%s = %d \n", postExp2, EvalRPNExp(postExp2));

	return 0;
}