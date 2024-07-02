#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int r, s;
    cin >> r >> s;
    string* pic = new string[r];
    int* starFirst = new int[s];
    int* starLast = new int[s](); // 해당 열에서 마지막으로 발견되는 star의 행
    bool* ground = new bool[s](); //해당 열에서 ground 발견하면 true
    int minDist = 30000; //운석이 떨어지는 거리
    for (int i = 0; i < s; i++)
        starFirst[i] = 30000;
    for (int i = 0; i < r; i++) {
        cin >> pic[i];
        for (int j = 0; j < s; j++) {
            if (pic[i][j] == 'X') {
                if (starFirst[j] == 30000)
                    starFirst[j] = i;
                starLast[j] = i;
            }
            if (pic[i][j] == '#' && !ground[j]) {
                ground[j] = true;
                if (starFirst[j] != 30000)
                    minDist = min(minDist, i - starLast[j] - 1);
            }
        }
    }
    if (minDist != 30000) {
        for (int i = 0; i < s; i++) {
            if (starFirst[i] > starLast[i])
                continue;
            for (int j = starLast[i]; j >= starFirst[i]; j--) 
                pic[j + minDist][i] = pic[j][i];
            for (int j = 0; j < minDist; j++)
                pic[starFirst[i] + j][i] = '.';
        }
    }

    for (int i = 0; i < r; i++)
        cout << pic[i] << '\n';
}