#include <iostream>
using namespace std;

void swap(int& a, int& b){
    int t = a;
    a = b;
    b = t;
}

int main()
{
    int x1[2], y1[2], x2[2], y2[2]; //좌표가 [0], [1]인 사각형 2개
    for(int i = 0; i < 2; i++)
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
    
    if(x1[1] < x1[0]) {
        swap(x1[0], x1[1]);
        swap(x2[0], x2[1]);
    }
    if(y1[1] < y1[0]){
        swap(y1[0], y1[1]);
        swap(y2[0], y2[1]);
    }
    //x1[0] < x1[1],    y1[0] < y1[1]
    
    if(x2[0] < x1[1] || y2[0] < y1[1]){
        cout << "NULL";
    }
    else if(x2[0] == x1[1]){
        if(y2[0] == y1[1]){
            cout << "POINT";
        }
        else if(y2[0] > y1[1]){
            cout << "LINE";
        }
    }
    else if(x2[0] > x1[1]){
        if(y2[0] == y1[1]){
            cout << "LINE";
        }
        else if(y2[0] > y1[1]){
            cout << "FACE";
        }
    }

    return 0;
}