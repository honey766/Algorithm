#include <stdio.h>
#include <stdlib.h>

typedef struct point {
    int x;
    int color;
}Point;

int Abs(int a)
{
    return a > 0 ? a : -a;
}

int compare(const void*a,const void*b)
{
    Point first=*(Point*)a;
    Point second=*(Point*)b;
    if(first.color<second.color)
        return -1;
    else if(first.color>second.color)
        return 1;
    else
        return 0;
}

// The following is main function to output testcase.
int main() {
    int n;
    int find; //if find,1
    long long sum = 0;
    long long lp;
    int cur[2]={0,0};   //curindex, curcolornumber
                        //colornumber가 같은 애들끼리만 비교하기 위함
    scanf("%d", &n);
    Point* p = (Point*)malloc(sizeof(Point) * n);
    for (int i = 0; i < n; i++)scanf("%d %d", &p[i].x, &p[i].color);
    
    qsort(p,n,sizeof(Point),compare);
    
    for (int i = 0; i < n; i++)
    {
        lp = 2000000000000000000;
        find = 0;
        if(p[i].color>cur[1])
        {
            cur[0]=i;
            cur[1]=p[i].color;
        }
        int j=cur[0]-1;
        while(1)
        {
            j++;
            if(p[j].color!=p[i].color)break;
            if(i==j)continue;
            find = 1;
            int a = Abs(p[i].x - p[j].x);
            if (a < lp) lp = a;
        }
        if(find)
            sum += lp;
    }
    printf("%lld", sum);
}