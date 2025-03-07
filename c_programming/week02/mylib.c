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

// ����
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
	// ���� ���� ���� a,b�� ���� ������ ��. �ٵ� void�� ���� ���ؼ��� ���� �������� ��
	// �׷� ����ϳ�?

	// => �� char�� �����ϼ�. char ������ ������ �ݺ���Ŵ (1����Ʈ ¥��)
	// ���̸� ���޹����� double �� char 8��, int�� char 4��. �̷��� �����ؼ� �Ѱ� �Ѱ��� swap�ϸ� �ȴ�.

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
	return comp_char(*(char**)a, *(char**)b);   // strcmp ����ص� ����
}

int comp_float(const void* a, const void* b) {
	// return *(float*)a - *(float*)b;  �̷��� �ȵ�.
	float tmp;
	tmp = *(float*)a - *(float*)b;
	if (tmp > 0) return 1;
	else return 0;
}