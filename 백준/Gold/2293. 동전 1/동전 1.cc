#import<iostream>
int d[10001];main(){int n,k,a,j;std::cin>>n>>k;d[0]=1;while(n--){std::cin>>a;for(j=a;j<=k;j++)d[j]+=d[j-a];}std::cout<<d[k];}