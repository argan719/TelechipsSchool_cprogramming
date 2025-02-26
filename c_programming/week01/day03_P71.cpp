
#include<stdio.h>

#if 0
void func(void) {
	int a = 10;
	if (a > 10) {
		printf("a > 10");
	}
	else {
		printf("a <= 10");
	}
}
int main(void) {

}
#endif


#if 01
void func1(int num) {
	if (num % 2 == 0) {
		printf("짝수입니다.\n");
	}
	else printf("홀수입니다.\n");
}

int func2(int num) {
	if (num % 2 == 0) {
		printf("2\n");
	}
	else if (num % 3 == 0) {
		printf("3\n");
	}
	else if (num % 5 == 0) {
		printf("5\n");
	}
	return 0;
}

void func3(int num) {
	if (num >= 70) printf("합격입니다.\n");
	else {
		if (num >= 60 && num <= 69) printf("재시험보세요.\n");
		else printf("불합격입니다.\n");
	}
	printf("감사합니다.\n");
}

// printf("%s\n", (num % 2) ? "홀수" : "짝수");

int main(void) {

}
#endif