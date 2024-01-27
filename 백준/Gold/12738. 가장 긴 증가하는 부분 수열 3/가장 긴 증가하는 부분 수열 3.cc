#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, size = 1;
    cin >> n;
    int* arr = new int[n];
    int* vec = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vec[0] = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > vec[size - 1])
            vec[size++] = arr[i];
        else {
            int idx = lower_bound(vec, vec + size, arr[i]) - vec;
            vec[idx] = arr[i];
        }
    }
    cout << size;
}