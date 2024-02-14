#include<iostream>
using namespace std;
int main(){int a,b,c,d,e,f,w;cin>>a>>d>>b>>e>>c>>f;w=(b-a)*(f-e)-(c-b)*(e-d);cout<<(!w?0:w>0?1:-1);}