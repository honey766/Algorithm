#include <iostream>
using namespace std;

int main()
{
    int a;
    cin >> a;
    cout << (a < 60 ? 'F' : (a < 70 ? 'D' : (a < 80 ? 'C' : (a < 90 ? 'B' : 'A'))));
}