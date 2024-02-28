#include <iostream>
#include <vector>
#include <cstring>
#include <unordered_set>
using namespace std;

unordered_set<int> s;
vector<int>* pos; //pos[i] : 전기용품 i를 사용하는 인덱스 모임
int* idx; //idx[i] : 현재 전기용품 i는 pos[i] 벡터의 idx[i] 번째까지 봄

//꽂혀 있는 전기용품 중 앞으로 가장 늦게 사용하게 될 용품 반환
int FindMax() {
    int MaxApp, MaxIdx = -1;

    for (auto it = s.begin(); it != s.end(); it++) {
        int cur = *it;
        if (idx[cur] + 1 == pos[cur].size()) {
            //더 이상 해당 전기용품을 사용하지 않는다
            MaxApp = cur;
            break;
        }
        if (MaxIdx < pos[cur][idx[cur] + 1]) {
            MaxIdx = pos[cur][idx[cur] + 1];
            MaxApp = cur;
        }
    }
    return MaxApp;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, k, cnt = 0; //cnt : 플러그 빼는 횟수
    cin >> n >> k;
    int* arr = new int[k];
    pos = new vector<int>[k + 1];
    idx = new int[k + 1];
    memset(idx, -1, (k + 1) * 4);

    for (int i = 0; i < k; i++) {
        cin >> arr[i];
        pos[arr[i]].push_back(i);
    }

    for (int i = 0; i < k; i++) {
        //멀티탭이 꽉 차 있고 코드를 하나 뽑아야 한다면
        bool exist = s.count(arr[i]);
        if (s.size() == n && !exist) {
            //꽂혀 있는 전기용품 중 가장 늦게 사용하게 될 용품을 뽑는다
            s.erase(FindMax());
            cnt++;
        }
        if(!exist) s.insert(arr[i]);
        idx[arr[i]]++;
    }
    cout << cnt;
}