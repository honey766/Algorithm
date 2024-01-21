#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int tc; cin >> tc;
    int n, a, b, mid, cnt;
    while (tc--) {
        priority_queue<int> max_h; //중앙값보다 작은 수
        priority_queue<int, vector<int>, greater<int>> min_h; //중앙값보다 큰 수

        cin >> n >> mid;
        n /= 2;
        cout << n + 1 << '\n' << mid << ' ';
        cnt = 1;
        //2개씩 묶어서 처리하여 2개를 평균 3 * logn 시간으로 처리
        while (n--) {
            cnt++;
            cin >> a >> b;
            if (mid < a && mid < b) {//mid는 min_h의 최솟값
                max_h.push(mid);
                min_h.push(a);
                min_h.push(b);
                mid = min_h.top();
                min_h.pop();
            }
            else if (a < mid && b < mid) {//mid는 max_h의 최댓값
                min_h.push(mid);
                max_h.push(a);
                max_h.push(b);
                mid = max_h.top();
                max_h.pop();
            }
            else {//mid는 그대로
                if (a < mid) {
                    max_h.push(a);
                    min_h.push(b);
                }
                else {
                    max_h.push(b);
                    min_h.push(a);
                }
            }
            if (cnt % 10 == 1) cout << '\n';
            cout << mid << ' ';
        }
        cout << '\n';
    }
}