#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Data{
    int x;
    int y;
    bool operator< (const Data &a){
        return (x == a.x ? y < a.y : x < a.x);
    }
    bool operator<= (const Data &a){
        return (x == a.x ? y <= a.y : x < a.x);
    }
};

struct Line{
    Data p1;
    Data p2;
};

int ccw(Data a, Data b, Data c){
    long long t = (long long)(b.x - a.x) * (c.y - a.y) - (long long)(c.x - a.x) * (b.y - a.y);
    return t ? (t > 0 ? 1 : -1) : 0;
}

int parent[10000];
int Rank[10000];

void init(int n){
    for(int i = 0; i < n; i++)
        parent[i] = i;
}

int Find(int a){
    if(a == parent[a]) return a;
    return parent[a] = Find(parent[a]);
}

int Union(int a, int b){
    int A = Find(a);
    int B = Find(b);
    
    if(A == B)
        return 0;
    if(Rank[A] < Rank[B]){
        parent[A] = B;
    }
    else{
        parent[B] = A;
        if(Rank[A] == Rank[B])
            Rank[A]++;
    }
    return 1;
}

bool isOverlap(Line a, Line b){
    if(a.p2 < a.p1)
        swap(a.p1, a.p2);
    if(b.p2 < b.p1)
        swap(b.p1, b.p2);
    if(b.p1 < a.p1)
        swap(a, b);
    return b.p1 <= a.p2;
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n; cin >> n;
    vector<Line> lines(n);
    for(int i = 0; i < n; i++){
        double a, b, c, d;
        cin >> a >> b >> c >> d;
        lines[i].p1.x = (int)(a * 100 + 0.5);
        lines[i].p1.y = (int)(b * 100 + 0.5);
        lines[i].p2.x = (int)(c * 100 + 0.5);
        lines[i].p2.y = (int)(d * 100 + 0.5);
    }
    
    init(n);
    int ans = n;
    for(int i = 0; i < n; i++){
        Line li = lines[i];
        for(int j = i + 1; j < n; j++){
            Line lj = lines[j];
            if(ccw(li.p1, li.p2, lj.p1) == 0 && 
                ccw(li.p1, li.p2, lj.p2) == 0 && isOverlap(li, lj)) {
                ans -= Union(i, j);
            }
        }
    }
    cout << ans;
}