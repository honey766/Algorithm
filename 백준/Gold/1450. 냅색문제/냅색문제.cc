#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 2'000'000'000

int N, c;
int* arr;
long long cnt = 0, sum = 0;
vector<int> vec;

void f(int n, int i) {
    if (i > n) {
        if (n == N - 1)
            cnt += upper_bound(vec.begin(), vec.end(), c - sum) - vec.begin();
        else 
            vec.push_back(sum > INF ? INF : sum);
        return;
    }
    sum += arr[i];
    f(n, i + 1);
    sum -= arr[i];
    f(n, i + 1);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int sn;
    cin >> N >> c;
    arr = new int[N];
    for (int i = 0; i < N; ++i)
        cin >> arr[i];
    sn = (N - 1) / 2;
    
    if (N == 1) {
        cout << ((arr[0] <= c) ? 2 : 1);
        return 0;
    }
    f(sn, 0);
    sort(vec.begin(), vec.end());
    f(N - 1, sn + 1);
    cout << cnt;
}