#include<iostream>
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MAX4(x, y, z, w) (MAX(MAX(MAX((x), (y)), (z)), (w)))

using namespace std;

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	int test_case;
	int T;

	T = 10;
    int* arr = new int[1000]();
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n, a, max, count = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a; arr[i] = a;
		}
		for (int i = 2; i < n - 2; i++) {
			max = MAX4(arr[i - 2], arr[i - 1], arr[i + 1], arr[i + 2]);
			max = arr[i] - max;
			max = max < 0 ? 0 : max;
			count += max;
		}
		cout << '#' << test_case << ' ' << count << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}