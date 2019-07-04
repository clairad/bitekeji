#include "deque.h"

int main()
{
	deque test;
	dequeInit(&test);
	printf("%d\n", dequePush(&test, 1));
	printf("%d\n", dequePush(&test, 1));
	printf("%d\n", dequePush(&test, 1));
	printf("%d\n", dequePush(&test, 1));
	printf("%d\n", dequePush(&test, 1));

	return 0;
}