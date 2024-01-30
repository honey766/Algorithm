#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct Data {
    int n;
    int cnt;
    vector<long long> vec; //2비트씩 곱셈/덧셈/뺄셈 중 하나의 정보를 저장함. long long 하나에 32개까지 저장
    Data() {}
    Data(int N, int C) { n = N; cnt = C; vec.push_back(0); }
    Data(int N, int C, vector<long long>& V) { n = N; cnt = C; vec = V; }
};

bool visited[100001];
queue<Data> que;

void pushque(Data& a, long long how) {
    vector<long long> vec = a.vec;
    int cnt = a.cnt % 32;
    if (!cnt) vec.push_back(0);
    vec[vec.size() - 1] += how << (cnt * 2);

    switch (how) {
    case 1:
        cnt = a.n * 2;
        break;
    case 2:
        cnt = a.n + 1;
        break;
    case 3:
        cnt = a.n - 1;
        break;
    }
    que.push(Data(cnt, a.cnt + 1, vec));
    visited[cnt] = true;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, k, cnt = 0;
    Data a;
    cin >> n >> k;
    if (k <= n) {
        cout << n - k << '\n';
        for (int i = n; i >= k; i--)
            cout << i << ' ';
        return 0;
    }
    memset(visited, 0, 100001);

    que.push(Data(n, 0));
    visited[n] = true;
    while (!que.empty()) {
        int sz = que.size();
        while (sz--) {
            a = que.front();
            if (a.n == k) break;
            que.pop();
            if (a.n * 2 <= 100000 && !visited[a.n * 2]) pushque(a, 1);
            if (a.n < 100000 && !visited[a.n + 1]) pushque(a, 2);
            if (a.n > 0 && !visited[a.n - 1]) pushque(a, 3);
        }
        if (a.n == k) break;
        cnt++;
    }
    cout << cnt << '\n' << n;
    vector<long long> vec = a.vec;
    for (int i = 0; i < vec.size(); i++) {
        unsigned long long num = vec[i];
        while (num) {
            switch (num & 3) {
            case 1:
                n *= 2;
                break;
            case 2:
                ++n;
                break;
            case 3:
                --n;
                break;
            }
            cout << ' ' << n;
            num >>= 2;
        }
    }
}