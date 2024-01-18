#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    getline(cin, s);
    int i = 0, num = 0, n = s.size();
    if(s[0] == ' ') i++;
    for(; i < n; i++) if(s[i] == ' ') num++;
    if(s[n - 1] != ' ') num++;
    cout << num;
}