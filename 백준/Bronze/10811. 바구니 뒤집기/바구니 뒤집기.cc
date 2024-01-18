#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    int* arr;
    int a, b, mid, temp;
    cin >> n >> m;
    arr = new int[n];
    for(int i = 0; i < n; i++) arr[i] = i + 1;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        a--; b--; mid = (a + b + 1) / 2;
        for(int j = a; j < mid; j++){
            temp = arr[j];
            arr[j] = arr[a + b - j];
            arr[a + b - j] = temp;
        }
    }
    for(int i = 0; i < n; i++) cout << arr[i] << ' ';
}