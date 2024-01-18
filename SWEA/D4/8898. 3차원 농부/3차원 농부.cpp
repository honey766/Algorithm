#include <iostream>
#include <algorithm>
using namespace std;
#define DIS(x, y) ((x) > (y) ? (x) - (y) : (y) - (x))

int n, m, c1, c2;
int cow[500000];
int horse[500000];
int cDis;

//거리가 dis보다 작거나 같은 쌍이 있다면 true
bool f(int dis) { //cow와 horse는 정렬됨
    //cDis = DIS(c1, c2);
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (DIS(cow[i], horse[j]) + cDis <= dis) return true; 
        if (cow[i] < horse[j]) i++; //cow와 horse의 격차를 줄이는 방향으로 index 증가
        else j++;
    }
    return false;
}

int minCount(int dis) {
    int i = 0, j = 0, cnt = 0;
    while (i < n && j < m) {
        if (DIS(cow[i], horse[j]) + cDis == dis) cnt++;
        if (cow[i] < horse[j]) i++;
        else j++;
    }
    return cnt;
}

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int test_case;
    int T;

    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {      
        cin >> n >> m >> c1 >> c2;
        for (int i = 0; i < n; i++) cin >> cow[i];
        for (int i = 0; i < m; i++) cin >> horse[i];
        cDis = DIS(c1, c2);
        sort(cow, cow + n);
        sort(horse, horse + m);
        
        int left, right, mid, ans;
        left = 0; right = 400000000;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (f(mid)) { //거리 mid보다 같거나 작은 쌍이 존재한다면
                right = mid - 1; //왼쪽을 본다
                ans = mid;
            }
            else {
                left = mid + 1;
            }
        }
        //ans : 최소 거리
        cout << '#' << test_case << ' ';
        cout << ans << ' ' << minCount(ans) << '\n';
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}