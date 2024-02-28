#include <iostream>
#include <queue>
using namespace std;
#define ll long long

short arr[1'000'000];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int t, k;
    ll a, b, sum;
    cin >> t;
    while (t--) {
        cin >> k;
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        for (int i = 0; i < k; i++) {
            cin >> a;
            pq.push(a);
        }
        sum = 0;
        while (pq.size() >= 2) {
            a = pq.top(); pq.pop();
            b = pq.top(); pq.pop();
            sum += a + b;
            pq.push(a + b);
        }
        cout << sum << '\n';
    }

}