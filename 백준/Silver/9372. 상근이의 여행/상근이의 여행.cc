#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, n, m;
    string s;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        while (m--)
            cin >> s >> s;
        cout << n - 1 << '\n';
    }
}