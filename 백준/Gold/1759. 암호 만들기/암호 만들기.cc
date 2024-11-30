#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

char* crypt, *arr;
int vowels, consonants, l, c;

bool isVowels(char ch){
    return (ch == 'a') || (ch == 'e') || (ch == 'i') || (ch == 'o') || (ch == 'u');
}

void dfs(int i, int cnt){
    if(cnt >= l){
        if(vowels >= 1 && consonants >= 2)
            cout << crypt << '\n';
        return;
    }
    for(int j = i; j < c - (l - cnt - 1); j++){
        crypt[cnt] = arr[j];
        
        if(isVowels(arr[j])) vowels++;
        else consonants++;
        
        dfs(j + 1, cnt + 1);
        
        if(isVowels(arr[j])) vowels--;
        else consonants--;
    }
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	vowels, consonants = 0;
	cin >> l >> c;

	arr = new char[c];
	crypt = new char[l];
	
	cin.ignore();
	string s;
	getline(cin, s);
	
	for(int i = 0; i < c; i++)
	    arr[i] = s[2 * i];
	sort(arr, arr + c);
	
	dfs(0, 0);
}