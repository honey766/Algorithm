#include <iostream>
using namespace std;
#define N 1'000'000'007

int pows[100'000];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int tc, hCnt, questCnt;
	pows[0] = 1;
	for (int i = 1; i < 100'000; i++)
		pows[i] = (pows[i - 1] * 2) % N;

	string s;
	cin >> tc;
	while (tc--) {
        // ?는 제외하고 T와 H에서, H가 홀수개면 가능하다
		hCnt = questCnt = 0;
		cin >> s;
        //H가 홀수면 ?에서 짝수개를 H로 바꾼다. H가 짝수면 홀수개를 H로 바꾼다
		//nC0 + ... + nCn == nC1 + ... + nCn-1 == 2^(n-1)
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'H') hCnt++;
			else if (s[i] == '?') questCnt++;
		}
		if (questCnt > 0) cout << pows[questCnt - 1];
		else if (hCnt % 2) cout << 1;
		else cout << 0;
		cout << '\n';
	}
}