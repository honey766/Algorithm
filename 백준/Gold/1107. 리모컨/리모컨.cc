#include <iostream>
#include <algorithm>
using namespace std;
#define DIF(x, y) ((x) > (y) ? (x) - (y) : (y) - (x))

int target, k, * use, curNum;

int pow(int n) {
    int a = 1;
    while (--n) a *= 10;
    return a;
}

int f(int n) {
    if (n == 0) return DIF(target, curNum);
    int Min = 500000;
    for (int i = 0; i < k; ++i) {
        curNum += use[i] * pow(n);
        Min = min(Min, f(n - 1));
        curNum -= use[i] * pow(n);
    }
    return Min;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, j, Min;
    cin >> target >> n;
    int* ban = new int[n];
    for (int i = 0; i < n; ++i)
        cin >> ban[i];
    sort(ban, ban + n);
    use = new int[10 - n];
    j = k = 0;
    for (int i = 0; i < 10; ++i)
        if (j < n && i == ban[j]) ++j;
        else use[k++] = i;

    curNum = 0;
    Min = 500000;
    if(n != 10)
        for (int i = 1; i <= 6; ++i) 
            Min = min(Min, f(i) + i);
    Min = min(Min, DIF(target, 100));
    cout << Min;
}