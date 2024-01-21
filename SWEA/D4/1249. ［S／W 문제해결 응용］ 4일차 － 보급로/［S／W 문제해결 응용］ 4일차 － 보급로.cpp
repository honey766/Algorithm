#include <iostream>
#include <queue>
#include <functional>
using namespace std;
#define INF 2100000000

int arr[100][100][4];   //각 노드의 간선은 최대 4개
                        	//지도 상에서 a[i][j]의 간선의 가중치는 arr[i][j][0~3]
                        	//0:위, 1:왼, 2:오른, 3:아래
int a[100][100]; //지도
int dist[100][100];
int T1[4] = { -1, 0, 0, 1 };
int T2[4] = { 0, -1, 1, 0 };

void makeEdge(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            //위
            if (i == 0) arr[i][j][0] = -1;
            else arr[i][j][0] = a[i - 1][j];
            //아래
            if (i == n - 1) arr[i][j][3] = -1;
            else arr[i][j][3] = a[i + 1][j];
            //왼
            if (j == 0) arr[i][j][1] = -1;
            else arr[i][j][1] = a[i][j - 1];
            //오른
            if (j == n - 1) arr[i][j][2] = -1;
            else arr[i][j][2] = a[i][j + 1];
        }
    }
}

int dijkstra(int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dist[i][j] = INF;
    dist[0][0] = 0;

    int curDist, curNode;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, 0 });
    while (!pq.empty()) {
        curDist = pq.top().first;
        curNode = pq.top().second;
        pq.pop();

        int i = curNode / n;
        int j = curNode % n;
        if (curDist != dist[i][j]) continue; //이미 dist가 갱신됐다면 패스

        for (int k = 0; k < 4; k++) {
            if (arr[i][j][k] == -1) continue; //간선이 없음
            if (dist[i + T1[k]][j + T2[k]] > curDist + arr[i][j][k]) {
                dist[i + T1[k]][j + T2[k]] = curDist + arr[i][j][k];
                pq.push({ dist[i + T1[k]][j + T2[k]], n * (i + T1[k]) + (j + T2[k]) });
            }//dist[i-1][j], dist[i][j+1] 등에 접근하기 용이하도록 T1, T2를 씀
        }
    }

    return dist[n - 1][n - 1];
}

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int test_case;
    int T;
    int n;

    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        cin >> n;
        string s;
        for (int i = 0; i < n; i++) {
            cin >> s;
            for (int j = 0; j < n; j++)
                a[i][j] = s[j] - '0';
        }
        makeEdge(n);
        cout << '#' << test_case << ' ';
        cout << dijkstra(n) << '\n';
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}