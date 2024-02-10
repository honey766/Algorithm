#include <iostream>
#include <map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    map<int, int> maps;
    char c;
    int n, a, tc; 
    cin >> tc;
    while (tc--) {
        maps.clear();
        cin >> n;
        while (n--) {
            cin >> c >> a;
            if (c == 'I')
                if (maps.count(a) == 0)
                    maps.emplace(a, 1);
                else
                    ++maps[a];
            else if (maps.empty())
                continue;
            else {
                pair<int, int> p;
                if (a == 1) p = *maps.rbegin();
                else p = *maps.begin();
                if (p.second == 1)
                    maps.erase(p.first);
                else
                    --maps[p.first];
            }
        }

        if (maps.empty())
            cout << "EMPTY\n";
        else
            cout << (*maps.rbegin()).first << ' ' << (*maps.begin()).first << '\n';
    }
}