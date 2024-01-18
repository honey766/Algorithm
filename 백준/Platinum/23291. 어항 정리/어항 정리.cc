#include <iostream>
#include <vector>
using namespace std;

int** temp;

void Rotate(int** levitation, int x, int y) {
	//temp는 main함수에서 초기화함
	//공중제비만 한 번 돎
	int prevx, prevy, i, j;
	if (x == y) {
		prevx = x - 1; prevy = y;
	}
	else {
		prevx = x; prevy = y - 1;
	}
	for (i = 0; i < prevx; i++)
		for (j = 0; j < prevy; j++)
			temp[i][j] = levitation[i][j];
	for (i = 0; i < prevx; i++)
		for (j = 0; j < prevy; j++)
			levitation[j][prevx - i] = temp[i][j];
}

int FishControl(int x, int y) {
	//x가 y보다 작다면 y에게서 물고기를 받는다(+)
	//x가 y보다 크다면 y에게 준다. (-)
	return (y - x) / 5;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int i, j, n, k, count = 0, Min, Max, sum;
	int levitationNum, squareHorizon, squareVertical;
	cin >> n >> k;
	int* arr = new int[n];
	for (i = 0; i < n; i++) cin >> arr[i];
	while(++count) {
		Max = 0; Min = 10001;
		vector<int> idxVec;
		////Step1 : 초기 작업
		for (i = 0; i < n; i++) {//Max, Min 구하고, Min 값의 index 구하기
			Max = arr[i] > Max ? arr[i] : Max;
			if (arr[i] <= Min) {
				if (arr[i] < Min) {
					idxVec.clear();
					Min = arr[i];
				}
				idxVec.push_back(i);
			}
		}
		if (Max - Min <= k) break; //탈출 조건
		for (i = 0; i < idxVec.size(); i++) //Min값 1씩 늘리기
			arr[idxVec[i]]++;

		////Step2 : 공중제비 시키기
		sum = 0;
		for (i = -2; sum <= n; i++)
			sum += (i + 4) / 2; // 1, 1, 2, 2, ...을 더하기
		//i에는 공중제비 횟수가 저장
		levitationNum = n - (sum - (2 * i + 5) / 2); //공중제비 끝났을 때 어항 가로 길이
		int** levitation = new int* [levitationNum];
		temp = new int* [levitationNum];
		squareHorizon = (i + 2) / 2; //직사각형 부분 가로 길이
		squareVertical = (i + 3) / 2; //세로 길이
		for (j = 0; j < squareHorizon; j++) {
			levitation[j] = new int[squareVertical];
			temp[j] = new int[squareVertical];
		}
		for (; j < levitationNum; j++) {
			levitation[j] = new int[1];
			temp[j] = new int[1];
			levitation[j][0] = arr[n - levitationNum + j]; //공중제비 안 도는 영역은 우선적으로 복붙
		}
		levitation[0][0] = arr[0];
		for (sum = 0, j = 1; j <= i; j++) {//공중제비 시키기
			int horizonNum = (j + 2) / 2;
			sum += (j + 1) / 2;
			Rotate(levitation, horizonNum, (j + 3) / 2);
			for (int k = 0; k < horizonNum; k++)
				levitation[k][0] = arr[sum + k]; //밑둥 복사
		}

		////Step3 : 물고기 수 조절
		  //temp에 levitation 그대로 복사
		for (i = 0; i < squareHorizon; i++)
			for (j = 0; j < squareVertical; j++)
				temp[i][j] = levitation[i][j];
		for (; i < levitationNum; i++)
			temp[i][0] = levitation[i][0];
		//물고기 수 조절
		for (i = 0; i < squareHorizon; i++) {
			for (j = 0; j < squareVertical; j++) {
				if (j < squareVertical - 1)
					levitation[i][j] += FishControl(temp[i][j], temp[i][j + 1]);
				if (j > 0)
					levitation[i][j] += FishControl(temp[i][j], temp[i][j - 1]);
				if ((i < squareHorizon - 1) ||
					((i == squareHorizon - 1) && j == 0 && i < levitationNum - 1))
					levitation[i][j] += FishControl(temp[i][j], temp[i + 1][j]);
				if (i > 0)
					levitation[i][j] += FishControl(temp[i][j], temp[i - 1][j]);
			}
		}
		for (; i < levitationNum; i++) {
			if (i < levitationNum - 1)
				levitation[i][0] += FishControl(temp[i][0], temp[i + 1][0]);
			levitation[i][0] += FishControl(temp[i][0], temp[i - 1][0]);
		}
		for (i = 0; i < levitationNum; i++)
			delete[] temp[i];
		delete[] temp;

		////Step4 : 일렬로 되돌리기
		int tempNum = -1;
		for (i = 0; i < squareHorizon; i++)
			for (j = 0; j < squareVertical; j++)
				arr[++tempNum] = levitation[i][j];
		for (; i < levitationNum; i++)
			arr[++tempNum] = levitation[i][0];

		////Step5 : 공중부양 2번
		temp = new int* [n / 2];
		//1번째
		for (i = 0; i < n / 2; i++) {
			temp[i] = new int[4];
			temp[i][0] = arr[n / 2 + i];
			temp[i][1] = arr[n / 2 - 1 - i];
		}
		//2번째
		for (i = 0; i < n / 4; i++)
			for (j = 0; j < 2; j++)
				temp[n / 2 - 1 - i][3 - j] = temp[i][j];

		////Step6 : 일렬로 되돌리기
		for (i = 0; i < n / 4; i++)
			for (j = 0; j < 4; j++)
				arr[i * 4 + j] = temp[n / 4 + i][j];

		////Step7 : 물고기 수 조절(Step6, 7은 순서 바껴도 영향X)
		for (i = n / 4; i < n / 2; i++) {
			for (j = 0; j < 4; j++) {
				if (j < 3)
					arr[(i - n / 4) * 4 + j] += FishControl(temp[i][j], temp[i][j + 1]);
				if (j > 0)
					arr[(i - n / 4) * 4 + j] += FishControl(temp[i][j], temp[i][j - 1]);
				if (i < n / 2 - 1)
					arr[(i - n / 4) * 4 + j] += FishControl(temp[i][j], temp[i + 1][j]);
				if (i > n / 4)
					arr[(i - n / 4) * 4 + j] += FishControl(temp[i][j], temp[i - 1][j]);
			}
		}
	}
	std::cout << count - 1;
}