#include <iostream>
#include <algorithm>
using namespace std;

struct coordinate {
    int x;
    int y;
};

bool incr(coordinate a, coordinate b) {
    if (a.x == b.x) return a.y < b.y;
    else return a.x < b.x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x, y;
    cin >> n;
    coordinate *a = new coordinate[n];
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        a[i].x = x; a[i].y = y;
    }
    sort(a, a + n, incr);
    for (int i = 0; i < n; i++) cout << a[i].x << ' ' << a[i].y << '\n';
}