#include <iostream>
#include <vector>
using namespace std;
#define vs vector<short>

vs program[100];
short pi1[1000], pi2[1000];
int k;

void swap(vs& vec1, vs& vec2) {
	vs tmpVec = vec1;
	vec1 = vec2;
	vec2 = tmpVec;
}

void makePi(short* s1, short* s2) {
	int i, j1, j2;
	j1 = j2 = pi1[0] = pi2[0] = 0;
	for (i = 1; i < k; i++) {
		while (j1 > 0 && s1[i] != s1[j1])
			j1 = pi1[j1 - 1];
		while (j2 > 0 && s2[i] != s2[j2])
			j2 = pi2[j2 - 1];
		if (s1[i] == s1[j1])
			pi1[i] = j1;
		else
			pi1[i] = 0;
		if (s2[i] == s2[j2])
			pi2[i] = j2;
		else
			pi2[i] = 0;
	}
}

//s에 pattern이 있는지
bool kmpCheck(short* pattern1, short* pattern2, vs& s) {
	int n = s.size();
	int j1 = 0, j2 = 0;
	for (int i = 0; i < n; i++) {
		while (j1 > 0 && pattern1[j1] != s[i])
			j1 = pi1[j1 - 1];
		while (j2 > 0 && pattern2[j2] != s[i])
			j2 = pi2[j2 - 1];
		if (pattern1[j1] == s[i])
			if (++j1 == k)
				return true;
		if (pattern2[j2] == s[i])
			if (++j2 == k)
				return true;
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n, a, MinIdx, Min = 10000;
	cin >> n >> k;
	short pattern[1000], pattern2[1000];
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a < Min) {
			Min = a;
			MinIdx = i;
		}
		program[i].resize(a);
		for (int j = 0; j < a; j++)
			cin >> program[i][j];
	}
	if (Min < k) {
		cout << "NO"; return 0;
	}

	//program[0]의 길이가 가장 짧음
	swap(program[0], program[MinIdx]);

	bool check;
	//k+1개의 코드가 겹친다면 k개의 코드도 겹친다. k개일 때만 확인한다
	for (int j = 0; j <= Min - k; j++) { //program[j~j+k-1]의 코드가 겹치는지
		check = true;
		for (int l = 0; l < k; l++) //패턴 생성
			pattern[l] = program[0][j + l];
		for (int l = 0; l < k; l++) //반대 패턴 생성
			pattern2[k - l - 1] = program[0][j + l];
		makePi(pattern, pattern2);

		for (int i = 1; i < n; i++)//1~n-1번가지의 프로그램에 해당 코드가 있는지
			if (!kmpCheck(pattern, pattern2, program[i])) {
				check = false;
				break;
			}
		if (check)
			break;
	}
	if (check) cout << "YES";
	else cout << "NO";
}