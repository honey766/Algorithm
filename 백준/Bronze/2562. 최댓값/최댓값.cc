#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int a;
    int max = -1;
    int idx = -1;
    for(int i = 1; i <= 9; i++){
        cin >> a;
        if(a > max){
            max = a;
            idx = i;
        }
    }
    cout << max << '\n' << idx;
}