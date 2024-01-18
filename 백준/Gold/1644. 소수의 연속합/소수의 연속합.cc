#include <iostream>
using namespace std;

const int primeNum = 283146; //소수의 개수
bool* a = new bool[4000001](); //소수라면 false

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t = 0, n, count = 0, sum;
    int* prime = new int[primeNum];
    for (int i = 2; i <= 4000000; i++) {
        if (a[i]) continue;
        prime[t++] = i;
        for (int j = 2 * i; j <= 4000000; j += i)
            a[j] = true;
    }
    cin >> n;
    for (int i = 0; i < primeNum; i++) {
        sum = 0;
        for (int j = i; j < primeNum && sum <= n; j++) {
            sum += prime[j];
            if (sum == n) {
                count++; break;
            }
        }
    }
    cout << count;
}