#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    //막대의 높이들을 스택에 넣다가, 스택의 탑보다 높이가 낮은 시점에 넓이를 계산한다
    int i, n, a, Max = -1;
    stack<int> stk; //idx를 넣음
    cin >> n;
    int* arr = new int[n];
    for (i = 0; i < n; i++) {
        cin >> arr[i];
        //스택 안에는 높이가 오름차순으로 정렬되어 있음
        //4 3 9 8 7 순으로 들어오면 스택에는 3 7이 남으며, idx로는 1 4이 남는다.
        //stk.top은 4이며, 높이 7이 유지되는 너비는 이전 idx인 1보다 큰 범위이다
        while (!stk.empty() && arr[stk.top()] > arr[i]) {
            a = stk.top();
            stk.pop();
            if (stk.empty()) //너비는 0 ~ i-1
                Max = max(Max, arr[a] * i);
            else //너비는 stk.top()+1 ~ i-1
                Max = max(Max, arr[a] * (i - stk.top() - 1));
        }
        stk.push(i);
    }
    while (!stk.empty()) {
        a = stk.top();
        stk.pop();
        if (stk.empty()) //너비는 0 ~ n-1
            Max = max(Max, arr[a] * n);
        else //너비는 stk.top()+1 ~ n-1
            Max = max(Max, arr[a] * (n - stk.top() - 1));
    }
    cout << Max;
}