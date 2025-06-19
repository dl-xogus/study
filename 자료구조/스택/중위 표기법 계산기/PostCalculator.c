#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <ctype.h>
#include "PostCalculator.h"
#include "ListBaseStack.h"

int EvalRPNExp(char exp[])
{
	Stack stack;
	int expLen = strlen(exp);
	int i;
	char tok, op1, op2;

	StackInit(&stack);

	for (i = 0; i < expLen; i++)			// ������ �����ϴ� ���ڸ� ������ ������� �ݺ�
	{
		tok = exp[i];						// �� ���ھ� tok�� �����ϰ�
		if (isdigit(tok))					// ������ ������ �������� Ȯ���Ѵ�
		{
			SPush(&stack, tok - '0');		// ������ ���ڷ� ��ȯ �� ���ÿ� PUSH
		}
		else								// ������ �ƴ� �����ڶ��
		{
			op2 = SPop(&stack);				// ���ÿ��� �� ��° �����ڸ� ������
			op1 = SPop(&stack);				// ���ÿ��� ù ��° �����ڸ� ������

			switch (tok)					// �����ϰ� �� ����� �ٽ� ���ÿ� PUSH
			{
			case '+':
				SPush(&stack, op1 + op2);
				break;
			case '-':
				SPush(&stack, op1 - op2);
				break;
			case '*':
				SPush(&stack, op1 * op2);
				break;
			case '/':
				SPush(&stack, op1 / op2);
				break;
			}
		}
	}
	return SPop(&stack);		// ������ �������� ���ÿ��� ������ ��ȯ
}