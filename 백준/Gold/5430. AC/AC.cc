#include <iostream>
#include <deque>
using namespace std;

void init(deque<int>& deq, string s) {
    deq.clear();
    int i = 0, n;
    while (s[i] != ']') {
        ++i;
        n = 0;
        while (s[i] != ',' && s[i] != ']') {
            n *= 10;
            n += s[i++] - '0';
        }
        if(n != 0) deq.push_back(n);
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int tc, a; cin >> tc;
    bool rev, error;
    string s1, s2;
    deque<int> deq;
    while (tc--) {
        cin >> s1 >> a >> s2;
        rev = error = false;
        init(deq, s2);
        for (char c : s1) {
            if (c == 'R') 
                rev = !rev;
            else if (deq.empty()) {
                error = true;
                break;
            }
            else if (rev) 
                deq.pop_back();
            else 
                deq.pop_front();
        }
        if (error) {
            cout << "error\n";
            continue;
        }

        //출력
        cout << '[';
        while (!deq.empty()) {
            if (rev) {
                cout << deq.back();
                deq.pop_back();
            }
            else {
                cout << deq.front();
                deq.pop_front();
            }
            if (!deq.empty()) 
                cout << ',';
        }
        cout << "]\n";
    }
}