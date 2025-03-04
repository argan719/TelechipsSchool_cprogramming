#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#if 0
int main(void) {
	char ch1, ch2;
	char ch3;

	scanf(" %c %c", &ch1, &ch2);
	printf("[%c%c]\n", ch1, ch2);
	return 0;
}
#endif


#if 0
int main(void) {
	int ch;
	ch = getchar();
	printf("입력한 문자: ");
	putchar(ch);
	putchar('\n');

	putchar(97);
	putchar('\n');
	return 0;
}
#endif


#if 0
void my_gets(char *str, int size) {
	int ch;
	for (int i = 0; i < size-1; ++i) {
		ch = getchar();
		if (ch == '\n') break;
		else {
			str[i] = ch;
		}
	}
	str[size-1] = '\0';
}
int main(void) {
	char str[8] = { 0 };
	int n = sizeof(str) / sizeof(str[0]);

	my_gets(str, n);
	printf("%s\n", str);
}
#endif


#if 0
void my_gets(char* str, int size) {
	int ch;
	for (int i = 0; i < size - 1; ++i) {
		ch = getchar();
		if (ch != '\n') str[i] = ch;
	}
	str[size - 1] = '\n';
}
int main(void) {
	char str[8] = { 0 };
	int n = sizeof(str) / sizeof(str[0]);

	my_gets(str, n);
	printf("%s\n", str);
}
#endif




#if 0
char* to_upper(char* str, int n) {

	//char name[40] = { 0 };   이렇게 할려면 동적할당을 해줘야 함.
	// 여기서는 그냥 원본도 바꾸고 원본도 리턴해주면 됨. =  str을 리턴해주면 됨. 새로 만들어서 복사할 필요도 없이.
	char* name;
	name = malloc(sizeof(str) / sizeof(str[0]));

	for (int i = 0; i < n; i++) {    // for (int i=0; name[i] != '\0'; ++i)
		if (str[i] >= 97 && str[i] <= 122) {
			name[i] = str[i] - 32;   // name[i] -= ('a' - 'A');
		}
		else name[i] = str[i];
	}

	return name;
}

char* to_upper2(char* name) {
	char* save = name;
	for (; *name != '\0';) {
		if (*name >= 'a' && *name <= 'z') {
			*name -= ('a' - 'A');
		}
		++name;
	}
	return save;
}
void print_ary(char* str, int n) {

	for (int i = 0; i < n ; ++i) {
		putchar(str[i]);
	}

}
int main(void) {
	char name[] = "Tom & Jerry!";
	int n = sizeof(name) / sizeof(name[0]);
	printf("size : %d\n", n);
	print_ary(to_upper(name, n), n);
}
#endif



#if 0
int main(void) {
	int cnt[10] = { 0, };
	int n;
	int i;
	for (i = 0;; i++) {
		scanf("%d", &n);
		if (n == 0) break;
		else {
			cnt[n % 10]++;
		}
	}
	for (int i = 0; i <= 9; i++) {
		if (cnt[i] == 0) continue;
		printf("%d : %d개\n", i, cnt[i]);
	}
}
#endif



#if 0
void func(int* arr);

int main(void) {
	int cnt[10] = { 0, };
	func(cnt);
	for (int i = 0; i <= 9; i++) {
		if (cnt[i] == 0) continue;    // == if(cnt[i] <= 0)
		printf("%d : %d개\n", i, cnt[i]);
	}
}

void func(int* arr) {
	int n, i;
	for (i = 0;; i++) {
		scanf("%d", &n);
		if (n == 0) break;
		else {
			arr[n % 10]++;
		}
	}
}
#endif



#if 0
int main(void) {
	char* dessert = "apple";
	char fruit[20] = "watermelon";

	dessert = "banana";
	strcpy(fruit, "mango");
	//memcpy(fruit, "banana", sizeof("banana"));
	//memmove(fruit, "banana", sizeof("banana"));
	printf("%s %s\n", dessert, fruit);
}
#endif


#if 0

void func(void) {  //(아래 main 내용 정리)
	char a = 'x';
	char b = 'z';
	char brr[5] = "done";
	char arr[3] = "ab";
	char* c1 = &a;      // a는 로컬변수이기 때문에 스택. 
	char* c2 = arr;    // c2는 배열이랑 똑같음. 배열과 똑같이 사용 가능
	char* c3 = "apple";  // c3은 사용 괜춘, but *c3으로 접근해서 (참조)값을 변경, 쓰는 것은 안됨. 왜냐? rodata니까.

	printf("%c\n", c1);  // 불가능. c1은 주소값이기 때문
	print("%c\n", *c1);  // 가능. *c1 = c1[0] 둘 다 가능
	printf("%s %c\n", c2, c2[0]);  // 가능
	printf("%s %c\n", c3, c3[0]);  // 가능
	// c1 = c2 = c3 = &b;  가능
	// c1 = c2 = c3 = brr;  가능
	// c1 = c2 = c3 = "kiwi";  가능

	//*c1 = 'y';  가능
	//*c2 = 'y';  가능
	//*c3 = 'y';  이게 불가능.  .rodata 영역이라 쓰기 안됨.
}
void func2(void) {
	char ch = 'x';
	char arr[5] = "done";
	// const가 char 뒤에 있기 때문에 c1, c2, c3는 해당 이름으로 char를 수정할 수 없음
	char const* c1 = &ch;
	char const* c2 = arr;
	char const* c3 = "apple";
	//*c1 = 'y' // 불가능    => 그니까 const는 char*에 붙은 거임 char *c1이 const니까 바꿀 수 없음
	// c1 = c2 = c3 = "banana"  // 가능 => 포인터 c1, c2, c3 자체에 대해서는 const가 아니므로 가능. 포인터는 가능


	// const가 char* 뒤에 있기 때문에 c4, c5, c6는 포인터로 수정할 수 없음.
	char* const c4 = "apple";  // 이 경우 const가 * 뒤에 있기 때문에 포인터를 못 바꿈. 포인터가 const인 거고 
	char* const c5 = arr;
	char* const c6 = "apple";
	// *c4 = 'y'  // 따라서 가능
	// c5 = arr;  // 이게 불가능.
	//*c6 = 'y'  // 불가능
	// c6 = brr  // 불가능. 포인터를 바꾸자는 거니까. 지금 포인터는 const

	// c7, c8, c9는 해당 이름으로 char와 char*을 수정할 수 없음. 걍 아무것도 수정 못하는 거임.
	char const* const c7 = &ch;
	char const* const c2 = arr;
	char const* const c3 = "apple";
	
}

int main(void) {
	char ch = 'x';
	char* dessert1 = "apple";  // desert1 = 주소할당 가능
	const char* dessert2 = "apple";
	char const* dessert3 = "apple";

	//dessert1 = 'A';  // 그냥 단일 문자는 주소가 없음(' '). 들어가지기는 하나, 논리적 
	dessert1[0] = 'y';  // 불가능 ("apple" 문자열. rodata라서 읽기 전용으로 잡혀있는데 그 위에 y를 쓰려고 하니까 에러 뜸
	dessert1 = &ch;   // 가능 
	dessert1[0] = 'y';   // 가능  // &ch로 주소가 다시 잡혔기 때문에 쓸 수 있음
	dessert1[1] = 'y';  // 불가능  // out of buffer 

}
#endif




#if 0
#define Tax_Rate 0.11
double TaxA(int income) {
#define Tax_Rate 0.03
	return ((double)income * Tax_Rate);  // 여기서는 Tax_Rate가 0.03으로
}
#define Tax_Rate 0.07
double TaxB(int income) {
	return ((double)income * Tax_Rate);  // 여기서는 Tax_Rate가 0.07으로 적용됨.
}
int main(void) {
	printf("Tax_Rate (3%%) : %.1lf\n", TaxA(1000000));
	printf("Tax_Rate (11%%) : %.1lf\n", TaxB(1000000));
}
#endif



#if 0
int main(void) {
	char ch;
	char brr[30] = { 0 };
	char* arr = brr;
	scanf("%s", brr);   // 여기에 엔터가 포함됨.
	scanf("%c", &ch);   // ch가 새로 입력 안받고 버퍼에 남아있던 엔터를 가져감.  ch는 입력 안받고 건너뜀
	printf("%s [%c]\n", brr, ch);

	gets(brr);    // gets를 썼기 때문에 gets가 엔터까지 가져감.
	scanf("%c", &ch);   // 따라서 ch도 입력받을 수 있음. ch가 입력 받으려고 기다리고 있음.
	printf("%s [%c]\n", brr, ch);

	fgets(brr, sizeof(brr) / sizeof(brr[0]), stdin);  // fgets로 마찬가지로 엔터까지 가져감
	scanf("%c", &ch);  // 따라서 ch도 입력받을 수 있음.
	brr[strlen(brr) - 1] = '\0';   // 마지막 스페이스 삭제해줌.
	printf("%s [%c]\n", brr, ch);

	return 0;
}
#endif