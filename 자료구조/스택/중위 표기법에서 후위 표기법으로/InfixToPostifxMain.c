#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "InfixToPostfix.h"

int main()
{
	/*중위 표기법의 수식*/
	char exp1[] = "1+2*3";
	char exp2[] = "(1+2)*3";
	char exp3[] = "((1-2)+3)*(5-2)";

	/*후위 표기법의 수식으로 변환을 요청*/
	ConvToRPNExp(exp1);
	ConvToRPNExp(exp2);
	ConvToRPNExp(exp3);

	printf("%s \n", exp1);
	printf("%s \n", exp2);
	printf("%s \n", exp3);
	return 0;
}