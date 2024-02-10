#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    char c;
    int n, a, tc; 
    cin >> tc;
    while (tc--) {
        //최대힙, 최소힙에 둘 다 넣고 삭제 연산은 둘 중에 하나에서 뺀다
        //최대힙에서 뺀다면, 최소힙에서는 그 원소가 남아있으면 안 된다. 이러한 원소를 mintrash에 담는다
        priority_queue<int> maxpq;
        priority_queue<int> maxtrash;
        priority_queue<int, vector<int>, greater<int>> minpq;
        priority_queue<int, vector<int>, greater<int>> mintrash;
        cin >> n;
        while (n--) {
            cin >> c >> a;
            if (c == 'I') {
                maxpq.push(a); minpq.push(a);
            }
            else if (maxpq.size() + minpq.size() == maxtrash.size() + mintrash.size())
                continue;
            else if(a == 1){
                while (!maxtrash.empty() && maxtrash.top() == maxpq.top()) {
                    maxtrash.pop(); maxpq.pop();
                }
                mintrash.push(maxpq.top());
                maxpq.pop();
            }
            else {
                while (!mintrash.empty() && mintrash.top() == minpq.top()) {
                    mintrash.pop(); minpq.pop();
                }
                maxtrash.push(minpq.top());
                minpq.pop();
            }
        }

        while (!maxtrash.empty() && maxtrash.top() == maxpq.top()) {
            maxtrash.pop(); maxpq.pop();
        }
        while (!mintrash.empty() && mintrash.top() == minpq.top()) {
            mintrash.pop(); minpq.pop();
        }
        if (maxpq.size() + minpq.size() == maxtrash.size() + mintrash.size())
            cout << "EMPTY\n";
        else
            cout << maxpq.top() << ' ' << minpq.top() << '\n';
    }
}