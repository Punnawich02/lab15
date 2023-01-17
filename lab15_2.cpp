#include<iostream>
using namespace std;

const int N = 5;

void inputMatrix(double [][N]);

void findLocalMax(const double [][N], bool [][N]);

void showMatrix(const bool [][N]);

int main(){
	double A[N][N]; 
	bool B[N][N]; 
	cout << "Input the matrix.....\n";
	inputMatrix(A);
	findLocalMax(A,B);
	cout << "Result is \n";
	showMatrix(B);
	return 0;
}

void inputMatrix(double Mat[][N])
{
	for(int i = 0;i < N;i++)
	{
		cout << "Row " << i+1 << ": ";
		for(int j = 0; j < N;j++)
		{
			cin >> Mat[i][j];
		}
	}
}

void showMatrix(const bool Mat[][N])
{
	for(int i = 0;i < N;i++)
	{
		for(int j = 0;j < N;j++)
		{
			cout << Mat[i][j] << " ";
		}
		cout << "\n";
	}
}

void findLocalMax(const double QMat[][N], bool ansMat[][N])
{
	for(int i = 0;i <= N;i++)
	{
		for(int j = 0;j <= N;j++)
		{
			ansMat[i][j] = false;
		} 
	}
	
	for(int i = 1;i < N-1;i++)
	{
		for(int j = 1;j < N-1;j++)
		{
			if(QMat[i][j] >= QMat[i-1][j] and QMat[i][j] >= QMat[i+1][j] and QMat[i][j] >= QMat[i][j-1] and QMat[i][j] >= QMat[i][j+1])
			{
				ansMat[i][j] = true;
			}
		}
	}
}

