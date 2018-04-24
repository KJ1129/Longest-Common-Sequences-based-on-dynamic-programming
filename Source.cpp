#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
int max(int a, int b);

int main(){

	char x[30] = { 0 };
	char y[30]  = { 0 };
	int row, col;  //row->x  col->y
	char *LCS = { 0 };
	int **L ;
	int LCS_len=0;
	cout << "Please input the first sequence: " << endl;
	cin >> x;
	cout << endl;
	cout << "Please input the second sequence: " << endl;
	cin >> y;
	cout << endl;
	
	for (int i = 0; i < 30; i++){
		if (x[i] == 0){
			row = i ;
			break;
		}
	}
	for (int i = 0; i < 30; i++){
		if (y[i] == 0){
			col = i ;
			break;
		}
	}

	L = new int *[row+1]; //°t¸m¤Gºû°ÊºA°}¦C
	for (int i = 0; i < row+1; i++){
		L[i] = new int[col+1];
	}

	for (int i = 0; i < row+1; i++){
		for (int j = 0; j < col+1; j++){
			if (i == 0 || j == 0)
				L[i][j] = 0;

			else if (x[i - 1] == y[j - 1])
				L[i][j] = L[i - 1][j - 1] + 1;

			else
				L[i][j] = max(L[i - 1][j], L[i][j - 1]);
		}
	}

	for (int i = 0; i < row + 1; i++){
		for (int j = 0; j < col + 1; j++){
			cout << L[i][j] << "  ";
		}
		cout << endl;
	}
	cout << endl << endl;

	LCS_len = L[row][col];

	LCS = new char [LCS_len];
	while (row > 0 && col > 0){
		if (x[row - 1] == y[col - 1]){
			LCS[LCS_len-1] = x[row - 1];
			LCS_len = LCS_len - 1;
			row = row - 1;
			col = col - 1;
		}
		else if (L[row - 1][col] > L[row][col - 1])
			row = row - 1;
		else
			col = col - 1;	
	}
	
	cout << "The LCS of the two sequences is : " << endl;
	cout << LCS;

	cout << endl;

	system("pause");
	return 0;
}

int max(int a, int b){
	if (a>b){
		return a;
	}
	else{
		return b;
	}
}


