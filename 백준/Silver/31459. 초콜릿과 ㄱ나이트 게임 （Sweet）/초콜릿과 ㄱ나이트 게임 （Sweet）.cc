#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int tc, X, Y, x, y, cnt;
	cin >> tc;
	while (tc--) {
		cin >> X >> Y >> x >> y;
		cnt = 0;
		while (X > 0 && Y > 0) {
			if (X < x || Y < y) cnt += X * Y;
			else cnt += Y * x + X * y - x * y; //X*Y칸에서 아래와 오른쪽을 가능한 한 많이 채운다
			//이제 채운 곳에서 위로 y칸, 왼쪽 x칸은 못 채운다
			Y -= 2 * y;
			X -= 2 * x;
		}
		cout << cnt << '\n';
	}
}