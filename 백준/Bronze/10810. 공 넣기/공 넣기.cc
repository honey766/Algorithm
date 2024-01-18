#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    int a, b, c;
    int* arr;
    cin >> n >> m;
    arr = new int[n]();
    
    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        for(int j = a - 1; j <= b - 1; j++){
            arr[j] = c;
        }
    }
    for(int i = 0; i < n; i++) {
        cout << arr[i];
        if(i != n - 1) cout << ' ';
    }
}