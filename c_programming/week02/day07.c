
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
#include<stdlib.h>

#if 1
int main(void) {
	int (*a)[3];

	int a1[2][3] = { 1,2,3,4,5,6 };
	int a2[3][3] = { 7,8,9,10,11,12,13,14,15 };
	int a3[1][3] = { 16, 17, 18 };
	int a4[4][3] = { 19,20,21,22,23,24,25,26,27,28,29,30 };

	int (*a[4])[3] = { a1, a2, a3, a4 };

	printf("Debug point");
	return 0;
}
#endif