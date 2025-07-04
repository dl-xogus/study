#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "PriorityQueue.h"

int DataPriorityComp(char* str1, char* str2)
{
	return strlen(str2) - strlen(str1);
}

int main()
{
	PQueue pq;
	PQueueInit(&pq, DataPriorityComp);

	PEnqueue(&pq, "Good morning");
	PEnqueue(&pq, "I am a boy");
	PEnqueue(&pq, "Priority Queue");
	PEnqueue(&pq, "I am so happy");

	while (!PQIsEmpty(&pq))
		printf("%s \n", PDequeue(&pq));

	return 0;
}