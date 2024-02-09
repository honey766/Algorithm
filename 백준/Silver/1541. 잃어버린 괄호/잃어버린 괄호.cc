#include <iostream>
#include <queue>
using namespace std;

//숫자와, 숫자가 끝나는 idx의 +1을 return
pair<int, int> toInt(const string& s, int i) {
    int n = 0;
    while (s[i] != '+' && s[i] != '-' && s[i] != '\0') {
        n *= 10;
        n += s[i++] - '0';
    }
    return { n, i };
}

//뺄셈이 등장할 때까지 수를 더했다가, 뺄셈이 등장하면 큐에 넣는다.
//큐에서 하나씩 빼며 수를 빼주면 최소이다.
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    queue<int> que;
    string s;
    cin >> s;
    int n = 0, i = 0;
    while (i < s.size()) {
        pair<int, int> p = toInt(s, i);
        n += p.first;
        i = p.second;
        if (s[i++] == '-') {
            que.push(n);
            n = 0;
        }
    }
    que.push(n);
    n = que.front(); que.pop();
    while (!que.empty()) {
        n -= que.front();
        que.pop();
    }
    cout << n;
}