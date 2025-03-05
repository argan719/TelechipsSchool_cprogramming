
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
#include<stdlib.h>

#if 0
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



#if 1
int main(void) {
	int arr[20] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
	int* p1 = arr;   // p1 == arr
	int (*p2)[5] = arr;  // 오류는 안남. 짝이 맞지는 않음. 내가 책임을 지는 거임
	int (*p3)[4] = arr;  // 마찬가지
	int(*p4)[10] = arr;
	printf("%d\n", (int(*)[7])arr[1][2]);  // 형변환 가능. int 7개짜리를 가리키는 포인터. 
	printf("%d %d %d %d\n", p1[7], p2[1][2], p3[1][3], p3[2][-1], p4[0][7], p4[1][-3]);  // 모두 8이 나오도록. 모두 8이 나옴.
	printf("Arr : %p\n", arr);
	printf("%p %p %p %p\n", p1 + 1, p2 + 1, p3 + 1, p4 + 1);
}
#endif