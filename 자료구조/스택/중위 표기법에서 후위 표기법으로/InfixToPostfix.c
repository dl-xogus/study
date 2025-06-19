#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "InfixToPostfix.h"
#include "ListBaseStack.h"

int GetOpPrec(char op)	// �������� ���� �켱���� ������ ��ȯ�Ѵ�
{
	switch (op)
	{
	case '*':
	case '/':
		return 5;	// ���� ���� ������ �켱����
	case '+':
	case '-':
		return 3;	// 5���� �۰� 1���� ���� ������ �켱����

	case '(':
		return 1;	// ���� ���� ������ �켱����
	}

	return -1;		// ��ϵ��� ���� ���������� �˸�
}

int WhoPrecOp(char op1, char op2)
{
	int op1Prec = GetOpPrec(op1);
	int op2Prec = GetOpPrec(op2);

	if (op1Prec > op2Prec)			// op1�� �켱������ �� ���ٸ�
		return 1;
	else if (op1Prec < op2Prec)		// op2�� �켱������ �� ���ٸ�
		return -1;
	else
		return 0;					// op1�� op2�� �켱������ ���ٸ�
}

void ConvToRPNExp(char exp[])	// ���� ǥ����� �������� ��ȯ
{
	Stack stack;
	int expLen = strlen(exp);
	char* convExp = (char*)malloc(expLen + 1);			// ��ȯ�� ������ ���� ���� ����

	int i, idx = 0;
	char tok, popOp;

	memset(convExp, 0, sizeof(char) * expLen + 1);		// �Ҵ�� �迭�� 0���� �ʱ�ȭ
	StackInit(&stack);

	for (i = 0; i < expLen; i++)
	{
		tok = exp[i];				// exp�� ���޵� ������ �� ���徿 tok�� ����
		if (isdigit(tok))			// tok�� ����� ���ڰ� �������� Ȯ��
		{
			convExp[idx++] = tok;	// �����̸� �迭 convExp�� �׳� ����
		}
		else						// ���ڰ� �ƴ϶��(�����ڶ��)
		{
			switch (tok)
			{
			case '(':					// ���� �Ұ�ȣ���
				SPush(&stack, tok);		// ���ÿ� �״´�
				break;

			case ')':					// �ݴ� �Ұ�ȣ���
				while (1)				// �ݺ��ؼ�
				{
					popOp = SPop(&stack);		// ���ÿ��� �����ڸ� ������
					if (popOp == '(')			// ������ ) �� ���� ������
						break;
					convExp[idx++] = popOp;		// �迭 covExp�� �����Ѵ�
				}
				break;

			case '+': case '-':
			case '*': case '/':
				while (!SIsEmpty(&stack) && WhoPrecOp(SPeek(&stack), tok) >= 0)
					convExp[idx++] = SPop(&stack);

				SPush(&stack, tok);
				break;
			}
		}
	}

	while (!SIsEmpty(&stack))				// ���ÿ� ���� �ִ� ��� �����ڸ�
		convExp[idx++] = SPop(&stack);		// �迭 convExp�� �̵��Ѵ�

	strcpy(exp, convExp);	// ��ȯ�� ������ exp�� �����ϰ�
	free(convExp);			// convExp�� �Ҹ��Ų��
}