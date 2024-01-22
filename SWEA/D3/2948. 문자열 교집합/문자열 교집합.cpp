#include <iostream>
#include <set>
using namespace std;

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int test_case;
    int T;
    int n, m, cnt;
    string s;

    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        cnt = 0;
        set<string> mySet;
        cin >> n >> m;
        while (n--) {
            cin >> s;
            mySet.insert(s);
        }
        while (m--) {
            cin >> s;
            cnt += mySet.count(s);
        }
        cout << '#' << test_case << ' ';
        cout << cnt << '\n';
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}