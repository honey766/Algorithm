#include <iostream>
using namespace std;
#define MIN(x,y) ((x) > (y) ? (y) : (x))

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n, Min;
	cin >> n;
	int* rgb = new int[3 * n];
	int* dpr = new int[n];
	int* dpg = new int[n];
	int* dpb = new int[n];
	for (int i = 0; i < 3 * n; i++) cin >> rgb[i];
	dpr[0] = rgb[0]; dpg[0] = rgb[1]; dpb[0] = rgb[2];
	for (int i = 1; i < n; i++) {
		dpr[i] = MIN(dpg[i - 1], dpb[i - 1]) + rgb[3 * i];
		dpg[i] = MIN(dpr[i - 1], dpb[i - 1]) + rgb[3 * i + 1];
		dpb[i] = MIN(dpr[i - 1], dpg[i - 1]) + rgb[3 * i + 2];
	}
	Min = MIN(MIN(dpr[n - 1], dpg[n - 1]), dpb[n - 1]);
	cout << Min;
}