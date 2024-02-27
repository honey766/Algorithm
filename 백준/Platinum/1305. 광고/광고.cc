#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, j;
    string s;
    cin >> n >> s;

    //abc abc ab라면 맨 앞과 맨 끝이 5글자 겹침
    //abcde abc, cde abcde : 3글자 겹침
    //ef abcdef abc : 5글자 겹침
    //aa abcaa abca : 6글자 겹침
    int* pi = new int[n];
    pi[0] = j = 0;
    for (int i = 1; i < n; i++) {
        if (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            pi[i] = ++j;
        else
            pi[i] = 0;
    }
    cout << n - pi[n - 1];
}