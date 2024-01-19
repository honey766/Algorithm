#include<iostream>
using namespace std;

class heap{
private:
	int* data;
    int size;
    bool isMax;
    void swap(int& a, int& b){
    	int tmp = a;
        a = b;
        b = tmp;
    }
    bool compare(int a, int b){
        if(isMax) return a < b;
        else return a > b;
    }
public:
    heap(int n, bool Max){
        data = new int[n];
        isMax = Max;
        size = 0;
    }
    
    void push(int x){
        data[++size] = x;
        int child = size;
        int parent = child / 2;
        while(parent != 0 && compare(data[parent], data[child])){
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
			if(left <= size && compare(data[index], data[left])) index = left;
            if(right <= size && compare(data[index], data[right])) index = right;
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
	int test_case;
	int T;
	cin>>T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cout << '#' << test_case << ' ';
        int n, mid, x, y, sum = 0;
        int number = 20171109;
        cin >> n >> mid;
        heap max_heap(n, true);
        heap min_heap(n, false);
        while(n--){
            cin >> x >> y;
            if(x < mid && y < mid){
                min_heap.push(mid);
                max_heap.push(x);
                max_heap.push(y);
                mid = max_heap.pop();
            }else if(mid < x && mid < y){
                max_heap.push(mid);
                min_heap.push(x);
                min_heap.push(y);
                mid = min_heap.pop();
            }else{
                if(x < mid) max_heap.push(x);
                else min_heap.push(x);
                if(y < mid) max_heap.push(y);
                else min_heap.push(y);
            }
            sum = (sum + mid) % number;
        }
        cout << sum << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}