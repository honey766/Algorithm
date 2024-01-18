#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int num, n;
    string s;
    cin >> num;
    for(int i = 0; i < num; i++){
        cin >> n >> s;
        for(int j = 0; j < s.length(); j++)
            for(int k = 0; k < n; k++)
                cout << s[j];
        cout << '\n';
    }
}