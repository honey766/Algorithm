#include <iostream>
#include <algorithm>
using namespace std;

struct Data {
	int x, y, len;
};

bool comp(const Data& a, const Data& b) {
	return a.len > b.len;
}

Data Pos[40];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n, Min = 50;
	int lx, ly, hx, hy, sum, rqLen, cutCnt;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> Pos[i].x >> Pos[i].y >> Pos[i].len;
	sort(Pos, Pos + n, comp);

	//Pos[i], Pos[j]가 울타리 사각형의 양 끝점일 때
	//해당 사각형 밖의 나무를 전부 벌목하고, 사각형 안의 나무들을 길이가 큰 순서대로 벌목한다
	//울타리를 만들 수 있는 시점에 벌목한 나무 수를 기록한다
	//실행횟수 : 40H4 * 80 = 123410 * 80 = 1000만 (중복조합)
	for (int i = 0; i < n; i++) for (int j = i; j < n; j++)
		for (int ii = j; ii < n; ii++) for (int jj = ii; jj < n; jj++) {
			sum = cutCnt = 0;
			lx = min({ Pos[i].x, Pos[j].x, Pos[ii].x, Pos[jj].x });
			hx = max({ Pos[i].x, Pos[j].x, Pos[ii].x, Pos[jj].x });
			ly = min({ Pos[i].y, Pos[j].y, Pos[ii].y, Pos[jj].y });
			hy = max({ Pos[i].y, Pos[j].y, Pos[ii].y, Pos[jj].y });
			rqLen = 2 * (hx - lx + hy - ly);

			for (int k = 0; k < n; k++) {
				if (k == i || k == j || k == ii || k == jj) continue;
				if (Pos[k].x < lx || Pos[k].x > hx || Pos[k].y < ly || Pos[k].y > hy) {
					sum += Pos[k].len; cutCnt++;
				}
			}

			for (int k = 0; k < n && sum < rqLen; k++) {
				if (k == i || k == j || k == ii || k == jj) continue;
				if (lx < Pos[k].x && Pos[k].x < hx && ly < Pos[k].y && Pos[k].y < hy) {
					sum += Pos[k].len; cutCnt++;
				}
			}

			if (sum >= rqLen) Min = min(Min, cutCnt);
		}
	cout << Min;
}