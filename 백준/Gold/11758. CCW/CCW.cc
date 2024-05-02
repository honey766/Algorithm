#import<iostream>
main(){int a,b,c,d,e,f,w;std::cin>>a>>d>>b>>e>>c>>f;w=(b-a)*(f-e)-(c-b)*(e-d);std::cout<<(w?w>0?1:-1:0);}