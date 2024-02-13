#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int sum, s, N;
int* arr;
long long cnt = 0;
vector<int> vec;

void f(int n, int i) {
    if (i > n) {
        if (n == N - 1) {
            cnt += upper_bound(vec.begin(), vec.end(), s - sum) -
                lower_bound(vec.begin(), vec.end(), s - sum);
        }
        else {
            vec.push_back(sum);
        }
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
    cin >> N >> s;
    arr = new int[N];
    for (int i = 0; i < N; ++i)
        cin >> arr[i];
    sn = (N - 1) / 2;
    
    if (N == 1) {
        cout << (int)(arr[0] == s);
        return 0;
    }
    sum = 0;
    f(sn, 0);
    sort(vec.begin(), vec.end());
    f(N - 1, sn + 1);
    //아무것도 넣지 않으면 sum은 0이다. s가 0일 경우 아무것도 넣지 않은 경우를 빼 준다
    if (s == 0) --cnt;
    cout << cnt;
}