#include <iostream>
#include <algorithm>
using namespace std;

struct Nilou {
    int count;
    int num;
};

bool comp(const Nilou a, const Nilou b) {
    return a.count < b.count;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, a, sum = 0, median = 0, mode = 0, modeIdx, max = -4000, min = 4000;
    Nilou* count = new Nilou[8001]();
    cin >> n;
    for (int i = 0; i <= 8000; i++) count[i] = Nilou{ 0, 4000 - i }; //역순 저장
    for(int i = 0; i < n; i++) {
        cin >> a;
        sum += a;
        count[4000 - a].count++; 
        max = a > max ? a : max;
        min = a < min ? a : min;
    }
    if (sum >= 0) sum = (int)(((double)sum) / n + 0.5);
    else sum = (int)(((double)sum) / n - 0.5);
    for (int i = 0; i <= 8000; i++) {
        median += count[i].count;
        if (median >= (n + 1) / 2) {
            median = 4000 - i; break;
        }
    }
    stable_sort(count, count + 8001, comp);
    if (count[8000].count == count[7999].count) mode = count[7999].num;
    else mode = count[8000].num;

    cout << sum << '\n';
    cout << median << '\n';
    cout << mode << '\n';
    cout << max - min << '\n';
}