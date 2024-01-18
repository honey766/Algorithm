#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int arr[26] = {3, 3, 3,  4, 4, 4,  5, 5, 5,  6, 6, 6,  7, 7, 7,  
                   8, 8, 8, 8,  9, 9, 9,  10, 10, 10, 10};
    string s;
    cin >> s;
    int n = 0;
    for(int i = 0; i < s.size(); i++) n += arr[s[i] - 'A'];
    cout << n;
}