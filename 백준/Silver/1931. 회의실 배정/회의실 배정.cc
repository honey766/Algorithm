#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int a, b, n, finishT = 0, cnt = 1;
    cin >> n;
    pair<int, int>* arr = new pair<int, int>[n];
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        arr[i].first = b; //끝나는 시간 기준 정렬
        arr[i].second = a;
    }
    sort(arr, arr + n);
    finishT = arr[0].first;
    for (int i = 1; i < n; i++)
        if (finishT <= arr[i].second) {
            ++cnt;
            finishT = arr[i].first;
        }
    cout << cnt;
}