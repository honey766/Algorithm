#include <iostream>
using namespace std;
#define ABS(x) ((x) > 0 ? (x) : -(x))

struct Data {
	short x;
	short y;
};

int ccw(Data a, Data b, Data c) {
	return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cout << fixed;
	cout.precision(1);
	
	int n, a, b, cnt = 0, w[3];
	Data cor[4];
	for (int i = 0; i < 3; ++i)
		cin >> cor[i].x >> cor[i].y;
	cor[3] = cor[0];
	cout << ABS(ccw(cor[0], cor[1], cor[2]) / 2.0) << '\n';

	cin >> n;
	cout.precision(0);
	while (n--) {
		cin >> a >> b;
		Data tmp = { a, b };
		for (int i = 0; i < 3; ++i) {
			a = ccw(cor[i], cor[i + 1], tmp);
			w[i] = (a ? (a > 0 ? 1 : -1) : 0);
		}
		//세 외적 결과의 방향이 같아야 함
		if ((w[0] >= 0 && w[1] >= 0 && w[2] >= 0) || (w[0] <= 0 && w[1] <= 0 && w[2] <= 0))
			++cnt;
	}
	cout << cnt;
}