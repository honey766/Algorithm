#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int temp, i, j, sum = 0;
    int arr[5];
    for (i = 0; i < 5; i++) { //Insertion sort
        cin >> arr[i];
        temp = arr[i];
        sum += temp;
        for (j = i - 1; j >= 0; j--) {
            if (arr[j] > temp) arr[j + 1] = arr[j];
            else break;
        }
        arr[j + 1] = temp;
    }
    cout << sum / 5 << '\n' << arr[2];
}