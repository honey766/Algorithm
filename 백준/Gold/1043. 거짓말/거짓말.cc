#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	set<int> st;
	int n, m, cnt, a;
	bool check;
	cin >> n >> m >> cnt;
	while (cnt--) {
		cin >> a;
		st.insert(a);
	}
	vector<vector<int>> arr(m, vector<int>());
	for(int i = 0; i < m; i++) {
		cin >> cnt;
		arr[i].resize(cnt);
		while (cnt--)
			cin >> arr[i][cnt];
	}
	//처음 진실을 알고 있는 사람과 같이 있으면 진실을 알게 된다.
	//새로 알게 된 사람과 같이 있으면 진실을 알게 된다.
	//이 걸 파티 수만큼 하면 다 알아낼 수 있다
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			check = false;
			for (int k = 0; k < arr[j].size(); k++)
				if (st.count(arr[j][k])) {
					check = true;
					break;
				}
			if (!check) continue;
			for (int k = 0; k < arr[j].size(); k++)
				st.insert(arr[j][k]);
		}
	}
	cnt = 0;
	for (int i = 0; i < m; i++)
		if (!st.count(arr[i][0]))
			cnt++;
	cout << cnt;
}