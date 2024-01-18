#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int k, a, sum = 0;
    stack<int> st;
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> a;
        if (a == 0) st.pop();
        else st.push(a);
    }
    while (!st.empty()) {
        sum += st.top();
        st.pop();
    }
    cout << sum;
}