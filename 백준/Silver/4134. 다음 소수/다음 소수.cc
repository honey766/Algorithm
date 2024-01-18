#include <iostream>
#include <cmath>
using namespace std;

long long int prime(long long int a) {
    if (a < 2) return 2;
    int sqrta;
    bool isprime;
    while (true) {
        sqrta = sqrt(a);
        isprime = true;
        for (int i = 2; i <= sqrta; i++)
            if (a % i == 0) { isprime = false; break; }
        if (isprime) return a;
        a++;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
 
    int n;
    long long int a;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        cout << prime(a) << '\n';
    }
}