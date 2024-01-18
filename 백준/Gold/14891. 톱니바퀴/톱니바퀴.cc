#include <iostream>
#include <deque>
using namespace std;

deque<char> deq[4];

void Rotate(int* rotateDir) {
    for (int i = 0; i < 4; i++) {
        if (rotateDir[i] == 0) continue;
        if (rotateDir[i] == 1) { //시계 방향
            deq[i].push_front(deq[i].back());
            deq[i].pop_back();
        }
        else {
            deq[i].push_back(deq[i].front());
            deq[i].pop_front();
        }
    }
}

void MakeRotateDir(int* rotateDir, int num, int dir) {
    rotateDir[num - 1] = dir;
    for (int i = num; i < 4; i++) {
        if (deq[i - 1][2] != deq[i][6])
            rotateDir[i] = -rotateDir[i - 1];
        else
            rotateDir[i] = 0;
    }
    for (int i = num - 2; i >= 0; i--) {
        if (deq[i][2] != deq[i + 1][6])
            rotateDir[i] = -rotateDir[i + 1];
        else
            rotateDir[i] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    string s;
    int k, num, dir, rotateDir[4], score, mul;
    for (int i = 0; i < 4; i++) {
        cin >> s;
        for (int j = 0; j < 8; j++)
            deq[i].push_back(s[j]);
    }
    cin >> k;
    while (k--) {
        cin >> num >> dir;
        MakeRotateDir(rotateDir, num, dir);
        Rotate(rotateDir);
    }
    score = 0; mul = 1;
    for (int i = 0; i < 4; i++) {
        if (deq[i][0] == '1') score += mul;
        mul = mul << 1;
    }
    cout << score;
}