#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
#include<stdlib.h>

int sum(int a, int b) {
	return a + b;
}
int sub(int a, int b) {
	return a - b;
}
int mul(int a, int b) {
	return a * b;
}
int divi(int a, int b) {
	return a / b;
}
int mod(int a, int b) {
	return a % b;
}
int minv(int a, int b) {
	return (a < b) ? a : b;
}
int maxv(int a, int b) {
	return (a > b) ? a : b;
}

int comp_asc(int a, int b) {
	return a > b;
}

int comp_dsc(int a, int b) {
	return a < b;
}

// 정렬
int* sort_ary(int* ary, int n, int (*comp)(int , int )) {
	int* save = ary;
	int temp;
	for (int i = 0; i < n - 1; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (comp(ary[i], ary[j])) {
				temp = ary[i];
				ary[i] = ary[j];
				ary[j] = temp;
			}
		}
	}
	return save;
}

void input_ary(int* ary, int n) {
	for (int i = 0; i < n; i++) {
		scanf("%d ", ary+i);
	}
}


void print_ary(int* ary, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", ary[i]);
	}
	printf("\n");
}

void print_str(char** ary, int n) {
	for (int i = 0; i < n; i++) {
		printf("%s ", ary[i]);
	}
	printf("\n");
}

void print_float(float* ary, int n) {
	for (int i = 0; i < n; i++) {
		printf("%.2f ", ary[i]);
	}
	printf("\n");
}


void swap(void* a, void* b, int n) {
	// 내가 전달 받은 a,b가 무슨 형인지 모름. 근데 void를 쓰기 위해서는 형을 명시해줘야 함
	// 그럼 어떡해하나?

	// => 다 char로 생각하셈. char 단위로 동작을 반복시킴 (1바이트 짜리)
	// 길이만 전달받으면 double 은 char 8개, int는 char 4개. 이렇게 생각해서 한개 한개씩 swap하면 된다.

	char temp;
	for (int i = 0; i < n; ++i) {
		temp = *(char*)a;
		*(char*)a = *(char*)b;
		*(char*)b = temp;

		((char*)a)++;
		((char*)b)++;
	}

}


int comp_int(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}


int comp_char(const void* a, const void* b) {
	return *(char*)a - *(char*)b;
}

int comp_str(const void** a, const void** b) {
	return comp_char(*(char**)a, *(char**)b);   // strcmp 사용해도 가능
}

int comp_float(const void* a, const void* b) {
	// return *(float*)a - *(float*)b;  이러면 안됨.
	float tmp;
	tmp = *(float*)a - *(float*)b;
	if (tmp > 0) return 1;
	else return 0;
}