#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    //0~i번째까지 합을 m으로 나눈 나머지를 구한다
    //나머지가 같은 애들끼리 빼면 m으로 나누어 떨어진다
    //sum[6] % m == x, sum[3] % m == x라면 arr[4~6]을 더하면 m의 배수이다
    //나머지가 같은 구간합이 4개라면, 나머지 != 0일 때 1+2+3개의 쌍이 나온다
    int n, m, a, sum = 0;
    long long cnt;
    cin >> n >> m;
    int* hash = new int[m]();
    while (n--) {
        cin >> a;
        sum = (sum + a) % m;
        hash[sum]++; //나머지가 sum인 구간합의 개수
    }
    cnt = (long long)hash[0] * (hash[0] + 1) / 2;
    for (int i = 1; i < m; i++)
        cnt += (long long)hash[i] * (hash[i] - 1) / 2;
    cout << cnt;
}