#include<iostream>
using namespace std;
#define INF 1000000000000000
#define MIN(x,y) ((x) > (y) ? (y) : (x))
#define POW(x) ((x) * (x))

struct coor{
    long long x;
    long long y;
};

coor co[1000];
long long dist[1000];
bool selected[1000]; 

long long prim(int n){
    dist[0] = 0;
    long long ret = 0;
    for(int i = 0; i < n; i++){
		int now = -1;
        long long min_dist = INF;
        for(int j = 0; j < n; j++)
        	if(!selected[j] && min_dist > dist[j]){
             	now = j; min_dist = dist[j];   
            }
        selected[now] = true;
        ret += dist[now];
        for(int j = 0; j < n; j++)
            dist[j] = MIN(dist[j], POW(co[now].x - co[j].x) + POW(co[now].y - co[j].y));
    }
    return ret;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cout << '#' << test_case << ' ';
		int n; cin >> n;
        double E;
        for(int i = 0; i < n; i++){
            dist[i] = INF;
            selected[i] = false;
            cin >> co[i].x;
        }
        for(int i = 0; i < n; i++)
        	cin >> co[i].y;
        cin >> E;
        cout << (long long)(E * prim(n) + 0.5) << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}