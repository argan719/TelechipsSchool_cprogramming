
#include<stdio.h> 
#if 0   // 여기가 0이면 실행(컴파일) 안하겠다, 1이면 실행하겠다. (if문 뒤에 오는 구문이 0,1에 따라)
int main(void) {
	int a = -137;
	printf("%x\n", a);

	printf("%.1f\n", 1e6);
	printf("%.7f\n", 3.14e-5);
	printf("%le\n", 0.0000314);
	printf("%.2le\n", 0.0000314);

	return 0;
}
#endif


#if 0
int main(void) {
	float a = 1.23456789f;
	double b = 1.23456789f;
}
#endif
