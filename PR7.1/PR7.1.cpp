#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** r, const int rowCount, const int colCount, const int Low, const int High);
void Print(int** r, const int rowCount, const int colCount);
void Sort(int** r, const int rowCount, const int colCount);
void Change(int** r, const int col1, const int col2, const int rowCount);
void Calc(int** r, const int rowCount, const int colCount, int& S, int& k);

int main()
{
	srand((unsigned)time(NULL));

	int Low = -12;
	int High = 37;

	int rowCount = 7;
	int colCount = 9;

	int** r = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		r[i] = new int[colCount];
	Create(r, rowCount, colCount, Low, High);
	Print(r, rowCount, colCount);
	Sort(r, rowCount, colCount);
	Print(r, rowCount, colCount);

	int S = 0;
	int k = 0;
	Calc(r, rowCount, colCount, S, k);

	cout << "S = " << S << endl;
	cout << "k = " << k << endl;
	Print(r, rowCount, colCount);

	for (int i = 0; i < rowCount; i++)
		delete[] r[i];
	delete[] r;

	return 0;
}
void Create(int** r, const int rowCount, const int colCount, const int Low, const int High)
{
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			r[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** r, const int rowCount, const int colCount)
{
	cout << endl;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			cout << setw(4) << r[i][j];
		cout << endl;
	}
	cout << endl;
}

void Sort(int** r, const int rowCount, const int colCount)
{
	for (int i0 = 0; i0 < colCount - 1; i0++)
		for (int i1 = 0; i1 < colCount - i0 - 1; i1++)
			if ((r[0][i1] > r[0][i1 + 1])
				|| (r[0][i1] == r[0][i1 + 1] && r[1][i1] > r[1][i1 + 1])
				|| (r[0][i1] == r[0][i1 + 1] && r[1][i1] == r[1][i1 + 1]
					&& r[2][i1] > r[2][i1 + 1]))
				Change(r, i1, i1 + 1, rowCount);
}
void Change(int** r, const int col1, const int col2, const int rowCount)
{
	int tmp;
	for (int i = 0; i < rowCount; i++)
	{
		tmp = r[i][col1];
		r[i][col1] = r[i][col2];
		r[i][col2] = tmp;
	}
}

void Calc(int** r, const int rowCount, const int colCount, int& S, int& k)
{
	S = 0;
	k = 0;
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			if (r[i][j] > 0 || r[i][j] % 3 != 0)
			{
				S += r[i][j];
				k++;
				r[i][j] = 0;
			}
}
