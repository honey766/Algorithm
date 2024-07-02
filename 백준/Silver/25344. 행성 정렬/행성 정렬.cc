#include <iostream>
#include <numeric>
using namespace std;

int main(){
    int n; cin >> n;
    int prev = 1, next;
    cin >> next;
    for(int i = 0; i < n - 2; i++) {
        prev = lcm(prev, next);
        cin >> next;
    }
    cout << lcm(prev, next);
}