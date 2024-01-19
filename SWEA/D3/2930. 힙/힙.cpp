#include<iostream>
using namespace std;

class max_heap{
private:
	int* data;
    int size;
    void swap(int& a, int& b){
    	int tmp = a;
        a = b;
        b = tmp;
    }
public:
    max_heap(int n){
        data = new int[n];
        size = 0;
    }
    
    void push(int x){
        data[++size] = x;
        int child = size;
        int parent = child / 2;
        while(parent != 0 && data[parent] < data[child]){
        	swap(data[parent], data[child]);
            child = child / 2;
            parent = child / 2;
        }
    }
    
    int pop(){
        if(size == 0) return -1;
        
		int rst = data[1];
        data[1] = data[size--];
        int parent = 1;
        int index = 1;
        int left = 2 * parent;
        int right = 2 * parent + 1;
        
        while(true){
			if(left <= size && data[left] > data[index]) index = left;
            if(right <= size && data[right] > data[index]) index = right;
            if(parent == index) break;
            
            swap(data[parent], data[index]);
            parent = index;
            left = 2 * parent;
       	 	right = 2 * parent + 1;
        }
        
        return rst;
    }
    
    
};


int main(int argc, char** argv)
{
     ios_base::sync_with_stdio(false); cin.tie(NULL);
	int test_case;
	int T;
	cin>>T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cout << '#' << test_case << ' ';
        int a, n; cin >> n;
        max_heap h(n);
		while(n--){
            cin >> a;
            if(a == 1){
                cin >> a;
                h.push(a);
            }else{
                cout << h.pop() << ' ';
            }
        }
        cout << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}