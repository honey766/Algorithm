#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<vector<short>> vec(n + 1, vector<short>(m + 1));
    //vec[i][j] = (i,j)가 왼쪽 위 꼭짓점일 때 최대 정사각형 크기
    //처음에는 행렬 저장 역할
    
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < m; j++)
            vec[i][j] = s[j] - '0';
    }
    for(int i = 0; i < n; i++)
        vec[i][m] = 0;
    for(int j = 0; j < m; j++)
        vec[n][j] = 0;
        
    int Max = 0;
    for(int i = n - 1; i >= 0; i--){
        for(int j = m - 1; j >= 0; j--){
            if(vec[i][j] == 0) continue;
            //아래, 오른쪽, 대각선의 정사각형 크기 고려
            vec[i][j] = 1 + min(min(vec[i + 1][j], vec[i][j + 1]), vec[i + 1][j + 1]);
            Max = max(Max, (int)vec[i][j]);
        }
    }

    cout << Max * Max;
    return 0;
}