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
	printf("�Է��� ����: ");
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

	//char name[40] = { 0 };   �̷��� �ҷ��� �����Ҵ��� ����� ��.
	// ���⼭�� �׳� ������ �ٲٰ� ������ �������ָ� ��. =  str�� �������ָ� ��. ���� ���� ������ �ʿ䵵 ����.
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
		printf("%d : %d��\n", i, cnt[i]);
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
		printf("%d : %d��\n", i, cnt[i]);
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

void func(void) {  //(�Ʒ� main ���� ����)
	char a = 'x';
	char b = 'z';
	char brr[5] = "done";
	char arr[3] = "ab";
	char* c1 = &a;      // a�� ���ú����̱� ������ ����. 
	char* c2 = arr;    // c2�� �迭�̶� �Ȱ���. �迭�� �Ȱ��� ��� ����
	char* c3 = "apple";  // c3�� ��� ����, but *c3���� �����ؼ� (����)���� ����, ���� ���� �ȵ�. �ֳ�? rodata�ϱ�.

	printf("%c\n", c1);  // �Ұ���. c1�� �ּҰ��̱� ����
	print("%c\n", *c1);  // ����. *c1 = c1[0] �� �� ����
	printf("%s %c\n", c2, c2[0]);  // ����
	printf("%s %c\n", c3, c3[0]);  // ����
	// c1 = c2 = c3 = &b;  ����
	// c1 = c2 = c3 = brr;  ����
	// c1 = c2 = c3 = "kiwi";  ����

	//*c1 = 'y';  ����
	//*c2 = 'y';  ����
	//*c3 = 'y';  �̰� �Ұ���.  .rodata �����̶� ���� �ȵ�.
}
void func2(void) {
	char ch = 'x';
	char arr[5] = "done";
	// const�� char �ڿ� �ֱ� ������ c1, c2, c3�� �ش� �̸����� char�� ������ �� ����
	char const* c1 = &ch;
	char const* c2 = arr;
	char const* c3 = "apple";
	//*c1 = 'y' // �Ұ���    => �״ϱ� const�� char*�� ���� ���� char *c1�� const�ϱ� �ٲ� �� ����
	// c1 = c2 = c3 = "banana"  // ���� => ������ c1, c2, c3 ��ü�� ���ؼ��� const�� �ƴϹǷ� ����. �����ʹ� ����


	// const�� char* �ڿ� �ֱ� ������ c4, c5, c6�� �����ͷ� ������ �� ����.
	char* const c4 = "apple";  // �� ��� const�� * �ڿ� �ֱ� ������ �����͸� �� �ٲ�. �����Ͱ� const�� �Ű� 
	char* const c5 = arr;
	char* const c6 = "apple";
	// *c4 = 'y'  // ���� ����
	// c5 = arr;  // �̰� �Ұ���.
	//*c6 = 'y'  // �Ұ���
	// c6 = brr  // �Ұ���. �����͸� �ٲ��ڴ� �Ŵϱ�. ���� �����ʹ� const

	// c7, c8, c9�� �ش� �̸����� char�� char*�� ������ �� ����. �� �ƹ��͵� ���� ���ϴ� ����.
	char const* const c7 = &ch;
	char const* const c2 = arr;
	char const* const c3 = "apple";
	
}

int main(void) {
	char ch = 'x';
	char* dessert1 = "apple";  // desert1 = �ּ��Ҵ� ����
	const char* dessert2 = "apple";
	char const* dessert3 = "apple";

	//dessert1 = 'A';  // �׳� ���� ���ڴ� �ּҰ� ����(' '). ������� �ϳ�, ���� 
	dessert1[0] = 'y';  // �Ұ��� ("apple" ���ڿ�. rodata�� �б� �������� �����ִµ� �� ���� y�� ������ �ϴϱ� ���� ��
	dessert1 = &ch;   // ���� 
	dessert1[0] = 'y';   // ����  // &ch�� �ּҰ� �ٽ� ������ ������ �� �� ����
	dessert1[1] = 'y';  // �Ұ���  // out of buffer 

}
#endif




#if 0
#define Tax_Rate 0.11
double TaxA(int income) {
#define Tax_Rate 0.03
	return ((double)income * Tax_Rate);  // ���⼭�� Tax_Rate�� 0.03����
}
#define Tax_Rate 0.07
double TaxB(int income) {
	return ((double)income * Tax_Rate);  // ���⼭�� Tax_Rate�� 0.07���� �����.
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
	scanf("%s", brr);   // ���⿡ ���Ͱ� ���Ե�.
	scanf("%c", &ch);   // ch�� ���� �Է� �ȹް� ���ۿ� �����ִ� ���͸� ������.  ch�� �Է� �ȹް� �ǳʶ�
	printf("%s [%c]\n", brr, ch);

	gets(brr);    // gets�� ��� ������ gets�� ���ͱ��� ������.
	scanf("%c", &ch);   // ���� ch�� �Է¹��� �� ����. ch�� �Է� �������� ��ٸ��� ����.
	printf("%s [%c]\n", brr, ch);

	fgets(brr, sizeof(brr) / sizeof(brr[0]), stdin);  // fgets�� ���������� ���ͱ��� ������
	scanf("%c", &ch);  // ���� ch�� �Է¹��� �� ����.
	brr[strlen(brr) - 1] = '\0';   // ������ �����̽� ��������.
	printf("%s [%c]\n", brr, ch);

	return 0;
}
#endif