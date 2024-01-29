#include <iostream>
#include <map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t, n, sum;
    string s1, s2;
    map<string, int> maps;
    cin >> t;
    while (t--) {
        maps.clear();
        cin >> n;
        while (n--) {
            cin >> s1 >> s2;
            if (maps.count(s2)) ++maps[s2];
            else maps.emplace(s2, 1);
        }
        sum = 1;
        for (auto it = maps.begin(); it != maps.end(); it++)
            sum *= (*it).second + 1; //같은 종류 옷의 개수 + 안 입는 경우
        cout << sum - 1 << '\n'; //알몸인 경우를 뺌
    }
}