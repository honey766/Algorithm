#include <iostream>
using namespace std;

struct Data {
	int x;
	int y;
};
struct pr {
	Data p1;
	Data p2;
};

void swap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}

int ccw(Data a, Data b, Data c) { //ab, ac 외적
	long long t = (long long)(b.x - a.x) * (c.y - a.y) - (long long)(c.x - a.x) * (b.y - a.y);
	return (t ? (t > 0 ? 1 : -1) : 0);
}

int check(pr a, pr b) {
	int w1, w2, w3, w4;
	w1 = ccw(a.p1, a.p2, b.p1);
	w2 = ccw(a.p1, a.p2, b.p2);
	w3 = ccw(b.p1, b.p2, a.p1);
	w4 = ccw(b.p1, b.p2, a.p2);
	int ccw1 = w1 * w2;
	int ccw2 = w3 * w4;
	
	if (!w1 && !w2 && !w3 && !w4) { //4개의 점이 일직선 상에 있음
		int c = a.p1.x, d = a.p2.x, e = b.p1.x, f = b.p2.x;
		if (c == d) {//수직선, y좌표를 비교
			c = a.p1.y; d = a.p2.y; e = b.p1.y; f = b.p2.y;
		}
		if (c > d) swap(c, d);
		if (e > f) swap(e, f);
		if (d == e || c == f) return 1;
		if (e < d && c < f) return 3;
		return 0;
	}
	else if (ccw1 == 0 && ccw2 == 0) { //3개의 점이 일직선 상에 있음(두 점이 같음)
		return 1;
	}
	else if (ccw1 == 0 || ccw2 == 0) { //3개의 점이 일직선 상에 있음(두 점이 다름)
		if (ccw1 > 0 || ccw2 > 0) //두 선분이 만나지 않음
			return 0;
		return 1; //한 선분의 끝점에서 만남
	}
	if (ccw1 > 0 || ccw2 > 0)
		return 0;
	return 2;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n;
	cin >> n;
	pr* line = new pr[n];
	for (int i = 0; i < n; ++i)
		cin >> line[i].p1.x >> line[i].p1.y >> line[i].p2.x >> line[i].p2.y;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			cout << check(line[i], line[j]);
		cout << '\n';
	}
}