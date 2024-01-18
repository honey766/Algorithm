#include <iostream>
using namespace std;

int main()
{
    int a, b, c;
    int price = 0;
    cin >> a >> b >> c;
    if(a == b && b == c){
        price = 10000 + 1000 * a;
    }else if(a == b || a == c){
        price = 1000 + 100 * a;
    }else if(b == c){
        price = 1000 + 100 * b;
    }else{
        price = 100 * (a > b ? (c > a ? c : a) : (c > b ? c : b));
    }
    cout << price;
}