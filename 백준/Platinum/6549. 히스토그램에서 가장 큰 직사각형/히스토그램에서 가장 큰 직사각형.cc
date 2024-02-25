#include <iostream>
using namespace std;
#define ll long long

int arr[100'000];

// merge sort랑 유사
ll f(int s, int e) {
    if (s == e) {
        return arr[s];
    }
    int mid = (s + e) / 2;
    ll Max = max(f(s, mid), f(mid + 1, e));

    ll l = mid, r = mid + 1, h = min(arr[mid], arr[mid + 1]);
    Max = max(Max, 2 * h);
    while (s < l && r < e) {
        if (arr[r + 1] > arr[l - 1])
            h = min(h, (ll)arr[++r]);
        else
            h = min(h, (ll)arr[--l]);
        Max = max(Max, h * (r - l + 1));
    }
    while (s < l) {
        h = min(h, (ll)arr[--l]);
        Max = max(Max, h * (r - l + 1));
    }
    while (r < e) {
        h = min(h, (ll)arr[++r]);
        Max = max(Max, h * (r - l + 1));
    }

    return Max;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    while (true) {
        cin >> n;
        if (n == 0) break;
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cout << f(0, n - 1) << '\n';
    }
}