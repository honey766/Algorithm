#include <iostream>
#include <cstring>
using namespace std;

int exists[1000001];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, a, b;
    cin >> n;
    int* arr = new int[n];
    int* score = new int[n]();
    memset(exists, -1, 4000004);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        exists[arr[i]] = i;
    }
    for (int i = 0; i < n; ++i) {
        a = arr[i];
        for (int j = a * 2; j <= 1000000; j += a) {
            if ((b = exists[j]) > -1) {
                ++score[i];
                --score[b];
            }
        }
    }
    for (int i = 0; i < n; ++i)
        cout << score[i] << ' ';
}