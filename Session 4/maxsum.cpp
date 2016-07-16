# include<iostream>
# include<cmath>

using namespace std;

int main(void) {
	int grid[10][55];
	int sol[10][55];
	int rows = 0;

	cin >> rows;

	for(int i = 0; i < rows; i++) {
		for(int j = 0; j <= i; j++) {
			cin >> grid[i][j];
			sol[i][j] = grid[i][j];
		}
	}

	for(int i = rows-1; i >= 1; i--) {
		for(int j = 0; j <= i; j++) {
			sol[i-1][j] += max(sol[i][j],sol[i][j+1]);
		}
	}
	cout << "Enter number of rows: Enter values for array: " << endl;
	cout << "Maximum path value = " << sol[0][0] << endl;
}
