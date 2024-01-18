#include<stdio.h>
int main()
{
    int n,ans,max=0;
    int arr[100]={0,};
    scanf("%d %d",&n,&ans);
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    for(int i=0;i<n-2;i++)
        for(int j=1;j<n-1;j++)
            for(int k=2;k<n;k++)
            {
                if(!(i<j&&j<k))continue;
                int a=arr[i]+arr[j]+arr[k];
                if(ans>=a&&a>max)max=a;
            }
    printf("%d",max);
    return 0;
}