#include <iostream>
using namespace std;

int selfNumber(int n) {
    int self = n;
    while (n) {
        self += n % 10;
        n /= 10;
    }
    return self;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    bool check;
    for (int i = 1; i <= 10000; i++) {
        check = false;
        int k = i > 36 ? i - 36 : 1;
        for(int j = k; j < i; j++)
            if (selfNumber(j) == i) {
                check = true;
                break;
            }
        if (!check) cout << i << '\n';
    }
}