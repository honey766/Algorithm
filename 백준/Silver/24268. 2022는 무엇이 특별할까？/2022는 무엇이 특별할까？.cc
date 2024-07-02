#include <iostream>
using namespace std;

bool digit[9];
int n, ans, d;

void check(int t, int curNum, int dig){
    if(t == d){
        if(n < curNum)
            ans = (ans != -1 && ans < curNum) ? ans : curNum;
        return;
    }
    for(int i = 0; i < d; i++){
        if(digit[i] || (t == d - 1 && i == 0)) continue;
        digit[i] = true;
        check(t + 1, curNum + i * dig, dig * d);
        digit[i] = false;
    }
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> d;
    
    ans = -1;
    check(0, 0, 1);
    cout << ans;
}