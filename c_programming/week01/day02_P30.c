#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
// 01-8. const를 사용한 변수
#if 0
int main(void) {
	int income = 0;
	double tax;
	const double tax_rate = 0.12;
	double* temp = &tax_rate;

	income = 10000;
	tax = income * tax_rate;
	
	
	printf("세금은 : %.1lf입니다. \n", tax);
	*temp = 0.15;
	tax = income * tax_rate;
	printf("세금은 : %.1lf입니다. \n", tax);


}
#endif

//01-8b. 
#if 0
int main(void) {
	int x = 10;
	int y = 20;
	const int* a = &x;
	int const* const b = &x;

	//*a = &y;
	//*b = &y

	x = 40;
	a = &y;   //*a가 const인거지, a는 const가 아니기 때문에 값 변경 가능하다.
	//b = &y;
	//b = y;
	printf("*a = %d, *b = %d\n", *a, *b);

}
#endif


#if 0
int main(void) {
	int pre;
	int a = 10;
	int b = 10;
	++a;
	b++;

	printf("a=%d, b=%d\n", a, b);
}
#endif


#if 0
int f1(int a, int b) {
	return a - b;
}
int f2(int a, int b) {
	return b - a;
}

int main(void) {
	int (*f)(int, int);  // 함수 포인터 변수

	int a = 10;
	int b = 7;
	int ret;

	f = a > b ? f1 : f2;
	ret = f(a, b);
	printf(ret);
	return 0;
}
#endif



#if 0
int main(void) {
	int a = -10;
	int b = 12;

	printf("a & b : %x\n", a & b);
	printf("a ^ b : %x\n", a ^ b);
	printf("a | b : %x\n", a | b);
	printf("~a : %x\n", ~a);
	printf("a << 1 : %x\n", a << 1);
	printf("a >> 2 : %x\n", a >> 2);


}
#endif



#if 0

unsigned int setBit(unsigned int num, int bitPosition) {
	int result;
	result = num | (1 << bitPosition);

	return result;
}
unsigned int clearBit(unsigned int num, int bitPosition) {
	int result;
	result = num & ~(1 << bitPosition);  

	return result;
}
unsigned int toggleBit(unsigned int num, int bitPosition) {
	int result;
	result = num ^ (1 << bitPosition);

	return result;
}

int main(void) {
	unsigned int num = 0b1010;
	printf("%X\n", setBit(num, 2));
	printf("%X\n", clearBit(num, 1));
	printf("%X\n", toggleBit(num, 3));
}
#endif



#if 0
unsigned int setBits(unsigned int num, int start, int count) {
	unsigned int result;
	result = num | ((1 << count) - 1) << start;

	return result;
}
unsigned int clearBits(unsigned int num, int start, int count) {
	unsigned int result;
	result = num & ~(((1 << count) - 1) << start);

	return result;
}
unsigned int toggleBits(unsigned int num, int start, int count) {
	unsigned int result;
	result = num ^ (((1 << count) - 1) << start);

	return result;
}

unsigned int checkBits(unsigned int num, int start) {
	unsigned int result;
	num = num >> start;
	result = num & 0b0001;

	return result;
}

int main(void) {
	unsigned int num = 0b10101010;
	printf("%X\n", setBits(num, 2, 3));  // 2번 비트부터 3개에 적용  // 0b1011 1110
	printf("%X\n", clearBits(num, 4, 2));  // 0b1000 1010
	printf("%X\n", toggleBits(num, 1, 5));  // 0b1001 0100

	printf("%X\n", checkBits(num, 1));
}
#endif




#if 0
int isthreeorfive(int num) {
	return (num % 3 == 0 || num % 5 == 0);
}
int isfourtoeight(int num) {
	return (4 <= num && num <= 8);
}
char changeAlpha(char a) {
	if (a >= 'a' && a <= 'z') a += 32;
	else if (a >= 'A' && a <= 'Z') a -= 32;
	return a;
}
int main(void) {
	int a;
	scanf("%d", &a);
	int a4 = 2753 / 1000;
	a = a % 1000;
	int a3 = a / 100;
	a = a % 100;
	int a2 = a / 10;
	a = a % 10;
	int a1 = a;

	printf("%d %d %d %d\n", a4, a3, a2, a1);

}
#endif