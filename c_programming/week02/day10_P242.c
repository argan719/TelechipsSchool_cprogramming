#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdint.h>

#if 0
typedef struct _profile {  // �̸����� _ ���̰�
	int age;
	double height;
	char name[20];
	char* phone_no;
}profile_t;  // ���� �̸� ����ؼ� Ÿ�� ����

typedef struct _student{
	profile_t pf;
	int num;
	double grade;
}student_t;

typedef struct _student2 {
	profile_t* pp;
	int num;
	double grade;
}student_t2;

int main() {
	// �ڱ���������ü �̿�� . . �� �� ���� ��.
	student_t s1;
	s1.pf.age = 10;
	// �ʱ�ȭ ��
	student_t s2 = { {20, 175, "ȫ�浿", "1111"}, 2, 4.5 };   // {a, 2, 4.5} �� ����
	student_t* p = &s2;
	printf("%d %0.f %s %s\n", s2.pf.age, s2.pf.name, s2.pf.phone_no);
	printf("%d %.1f\n", s2.num, s2.grade);
}
int main(void) {
	profile_t a = { 20, 175, "ȫ�浿", "010-1111" };
	profile_t b = a;
	student_t s1 = { {20, 175, "ȫ�浿", "1111"}, 2, 4.5 };
	student_t* p1 = &s1;
	student_t2 s2 = { &a, 2, 4.5 };
	student_t2* p2 = &s2;

	// p2 : p2->pp->age
	// p2 : p2->num
	printf("%d %0.f %s %s\n", p2->pp->age, p2->pp->height, p2->pp->name, p2->pp->phone_no);
	printf("%d %.1f\n", p2->num, p2->grade);
}

int main() {
	student_t s1 = { {20, 175, "ȫ�浿", "1111"}, 2, 4.5 };   
	student_t* p = &s1;
	printf("%d %0.f %s %s\n", p->pf.age, p->pf.height, p->pf.name);
	printf("%d %.1f\n", p->num, p->grade);
}

int main(void) {
	profile_t a = { 20, 175, "ȫ�浿" };
	profile_t b = a;   // ����ü������ ���簡 ���� (�ּҴ� ����X. �ܼ� Copy)
	b.age += 2;
	//a.name = "������";   // ����. �Ұ��� (a.name�� �迭, ������ ����̹Ƿ�)
	b.phone_no = "010-1234";  // ����. ������ �����̹Ƿ�
	printf("%d %.0f %s\n", a.age, a.height, a.name);
	printf("%d %.0f %s\n", b.age, b.height, b.name);
	return 0;
}
#endif



#if 0
typedef struct _subject {  
	int score;
	char sub_name[10];
}subject_t;  

typedef struct _student {
	subject_t subject[3];
	int num;
	char stu_name[10];
}student_t;

#define SIZE (arr) (sizeof(arr)/sizeof((arr)[0]))

int main(void) {
	student_t s1 = { {{100, "kor"}, {90, "eng"}, {95, "mat"}}, 1, "Tom" };
	// 1 Tom
	printf("%d %s\n", s1.num, s1.stu_name);
	// Kor - 100
	printf("%d %s\n", s1.subject[0].score, s1.subject[0].sub_name);
	// Eng - 90
	printf("%d %s\n", s1.subject[1].score, s1.subject[1].sub_name);
	// Mat - 95
	printf("%d %s\n\n", s1.subject[2].score, s1.subject[2].sub_name);


	student_t arr[3] = { {{{100, "kor"}, {90, "eng"}, {95, "mat"}}, 1, "Tom"},
		{{{90, "kor"}, {80, "eng"}, {75, "mat"}}, 2, "Jerry"},
		{{{80, "kor"}, {70, "eng"}, {65, "mat"}}, 3, "John"}
	};
	// 1 Tom
	printf("%d %s\n", arr[0].num, arr[0].stu_name);
	// Kor - 100
	printf("%s %d\n", arr[0].subject->sub_name, arr[0].subject->score);
	// Eng - 90
	printf("%s %d\n", (arr[0].subject + 1)->sub_name, (arr[0].subject +1)->score);
	// Mat - 95
	printf("%s %d\n\n", (arr->subject + 2)->sub_name, (arr->subject + 2)->score);


	printf("<< �ݺ��� ��� ��ü ��� >>\n\n");
	// �ݺ��� ��� arr �迭 ��ü ���
	for (int i = 0; i < (sizeof(arr) / sizeof(arr[0])); i++) {
		printf("%d %s\n", arr[i].num, arr[i].stu_name);
		// Kor - 100
		printf("%s %d\n", arr[i].subject->sub_name, arr[i].subject->score);
		// Eng - 90
		printf("%s %d\n", (arr[i].subject + 1)->sub_name, (arr[i].subject + 1)->score);
		// Mat - 95
		printf("%s %d\n\n", ((arr +i)->subject + 2)->sub_name, ((arr+i)->subject + 2)->score);
	}

}

#endif


#if 0
#define size_ary(x) (sizeof(x) / sizeof((x)[0]))
struct student {
	int id;
	int scores[3];
	char name[20];
};
// ���� �����. ���� ���� �ҷ��ͼ� ����
void input_data(struct student* arr, int n) {
	for (int i = 0; i < n; ++i) {
		(void)scanf("%d %d %d %d %s", &arr[i].id, &arr[i].scores[0], &arr[i].scores[1], &arr[i].scores[2], arr[i].name);
	}
}
// �״�� ���
void print_data(struct student* arr, int n) {
	for (int i = 0; i < n; ++i) {
		printf("%d %d %d %d %s\n", arr[i].id, arr[i].scores[0], arr[i].scores[1], arr[i].scores[2], arr[i].name);
	}
}
int main(void) {
	struct student stu[5] = { 0 };
	(void)freopen("student.txt", "r", stdin);

	input_data(stu, size_ary(stu));
	print_data(stu, size_ary(stu));
	return 0;
}
#endif




#if 0
typedef struct student {
	int id;
	int *scores;
	char name[20];
}student_t;

student_t* init_data(int n_student, int n_score) {
	student_t* temp = 0;
	temp = (student_t*)calloc(n_student, sizeof(student_t));
	if (temp == NULL) {
		printf("�޸� ���� 1\n");
		return 0;
	}
	for (int i = 0; i < n_student; ++i) {
		temp[i].scores = (int*)calloc(n_score, sizeof(int));
		if (temp[i].scores == NULL) {
			for (int j = 0; j < i; ++j)
				free(temp[j].scores);
			free(temp);
			printf("�޸� ���� 2\n");
			return 0;
		}
	}
	return temp;
}

// ���� �����. ���� ���� �ҷ��ͼ� ����
void input_data(student_t** arr, int n) {
	for (int i = 0; i < n; ++i) {
		(void)scanf("%d %d %d %d %s", &((*arr)[i].id), &((*arr)[i].scores[0]), &((*arr)[i].scores[1]), &((*arr)[i].scores[2]), (*arr)[i].name);
	}
}
void input_data2(student_t* stu, int n_student, int n_score) {
	// ������ �Է�
	student_t* curr = 0;
	for (int i = 0; i < n_student; ++i) {
		curr = stu + i;
		(void)scanf("%d", &stu[i].id);
		for (int j = 0; j < n_score; ++j) {
			(void)scanf("%d", stu[i].scores + j);
		}
		(void)scanf("%s", stu[i].name);
	}
}
void free_data(student_t* stu, int n_student) {
	for (int i = 0; i < n_student; ++i) {
		free(stu[i].scores);
		stu[i].scores = NULL;
	}
	free(stu);
	// �� �ȿ� �޸� ���� �����ϰ� �� ������ ��ü �޸� ��������� ��.
}
// �״�� ���
void print_data(student_t* arr, int n) {
	for (int i = 0; i < n; ++i) {
		printf("%d %d %d %d %s\n", arr[i].id, arr[i].scores[0], arr[i].scores[1], arr[i].scores[2], arr[i].name);
	}
}

int main(void) {

	//student_t stu[5] = { 0 };   // 5�� �𸥴ٰ� ����. ���Ϸκ��� �޾ƿ�����
	(void)freopen("student.txt", "r", stdin);
	int N, M;
	(void)scanf("%d %d", &N, &M);
	printf("�迭 ���� Ȯ�� : %d %d\n\n", N, M);

	//stu = init_data(n_student, n_score);
	student_t* stu = (student_t*)malloc(N * sizeof(student_t));
	for (int i = 0; i < N; i++) {
		(stu + i)->scores = (int*)malloc(M * sizeof(int));
	}
	input_data(&stu, N);
	print_data(stu, N);
	free_data(stu, N); stu = NULL;
	return 0;
}
#endif


#if 0
typedef struct student {
	int id;
	int* scores;
	char name[20];
}student_t;

void init_data(student_t** stu, int** score, int n_student, int n_score) {

}
student_t* init_data_1(int n_student) {
	student_t* temp = NULL;
	temp = (student_t*)callo(n_student, sizeof(student_t));
	if (temp == NULL) {
		printf("�޸� ���� 1\n");
		return 0;
	}
	return temp;
}

int* init_data_2(int n) {
	int* temp = NULL;
	temp = (int*)calloc(n, sizeof(int));
	if (temp == NULL) {
		printf("�޸� ���� 2\n");
		return 0;
	}
	return temp;
}

typedef int a_int3[3];
typedef a_int3* ap_int3;

int (*init_data_3(int n_student))[3] {  // input_data_2�� ������ ������ �ڵ�. ���� �͸� �ٸ���. ���� ������ �ٸ���.
	int(*temp)[3] = NULL;
	temp = (int(*)[3])calloc(n_student, sizeof(int[3]));
	if (temp == NULL) {
		printf("�޸� ���� 2\n");
		return 0;
	}
	return temp;
}

void free_data(student_t** stu, int* scores) {
	free(*stu);
	free(*scores);
	*stu = 0;
	*scores = 0;
}

int main(void) {

	//student_t stu[5] = { 0 };   // 5�� �𸥴ٰ� ����. ���Ϸκ��� �޾ƿ�����
	student_t* stu = 0;
	int* scores = 0;

	int n_student, n_score;
	int (*score_arr)[3] = 0;
	(void)freopen("student2.txt", "r", stdin);
	(void)scanf("%d %d", &n_student, &n_score);
	stu = init_data_1(n_student);
	//scores = init_data_2(n_student * n_score);
	score_arr = init_data_3(n_student);
	for (int i = 0; i < n_student; ++i) {
		//stu[i].scores = scores + i * 3;
		stu[i].scores = score_arr + i;
	}
	input_data(&stu, n_student, n_score);
	print_data(stu, n_student, n_score);
	free_data(stu, n_student); stu = NULL;
	return 0;
}
#endif



#if 0
struct mix1 {
	double z;
	int a;
	char x;
};

struct mix2 {
	char x;
	double z;
	int a;
};

int main(void) {
	printf("%d %d\n", sizeof(struct mix1), sizeof(struct mix2));
	return 0;
}
#endif



#if 0
#pragma pack(push, 1)
struct mix1 {
	double z;
	int a;
	char x;
};

struct mix2 {
	char x;
	double z;
	int a;
};

int main(void) {
	printf("%d %d\n", sizeof(struct mix1), sizeof(struct mix2));
	return 0;
}

#endif



#if 0
#pragma pack(push, 4)
struct bit_00 {
	unsigned int Version;
	unsigned int IHL;
	double TOS;
	double len[2];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct bit_04 {
	double identification[2];
	char frag_offset[13];
	char ip_flag_x;
	char ip_flag_D;
	char ip_flag_M;
};
#pragma pack(pop)

#pragma pack(push, 8)
struct bit_08 {
	double TTL;
	double Protocol;
	double Header_checksum[2];
};
#pragma pack(pop)

struct bit_12 {
	double Source_Address[4];
};

struct bit_16 {
	double Destination_Address[4];
};

struct bit_206 {
	double IP_Option[4];
};

#endif



#if 1
typedef struct _rgb_t {
	unsigned short blue : 5;
	unsigned short green : 6;
	unsigned short red : 7;
}rgb_t;

typedef union _pixel {
	rgb_t rgb;
	unsigned short color;
}pixel_t;

int main(void) {
	pixel_t dot1 = { 1, 2, 3 };  // ����ü�� ���ǵ� ������� �� blue=1, green=2, red=3
	printf("%d %d %d\n", dot1.rgb.red, dot1.rgb.green, dot1.rgb.blue);  // 3 2 1 

	printf("%d %d\n", sizeof(rgb_t), sizeof(pixel_t));
	printf("%p %p\n", &dot1.rgb, &dot1.color);  // ���� �ּҰ� ����
	//printf("%p\n", &dot1.rgb,red)  // ����. �ּ� ����.
	dot1.color = 0x1234;  //00010 010001 10100
	printf("%d %d %d\n", dot1.rgb.red, dot1.rgb.green, dot1.rgb.blue);
	dot1.rgb.red = 13;
	printf("%x\n", dot1.color);

}
#endif