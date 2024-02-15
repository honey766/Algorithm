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

int ccw(Data a, Data b, Data c) { //ab, ac 외적
	long long t = (long long)(b.x - a.x) * (c.y - a.y) - (long long)(c.x - a.x) * (b.y - a.y);
	return (t ? (t > 0 ? 1 : -1) : 0);
}

bool check(pr a, pr b) {
	int ccw1 = ccw(a.p1, a.p2, b.p1) * ccw(a.p1, a.p2, b.p2);
	int ccw2 = ccw(b.p1, b.p2, a.p1) * ccw(b.p1, b.p2, a.p2);
	return ccw1 < 0 && ccw2 < 0;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	pr line[2];
	for (int i = 0; i < 2; ++i)
		cin >> line[i].p1.x >> line[i].p1.y >> line[i].p2.x >> line[i].p2.y;
	cout << (int)check(line[0], line[1]);
}