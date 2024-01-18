#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, temp, i, j, *arr;
    cin >> n;
    arr = new int[n];
    for (i = 0; i < n; i++) { //Insertion sort
        cin >> arr[i];
        temp = arr[i];
        for (j = i - 1; j >= 0; j--) {
            if (arr[j] > temp) arr[j + 1] = arr[j];
            else break;
        }
        arr[j + 1] = temp;
    }
    for (i = 0; i < n; i++) cout << arr[i] << '\n';
}