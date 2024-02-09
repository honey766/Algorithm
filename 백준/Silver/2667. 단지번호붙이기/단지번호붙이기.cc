#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int T1[4] = { -1,0,0,1 };
int T2[4] = { 0,-1,1,0 };
bool** a;
bool** visited;

bool validPos(int i, int j) {
    return 0 <= i && i < n && 0 <= j && j < n;
}

int dfs(int i, int j) {
    int cnt = 0;
    visited[i][j] = true;
    for (int k = 0; k < 4; ++k) {
        int ni = i + T1[k];
        int nj = j + T2[k];
        if (validPos(ni, nj) && a[ni][nj] && !visited[ni][nj])
            cnt += dfs(ni, nj);
    }
    return cnt + 1;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int cnt = 0; cin >> n;
    string s;
    a = new bool*[n];
    visited = new bool* [n];
    for (int i = 0; i < n; ++i) {
        a[i] = new bool[n];
        visited[i] = new bool[n]();
        cin >> s;
        for (int j = 0; j < n; ++j)
            a[i][j] = s[j] - '0';
    }

    vector<int> vec;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (!visited[i][j] && a[i][j]) {
                vec.push_back(dfs(i, j));
                ++cnt;
            }

    sort(vec.begin(), vec.end());
    cout << vec.size() << '\n';
    for (int i = 0; i < vec.size(); ++i)
        cout << vec[i] << '\n';
}