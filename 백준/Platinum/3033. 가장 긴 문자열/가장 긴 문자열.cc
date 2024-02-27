#include <iostream>
#include <algorithm>
using namespace std;
//https://blog.naver.com/kks227/221028710658

int* sa, * pos;
int d, m;
bool cmp(int i, int j) {
    if(pos[i] != pos[j])
        return pos[i] < pos[j];
    i += d;
    j += d;
    return (i < m && j < m ? pos[i] < pos[j] : i > j);
}

//접미사 배열과 LCP 배열 이용
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    string s;
    cin >> m >> s;
    int Max = 0;
    int* temp = new int[m];
    int* lcp = new int[m]();
    sa = new int[m];
    pos = new int[m];
    for (int i = 0; i < m; i++) {
        sa[i] = i; //사전순으로 i번째인 접미사의 시작 위치
        pos[i] = s[i]; //시작 위치가 i인 접미사의 사전순서
    }
    for (d = 1; ; d <<= 1) {
        sort(sa, sa + m, cmp);
        temp[0] = 0;
        for (int i = 1; i < m; i++)
            temp[i] = temp[i - 1] + cmp(sa[i - 1], sa[i]);
        for (int i = 0; i < m; i++)
            pos[sa[i]] = temp[i];
        if (temp[m - 1] == m - 1) 
            break;
    }

    //lcp배열
    int k = 0;
    for (int i = 0; i < m; i++) {
        int idx = pos[i];
        if (idx == m - 1) continue;

        int j = sa[idx + 1];
        while (i + k < m && j + k < m) {
            if (s[i + k] != s[j + k]) break;
            k++;
        }

        Max = max(Max, k);
        k = max(k - 1, 0);
    }
    cout << Max;
}