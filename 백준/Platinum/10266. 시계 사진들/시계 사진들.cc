#include <iostream>
#include <algorithm>
using namespace std;
#define f(x) (((x) + 360000) % 360000)

int n;
int pi[200'000];

void change(int* arr) {
	int prev, cur;
	prev = arr[0];
	arr[0] = f(arr[0] - arr[n - 1]);
	for (int i = 1; i < n; i++) {
		cur = arr[i];
		arr[i] = f(arr[i] - prev);
		prev = cur;
	}
}

int kmps(int* pattern, int* text) {
	int j;
	j = pi[0] = 0;
	for (int i = 1; i < n; i++) {
		while (j > 0 && pattern[j] != pattern[i])
			j = pi[j - 1];
		if (pattern[j] == pattern[i])
			pi[i] = ++j;
		else
			pi[i] = 0;
	}
	j = 0;
	for (int i = 0; i < n; i++) {
		while (j > 0 && pattern[j] != text[i])
			j = pi[j - 1];
		if (pattern[j] == text[i])
			++j;
	}
	return j;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n;
	int* arr1 = new int[n];
	int* arr2 = new int[n];
	for (int i = 0; i < n; i++) cin >> arr1[i];
	for (int i = 0; i < n; i++) cin >> arr2[i];
	sort(arr1, arr1 + n);
	sort(arr2, arr2 + n);
	//각도 순으로 다 정렬하고, 두 인접한 바늘 사이의 각도로 바꿈
	//360도 기준, 30-150-80-100과 150-80-100-30은 같음
	//즉 abcd, bcda, cdab, dabc끼리 같음
	//두 문자열 abcd, bcda에서 한 쪽의 접미사와 다른 한 쪽의 접두사는 겹침(bcd와 a)
	//이 겹치는 길이를 2개 더하면 전체 길이인 4가 나옴
	//aabbaaa와 aaabbaa는 겹치는 길이가 7이 넘는다

	change(arr1);
	change(arr2); //각도로 바꿈

	if (kmps(arr1, arr2) + kmps(arr2, arr1) >= n)
		cout << "possible";
	else
		cout << "impossible";
}