#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s[5];
    int max = 0;
    for (int i = 0;i < 5; i++) {
        cin >> s[i];
        if (s[i].size() > max) max = s[i].size();
    }
    for (int i = 0;i < max; i++)
        for (int j = 0;j < 5; j++)
            if (s[j].size() > i)
                cout << s[j][i];
}