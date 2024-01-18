#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    int a, max = -1, sum = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a;
        sum += a;
        if(a > max) max = a;
    }
    cout << (double)sum * 100 / max / n;
}