#include <iostream>
using namespace std;
#define MOD(x, m) ((x) % (m) == 0 ? (m) : (x) % (m))

int gcd(int a, int b)
{
    int tmp;
    while (b > 0) {
        tmp = a;
        a = b;
        b = tmp % b;
    }
    return a;
}

void swap(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int tc, m, n, x, y;
    long long lcm;
    cin >> tc;
    while (tc--) {
        cin >> m >> n >> x >> y;
        lcm = (long long)m * n / gcd(m, n);
        if (m < n) { //m이 더 크게
            swap(m, n); swap(x, y);
        }

        int tmp = x - m;
        while ((tmp += m) <= lcm)
            if (MOD(tmp, n) == y) break;

        if (tmp > lcm) cout << "-1\n";
        else cout << tmp << '\n';
    }
}