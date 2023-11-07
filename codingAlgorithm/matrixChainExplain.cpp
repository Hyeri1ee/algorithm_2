#include <iostream>
using namespace std;
/*입력:연속된 행렬 A1XA2X ... X An
단, A1은 d0xd1, A2는 d1xd2, ..., An은 d(n - 1)xdn 이다
출력 : 입력의 행렬 곱셈에 필요한 원소 간의 최소 곱셈 횟수*/
void printOptimal(int s[5][5], int i, int j) {
	if (i == j) {

		cout << "A" << i<<" " ;
	}
	else {
		cout << "(";
		printOptimal(s, i, s[i][j]);
		printOptimal(s, s[i][j] + 1, j);
		cout << ")";
	}
}
int matrixChain(int d0, int d1, int d2, int d3, int d4, int n)
{
	int d[5] = { d0,d1,d2,d3,d4 };
	int C[5][5];
	int s[5][5];
	for (int i1 = 1; i1 <= n; i1++)
		C[i1][i1] = 0;

		for (int L = 1 ; L < n ; L++){//L은 부분문제의 크기를 "조절"하는 인덱스이다.
			for (int i = 1 ; i < n ; i++){ //i는 각 부분문제의 맨 왼쪽 원소의 인덱스(n-L = 부분문제의 갯수)
				int j = i + L; //j는 부분문제의 맨 오른쪽 원소의 인덱스
				C[i][j] = 218900;
				for (int k = i; k < j; k++) {//어떤 부분문제를 먼저 계산하면 곱셈 횟수가 최소인지 찾는 과정
					int	temp = C[i][k] + C[k + 1][j] + d[i - 1] * d[k] * d[j]; //곱셈횟수 계산
					if (temp < C[i][j]){
					C[i][j] = temp;
					s[i][j] = k;
				}
				}
			}
		}
	printOptimal(s, 1, n);
	cout << "\n 최적해 : ";
	return C[1][n];
}

int main() {
	int d0, d1, d2, d3, d4;
	cin >> d0 >> d1 >> d2 >> d3 >> d4;
	int n = 4;
	cout << matrixChain(d0, d1, d2, d3, d4, n) << endl;
	return 0;
}
