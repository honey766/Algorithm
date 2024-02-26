#include <iostream>
using namespace std;
#define f(x) (((x % sosu) + sosu) % sosu)
#define ll long long

const ll pows = 2;
const ll sosu = 100'000'009;

char map[2000][2000];
ll mul[2000][2000];
ll hashs[2001][2001];
ll target;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
    int tc;
    cin >> tc;
	int hp, wp, hm, wm, cnt;
	ll ha;
	string s;
    for(int T = 1; T <= tc; T++){
    cnt = 0;
	cin >> hp >> wp >> hm >> wm;
	target = 0; mul[0][0] = 1;

	for (int i = 0; i < hm; i++) {
		if(i != 0) mul[i][0] = f(mul[i - 1][wm - 1] * pows);
		for (int j = 1; j < wm; j++) {
			mul[i][j] = f(mul[i][j - 1] * pows);
		}
	}

	for (int i = 0; i < hm; i++) {
		for (int j = 0; j < wm; j++) {
			//cout << mul[i][j] << ' ';
		}
		//cout << '\n';
	}

	//타겟이 되는 그림의 해쉬값 구하기
	for (int i = 0; i < hp; i++) {
		cin >> s;
		for (int j = 0; j < wp; j++) {
			target = f(target + (s[j] == 'o') * mul[i][j]);
		}
	}
	//cout << "target : " << target << '\n';

	//걸작 입력받기
	for (int i = 0; i < hm; i++) {
		cin >> s;
		for (int j = 0; j < wm; j++) {
			map[i][j] = s[j];
		}
	}

	//해쉬값 채우기
	for (int i = 1; i <= hm; i++) {
		for (int j = 1; j <= wm; j++) {
			hashs[i][j] = (map[i - 1][j - 1] == 'o') * mul[i - 1][j - 1] + hashs[i - 1][j] + hashs[i][j - 1] - hashs[i - 1][j - 1];
			hashs[i][j] = f(hashs[i][j]);
			//cout << hashs[i][j] << '(' << s[j] << ')' << ' ';
			//cout << hashs[i][j] << ' ';
		}
		//cout << '\n';
	}

	//해쉬값을 target과 비교하기
	for (int i = 0; i <= hm - hp; i++) {
		for (int j = 0; j <= wm - wp; j++) {
			ha = hashs[i + hp][j + wp] - hashs[i][j + wp] - hashs[i + hp][j] + hashs[i][j];
			ha = f(ha);
			//cout << ha << ' ';
			if (ha == f(target * mul[i][j]))
				cnt++;
		}
		//cout << '\n';
	}
        cout << '#' << T << ' ';
	cout << cnt << '\n';
    }
}