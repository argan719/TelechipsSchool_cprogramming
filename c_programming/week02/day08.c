#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
#include<stdlib.h>

#if 0
int main(void) {
	int* ptr;
	int n[] = { 5,10,22,34,36,44 };
	ptr = n;

	printf("%d", *ptr++);
	printf(" %d\n", *ptr);
}
#endif


#if 0
void print_ary(int ***ary, int, int);
void print_ary(int (*)[4], int, int);
int main(void) {

	int ary[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%5d", ary[i][j]);
		}
		printf("\n");
	}
	print_ary(ary, 3, 4);
}

void print_ary(int*** ary, int a, int b) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%5d", ary[i][j]);
		}
		printf("\n");
	}
}
#endif




#if 0
void exchange0(int* a, int* b);
void exchange1(int** a, int** b);
void exchange2(int*** a, int*** b);
void exchange3(int** a, int** b);
void exchange4(int*** a, int*** b);
void exchange5(int*** a, int*** b);

int main(void) {
	int a = 10, b = 5;
	int* ap = &a;
	int* bp = &b;
	int** app = &ap;
	int** bpp = &bp;

	exchange0(&a, &b);
	exchange1(&ap, &bp);
	exchange2(&app, &bpp);
	exchange3(&ap, &bp);
	exchange4(&app, &bpp);
	exchange5(&app, &bpp);
}
void exchange0(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;

	printf("a : %d  b : %d\n", *a, *b);
}
void exchange1(int** a, int** b) {
	int temp = **a;
	**a = **b;
	**b = temp;

	printf("a : %d  b : %d\n", **a, **b);
}
void exchange2(int*** a, int*** b) {
	int temp = ***a;
	***a = ***b;
	***b = temp;

	printf("a : %d  b : %d\n", ***a, ***b);
}
void exchange3(int** a, int** b) {
	int* temp = *a;
	*a = *b;
	*b = temp;

	printf("ap : %d  bp : %d\n", *a, *b);

}
void exchange4(int*** a, int*** b) {
	int** temp = **a;
	**a = **b;
	**b = temp;

	printf("ap : %d  bp : %d\n", **a, **b);

}
void exchange5(int*** a, int*** b) {
	printf("\nBefore app, bpp exchange  app : %d  bpp : %d\n", *a, *b);

	int** temp = *a;
	*a = *b;
	*b = temp;

	printf("app : %d  bpp : %d\n", *a, *b);


}
#endif



#if 0
void exchange0(int* a, int* b);
void exchange1(int** a, int** b);
void exchange2(int*** a, int*** b);
void exchange3(int** a, int** b);
void exchange4(int*** a, int*** b);
void exchange5(int*** a, int*** b);

int main(void) {
	int a = 10, b = 5;
	int* ap = &a;
	int* bp = &b;
	int** app = &ap;
	int** bpp = &bp;

	printf("Before a : %d  b : %d\n", a, b);
	exchange0(&a, &b);
	printf("After a : %d  b : %d\n\n", a, b);

	printf("Before a : %d  b : %d\n", a, b);
	exchange1(&ap, &bp);
	printf("After a : %d  b : %d\n\n", a, b);

	printf("Before a : %d  b : %d\n", a, b);
	exchange2(&app, &bpp);
	printf("After a : %d  b : %d\n\n", a, b);

	printf("Before ap : 0x%x  bp : 0x%x\n", ap, bp);
	exchange3(&ap, &bp);
	printf("After ap : 0x%x  bp : 0x%x\n\n", ap, bp);

	printf("Before ap : 0x%x  bp : 0x%x\n", ap, bp);
	exchange4(&app, &bpp);
	printf("After ap : 0x%x  bp : 0x%x\n\n", ap, bp);

	printf("Before app : 0x%x  bpp : 0x%x\n", app, bpp);
	exchange5(&app, &bpp);
	printf("After app : 0x%x  bpp : 0x%x\n\n", app, bpp);

}
void exchange0(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
void exchange1(int** a, int** b) {
	int temp = **a;
	**a = **b;
	**b = temp;
}
void exchange2(int*** a, int*** b) {
	int temp = ***a;
	***a = ***b;
	***b = temp;
}
void exchange3(int** a, int** b) {
	int* temp = *a;
	*a = *b;
	*b = temp;
}
void exchange4(int*** a, int*** b) {
	int** temp = **a;
	**a = **b;
	**b = temp;
}
void exchange5(int*** a, int*** b) {
	int** temp = *a;
	*a = *b;
	*b = temp;
}
#endif




#if 0
int main(void) {
	int a[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	int* ap[3] = { a[0], a[1], a[2] };   // &(a+0) &(a+1)  &(a+2)

	printf("%d %d\n", a[2][1], ap[2][1]);  // 10  10 

	return 0;
}
#endif



// 함수 포인터 - 사용 전
#if 0
#include "mylib.h"

int main(void) {
	int a = 10, b = 20;
	int res_1, res_2, res_3, res_4, res_5, res_6;
	int tot;
	res_1= sum(a, b);
	res_2 = sub(a, b);
	res_3 = mul(a, b);
	res_4 = divi(a, b);
	res_5 = mod(a, b);
	tot = res_1 + res_2 + res_3 + res_4 + res_5 + res_6;
	printf("sum : %d\n", res_1);
	printf("sub : %d\n", res_2);
	printf("mul : %d\n", res_3);
	printf("div : %d\n", res_4);
	printf("mod : %d\n", res_5);
	printf("tot : %d\n", tot);

	return 0;
}
#endif


// 함수 포인터 사용 후
// 위 내용을 배열로 바꿔볼거임.
#if 0
#define N (7)
#include "mylib.h"

int main(void) {
	int a = 10, b = 20;
	int res[N];
	int tot = 0;
	int(*Func[N])(int, int) = { sum, sub, mul, divi, mod, minv, maxv };  // 함수 포인터 배열
	char* opname[N] = { "sum", "sub", "mul", "div", "mod", "minv", "maxv"};   // ** 이면 char지, 한번에 널까지 쭉 출력하려면 * 하나만 들어가야지
	for (int i = 0; i < N; i++) {
		res[i] = Func[i](a, b);
		tot += res[i];
		printf("%s : %d\n", opname[i], res[i]);
	}
	printf("tot : %d\n", tot);

	return 0;
}
#endif





// 함수 포인터 사용 후 - (+ 구조체)
#if 01
#define N (7)
#include "mylib.h"
typedef struct {
	int (*Func)(int, int);
	char* opname;
	int res;
}myop;

int main(void) {
	int a = 10, b = 20;
	myop OP[N] = { 
		{sum, "sum"}, 
		{sub, "sub"}, 
		{mul, "mul"}, 
		{div, "div"}, 
		{mod, "mod"}, 
		{minv, "minv"}, 
		{maxv, "maxv"}
	};
	myop curr;
	int tot = 0;

	for (int i = 0; i < N; i++) {
		curr = OP[i];
		curr.res = curr.Func(a, b);
		tot += curr.res;
		printf("%s : %d\n", curr.opname, curr.res);
	}
	printf("tot : %d\n", tot);

	return 0;
}
#endif