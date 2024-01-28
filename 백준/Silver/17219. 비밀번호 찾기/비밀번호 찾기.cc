#include <iostream>
#include <map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, m;
    string s1, s2;
    map<string, string> mapset;
    cin >> n >> m;
    while (n--) {
        cin >> s1 >> s2;
        mapset.emplace(s1, s2);
    }
    while (m--) {
        cin >> s1;
        cout << mapset[s1] << '\n';
    }
}