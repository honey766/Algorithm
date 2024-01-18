#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MIN(x, y) ((x) > (y) ? (y) : (x))

//바꾸는 김에 무게까지 더함
void Swap(int& a, int& b, int& sum) {
	int temp = a;
	a = b;
	b = temp;
	sum += a + b;
}

//sequenceArr[i] == j : i번째로 작은 원소는 arr[j]이다.
void findSequence(int* arr, int* arrSort, int* sequenceArr, int n) {
	int j;
	for (int i = 0; i < n; i++) {
		j = -1;
		while (arr[++j] != arrSort[i]);
		sequenceArr[i] = j;
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int i, j, k, n, sum = 0; cin >> n;
	int* arr = new int[n];
	int* arrSort = new int[n];
	int* sequenceArr = new int[n];
	for (i = 0; i < n; i++) {
		cin >> arr[i]; arrSort[i] = arr[i];
	}
	sort(arrSort, arrSort + n);
	findSequence(arr, arrSort, sequenceArr, n);

	//순환 사이클 분할
	bool* check = new bool[n]();
	vector<vector<int>> vec;
	for (int i = 0; i < n; i++) {
		if (check[i]) continue;
		int t = sequenceArr[i];
		vector<int> tmp;
		tmp.push_back(i);
		check[i] = true;
		while (t != i) {
			tmp.push_back(t);
			check[t] = true;
			t = sequenceArr[t];
		}
		vec.push_back(tmp);
	}//분할 완료

	for (vector<int> v : vec) {
		int len = v.size();
		int MinIdx = v[0];
		for (int a : v) MinIdx = MIN(MinIdx, a);//Min : 최소 원소의 idx
		if ((len + 1) * arrSort[0] < (len - 3) * arrSort[MinIdx]) //이러면 최소 원소를 가져오는 것이 이득임
			Swap(arr[0], arr[sequenceArr[MinIdx]], sum);
		//MinIdx가 v 내에서 최소인 원소는 맞지만, sequenceArr[MinIdx]에 위치해 있다. 

		j = sequenceArr[MinIdx];
		for (i = 0; i < len - 1; i++) {
			k = sequenceArr[j]; //j번째에 가야 할 애가 k에 있음
			Swap(arr[j], arr[k], sum);
			j = k;
		}

		if ((len + 1) * arrSort[0] < (len - 3) * arrSort[MinIdx]) //마지막으로 다시 Swap
			Swap(arr[0], arr[MinIdx], sum); //이제는 sequenceArr[MinIdx]가 아닌, MinIdx와 바꾸면 된다.
		//최소 원소를 가져오는 것은 for을 감싸는 if문 2번이다. 
		//두 번 더 Swap하고 이를 더해도 이득인 경우가 if()이다.
	}

	cout << sum;
}