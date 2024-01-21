#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, a;
    priority_queue<int> maxh; //중간값보다 작은 수
    priority_queue<int, vector<int>, greater<int>> minh; //중간값보다 큰 수

    cin >> n >> a;
    //중간값이 2개라면 작은 수를 말해야 하므로, maxh.size() >= minh.size()로 해서 
    //중간값이 maxh.top()이 되도록 한다
    maxh.push(a);
    cout << maxh.top() << '\n';;
    while (--n) {
        cin >> a;
        //두 힙 사이즈의 균형을 맞춤
        if (minh.size() < maxh.size()) minh.push(a);
        else maxh.push(a);
        //이전까지 힙의 정의를 만족했다는 가정 하에서, 정의를 만족하지 못할 때 하나씩만 바꾸면 된다
        if (maxh.top() > minh.top()) {
            maxh.push(minh.top()); minh.pop();
            minh.push(maxh.top()); maxh.pop();
        }
        cout << maxh.top() << '\n';
    }
}