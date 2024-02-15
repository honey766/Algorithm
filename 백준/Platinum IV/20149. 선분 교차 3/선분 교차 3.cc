#include <iostream>
using namespace std;
#define INF 10'000'000
#define prd pair<double, double>

struct Data {
	int x;
	int y;
};
struct pr {
	Data p1;
	Data p2;
};

void swap(Data& a, Data& b) {
	Data tmp = a;
	a = b;
	b = tmp;
}

int ccw(Data a, Data b, Data c) { //ab, ac 외적
	long long t = (long long)(b.x - a.x) * (c.y - a.y) - (long long)(c.x - a.x) * (b.y - a.y);
	return (t ? (t > 0 ? 1 : -1) : 0);
}

pair<bool, prd> check(pr a, pr b) {
	int w1, w2, w3, w4, ccw1, ccw2;
	w1 = ccw(a.p1, a.p2, b.p1);
	w2 = ccw(a.p1, a.p2, b.p2);
	w3 = ccw(b.p1, b.p2, a.p1);
	w4 = ccw(b.p1, b.p2, a.p2);
	ccw1 = w1 * w2;
	ccw2 = w3 * w4;
	prd cor = { INF, INF };

	if (ccw1 == 0 && ccw2 == 0) {
		Data c = a.p1, d = a.p2, e = b.p1, f = b.p2;
		if (c.x > d.x) swap(c, d);
		if (e.x > f.x) swap(e, f);

		bool chk = (e.x <= d.x && c.x <= f.x);
		if (c.y < d.y) {
			if (e.y <= f.y) chk = chk && (e.y <= d.y && c.y <= f.y);
			else chk = true;
		}
		else {
			if (e.y >= f.y) chk = chk && (e.y >= d.y && c.y >= f.y);
			else chk = true;
		}

		if (!w1 && !w2 && !w3 && !w4) { //네 점이 일직선
			if (c.x == d.x) {//수직선
				if (c.y > d.y) swap(c, d);
				if (e.y > f.y) swap(e, f);
				if(d.y == e.y) cor = { d.x, d.y };
				else if (c.y == f.y) cor = { c.x, c.y };
			}
			else {
				if (d.x == e.x) cor = { d.x, d.y };
				else if (c.x == f.x) cor = { c.x, c.y };
			}
			return { chk, cor };
		}
		
		if ((c.x == e.x && c.y == e.y) || (c.x == f.x && c.y == f.y)) cor = { c.x, c.y };
		if ((d.x == e.x && d.y == e.y) || (d.x == f.x && d.y == f.y)) cor = { d.x, d.y };
		return { chk, cor };
	}

	bool chk = (ccw1 <= 0 && ccw2 <= 0);
	if (chk) {
		if (a.p1.x != a.p2.x && b.p1.x != b.p2.x) {
			double m1 = (double)(a.p2.y - a.p1.y) / (a.p2.x - a.p1.x);
			double m2 = (double)(b.p2.y - b.p1.y) / (b.p2.x - b.p1.x);
			//m1 != m2가 보장됨
			double x = ((m2 * b.p1.x) + a.p1.y - (m1 * a.p1.x) - b.p1.y) / (m2 - m1);
			double y = m1 * (x - a.p1.x) + a.p1.y;
			cor = { x, y };
		}
		else if (a.p1.x == a.p2.x) { //a가 x축에 수직
			double m2 = (double)(b.p2.y - b.p1.y) / (b.p2.x - b.p1.x);
			double y = m2 * (a.p1.x - b.p1.x) + b.p1.y;
			cor = { a.p1.x, y };
		}
		else { //b가 x축에 수직
			double m1 = (double)(a.p2.y - a.p1.y) / (a.p2.x - a.p1.x);
			double y = m1 * (b.p1.x - a.p1.x) + a.p1.y;
			cor = { b.p1.x, y };
		}
	}
	return { chk, cor };
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cout << fixed;
	cout.precision(16);

	pr line[2];
	for (int i = 0; i < 2; ++i)
		cin >> line[i].p1.x >> line[i].p1.y >> line[i].p2.x >> line[i].p2.y;
	pair<bool, prd> prs = check(line[0], line[1]);
	cout << (int)prs.first << '\n';
	if (prs.first) {
		prd cor = prs.second;
		if (cor.first == INF) return 0;
		cout << cor.first << ' ' << cor.second;
	}
}