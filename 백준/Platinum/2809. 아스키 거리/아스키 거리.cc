#include <iostream>
#include <algorithm>
using namespace std;

string s;
int* sa, * pos;
int n, d;
bool cmp(int i, int j) {
    if (pos[i] != pos[j]) return pos[i] < pos[j];
    i += d;
    j += d;
    return (i < n && j < n ? pos[i] < pos[j] : i > j);
}

int lowerBound(int i, char c, int left, int right) {
    int l = left, r = right, mid;
    while (l < r) {
        mid = (l + r) / 2;
        int idx = sa[mid]; //사전순으로 mid번째의 접미사의 시작 위치
        //i-1번째 문자까지 같은 애들의 모임이기 때문에, i번째가 없다면 사전순으로 가장 왼쪽임
        //즉 i번째가 없다면 mid == l임
        if (idx + i >= n)
            l++;
        else if (s[idx + i] >= c)
            r = mid;
        else
            l = mid + 1;
    }
    if (s[sa[r] + i] != c) return -1;
    return r;
}

int upperBound(int i, char c, int left, int right) {
    int l = left, r = right, mid;
    while (l < r) {
        mid = (l + r + 1) / 2;
        int idx = sa[mid];
        //mid + i >= n이라면 mid가 l이겠지만, mid는 원소가 2개 남았을 때 오른쪽을 고르므로 mid > l이다
        if (s[idx + i] <= c)
            l = mid;
        else
            r = mid - 1;
    }
    if (sa[r] + i >= n || s[sa[r] + i] != c) return -1;
    return r;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> n >> s;
    sa = new int[n];
    pos = new int[n];
    int* lcp = new int[n];
    int* line = new int[n];
    bool* put = new bool[n]();
    //접미사 배열
    for (int i = 0; i < n; i++) {
        sa[i] = i;
        pos[i] = s[i];
    }
    for (d = 1; ; d <<= 1) {
        sort(sa, sa + n, cmp);
        lcp[0] = 0; //tmp 역할로 lcp 사용(메모리 절약)
        for (int i = 1; i < n; i++)
            lcp[i] = lcp[i - 1] + cmp(sa[i - 1], sa[i]);
        for (int i = 0; i < n; i++)
            pos[sa[i]] = lcp[i];
        if (lcp[n - 1] == n - 1) break;
    }
    //LCP 배열
    int k = 0;
    for (int i = 0; i < n; i++) {
        int idx = pos[i];
        if (idx == n - 1)continue;

        int j = sa[idx + 1];
        while (i + k < n && j + k < n) {
            if (s[i + k] != s[j + k]) break;
            k++;
        }

        lcp[idx] = k;
        k = max(k - 1, 0);
    }

    //문제풀이
    int cnt, m, l, r;
    string s2;
    cin >> cnt;
    line[0] = -1;
    while (cnt--) {
        cin >> s2;
        m = s2.size();
        l = 0; r = n - 1;
        //접미사 배열에서 bac를 찾는다고 하면 처음 문자가 'b'인 lower,upper_bound를 찾는다
        //2개의 bound를 left, right로 잡고, 이 안에서 두 번째 문자가 'a'인 l,r을 찾는다(첫번째 문자가 'b'라는 것이 보장됨)
        //'c'까지 봤을 때 right-left+1개의 접미사에서 채울 수 있다
        //시간복잡도는 O(log(300000) * 2 * 5000)
        for (int i = 0; i < m; i++) {
            int l1 = lowerBound(i, s2[i], l, r); //i번째 문자가 s2[i]인 lower_bound를 l~r 범위에서 찾기
            int r1 = upperBound(i, s2[i], l, r);
            l = l1; r = r1;
            if (l1 == -1) break;
        }
        
        if (l == -1) continue;
        //sa[i]부터 오른쪽으로 sa[i]+m-1까지 선을 긋는다. 원래 그어진 최댓값과 비교한다.
        //sa[i]번째부터 sa[i]+m-1까지의 박스를 칠한다고 생각하면 칠해지는 박스의 개수는 m개
        for (int i = l; i <= r; i++)
            line[sa[i]] = max(line[sa[i]], sa[i] + m - 1);
    }
    cnt++;
    l = 0; r = -1;
    //line[i]의 값이 i보다 작으면 해당 line은 없다는 뜻이다.
    //수직선에 그어진 선의 길이의 총합을 구한다
    //스위핑 알고리즘 참고함
    for (int i = 0; i < n; i++) {
        if (line[i] < i) continue;
        if (i <= r) r = max(r, line[i]);
        else {
            cnt += r - l + 1;
            l = i;
            r = line[i];
        }
    }
    cnt += r - l + 1;
    cout << n - cnt;
}