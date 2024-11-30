#include <iostream>
#include <vector>
using namespace std;

int n;

// swap the char a and b
void swap(char& a, char& b){
	char temp = a;
	a = b;
	b = temp;
}

// count the max number of candy in row i 
int countRowMax(char** a, int i){
	int count = 1, maxCount = 1;
	for(int j = 1; j < n; j++){
		if(a[i][j] == a[i][j-1]) maxCount = max(maxCount, ++count);
		else count = 1;
	}
	return maxCount;
}

// swap the candy a[i][j] and a[i][j+1], and count the max number of candy
int swapAndCountMax(char** a, char** aT, int i, int j){
	if(a[i][j] == a[i][j+1]) return 1; // can't change

	swap(a[i][j], a[i][j+1]);
	swap(aT[j][i], aT[j+1][i]);

	// ith row, jth column, (j+1)th column has changed
	int c1 = countRowMax(a, i);
	int c2 = countRowMax(aT, j);
	int c3 = countRowMax(aT, j+1);
	int maxCount = max(max(c1, c2), c3);

	swap(a[i][j], a[i][j+1]);
	swap(aT[j][i], aT[j+1][i]);
	
	return maxCount;
}

int main() {
	cin >> n;
	char** a = new char* [n];
	char** aT = new char* [n]; //a^T, matrix a transpose
	for (int i = 0; i < n; i++) {
		a[i] = new char[n];
		aT[i] = new char[n];
	}
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++) {
			a[i][j] = s[j];
			aT[j][i] = s[j];
		}
	}

	int maxCount = 1;
	for(int i = 0; i < n; i++){		
		maxCount = max(maxCount, countRowMax(a, i)); // horizontal		
		maxCount = max(maxCount, countRowMax(aT, i)); // vertical
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n-1; j++){			
			maxCount = max(maxCount, swapAndCountMax(a, aT, i, j)); // horizontal
			maxCount = max(maxCount, swapAndCountMax(aT, a, i, j)); // vertical
		}
	}
	cout << maxCount;
}