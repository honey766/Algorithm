#include <iostream>
#include <cstring>
#define INF 100'000'000
using namespace std;

int S[1000], Slen;
int N[1000], Nlen;
int dp[1000][1000][10]; // i~j까지 합쳐서 n을 만들기 위해 최소로 바꾸는 0의 개수
int Min;

void input()
{
    string s;
    cin >> s;
    Slen = s.length();
    for (int i = 0; i < Slen; i++)
        S[i] = s[i] - '0';
    cin >> s;
    Nlen = s.length();
    for (int i = 0; i < Nlen; i++)
        N[i] = s[i] - '0';

    for (int i = 0; i < Slen; i++)
        for (int j = i; j < Slen; j++)
            for (int k = 0; k < 10; k++)
                dp[i][j][k] = INF;
}

int add(int a, int b)
{
    return (a + b) % 10;
}

void makeDP()
{
    for (int i = 0; i < Slen; i++)
    {
        dp[i][i][S[i]] = 0;
        if (S[i] != 0)
            dp[i][i][0] = 1;
    }

    for (int len = 1; len < Slen; len++)
    {
        for (int i = 0; i < Slen - len; i++)
        {
            for (int j = 0; j < 10; j++)
                dp[i][i + len][j] = dp[i][i + len - 1][j] + 1; // 0으로 바꿀 때
            for (int j = 0; j < 10; j++)
            {
                dp[i][i + len][add(j, S[i + len])] = min(dp[i][i + len][add(j, S[i + len])], dp[i][i + len - 1][j]); // 0으로 바꾸지 않을 때
            }
        }
    }
}

void cal()
{
    int* sol = new int[1000];
    int* sol2 = new int[1000];
    for (int i = 0; i < Slen; i++)
    {
        if (dp[0][i][N[0]] < INF)
            sol[i] = dp[0][i][N[0]];
        else
            sol[i] = INF;
    }

    for (int n = 1; n < Nlen; n++)
    {
        for (int i = 0; i < Slen; i++)
            sol2[i] = INF;
        for (int i = 0; i < Slen; i++)
        {
            if (sol[i] >= INF) continue;
            for (int j = i + 1; j < Slen; j++)
            {
                if (dp[i + 1][j][N[n]] < INF)
                    sol2[j] = min(sol2[j], sol[i] + dp[i + 1][j][N[n]]);
            }
        }
        swap(sol, sol2);
    }

    if (sol[Slen - 1] >= INF) cout << "-1";
    else cout << sol[Slen - 1];
}

void solve()
{
    makeDP();
    cal();
}

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    input();
    solve();
}