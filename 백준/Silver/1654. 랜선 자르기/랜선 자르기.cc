#include <iostream>
using namespace std;

int k;
int* arr;
//mid길이로 잘랐을 때 몇 개 나오는지 반환
int f(int mid) {
    int cnt = 0;
    for (int i = 0; i < k; i++)
        cnt += arr[i] / mid;
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, Max = -1;
    cin >> k >> n;
    arr = new int[k];
    for (int i = 0; i < k; i++) {
        cin >> arr[i];
        Max = max(Max, arr[i]);
    }
    int l = 1, r = Max, mid;
    while (l < r) {
        mid = l + (r - l + 1) / 2;
        if (f(mid) >= n) l = mid;
        else r = mid - 1;
    }
    cout << r;
}