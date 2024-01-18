#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int prev, cur, count, quit;
    while (true) {
        cin >> cur;
        count = quit = 0;
        for (int i = 0; i < 3; i++) {
            prev = cur;
            cin >> cur;
            if (prev == 0 && cur == 0) quit++;
            if (i % 2)
                count += (cur - prev + 40) % 40;
            else 
                count += (prev - cur + 40) % 40;
        }
        if (quit == 3) break;
        cout << count * 9 + 1080 << '\n';
    }
}