#include <iostream>
using namespace std;

short A[100][100];
short B[100][100];
int C[100][100];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int N, M, K, i, j, k;
	cin >> N >> M;
	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++)
			cin >> A[i][j];
	cin >> M >> K;
	for (j = 0; j < M; j++)
		for (k = 0; k < K; k++)
			cin >> B[j][k];

	for (i = 0; i < N; i++)
		for (k = 0; k < K; k++)
			for (j = 0; j < M; j++)
				C[i][k] += (int)A[i][j] * B[j][k];

	for (i = 0; i < N; i++) {
		for (k = 0; k < K; k++)
			cout << C[i][k] << ' ';
		cout << '\n';
	}
}