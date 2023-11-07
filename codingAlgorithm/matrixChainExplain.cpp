#include <iostream>
using namespace std;
/*�Է�:���ӵ� ��� A1XA2X ... X An
��, A1�� d0xd1, A2�� d1xd2, ..., An�� d(n - 1)xdn �̴�
��� : �Է��� ��� ������ �ʿ��� ���� ���� �ּ� ���� Ƚ��*/
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

		for (int L = 1 ; L < n ; L++){//L�� �κй����� ũ�⸦ "����"�ϴ� �ε����̴�.
			for (int i = 1 ; i < n ; i++){ //i�� �� �κй����� �� ���� ������ �ε���(n-L = �κй����� ����)
				int j = i + L; //j�� �κй����� �� ������ ������ �ε���
				C[i][j] = 218900;
				for (int k = i; k < j; k++) {//� �κй����� ���� ����ϸ� ���� Ƚ���� �ּ����� ã�� ����
					int	temp = C[i][k] + C[k + 1][j] + d[i - 1] * d[k] * d[j]; //����Ƚ�� ���
					if (temp < C[i][j]){
					C[i][j] = temp;
					s[i][j] = k;
				}
				}
			}
		}
	printOptimal(s, 1, n);
	cout << "\n ������ : ";
	return C[1][n];
}

int main() {
	int d0, d1, d2, d3, d4;
	cin >> d0 >> d1 >> d2 >> d3 >> d4;
	int n = 4;
	cout << matrixChain(d0, d1, d2, d3, d4, n) << endl;
	return 0;
}
