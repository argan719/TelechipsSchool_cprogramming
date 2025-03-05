#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
#include<stdlib.h>

#if 0

int my_strcmp(const char* s1, const char* s2) {
	while (*s1 == *s2)
	{
		if (*s1 == 0)
			return 0;
		++s1;
		++s2;
	}
	return (*s1 - *s2);    
}
int my_strcmp2(const char* s1, const char* s2) {
	for (; *s1 && (*s1 == *s2); ++s1, ++s2);
	return *s1 - *s2;
}

char* my_strncpy(char* dst, const char* src, size_t n)
{
	if (n != 0) {
		char* d = dst;
		const char* s = src;

		do {
			if ((*d++ = *s++) == 0) {
				while (--n != 0)
					*d++ = 0;
				break;
			}
		} while (--n != 0);
	}
	return dst;
}

char* my_strncpy2(char* dst, const char* src, size_t n) {
	if (n == 0) return dst;
	char* d = dst;
	const char* s = src;
	int flag = 0;

	//printf("\n\n\n%s\n\n\n", d);
	//printf("\n\n\n%s\n\n\n", s); 

	while (n != 0) {
		//printf("%c %c ", *d, *s);
		if (*d == "\n") flag = 1;
		*d++ = *s++;
		n--;
	}
	if(flag) *d = "\n";

	return dst;
}

char* my_strncpy3(char* dest, const char* src, int n) {

	char* save = dest;
	while (n-- && (*dest++ = *src++));

	return save;
}

char* my_strcpy(char* to, const char* from) {
	char* save = to;
	while (*to++ = *from++);

	return save;
}

char* my_strcat(char *s, const char * append) {
	char* save = s;   // s의 맨 처음주소를 반환하기 위함(미리 저장해둠). 맨 처음 주소 keep

	for (; *s; ++s);
	while (*s++ = *append++);

	return save;
}
int main(void) {
	char a[20] = "apple";
	printf("%s\n", my_strcat(a, "jam"));   // apple jam
	printf("%s\n", a);   // apple jam

	printf("%s\n", my_strcpy(a, "bananna"));  // banana

	printf("%d \n", my_strcmp2("appl", "appl"));  // 0
	printf("%d \n", my_strcmp2("appl", "apple"));  // -101


	printf("%s\n", my_strncpy2(a, "MMMMMMMM", 10));
	return 0;
}
#endif


#if 0
int* auto_func(void) {
	int a = 0;  // = auto int a = 0;
	a++;
	printf("%p: %d\n", &a, a);
	return &a;  // 리턴하면 안됨. main가면 사라진다고 생각해야 함.
}

int* static_func(void) {
	static int a;
	a++;
	printf("%p: %d\n", &a, a);
	return &a;  // 리턴 가능. a는 static이기 때문에 고정 주소를 갖고 있는 거임.
}
int main(void) {
	printf("auto 사용함수\n");
	for (int i = 0; i < 3; ++i) {
		int* temp = auto_func();
		*temp += 100;
		printf("%d\n", *temp);
	}
	printf("static 사용함수\n");
	for (int i = 0; i < 3; ++i) {
		printf("%d\n", static_func());
	}
}
#endif



// with day06_sub.c
#if 0
int func3(void);   // day06_sub.c에 있는 걸 여기서 쓰고 싶어서 선언한 거임.
//int b = 1;   // 에러남. day06_sub에 있다고
static int c = 100;  // 다른 곳에서는 c 사용 못함. extern해도 사용 못함.

static int a = 10;  // 근데 얘는 에러 안남. 왜냐? static이기 때문에 day06_sub에 있는 (auto)a랑 다른 a이기 때문에
int func1(void) {
	return a + 10;
}

int func2(void) {
	return a + 100;
}

int main(void) {
	printf("func1 : %d\n", func1());   // 20
	a += 10;
	printf("func2 : %d\n", func2());   // 120
	printf("func3 : %d\n", func3());   // 1001


	return 0;
}
#endif


#if 0
int factorial(int n) {
	static int memo[100] = { 0 };
	if (memo[n] != 0) return memo[n];
	memo[n] = 1;
	for (int i = 2; i <= n; i++) {
		memo[n] *= i;
	}
	return memo[n];
}
int main(void) {
	int n = 5;
	printf("factorial(%d) = %d\n", n, factorial(n));
	printf("factorial(%d) = %d\n", n, factorial(n));


	return 0;
}
#endif






// 중요
#if 0
void input_data(int (*arr)[4], int r) {
	int i, j;
	int c = sizeof(*arr) / sizeof(arr[0][0]);
	printf("%d %d %d\n", sizeof(arr), sizeof(*arr), c);
	for (i = 0; i < r; ++i) {
		for (j = 0; j < c; ++j) {
			(void)scanf("%d", &arr[i][j]);
		}
	}
}
void input_data2(int* arr, int n) {
	int i;
	for (i = 0; i < n; i++) {
		(void)scanf("%d", &arr[i]);
	}
}
void print_data(int (*score)[4], int r, int c) {
	int i, j;
	for (i = 0; i < r; ++i) {
		for (j = 0; j < c; ++j) {
			(void)scanf("%d", score[i][j]);
		}
		printf("\n");
	}
}
void print_data2(int* arr, int n) {  // 2차원 -> 1차원 배열
	int i;
	for (i = 0; i < n; ++i) {
		if (i != 0 && i % 4 == 0) printf("\n");    //  i % 4 == 3
		printf("%3d", arr[i]);
	}
}
void print_sum_avg(int(*arr)[4], int r, int c) {
	int i, j, sum;
	for (i = 0; i < 3; i++) {
		sum = 0;
		for (j = 0; j < 4; j++) {
			sum += arr[i][j];
		}
		printf("총점: %d, 평균 : %.2f\n", sum, sum / 4.0);
	}
}
int get_sum(int* arr, int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i]; 
	}
	return sum;
}
void print_sum_avg2(int(*arr)[4], int r, int c) {
	int i, j, sum;
	for (i = 0; i < 3; ++i) {
		//sum = get_sum(arr, r * c);
		sum = get_sum(arr + i, c);  // 각 행의 시작 주소를 보냄
		printf("총점: %d, 평균 : %.2f\n", sum, sum / 4.0);
	}
}
//void average(int** score) {   // **score하면 안됨. 얘는 한칸단위로 움직임. 4칸(한줄)이 아니라
//	int i, j;
//	int cnt = 0;
//	int sum = 0;
//	for (i = 0; i < 3; ++i) {
//		for (j = 0; j < 4; ++j) {
//			sum += score[i][j];
//			cnt++;
//		}
//		printf("sum of score[%d] : %d", i, sum);
//		printf("average score[%d] : %.2f", i, sum / (float)cnt);
//		sum = 0; cnt = 0;
//	}
//}

int main(void) {
	int score[3][4] = { 0 };
	int i, j;
	(void)freopen("score.txt", "r", stdin);
	for (i = 0; i < 3; ++i) {
		for (j = 0; j < 4; ++j) {
			(void)scanf("%d", &score[i][j]);
		}
	}

	input_data(score, 3);
	input_data2(score, 3 * 4);
	print_data(score, 3, 4);
	print_data2(score, 3 * 4);
	print_sum_avg2(score, 3, 4);
}
#endif