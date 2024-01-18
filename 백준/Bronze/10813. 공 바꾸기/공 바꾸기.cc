#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    int a, b, temp;
    int* arr;
    cin >> n >> m;
    arr = new int[n];
    
    for(int i = 0; i < n; i++) arr[i] = i + 1;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        temp = arr[a - 1];
        arr[a - 1] = arr[b - 1];
        arr[b - 1] = temp;
    }
    for(int i = 0; i < n; i++) {
        cout << arr[i];
        if(i != n - 1) cout << ' ';
    }
}