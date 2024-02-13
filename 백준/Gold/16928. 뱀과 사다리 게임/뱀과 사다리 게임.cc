#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
#define pr pair<char, char>

int n, m;
queue<char> que;
bool visited[101];

void visit(int i) {
    que.push(i);
    visited[i] = true;
}

//찾으면 어디로 이동하는지 반환
char binarySearch(pr* arr, int n, char x) {
    int l = 0, r = n - 1, mid;
    while (l <= r) {
        mid = (l + r) / 2;
        if (arr[mid].first == x) return arr[mid].second;
        if (arr[mid].first < x) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    memset(visited, 0, 101);
    int i, j, to, cnt = -1;
    cin >> n >> m;
    pr* ladder = new pr[n];
    pr* snake = new pr[m];
    for (i = 0; i < n; ++i) {
        cin >> j >> to;
        ladder[i] = { j, to };
    }
    for (i = 0; i < m; ++i) {
        cin >> j >> to;
        snake[i] = { j, to };
    }
    sort(ladder, ladder + n);
    sort(snake, snake + m);

    visit(1);
    while (!que.empty() && i < 100) {
        int sz = que.size();
        while (sz--) {
            i = que.front();
            if (i == 100) break;
            que.pop();
            for (j = 1; j <= 6; ++j) {
                int tmp = i + j;
                if (visited[tmp] || 100 < tmp) continue;
                visited[tmp] = true;
                if ((to = binarySearch(ladder, n, i + j)) != -1) {
                    if (!visited[to])
                        visit(to);
                }
                else if ((to = binarySearch(snake, m, i + j)) != -1) {
                    if (!visited[to])
                        visit(to);
                }
                else visit(tmp);
            }
        }
        ++cnt;
    }
    cout << cnt;
}