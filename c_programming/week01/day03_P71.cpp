
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
		printf("¦���Դϴ�.\n");
	}
	else printf("Ȧ���Դϴ�.\n");
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
	if (num >= 70) printf("�հ��Դϴ�.\n");
	else {
		if (num >= 60 && num <= 69) printf("����躸����.\n");
		else printf("���հ��Դϴ�.\n");
	}
	printf("�����մϴ�.\n");
}

// printf("%s\n", (num % 2) ? "Ȧ��" : "¦��");

int main(void) {

}
#endif