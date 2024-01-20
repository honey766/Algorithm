#include <iostream>
using namespace std;

int cal(int a, int k) {
    int cnt = 0;
    while (a < k) {
        if (k < 2 * a) {
            cnt += k - a - 1;
            k = a;
        }
        else if (k % 2)
            k--;
        else k /= 2;
        cnt++;
    }
    return cnt;
}

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int a, k;
    cin >> a >> k;
    cout << cal(a, k);
}