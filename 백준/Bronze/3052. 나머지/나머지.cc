#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int* arr = new int[42]();
    int a;
    int num = 0;
    for(int i = 0; i < 10; i++){
        cin >> a;
        arr[a % 42] = 1;
    }
    for(int i = 0; i < 42; i++){
        num += arr[i];
    }
    cout << num;
}