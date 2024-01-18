#include <iostream>
using namespace std;

int main()
{
    int n;
    int* a;
    int c;
    int num = 0;
    cin >> n;
    a = new int[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    cin >> c;
    for(int i=0; i<n; i++){
        if(a[i] == c)
            num++;
    }
    cout << num;  
}