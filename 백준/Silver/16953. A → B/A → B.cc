#include <stdio.h>
using namespace std;
#define INF 1000000000
#define MIN(x,y) ((x) > (y) ? (y) : (x))

int f(int A, int B, int cnt) {
    if (B < A) return INF;
    if (B == A) return cnt;
    int min1 = INF, min2 = INF;
    if (B % 2 == 0) min1 = f(A, B / 2, cnt + 1);
    if (B % 10 == 1) min2 = f(A, B / 10, cnt + 1);
    return MIN(min1, min2);
}

int main(int argc, char** argv)
{
    int a, b;
    scanf("%d %d", &a, &b);
    int cnt = f(a, b, 0);
    if (cnt == INF) printf("-1");
    else printf("%d", cnt + 1);
}