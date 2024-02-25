#include <iostream>
#include <cstring>
using namespace std;
#define ll long long
#define N 1'000'000'007

int n;
long long fibN;

// a*b 결과가 c에 저장
void mul(ll**& a, ll**& b, ll**& c) {
    for (int i = 0; i < n; i++)
        for (int k = 0; k < n; k++) {
            c[i][k] = 0;
            for (int j = 0; j < n; j++)
                c[i][k] = (c[i][k] + a[i][j] * b[j][k]) % N;
        }
}

void swap(ll**& a, ll**& b) {
    ll** tmp = a;
    a = b;
    b = tmp;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int i, j;
    ll** arr, ** ret, ** tmp;
    n = 2;
    cin >> fibN;
    arr = new ll* [n];
    ret = new ll* [n];
    tmp = new ll* [n];
    for (i = 0; i < n; i++) {
        arr[i] = new ll[n];
        ret[i] = new ll[n];
        tmp[i] = new ll[n];
        for (j = 0; j < n; j++) {
            ret[i][j] = 0;
        }
        ret[i][i] = 1; //단위행렬
    }
    arr[0][0] = arr[0][1] = arr[1][0] = 1;
    arr[1][1] = 0;

    while (fibN) {
        if (fibN % 2) {
            mul(ret, arr, tmp);
            //tmp에 저장돼 있는 결과를 ret에 옮김
            swap(ret, tmp);
        }
        mul(arr, arr, tmp);
        swap(arr, tmp);
        fibN /= 2;
    }

    cout << ret[1][0];
}