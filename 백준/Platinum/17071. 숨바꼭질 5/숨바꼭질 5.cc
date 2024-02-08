#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

struct visit {
    char visited;
    short cnt;
};

visit visited[500001];
vector<int> pos;
queue<int> que;

void pushque(int n, int cnt) {
    que.push(n);
    ++visited[n].visited;
    visited[n].cnt = cnt;
}

//같은 수에 대한 방문은 홀수 한 번, 짝수 한 번 허용한다.
//이미 방문했다면 true
bool visitCheck(int n, int cnt) {
    if (visited[n].visited == 0) return false;
    if (visited[n].visited == 1 && (visited[n].cnt + cnt) % 2 == 1) return false;
    return true;
}

void makePos(int k) {
    int a = 0;
    while (k <= 500000) {
        pos.push_back(k);
        k += ++a;
    }
}

//형은 cnt번 이동 후에 n에 있다. +1, -1을 반복하며 동생이 n에 오기를 기다린다.
//동생은 cnt번, cnt+2번, ... 번 이동 후에 형과 만날 수 있다.
//만나면 몇 번째에 만나는지 return한다.
//만나지 않으면 -1을 return한다.
int check(int n, int cnt) {
    int idx = lower_bound(pos.begin(), pos.end(), n) - pos.begin();
    if (idx != pos.size() && pos[idx] == n && cnt <= idx && (idx - cnt) % 2 == 0)
        return idx;
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, k, a, whenMeet, cnt = 0, Min = 1000000;
    cin >> n >> k;
    memset(visited, 0, 150'0005);
    
    makePos(k);
    pushque(n, 0);
    while (!que.empty() && cnt < pos.size() && cnt < Min) {
        int sz = que.size();
        while (sz--) {
            a = que.front();
            que.pop();
            if ((whenMeet = check(a, cnt)) != -1) Min = min(Min, whenMeet);
            if (a * 2 <= 500000 && !visitCheck(a * 2, cnt)) pushque(a * 2, cnt);
            if (a < 500000 && !visitCheck(a + 1, cnt)) pushque(a + 1, cnt);
            if (a > 0 && !visitCheck(a - 1, cnt)) pushque(a - 1, cnt);
        }
        ++cnt;
    }
    if (Min == 1000000) cout << "-1";
    else cout << Min;
}