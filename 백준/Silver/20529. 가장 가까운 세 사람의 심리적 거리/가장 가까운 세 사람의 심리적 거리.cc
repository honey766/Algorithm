#include <iostream>
#include <unordered_set>
using namespace std;

int dist(string& s1, string& s2){
	int cnt = 0;
	for (int i = 0; i < 4; ++i)
		cnt += (int)(s1[i] != s2[i]);
	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int t, n, Min;
	string s, s1, s2, s3;
	bool end;
	unordered_set<string> sets1, sets2; //해당 MBTI가 각각 1명, 2명 있음
	cin >> t;
	while(t--) {
		sets1.clear(); sets2.clear();
		end = false;
		Min = 100;
		n = 5;
		cin >> n;
		while (n--) {
			cin >> s;
			if (sets2.count(s)) {
				end = true;
			}
			else if (sets1.count(s)) {
				sets2.insert(s);
				sets1.erase(s);
			}
			else {
				sets1.insert(s);
			}
		}
		if (end) {
			cout << "0\n";
			continue;
		}

		for (auto it1 = sets2.begin(); it1 != sets2.end(); it1++) {
			s1 = *it1;
			for (auto it2 = next(it1); it2 != sets2.end(); it2++) {
				s2 = *it2;
				Min = min(Min, 2 * dist(s1, s2));
			}
			for (auto it2 = sets1.begin(); it2 != sets1.end(); it2++) {
				s2 = *it2;
				Min = min(Min, 2 * dist(s1, s2));
			}
		}

		for (auto it1 = sets1.begin(); it1 != sets1.end(); it1++) {
			s1 = *it1;
			for (auto it2 = next(it1); it2 != sets1.end(); it2++) {
				s2 = *it2;
				for (auto it3 = next(it2); it3 != sets1.end(); it3++) {
					s3 = *it3;
					Min = min(Min, dist(s1, s2) + dist(s1, s3) + dist(s2, s3));
				}
			}
		}

		cout << Min << '\n';
	}
}