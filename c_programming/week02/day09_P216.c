#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
#include<stdlib.h>



#if 0
#include "mylib.h"
#define SIZE(a) (sizeof(a) / sizeof((a)[0])) // a�� �������� �ʵ��� a�� ��ȣ�� ��������!


// int(*func)(int, int);  // �Լ� ������ -> �������� int�̰� �Ű������� int, int�� �Լ��� �ּҸ� ��� �Լ� ������ ����

int(*array_func)(int(*)[4], int, int);

int main(void) {
	int a[5] = { 4, 7, 2, 6, 1 };
	//int n = sizeof(a) / sizeof(a[0]);

	print_ary(a, SIZE(a));

	printf("\n�������� ����\n");
	sort_ary(a, SIZE(a), comp_asc);
	print_ary(a, SIZE(a));

	printf("�������� ����\n");
	sort_ary(a, SIZE(a), comp_dsc);
	print_ary(a, SIZE(a));


	return 0;
}

#endif



// void ������
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

#define SIZE(a) (sizeof(a) / sizeof((a)[0])) // a�� �������� �ʵ��� a�� ��ȣ�� ��������!

int main(void) {
	int a[5] = { 4, 7, 8, 5, 3 };
	char str[30] = "watermelon";
	char* msg[5] = { "kiwi", "orange", "apple", "watermelon", "mango" };
	float weight[5] = { 50.4, 48.9, 70.5, 50.2, 48.8 };
	qsort(a, SIZE(a), sizeof(a[0]), comp_int);
	print_ary(a, SIZE(a));

	printf("\n<<char ����>>\n");
	printf("%s\n", str);
	qsort(str, strlen(str), sizeof(str[0]), comp_char);
	printf("%s\n", str);

	printf("\n<<���ڿ� ����>>\n");
	print_str(msg, SIZE(msg));
	qsort(msg, SIZE(msg), sizeof(msg[0]), comp_str);
	print_str(msg, SIZE(msg));

	printf("\n<<float ����>>\n");  // float�� �����ؾ� �Ѵ�. �׳� ���� �����ؼ� int�� ��ȯ�ϴϱ�. �Ҽ������� ����� �ݿ��� �ȵ�.
	print_float(weight, SIZE(weight));
	qsort(weight, SIZE(weight), sizeof(weight[0]), comp_float);
	print_float(weight, SIZE(weight));
	
	return 0;
}

#endif



#if 01
#include "mylib.h"
int main(void) {
	int* ary = 0;  // �η� �ʱ�ȭ
	int n = 10;
	(void)freopen("score.txt", "r", stdin);

	ary = (int*)malloc(n * sizeof(int));
	input_ary(ary, n);   // �̷��� ���� size ���� ���� �� �����Ҵ� ���� ����.
	print_ary(ary, n);
	return 0;
}
#endif