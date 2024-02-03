#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    short arr[8];
    bool ascend, descend;
    ascend = descend = true;
    for (int i = 0; i < 8; i++)
        cin >> arr[i];
    for (int i = 0; i < 7; i++) 
        if (arr[i] > arr[i + 1]) ascend = false;
        else descend = false;
    if (!ascend && !descend) cout << "mixed";
    else if (ascend) cout << "ascending";
    else cout << "descending";
}