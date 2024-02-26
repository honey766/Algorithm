#include <iostream>
#include <algorithm>
using namespace std;
#define f(s, e) (((s) + (e)) * ((e) - (s)))

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int g;
    cin >> g;
    int n = g / 2 + 1;
    bool find = false;

    long long start, end;
    start = end = 1;
    while (start < n) {
        if (f(start, end) >= g || end >= n) {
            if (f(start, end) == g) {
                cout << end << '\n';
                find = true;
            }
            start++;
        }
        else
            end++;
    }
    if (!find) cout << "-1";
}