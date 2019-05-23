#include <stdio.h>

int main1()
{ 
	//int i = 0x43c0e800;
	int i = 0x80000000;

	//printf("%.4f", *(float *)&i);
	/*
	int a[3][4] = { 0 }; 
	printf("%d\n", sizeof(a));
	printf("%d\n", sizeof(a[0][0])); 
	printf("%d\n", sizeof(a[0]));
	printf("%d\n", sizeof(a[0] + 1));
	printf("%d\n", sizeof(*(a[0] + 1)));
	printf("%d\n", sizeof(a + 1));
	printf("%d\n", sizeof(*(a + 1))); 
	printf("%d\n", sizeof(&a[0] + 1)); 
	printf("%d\n", sizeof(*(&a[0] + 1)));
	printf("%d\n", sizeof(*a)); 
	printf("%d\n", sizeof(a[3]));*/

	int p = 3;
	printf("%d\n", sizeof(p++));
	printf("%d\n", p);
	return 0;
}