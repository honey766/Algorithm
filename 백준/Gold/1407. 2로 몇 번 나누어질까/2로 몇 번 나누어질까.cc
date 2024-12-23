#include <iostream>
using namespace std;

int main()
{
    long long A, B, sum = 0;
    cin >> A >> B;
    
    //1, 2의 배수
    sum += (B - A + 1) / 2 * 3;
    if((B - A) % 2 == 0)
        sum += (A + 1) % 2 + 1;
    
    //4,8,16,...의 배수
    long long d = 4;
    while(true){
        //A~B에서 d의 배수는 s부터 e까지 있음
        long long s = (A - 1) / d * d + d;
        long long e = B / d * d;
        if(s > B) break;
        
        sum += (e - s + d) / 2;
        d <<= 1;
    }
    
    cout << sum;
}