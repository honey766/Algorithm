#include <iostream>
#include <algorithm>
using namespace std;

struct id {
    int age;
    string name;
};

bool compare(id a, id b) {
    return a.age < b.age;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    id* arr = new id[n];
    id* replace = new id[n];
    int index[201] = { 0, };
    for (int i = 0; i < n; i++) {
        cin >> arr[i].age >> arr[i].name;
        index[arr[i].age]++;
    }
    for (int i = 2; i <= 200; i++) index[i] += index[i - 1];
    for (int i = n - 1; i >= 0; i--) replace[(index[arr[i].age]--) - 1] = arr[i];
    for (int i = 0; i < n; i++) cout << replace[i].age << ' ' << replace[i].name << '\n';
}