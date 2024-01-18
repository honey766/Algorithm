#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int a, b, c;
	int w[21][21][21];
	for (int i = 0; i <= 20; i++)
		for (int j = 0; j <= 20; j++)
			w[i][j][0] = w[0][i][j] = w[j][0][i] = 1;
	for (int i = 1; i <= 20; i++)
		for (int j = 1; j <= 20; j++)
			for (int k = 1; k <= 20; k++)
				if (i < j && j < k)
					w[i][j][k] = w[i][j][k - 1] + w[i][j - 1][k - 1] - w[i][j - 1][k];
				else
					w[i][j][k] = w[i - 1][j][k] + w[i - 1][j - 1][k] + w[i - 1][j][k - 1] - w[i - 1][j - 1][k - 1];
	
	while (cin >> a >> b >> c) {
		if (a == -1 && b == -1 && c == -1) break;
		if (a <= 0 || b <= 0 || c <= 0)
			cout << "w(" << a << ", " << b << ", " << c << ") = " << w[0][0][0] << '\n';
		else if(a > 20 || b > 20 || c > 20)
			cout << "w(" << a << ", " << b << ", " << c << ") = " << w[20][20][20] << '\n';
		else
			cout << "w(" << a << ", " << b << ", " << c << ") = " << w[a][b][c] << '\n';
	}
}