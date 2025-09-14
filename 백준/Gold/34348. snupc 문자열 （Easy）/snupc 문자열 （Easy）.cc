#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string S;
vector<int> idxs[5]; // s,n,u,p,c 순

void init()
{
    for (int i = 0; i < S.length(); i++)
    {
        if (S[i] == 's') idxs[0].push_back(i);
        else if (S[i] == 'n') idxs[1].push_back(i);
        else if (S[i] == 'u') idxs[2].push_back(i);
        else if (S[i] == 'p') idxs[3].push_back(i);
        else idxs[4].push_back(i);
    }
}

// f(k)가 가능하면 true
bool f(int sl, int sr, int k)
{
    int i = sl;
    for (int j = 0; j < 5; j++)
    {
        int idx = lower_bound(idxs[j].begin(), idxs[j].end(), i) - idxs[j].begin();
        if (idxs[j].size() < idx + k) return false;
        i = idxs[j][idx + k - 1];
        if (i > sr) return false;
        i++;
    }
    return true;
}

int solve(int sl, int sr)
{
    int l = 0, r = (sr - sl + 1) / 5;
    int mid;
    while (l < r)
    {
        mid = (l + r + 1) / 2;
        if (f(sl, sr, mid)) l = mid;
        else r = mid - 1;
    }
    return l;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int Q;
    cin >> S >> Q;
    init();
    while (Q--)
    {
        int l, r;
        cin >> l >> r;
        cout << solve(l - 1, r - 1) << '\n';
    }
}