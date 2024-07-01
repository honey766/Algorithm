#include <iostream>
using namespace std;

int main(){
    double v, w, d, t;
    int cnt = -1;
    cin >> v >> w >> d;
    while(d >= 0){
        ++cnt;
        t = w / v;
        d -= 5 * t * t;
        w *= 1.25;
    }
    cout << cnt;
}