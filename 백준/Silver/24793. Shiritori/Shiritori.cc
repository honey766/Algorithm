#include <iostream>
#include <set>
using namespace std;

enum Result {ONELOST, TWOLOST};
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	set<string> sets;
	string prev, next;
	int n, result = -1; 
	cin >> n >> next;
	sets.insert(next);

	for(int i = 1; i < n; i++) {
		prev = next;
		cin >> next;
		if (result >= 0) continue;
		if (prev[prev.size() - 1] != next[0] || sets.count(next))
			result = (i % 2 == 0) ? ONELOST : TWOLOST;
		sets.insert(next);
	}

	if (result == -1) cout << "Fair Game";
	else if (result == ONELOST) cout << "Player 1 lost";
	else cout << "Player 2 lost";
}