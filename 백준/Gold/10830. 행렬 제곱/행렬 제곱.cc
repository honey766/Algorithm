#include <iostream>
#include <cstring>
using namespace std;
#define N 1000

int n;
long long b;

// a*b 결과가 c에 저장
void mul(int**& a, int**& b, int**& c) {
    for (int i = 0; i < n; i++)
        for (int k = 0; k < n; k++) {
            c[i][k] = 0;
            for (int j = 0; j < n; j++)
                c[i][k] = (c[i][k] + a[i][j] * b[j][k]) % N;
        }
}

void swap(int**& a, int**& b) {
    int** tmp = a;
    a = b;
    b = tmp;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int i, j;
    int** arr, ** ret, ** tmp;
    cin >> n >> b;
    arr = new int* [n];
    ret = new int* [n];
    tmp = new int* [n];
    for (i = 0; i < n; i++) {
        arr[i] = new int[n];
        ret[i] = new int[n];
        tmp[i] = new int[n];
        for (j = 0; j < n; j++) {
            ret[i][j] = 0;
            cin >> arr[i][j];
        }
        ret[i][i] = 1; //단위행렬
    }

    while (b) {
        if (b % 2) {
            mul(ret, arr, tmp);
            //tmp에 저장돼 있는 결과를 ret에 옮김
            swap(ret, tmp);
        }
        mul(arr, arr, tmp);
        swap(arr, tmp);
        b /= 2;
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            cout << ret[i][j] << ' ';
        cout << '\n';
    }
}