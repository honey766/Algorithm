#include <iostream>
#include <vector>
using namespace std;
#define pr pair<int, int>

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

// with input p, adjust the content of rowMax[3]
void adjustRowMax(pr* rowMax, pr p){
	if(rowMax[0] < p){
		rowMax[2] = rowMax[1];
		rowMax[1] = rowMax[0];
		rowMax[0] = p;
	}
	else if(rowMax[1] < p){
		rowMax[2] = rowMax[1];
		rowMax[1] = p;
	}
	else if(rowMax[2] < p){
		rowMax[2] = p;
	}
}

// swap the candy a[i][j] and a[i][j+1], and count the max number of candy
int swapAndCountMax(char** a, char** aT, pr* rowMax, pr* colMax, int i, int j){
	if(a[i][j] == a[i][j+1]) return 1; // can't change

	swap(a[i][j], a[i][j+1]);
	swap(aT[j][i], aT[j+1][i]);

	// ith row, jth column, (j+1)th column has changed
	int c1 = countRowMax(a, i);
	int c2 = countRowMax(aT, j);
	int c3 = countRowMax(aT, j+1);
	int maxCount = max(max(c1, c2), c3);
	for(int k = 0; k < 3; k++){
		if(rowMax[k].second != i)
			maxCount = max(maxCount, rowMax[k].first);
		if(colMax[k].second != j && colMax[k].second != j+1)
			maxCount = max(maxCount, colMax[k].first);
	}

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

	// preprocessing
	pr rowMax[3], colMax[3]; // (candyNum, index), rowMax[i] = (i+1)th largest number of candy row (if not changed the candy)
	for(int i = 0; i < 3; i++)
		rowMax[i] = colMax[i] = {-1, -1};
	for(int i = 0; i < n; i++){
		// horizontal
		int count = countRowMax(a, i);
		adjustRowMax(rowMax, {count, i});
		// vertical
		count = countRowMax(aT, i);
		adjustRowMax(colMax, {count, i});
	}

	// count the max number of candy
	int maxCount = 1;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n-1; j++){
			// horizontal
			maxCount = max(maxCount, swapAndCountMax(a, aT, rowMax, colMax, i, j));
			// vertical
			maxCount = max(maxCount, swapAndCountMax(aT, a, colMax, rowMax, i, j));
		}
	}
	cout << maxCount;
}