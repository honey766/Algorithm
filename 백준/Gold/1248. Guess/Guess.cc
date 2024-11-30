#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> arr;
vector<string> matrix;

void p(int i){
    for(int j = 0; j <= i; j++)
        cout << arr[j] << ' ';
    cout << '\n';
}

bool guess(int i){
	if(i >= n)
		return true;
	if(matrix[i][i] == '0'){
		arr[i] = 0;
		return guess(i + 1);
	}

	int sign = 1, sum;
	bool accept;
	if(matrix[i][i] == '-') sign = -1;
	for(int j = 1; j <= 10; j++){
		sum = arr[i] = j * sign;
		accept = true;
		for(int k = i - 1; k >= 0; k--){
			sum += arr[k];
			if((matrix[k][i] == '+' && sum <= 0) || (matrix[k][i] == '-' && sum >= 0) ||
				(matrix[k][i] == '0' && sum != 0)){
				accept = false;
				break;
			}
		}
		if(accept && guess(i + 1))
			return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	int cnt = -1;
	string s;
	cin >> n >> s;
	arr.resize(n);
	matrix = vector<string>(n, string(n, 0));
	for(int i = 0; i < n; i++)
		for(int j = i; j < n; j++)
			matrix[i][j] = s[++cnt];
	guess(0);
	for(int i = 0; i < n; i++)
		cout << arr[i] << ' ';
}