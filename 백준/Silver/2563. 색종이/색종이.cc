#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int arr[100][100] = { 0, };
    int n, a, b, area = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        for (int j = 0; j < 10; j++)
            for (int k = 0; k < 10; k++)
                if (a + j < 100 && b + k < 100)
                    arr[a + j][b + k] = 1;
    }
    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++)
            area += arr[i][j];
    cout << area;
}