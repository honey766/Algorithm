#include <iostream>
using namespace std;

int n, p;
int a[200000];

//a[i] ~ a[j] 사이의 일수를 채운다면, 채워야 하는 일수는 a[j] - a[i] - (j - i)이다.(i < j)
//a[j] - a[i] - (j - i) <= p일 때 채울 수 있으며, 이 때 연속되는 일수는 (j - i) + 1 + p이다.(p는 상수)
//(a[j] - a[i]) < (a[j+1] - a[i]), (a[j] - a[i-1])이다.
//j와 i의 격차가 커진다면, 채워야 하는 일수는 같거나 커진다.
//이는, p < a[j+1] - a[i] - (j+1 - i)일 수도 있다는 것이다.
//그러므로, 연속되는 일수가 mid일 때 (j - i) = mid - p - 1에 대해서 검사한다.
//left = p+1, right = p+n이므로 0 <= (j - i) <= n-1이 보장된다.
bool f(int mid) { 
    int diff = mid - p - 1; //diff == j - i
    for (int i = 0; i < n - diff; i++)
        if (a[i + diff] - a[i] - diff <= p)
            return true;
    return false;
}

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int test_case;
    int T;

    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {          
        cin >> n >> p;
        for (int i = 0; i < n; i++) cin >> a[i];

        int left, right, mid, ans;
        left = 1 + p; right = n + p;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (f(mid)) { //연속 기간이 mid가 가능하다면
                left = mid + 1; //오른쪽을 본다
                ans = mid;
            }
            else {
                right = mid - 1;
            }
        }
        //ans : 최소 거리
        cout << '#' << test_case << ' ';
        cout << ans << '\n';
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}