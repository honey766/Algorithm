#include <iostream>
using namespace std;

void connect(int n1, int n2){
    cout << n1 << ' ' << n2 << '\n';
}

// n~n+5까지의 노드는 간선이 각각 5개
void connect9(int n){
    for(int i = n; i < n + 4; i++)
        for(int j = i + 2; j < n + 6; j++)
            if(!(i == n && j == n + 5))
                connect(i, j);
}

//n1노드에서서 n2~n2+2까지의 노드에 간선을 그음
void connect3(int n1, int n2){
    for(int i = n2; i < n2 + 3; i++)
        connect(n1, i);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int N, M;
    cin >> N >> M;
    if(N == 1 && M == 2){
        cout << "NO";
        return 0;
    }else{
        cout << "YES\n";
    }
    
    //알고리즘으로 커버 안 되는 케이스
    if(N == 2 && M == 4){
        for(int i = 1; i < 4; i++)
            for(int j = i + 1; j < 7; j++)
                connect(i, j);
        return 0;
    }
    
    N *= 3; M *= 3;
    
    //기본 간선 2개씩 가짐, 사이클 형성
    for(int i = 1; i < N; i++)
        connect(i, i + 1);
    connect(N, 1);
    M -= N;
    
    /*
    /// connect9: 6개의 노드를 묶어 간선을 5개씩 가지게 하고 간선 9개 생성
    /// 간선이 9개 미만이라면 connect3 함수로 간선 3개씩 생성
    /// if(M==6)에서 노드의 번호가 노드의 개수를 초과할 가능성이 있으나
    /// 6개의 노드로 얻을 수 있는 간선이 9개(>6)이므로 해당 알고리즘은 (노드의 개수)>=9에서 정상 작동
    /// (N개의 노드일 때 그어야 하는 최대 간선의 개수는 N개이므로)
    */
    int curNode = 1;
    while(M > 0){
        if(M >= 9){
            connect9(curNode);
            curNode += 6;
        }
        else{
            connect3(curNode, curNode + 2);
            if(M == 6)
                connect3(curNode + 1, curNode + 5);
        }
        
        M -= 9;
    }
    return 0;
}