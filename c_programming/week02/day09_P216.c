#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
#include<stdlib.h>



#if 0
#include "mylib.h"
#define SIZE(a) (sizeof(a) / sizeof((a)[0])) // a가 변형되지 않도록 a를 괄호로 묶어주자!


// int(*func)(int, int);  // 함수 포인터 -> 리턴형이 int이고 매개변수가 int, int인 함수의 주소를 담는 함수 포인터 변수

int(*array_func)(int(*)[4], int, int);

int main(void) {
	int a[5] = { 4, 7, 2, 6, 1 };
	//int n = sizeof(a) / sizeof(a[0]);

	print_ary(a, SIZE(a));

	printf("\n오름차순 정렬\n");
	sort_ary(a, SIZE(a), comp_asc);
	print_ary(a, SIZE(a));

	printf("내림차순 정렬\n");
	sort_ary(a, SIZE(a), comp_dsc);
	print_ary(a, SIZE(a));


	return 0;
}

#endif



// void 포인터
#if 0
int main(void) {
	int a = 10;
	double b = 3.5;
	void* vp;

	vp = &a;
	printf("a : %d\n", *(int*)vp);
	vp = &b;
	printf("b : %f\n", *(double*)vp);
	return 0;
}

#endif



#if 0
int main(void) {
	double a = 8.534;
	double b = 2.345;

	printf("a : %.3f   b : %.3f\n", a, b);
	swap(&a, &b, 8);
	printf("a : %.3f   b : %.3f", a, b);

}
#endif





#if 0
#include "mylib.h"

#define SIZE(a) (sizeof(a) / sizeof((a)[0])) // a가 변형되지 않도록 a를 괄호로 묶어주자!

int main(void) {
	int a[5] = { 4, 7, 8, 5, 3 };
	char str[30] = "watermelon";
	char* msg[5] = { "kiwi", "orange", "apple", "watermelon", "mango" };
	float weight[5] = { 50.4, 48.9, 70.5, 50.2, 48.8 };
	qsort(a, SIZE(a), sizeof(a[0]), comp_int);
	print_ary(a, SIZE(a));

	printf("\n<<char 정렬>>\n");
	printf("%s\n", str);
	qsort(str, strlen(str), sizeof(str[0]), comp_char);
	printf("%s\n", str);

	printf("\n<<문자열 정렬>>\n");
	print_str(msg, SIZE(msg));
	qsort(msg, SIZE(msg), sizeof(msg[0]), comp_str);
	print_str(msg, SIZE(msg));

	printf("\n<<float 정렬>>\n");  // float는 주의해야 한다. 그냥 빼기 빼기해서 int로 반환하니까. 소수점까지 계산이 반영이 안됨.
	print_float(weight, SIZE(weight));
	qsort(weight, SIZE(weight), sizeof(weight[0]), comp_float);
	print_float(weight, SIZE(weight));
	
	return 0;
}

#endif



#if 01
#include "mylib.h"
int main(void) {
	int* ary = 0;  // 널로 초기화
	int n = 10;
	(void)freopen("score.txt", "r", stdin);

	ary = (int*)malloc(n * sizeof(int));
	input_ary(ary, n);   // 이렇게 변수 size 쓰고 싶을 때 동적할당 쓰면 가능.
	print_ary(ary, n);
	return 0;
}
#endif