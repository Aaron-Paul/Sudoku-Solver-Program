// A recursive program in C++ to solve Sudoku problem
#include <bits/stdc++.h>
using namespace std;

// UNASSIGNED or zero is used for empty cells in sudoku grid
#define UNASSIGNED 0

// N is used for the size of Sudoku grid.
// Size will be NxN
#define N 9

bool isSafe(int grid[N][N])
{
	unordered_map<int, int>
		row_[9], column_[9], box[3][3];
	for (int row = 0; row < N; row++) {
		for (int col = 0; col < N; col++)
        {
			row_[row][grid[row][col]] += 1;
			column_[col][grid[row][col]] += 1;
			box[row / 3][col / 3][grid[row][col]] += 1;

			if ( box[row / 3][col / 3][grid[row][col]] > 1 || column_[col][grid[row][col]] > 1 || row_[row][grid[row][col]] > 1)
				return false;
		}
	}
	return true;
}
void printGrid(int grid[N][N])
{
	for (int row = 0; row < N; row++) {
		for (int col = 0; col < N; col++)
			cout << grid[row][col] << " ";
		cout << endl;
	}
}

bool SolveSudoku( int grid[N][N], int i, int j)
{
	if (i == N - 1 && j == N)
    {

		if (isSafe(grid))
        {
			printGrid(grid);
			return true;
		}
		return false;
	}
	if (j == N) {
		i++;
		j = 0;
	}
	if (grid[i][j] != UNASSIGNED)
		return SolveSudoku(grid, i, j + 1);

	for (int num = 1; num <= 9; num++)
    {
		grid[i][j] = num;

		if (SolveSudoku(grid, i, j + 1))
			return true;

		grid[i][j] = 0;
	}
	return false;
}
int main()
{
	// 0 means unassigned cells or you can write UNASSIGNED directly instead of 0
	int grid[N][N] = { { 3, 1, 6, 5, 7, 8, 4, 9, 2 }, 
                       { 5, 2, 9, 1, 3, 4, 7, 6, 8 }, 
                       { 4, 8, 7, 6, 2, 9, 5, 3, 1 }, 
                       { 2, 6, 3, 0, 1, 5, 9, 8, 7 }, 
                       { 9, 7, 4, 8, 6, 0, 1, 2, 5 }, 
                       { 8, 5, 1, 7, 9, 2, 6, 4, 3 }, 
                       { 1, 3, 8, 0, 4, 7, 2, 0, 6 }, 
                       { 6, 9, 2, 3, 5, 1, 8, 7, 4 }, 
                       { 7, 4, 5, 0, 8, 6, 3, 1, 0 } };
	if (SolveSudoku(grid, 0, 0) != true)
		cout << "No solution exists";
	return 0;
}
