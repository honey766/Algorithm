#include <iostream>
using namespace std;

void Rotate(char* arr, char docchi) {
    char temp[9];
    for (int i = 0; i < 9; i++) temp[i] = arr[i];
    if (docchi == '+') {
        arr[2] = temp[0]; arr[5] = temp[1]; arr[8] = temp[2];
        arr[1] = temp[3];                   arr[7] = temp[5];
        arr[0] = temp[6]; arr[3] = temp[7]; arr[6] = temp[8];
    }
    else {
        arr[6] = temp[0]; arr[3] = temp[1]; arr[0] = temp[2];
        arr[7] = temp[3];                   arr[1] = temp[5];
        arr[8] = temp[6]; arr[5] = temp[7]; arr[2] = temp[8];
    }
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    char U[9], D[9], F[9], B[9], L[9], R[9], temp[3];
    int n, m;
    string s;
    cin >> n;
    while (n--) {
        cin >> m;
        for (int i = 0; i < 9; i++) {
            U[i] = 'w'; D[i] = 'y';
            F[i] = 'r'; B[i] = 'o';
            L[i] = 'g'; R[i] = 'b';
        }
        while (m--) {
            cin >> s;
            switch (s[0]) {
            case 'U':
                Rotate(U, s[1]);
                for (int i = 0; i < 3; i++) temp[i] = F[i];
                if (s[1] == '+') {
                    for (int i = 0; i < 3; i++) {
                        F[i] = R[i]; R[i] = B[8 - i];
                        B[8 - i] = L[i]; L[i] = temp[i];
                    }
                }
                else {
                    for (int i = 0; i < 3; i++) {
                        F[i] = L[i]; L[i] = B[8 - i];
                        B[8 - i] = R[i]; R[i] = temp[i];
                    }
                }
                break;
            case 'D':
                Rotate(D, s[1]);
                for (int i = 0; i < 3; i++) temp[i] = F[6 + i];
                if (s[1] == '+') {
                    for (int i = 6; i < 9; i++) {
                        F[i] = L[i]; L[i] = B[8 - i];
                        B[8 - i] = R[i]; R[i] = temp[i - 6];
                    }
                }
                else {
                    for (int i = 6; i < 9; i++) {
                        F[i] = R[i]; R[i] = B[8 - i];
                        B[8 - i] = L[i]; L[i] = temp[i - 6];
                    }
                }
                break;
            case 'F':
                Rotate(F, s[1]);
                for (int i = 0; i < 3; i++) temp[i] = U[6 + i];
                if (s[1] == '+') {
                    for (int i = 0; i < 3; i++) {
                        U[6 + i] = L[8 - 3 * i]; L[8 - 3 * i] = D[2 - i];
                        D[2 - i] = R[3 * i]; R[3 * i] = temp[i];
                    }
                }
                else {
                    for (int i = 0; i < 3; i++) {
                        U[6 + i] = R[3 * i]; R[3 * i] = D[2 - i];
                        D[2 - i] = L[8 - 3 * i]; L[8 - 3 * i] = temp[i];
                    }
                }
                break;
            case 'B':
                Rotate(B, s[1]);
                for (int i = 0; i < 3; i++) temp[i] = U[i];
                if (s[1] == '+') {
                    for (int i = 0; i < 3; i++) {
                        U[i] = R[2 + 3 * i]; R[2 + 3 * i] = D[8 - i];
                        D[8 - i] = L[6 - 3 * i]; L[6 - 3 * i] = temp[i];
                    }
                }
                else {
                    for (int i = 0; i < 3; i++) {
                        U[i] = L[6 - 3 * i]; L[6 - 3 * i] = D[8 - i];
                        D[8 - i] = R[2 + 3 * i]; R[2 + 3 * i] = temp[i];
                    }
                }
                break;
            case 'L':
                Rotate(L, s[1]);
                for (int i = 0; i < 3; i++) temp[i] = U[3 * i];
                if (s[1] == '+') {
                    for (int i = 0; i < 9; i += 3) {
                        U[i] = B[i]; B[i] = D[i];
                        D[i] = F[i]; F[i] = temp[i / 3];
                    }
                }
                else {
                    for (int i = 0; i < 9; i += 3) {
                        U[i] = F[i]; F[i] = D[i];
                        D[i] = B[i]; B[i] = temp[i / 3];
                    }
                }
                break;
            case 'R':
                Rotate(R, s[1]);
                for (int i = 0; i < 3; i++) temp[i] = U[3 * i + 2];
                if (s[1] == '+') {
                    for (int i = 2; i < 9; i += 3) {
                        U[i] = F[i]; F[i] = D[i];
                        D[i] = B[i]; B[i] = temp[i / 3];
                    }
                }
                else {
                    for (int i = 2; i < 9; i += 3) {
                        U[i] = B[i]; B[i] = D[i];
                        D[i] = F[i]; F[i] = temp[i / 3];
                    }
                }
                break;
            }
        }
        for (int i = 0; i < 9; i++) {
            cout << U[i];
            if (i % 3 == 2) cout << '\n';
        }
    }
}