#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    char hash[21] = { 0, };
    int m, x;
    string s;
    cin >> m;
    while (m--) {
        cin >> s;
        switch (s[0]) {
        case 'a':
            switch (s[1]) {
            case 'd': //add x
                cin >> x;
                hash[x] = 1;
                break;
            case 'l': //all
                memset(hash, 1, 21);
                break;
            }
            break;
        case 'r': //remove x
            cin >> x;
            hash[x] = 0;
            break;
        case 'c': //check x
            cin >> x;
            cout << (int)hash[x] << '\n';
            break;
        case 't': //toggle x
            cin >> x;
            hash[x] = 1 - hash[x];
            break;
        case 'e': //empty
            memset(hash, 0, 21);
            break;
        }
    }
}