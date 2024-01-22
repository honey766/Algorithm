//시뮬레이션 코드
#include <iostream>
using namespace std;
#define XNOR(x, y) (!((int)(x) ^ (int)(y))) //(int)true == 1, (int)false == 0

bool hor[5]; //수평 빙고, 위부터 아래
bool ver[5]; //수직 빙고, 왼부터 오른
bool diag[2]; //대각선 빙고, 왼위 ~ 오른아래가 diag[0]
int horCnt, verCnt, diagCnt, bingoSqrCnt, coloredCnt, x, cnt;
//왼쪽부터 / 수평 빙고 개수 / 수직 빙고 개수 / 대각선 빙고 개수 /
//빙고 줄의 일부인 칸 개수 / 색칠된 칸 개수


//i번째 bit가 1이면 true
bool a(int i) {
    return x & (1 << i);
}

bool diagNice(int i) { //해당 칸이 대각선 빙고에 속하면 true
    bool diag1 = (i == 0 || i == 6 || i == 12 || i == 18 || i == 24) && diag[0];
    bool diag2 = (i == 4 || i == 8 || i == 12 || i == 16 || i == 20) && diag[1];
    return diag1 || diag2;
}

//5x5 빙고판에서 왼쪽 위부터 시작하여 오른쪽으로 0 1 2 3 4 ...
//a(i)가 true라면 해당 칸의 조건은 true여야 하고, false라면 조건이 false여야 한다.
//check(i)는 해당 칸이 색칠됐으면 조건이 true인지, 색칠이 안 됐으면 조건이 false인지를 검사한다.
bool check(int i) {
    bool cond; //조건이 true인지
    switch (i) {
    case 0:
        cond = !diag[1];
        break;
    case 1:
        cond = !hor[0] && !ver[1];
        break;
    case 2:
        cond = diag[0];
        break;
    case 3:
        cond = a(18);
        break;
    case 4:
        cond = hor[0] || ver[4] || diag[1];
        break;
    case 5:
        cond = !a(15);
        break;
    case 6:
        cond = (horCnt > 0) && (verCnt > 0) && (diagCnt > 0);
        break;
    case 7:
        cond = a(7);
        break;
    case 8:
        cond = coloredCnt <= 17;
        break;
    case 9:
        cond = !(bingoSqrCnt % 2);
        break;
    case 10:
        cond = hor[2] || ver[0];
        break;
    case 11:
        cond = coloredCnt - bingoSqrCnt >= 5;
        break;
    case 12:
        cond = !a(12) || hor[2] || ver[2] || diag[0] || diag[1];
        break;
    case 13:
        cond = verCnt >= 2;
        break;
    case 14:
        cond = bingoSqrCnt <= 15;
        break;
    case 15:
        cond = !a(5);
        break;
    case 16:
        cond = hor[1] || ver[3];
        break;
    case 17:
        cnt = 0;
        for (int i = 2; i < 25; i += 5) cnt += (int)a(i);
        cond = cnt <= 3;
        break;
    case 18:
        cond = a(3);
        break;
    case 19:
        cond = diagCnt > 0;
        break;
    case 20:
        cond = a(24);
        break;
    case 21:
        cond = false;
        break;
    case 22:
        cond = a(22);
        break;
    case 23:
        cond = (horCnt + verCnt + diagCnt) >= 3;
        break;
    case 24:
        cond = a(20);
        break;
    }
    return XNOR(a(i), cond);
}

bool check() {
    horCnt = verCnt = diagCnt = bingoSqrCnt = coloredCnt = 0;
    for (int i = 0; i < 5; i++) {
        hor[i] = true;
        ver[i] = true;
        for (int j = 0; j < 5; j++) {
            hor[i] = hor[i] && a(5 * i + j);
            ver[i] = ver[i] && a(i + 5 * j);
            coloredCnt += (int)a(5 * i + j);
        }
        horCnt += (int)hor[i];
        verCnt += (int)ver[i];
    }
    diag[0] = a(0) && a(6) && a(12) && a(18) && a(24);
    diag[1] = a(4) && a(8) && a(12) && a(16) && a(20);
    diagCnt = (int)diag[0] + (int)diag[1];
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            bingoSqrCnt += (int)(hor[i] || ver[j] || diagNice(5 * i + j));

    int i = 0;
    while (i < 25 && check(i++));
    return i == 25; //check(0~24)가 모두 true라면 true
}

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    x = -1;
    int end = 1 << 25; //end == 2^25

    //논리적으로 특수한 칸들을 무시해도 도는 횟수가 2^25번으로 적다.
    while (++x < end) {
        if (check()) { //정답이라면 해당 x를 출력
            for (int i = 0; i < 25; i++) {
                cout << (int)a(i) << ' ';
                if (i % 5 == 4) cout << '\n';
            }
        }
    }
}
