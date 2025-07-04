#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "ArrayBaseStack.h"

int main()
{
	/*Stack의 생성 및 초기화*/
	Stack stack;
	StackInit(&stack);

	/*데이터 넣기*/
	SPush(&stack, 1); SPush(&stack, 2);
	SPush(&stack, 3); SPush(&stack, 4);
	SPush(&stack, 5);

	/*데이터 꺼내기*/
	while (!SIsEmpty(&stack))
		printf("%d ", SPop(&stack));

	return 0;
}