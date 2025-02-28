#define _CRT_SECURE_NO_WARNINGS
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


#if 0
void func1(int num) {
	if (num % 2 == 0) {
		printf("짝수입니다.\n");
	}
	else printf("홀수입니다.\n");
}

int func2(int num) {
	if (num % 2 == 0) {
		return 2;
	}
	if (num % 3 == 0) {
		return 3;
	}
	if (num % 5 == 0) {
		return 5;
	}
	return 0;
}
// return (!(num % 2)) ? 2 : (!(num % 3)) ? 3 : (!(num % 5)) ? 5 : 0;
void func3(int num) {
	if (num >= 70) printf("합격입니다.\n");
	else {
		if (num >= 60 && num <= 69) printf("재시험보세요.\n");
		else printf("불합격입니다.\n");
	}
	printf("감사합니다.\n");
}
char* func3_2(int num) {  // c언어는 함수 오버로드 불가. 무조건 이름을 봄. 이름이 같으면 매개변수 달라도 안됨. 이름이 무조건 달라야 함.
	if (num >= 70) return "합격입니다.";
	else {
		if (num >= 60 && num <= 69) return "재시험보세요.";
		return "불합격입니다.";
	}
}

// printf("%s\n", (num % 2) ? "홀수" : "짝수");

int main(void) {
	int num;
	scanf("%d", &num);
	func1(num);
	printf("%d\n", func2(num));
	func3(num);
	printf("\n\n");
	printf("%s\n감사합니다.", func3_2(num));
}
#endif



#if 0

char getGrade1(int score) {
	char grade;
	switch (score /= 10) {
	case 10:
	case 9:
		grade = 'A'; break;
	case 8:
		grade = 'B'; break;
	case 7:
		grade = 'C'; break;
	case 6:
		grade = 'D'; break;
	default:
		grade = 'F'; break;
	}

	return grade;
}
char getGrade2(int score) {
	char* grade = "FFFFFFDCBAA";
	//printf("%c\n", grade[score / 10]);
	return grade[score / 10];
	// return "FFFFFFDCBAA"[score / 10];
}


int main(void) {
	int g;
	scanf("%d", &g);
	printf("%c", getGrade(g));
}
#endif


#if 0
int getCount(int num) {
	int count = 1;
	
	while (num >= 10) {
		num /= 10; 
		count++;
	} 

	return count;
}

int reverse(int num) {
	int cnt = getCount(num);
	int n = 1;  
	for (int i = 0; i < cnt - 1; i++) {
		n *= 10;
	}
	while (num) {
		num % n 
	}
}
int reverse_2(int num) {// 모범답안
	int result = 0;
	while (num) {
		result *= 10;
		result += num % 10;
		num /= 10;
	}
	return result;
}
int main(void) {
	int num;
	scanf("%d", &num);
	printf("%d", getCount(num));
}
#endif


#if 0
int getStatus(int num) {
	int n;
	while (num != 1234) {
		scanf("%d", &n);
		num = n;
	}
	return 1;
}
int getStatus2(void) {
	int num;
	do {
		(void)scanf("%d", &num);
	} while (num != 1234);
	return 1;
}
int main(void) {
	int num;
	scanf("%d", &num);
}
#endif


#if 0
int getSum(void) {
	int sum = 0;
	int num;
	scanf("%d", &num);

	while (num!=0) {
		if(num > 0) sum += num;
		scanf("%d", &num);
	}
	printf("sum = %d\n", sum);

	return sum;
}
int getSum_2(void) {
	int sum = 0;
	int num;
	do {
		scanf("%d", &num);
		if (num > 0) sum += num;
	} while (num);
	return sum;
}
char* confirmPassword(void) {
	char* msg = "";
	int num;
	scanf("%d", &num);
	int i;
	for (i = 0; i < 3; i++) {
		if (num == 1357) {
			msg = "로그인 성공!"; break;
		}
		scanf("%d", &num);
	}
	if (i >= 3) msg = "관리자에게 문의하세요";
	return msg;
}
#endif



#if 0
int main(void) {
	int ary[5] = { 10, 20, 30, 40, 50 };
	int i;
	for (i = 0; i < 5; i++) {
		printf("ary[%d] = %d\n", i, ary[i]);
	}
	return 0;
}
#endif


#if 0
int getSum(int* score, int n);
double getMean(int* score, int n);

int main(void) {
	int score[5];
	int i;
	int n = sizeof(score) / sizeof(score[0]);
	for (i = 0; i < n; i++) {
		scanf("%d", &score[i]);
		// scanf("%d", score+i);  score[i] == score+i
	}
	printf("sum = %d, mean = %.1f\n", getSum(score, n), getMean(score, n));
	return 0;
}

int getSum(int* score, int n) {
	int sum = 0;
	int i;

	for (int i = 0; i < n; i++) {
		sum += score[i];
	}
	return sum;
}
double getMean(int* score, int n) {
	return getSum(score) / (double)n;   // (double)(getSum(score)/5);
}
#endif



#if 0
int main(void) {
	char str[20];  //= "applejam";
	scanf("%s", str);
	printf("%s\n", str);
	return 0;
}
#endif


