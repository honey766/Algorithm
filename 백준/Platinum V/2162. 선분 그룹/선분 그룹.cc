#include <iostream>
using namespace std;
#define MAX(x, y) ((x) > (y) ? (x) : (y))

struct Data {
	long long x;
	long long y;
};
struct pr {
	Data p1;
	Data p2;
};

void swap(long long& a, long long& b) {
	long long tmp = a;
	a = b;
	b = tmp;
}

long long ccw(Data a, Data b, Data c) {
	return (long long)(b.x - a.x) * (c.y - b.y) - (long long)(c.x - b.x) * (b.y - a.y);
}

bool check(pr a, pr b) {
	long long ccw1 = ccw(a.p1, a.p2, b.p1) * ccw(a.p1, a.p2, b.p2);
	long long ccw2 = ccw(b.p1, b.p2, a.p1) * ccw(b.p1, b.p2, a.p2);

	if (!ccw1 && !ccw2) {
		long long c = a.p1.x, d = a.p2.x, e = b.p1.x, f = b.p2.x;
		long long c2 = a.p1.y, d2 = a.p2.y, e2 = b.p1.y, f2 = b.p2.y;
		if (c > d) swap(c, d);
		if (e > f) swap(e, f);
		if (c2 > d2) swap(c2, d2);
		if (e2 > f2) swap(e2, f2);
		return c <= f && e <= d && c2 <= f2 && e2 <= d2;
	}
	return ccw1 <= 0 && ccw2 <= 0;
}


long long cnt = 0;
long long* parent;
long long* sz;

long long Find(long long a) {
	if (a == parent[a]) return a;
	return parent[a] = Find(parent[a]);
}

void Union(long long a, long long b) {
	long long A = Find(a);
	long long B = Find(b);

	if (A == B) return;

	++cnt;
	parent[A] = B;
	sz[B] += sz[A];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	long long n, Max = -1; 
	cin >> n;
	pr* line = new pr[n];
	parent = new long long[n];
	sz = new long long[n];

	for (long long i = 0; i < n; ++i) {
		cin >> line[i].p1.x >> line[i].p1.y >> line[i].p2.x >> line[i].p2.y;
		parent[i] = i;
		sz[i] = 1;
	}
	for (long long i = 0; i < n; ++i)
		for (long long j = i + 1; j < n; ++j)
			if (check(line[i], line[j])) {//두 선분이 겹친다면
				Union(i, j);
			}
	for (long long i = 0; i < n; ++i)
		Max = MAX(Max, sz[i]);
	cout << n - cnt << '\n' << Max;
}