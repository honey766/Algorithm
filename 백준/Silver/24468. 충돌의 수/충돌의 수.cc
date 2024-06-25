#include <iostream>
using namespace std;

const int EMPTY = 101;

struct Data {
	int x;
	bool isLeft;
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int L, N, T, a, i, cnt = 0;
	char c;
	cin >> L >> N >> T;
	Data* ball = new Data[N];
	char* pos = new char[L + 1]; //pos[i] : i 위치에 몇 번째 공이 있냐

	for (i = 0; i < N; i++) {
		cin >> ball[i].x >> c;
		ball[i].isLeft = (c == 'L');
	}
	for (i = 0; i <= L; i++) 
		pos[i] = EMPTY;

	while(T--){
		for (i = 0; i < N; i++) {
			if (ball[i].x == 0 || ball[i].x == L)
				ball[i].isLeft = !ball[i].isLeft;
			if (ball[i].isLeft) --ball[i].x;
			else ++ball[i].x;
			//이동 완료
			//충돌 체크
			if (pos[ball[i].x] != EMPTY) {
				++cnt;
				Data* tmp = &ball[pos[ball[i].x]];
				tmp->isLeft = !tmp->isLeft;
				ball[i].isLeft = !ball[i].isLeft;
			}
			pos[ball[i].x] = i; //현재 위치에 i번째 공이 있음
		}
		for (i = 0; i < N; i++)
			pos[ball[i].x] = EMPTY;
	}
	std::cout << cnt;
}