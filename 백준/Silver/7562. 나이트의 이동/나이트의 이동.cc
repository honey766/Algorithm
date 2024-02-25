#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int n, si, sj, ei, ej;
bool visited[300][300];
queue<pair<short, short>> que;

bool validPos(int i, int j) {
    return 0 <= i && i < n && 0 <= j && j < n;
}

void visit(int a, int b) {
    if (validPos(a, b) && !visited[a][b]) {
        que.push({ a,b });
        visited[a][b] = true;
    }
}

//8곳을 방문
void visitEight(int a, int b) {
    for (int i = -1; i <= 1; i += 2) {
        for (int j = -2; j <= 2; j += 4) {
            visit(a + i, b + j);
            visit(a + j, b + i);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int tc, cnt, i, j;
    bool end;
    cin >> tc;
    while (tc--) {
        cin >> n >> si >> sj >> ei >> ej;
        memset(visited, 0, 90000);
        cnt = 0;
        que = queue<pair<short, short>>();
        visit(si, sj);
        while (!que.empty()) {
            end = false;
            int sz = que.size();
            while (sz--) {
                i = que.front().first;
                j = que.front().second;
                que.pop();
                if (i == ei && j == ej) {
                    end = true;
                    break;
                }
                visitEight(i, j);
            }
            if (end) break;
            cnt++;
        }
        cout << cnt << '\n';
    }
}