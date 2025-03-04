#if 0
int a = 1;
int b;   // 초기값을 안줬기 때문에 day06.c에 있는 b를 참조해서 사용함. b=1로
// 이런 경우 변수 앞에 extern을 붙여주면 좋음
// extern int b;   다른 곳에서 쓰는 b를 나도 같이 쓰자~
//extern int c;  // 오류. day06에서는 c를 static으로 선언했기 때문에 다른 곳에서 못 씀.
extern int c = 100;  // 사용 가능. 초기값이 있기 때문에 다른 곳에 c가 없으면 그냥 100으로 생성해버림. 
// 초기값 있는 게 우선.
// 원래는 extern이 없는 곳이 초기값이 있고, extern이 있는 곳에 초기값이 있으면 안됨.

int func3(void) {
	return a + b + c + 1000;
}
#endif