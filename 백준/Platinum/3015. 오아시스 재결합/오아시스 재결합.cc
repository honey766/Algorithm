#include <iostream>
#include <algorithm>
using namespace std;

int stk[500'000];
int top;

//a보다 큰 원소 중 idx의 최댓값 반환
int f(int a) {
    int l = 0, r = top, mid;
    while (l < r) {
        mid = (l + r + 1) / 2;
        if (stk[mid] > a) l = mid;
        else r = mid - 1;
    }
    return r;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    //i번째 이하에서 봤을 때, i-1번째를 포함하여 내림차순으로 정렬된 원소의 개수를 볼 수 있다.
    //정렬된 배열에서 두 번째 원소는 i번째 원소보다 같거나 작다.
    //6 4 1 2 2 5 1 3에서 5는, {6, 4, 2, 2}를 볼 수 있다. 3은, {5, 1}을 볼 수 있다. (왼쪽만)
    int n, a, prev;
    long long cnt = 0;
    top = -1;

    cin >> n >> a;
    while (--n) {
        prev = a;
        cin >> a;
        //prev보다 작은 원소 제거
        while (top >= 0 && stk[top] < prev)
            top--;
        stk[++top] = prev;
        cnt += top - f(a) + 1;
    }
    cout << cnt;
}