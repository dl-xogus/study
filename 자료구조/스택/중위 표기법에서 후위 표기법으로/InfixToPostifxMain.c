#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "InfixToPostfix.h"

int main()
{
	/*���� ǥ����� ����*/
	char exp1[] = "1+2*3";
	char exp2[] = "(1+2)*3";
	char exp3[] = "((1-2)+3)*(5-2)";

	/*���� ǥ����� �������� ��ȯ�� ��û*/
	ConvToRPNExp(exp1);
	ConvToRPNExp(exp2);
	ConvToRPNExp(exp3);

	printf("%s \n", exp1);
	printf("%s \n", exp2);
	printf("%s \n", exp3);
	return 0;
}