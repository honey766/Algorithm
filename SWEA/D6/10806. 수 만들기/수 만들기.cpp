#include <iostream>
#include <queue>
#include <functional>
using namespace std;

int n, k;
int arr[10];

struct container {
    int cnt;
    int k;
    container(int C, int K) : cnt(C), k(K) {}
    
    bool operator<(const container s) const {
        return this->cnt > s.cnt;
    }
};

//arr = {3, 5, 11}로 k = 63을 만든다고 하자.
//먼저 1을 세 번 더하면 60을 만들면 되며, 이제부터 3 또는 5를 더하면 된다.
//15씩 더한다고 하면 사실상, 처음부터 k = 4를 만드는 문제가 된다. 15의 배수를 더하는 문제이기 때문이다.
//k = 4의 경우, 1 + 3이다.
//이를 종합해 보면 1 + 1 + 1 + 15 + 45가 된다.
//
//c만큼씩 더하고 싶을 때, k를 c로 나눈 나머지만큼 1을 더하고
//남은 부분은 c씩 더하는 형태가 되며, 처음부터 (k - 나머지) / c를 만드는 문제가 된다.
//당장 나머지가 적다고 최적의 해가 보장되지 않기 때문에(3,14로 16 만들기), 모든 arr 원소에 대해 검사한다.
//(나머지)만큼 cnt가 추가되고, 이제 처음부터 (k - 나머지) / c를 만드는 문제를 재귀적으로 푼다. 
//
//pq는 cnt를 기준으로 최소힙이다.
int cal() {
    priority_queue<container> pq;
    pq.push(container(0, k));
    int cnt, k, r;
    while (true) {
        cnt = pq.top().cnt; 
        k = pq.top().k;
        if (k == 0) return cnt;
        pq.pop();
        for (int i = 0; i < n; i++) {
            r = k % arr[i];//1을 r번 더해주고, 남은 수는 arr[i]씩 더함
            pq.push(container(cnt + r, (k - r) / arr[i]));
        }
    }
}

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int test_case;
    int T;

    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> arr[i];
        cin >> k;

        cout << '#' << test_case << ' ';
        cout << cal() << '\n';
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}