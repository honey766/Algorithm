#include <iostream>
using namespace std;
#define f(n) ((n) * ((n) + 1) / 2) //1~n까지 합

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, k;
    cin >> n;
    pair<int, int>* arr = new pair<int, int>[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i].first >> arr[i].second;
    for (int i = 0; i < n; i++) {
        k = 0;
        for (int j = 0; j < n; j++)
            if (arr[i].first < arr[j].first && arr[i].second < arr[j].second)
                k++;
        cout << k + 1 << ' ';
    }
}