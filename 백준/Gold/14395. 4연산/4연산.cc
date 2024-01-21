#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct container {
    int s;
    bool divide; //처음에 s/s 연산을 했다면 true
    vector<unsigned int> vec;
    //vec의 각 원소는 32비트이며, 각 비트는 +인지 *인지 정보를 가진다.
    //4비트에 대해 1011이면, 밑에서부터 보아서 ++*+ 이다.(0 : *)
    //원소 1개당 * 또는 +를 32개까지 정보 저장이 가능하다.
    container(int S, bool D) : s(S), divide(D) {}
    container(int S, bool D, vector<unsigned int> V) : s(S), divide(D), vec(V) {}
};

bool isPowTwo(int t) { 
    while (t > 1) {
        if (t % 2 == 0) t /= 2;
        else return false;
    }
    return true;
}

container cal(int s, int t) {
    int curS, size, cnt = 0;
    bool d;
    vector<unsigned int> tmpVec;
    queue<container> que;
    que.push(container(s, false));
    while (!que.empty()) {
        size = que.size();
        while (size--) {
            curS = que.front().s;
            d = que.front().divide;
            tmpVec = que.front().vec;
            que.pop();
            if (curS == t) return container(cnt, d, tmpVec);

            if (cnt % 32 == 0) tmpVec.push_back(0);
            if ((long long)curS * curS <= t && curS > 1) {
                //tmpVec[cnt / 32] &= ~(1 << (cnt % 32));
                que.push(container(curS * curS, d, tmpVec));
            }
            if (2 * curS <= t) {
                tmpVec[cnt / 32] |= 1 << (cnt % 32);
                que.push(container(2 * curS, d, tmpVec));
            }
            //처음에 '/'가 들어갈 수 있는 경우는, t가 2^x인 경우이다.
            if (isPowTwo(t) && s > 1 && cnt == 0) {
                que.push(container(1, true, tmpVec));
            }
        }
        cnt++;
    }
    cout << "-1";
    return container(0, false);
}

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int s, t;
    cin >> s >> t;
    if (s == t) cout << '0';
    else if (t == 0) cout << '-';
    else {
        container con = cal(s, t);
        int cnt = con.s;
        int start = 0;
        vector<unsigned int> vec = con.vec;
        if (con.divide) {
            cout << '/'; start = 1;
        }
        for (int i = start; i < cnt; i++) {
            if (vec[i / 32] & (1 << (i % 32)))
                cout << '+';
            else
                cout << '*';
        }
    }
}