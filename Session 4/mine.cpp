# include<iostream>

using namespace std;

void addMines(int f[30][30],char f2[30][30],int rows,int cols,int x,int y) {
	for(int row = x-1; row <= x+1 && row < rows; row++) {
		for(int col = y-1; col <= y+1 && col < cols; col++) {
			if(row >= 0 && col >= 0 && !(row == x && col == y)) {
					if(f2[row][col] != '*') {
						f[row][col]++;
					}
			}
		}
	}
}

int main(void) {
	int count[16][30] = { 0 };
	char field[16][30] = { 0 };
	int lvl = 0,rows = 0,cols = 0;

	cin >> lvl;
	switch(lvl) {
		case 1:
			rows = 8;
			cols = 8;
			break;
		case 2:
			rows = 12;
			cols = 16;
			break;
		case 3:
			rows = 16;
			cols = 30;
	}

	for(int row = 0; row < rows; row++) {
		for(int col = 0; col < cols; col++) {
			cin >> field[row][col];
			//cout << field[row][col];
		}
		//cout << endl;
	}

	for(int row = 0; row < rows; row++) {
		for(int col = 0; col < cols; col++) {
			//cout << "current cell: (" << row << "," << col << ")" << endl;
			if(field[row][col] == '*') {
				//cout << "Cell is mined" << endl;
				addMines(count,field,rows,cols,row,col);
				count[row][col] = 9;
			}
		}
	}
	for(int row = 0; row < rows; row++) {
		int col = 0;
		for(col = 0; col < cols - 1; col++) {
			cout << " " << count[row][col];
		}
		cout << " " << count[row][col] << endl;
	}
}
