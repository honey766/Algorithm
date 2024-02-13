#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <algorithm>
#include <functional>
#include <map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    //freopen("1245.txt", "r", stdin);

    int n, k, a;
    long long sum = 0;
    cin >> n >> k;
    pair<int, int>* vm = new pair<int, int>[n];
    map<int, int> c;
    for (int i = 0; i < n; ++i)
        cin >> vm[i].second >> vm[i].first;
    for (int i = 0; i < k; ++i) {
        cin >> a;
        if (c.count(a)) ++c[a];
        c.emplace(a, 1);
    }

    //가치 기준 내림차순 정렬
    sort(vm, vm + n, greater<pair<int, int>>());

    for (int i = 0; !c.empty() && i < n; ++i) {
        auto it = c.lower_bound(vm[i].second);
        if (it == c.end()) continue;
        int m = (*it).first;
        if (c[m] == 1) c.erase(m);
        else --c[m];
        sum += vm[i].first;
    }
    cout << sum;
}