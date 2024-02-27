#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    string t, p;
    getline(cin, t);
    getline(cin, p);
    int n = t.size(), m = p.size(), j = 0, i;
    int* pi = new int[m];
    vector<int> vec;
    //pi배열
    pi[0] = 0;
    for (i = 1; i < m; i++) {
        while (j > 0 && p[i] != p[j])
            j = pi[j - 1];
        if (p[i] == p[j])
            pi[i] = ++j;
        else
            pi[i] = 0;
    }

    //kmp
    j = 0;
    for (i = 0; i < n; i++) {
        while (j > 0 && t[i] != p[j])
            j = pi[j - 1];
        if (t[i] == p[j]) {
            j++;
            if (j == m) {
                vec.push_back(i - m + 2);
                j = pi[j - 1];
            }
        }
    }
    cout << vec.size() << '\n';
    for (i = 0; i < vec.size(); i++)
        cout << vec[i] << ' ';
}