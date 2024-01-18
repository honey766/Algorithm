#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MIN(x, y) ((x) > (y) ? (y) : (x))

//a, b를 바꾸는 김에 무게까지 더함
void Swap(int& a, int& b, int& sum) {
	int temp = a;
	a = b;
	b = temp;
	sum += a + b;
}

//sequenceArr[i] == j : i번째로 작은 원소는 arr[j]이다.(j번째에 위치해 있다)
//arr : 1 5 6 4이면,
//sequenceArr : 0 3 1 2
void findSequence(int* arr, long long int* arrSort, int* sequenceArr, int n) {
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
	long long int* arrSort = new long long int[n];//정렬된 arr
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

	//각자의 길이 n인 사이클 내에서 n-1번 Swap하면 된다.
	//이 때, 사이클 내의 최소 원소인 b에 대해 b를 최대한 활용해 준다.
	//오름차순으로 값이 bcde이면 Swap은 (b,c), (b,d), (b,e)일 때 최소이다.
	//사이클 내에 없는 값(arrSort[0])을 불러오는 것이 최소일 수가 있다.
	//이 경우에는 Swap은 (a,b), (a,c), (a,d), (a,e), (a,b)가 된다.
	//사이클 내에서 가장 작은 값이 b였으므로, b를 a로 바꿔도 논리적으로 바뀌지 않는다.
	for (vector<int> v : vec) {
		long long int len = v.size();
		int MinIdx = v[0];
		for (int a : v) MinIdx = MIN(MinIdx, a);//MinIdx : 최소 원소의 idx
		//이 조건 하에서는 최소 원소를 가져오는 것이 이득임
		if ((len + 1) * arrSort[0] < (len - 3) * arrSort[MinIdx]) 
			Swap(arr[0], arr[sequenceArr[MinIdx]], sum);
		//arrSort[MinIdx]가 v 내에서 최소인 원소이고, 
		//이 원소는 arr 배열 상에서 sequenceArr[MinIdx]에 위치해 있다. 

		j = sequenceArr[MinIdx];
		for (i = 0; i < len - 1; i++) {
			k = sequenceArr[j]; //j번째에 가야 할 애가 k에 있음
			Swap(arr[j], arr[k], sum);
			j = k;
		}

		if ((len + 1) * arrSort[0] < (len - 3) * arrSort[MinIdx]) //마지막으로 다시 Swap
			Swap(arr[0], arr[MinIdx], sum); //이제는 sequenceArr[MinIdx]가 아닌, MinIdx와 바꾸면 된다.
		//최소 원소(arrSort[0])를 가져오는 것은 for을 감싸는 if문 2번이다. 
		//두 번 더 Swap하고 이를 더해도 이득인 경우가 if(조건문)이다.
	}
	//arrSort가 long long int*인 이유는 (len + 1)을 곱할 때 오버플로우 가능성이 있기 때문

	cout << sum;
}