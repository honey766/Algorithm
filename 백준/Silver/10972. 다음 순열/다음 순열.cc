#include <iostream>
#include <algorithm>
using namespace std;

int* arr;

// 내림차순 배열에서 target보다 큰 수 중 가장 작은 수의 인덱스 반환
int f(int s, int e, int target){
    int mid, ans = -1;
    while(s <= e){
        mid = (s + e) / 2;
        if(arr[mid] > target){
            s = mid + 1;
            ans = mid;
        }
        else{
            e = mid - 1;
        }
    }
    return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	int n, i;
	cin >> n;
	arr = new int[n];
	for(i = 0; i < n; i++)
	    cin >> arr[i];
	    
	//    2 3 4 7 6 5 1
	// => 2 3 5 7 6 4 1
	// => 2 3 5 1 4 6 7
	
	for(i = n - 2; i >= 0; i--)
	    if(arr[i] < arr[i + 1])
	        break;
	
	if(i == -1){
	    cout << "-1";
	    return 0;
	}
	
	int idx = f(i + 1, n - 1, arr[i]);
	int temp = arr[idx];
	arr[idx] = arr[i];
	arr[i] = temp;
	
	sort(arr + i + 1, arr + n);
	
	for(i = 0; i < n; i++)
	    cout << arr[i] << ' ';
}