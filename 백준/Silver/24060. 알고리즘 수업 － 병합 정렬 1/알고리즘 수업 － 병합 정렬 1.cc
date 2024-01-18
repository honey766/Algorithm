#include <iostream>
using namespace std;

int* tmp;

int merge(int* A, int p, int q, int r, int count, int k) {
    int i = p, j = q + 1,  t = p;
    while (i <= q && j <= r) {
        if (A[i] <= A[j]) tmp[t++] = A[i++];
        else tmp[t++] = A[j++];
    }
    while (i <= q)
        tmp[t++] = A[i++];
    while (j <= r)
        tmp[t++] = A[j++];
    i = t = p;
    while (i <= r) {
        A[i++] = tmp[t++];
        count++;
        if (count == k) {
            cout << A[i - 1];
            return count;
        }
    }
    return count;
}

int merge_sort(int* A, int p, int r, int count, int k) {
    if (p < r) {
        int q = (p + r) / 2;
        count = merge_sort(A, p, q, count, k);
        if (count == k) return count;
        count = merge_sort(A, q + 1, r, count, k);
        if (count == k) return count;
        count = merge(A, p, q, r, count, k);
    }
    return count;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
    int n, k, a, count;
    cin >> n >> k;
    int* arr = new int[n];
    tmp = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> a; arr[i] = a;
    }
    count = merge_sort(arr, 0, n - 1, 0, k);
    if (count != k) cout << "-1";
}