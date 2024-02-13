#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    vector<int> vec;
    int n;
    long long cnt = 0;
    cin >> n;
    int** a = new int*[n];
    for (int i = 0; i < n; ++i) {
        a[i] = new int[4];
        cin >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3];
    }

    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < n; ++j) 
            vec.push_back(a[i][0] + a[j][1]);
    sort(vec.begin(), vec.end());
    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < n; ++j) 
            cnt += upper_bound(vec.begin(), vec.end(), -a[i][2] - a[j][3]) -
                lower_bound(vec.begin(), vec.end(), -a[i][2] - a[j][3]);
    cout << cnt;
}