#include <iostream>
using namespace std;

int main(){
    int n, a[100], b[100], x[100];
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i] >> x[i];
        cout << a[i] * (x[i] - 1) + b[i] << '\n';
    }
}