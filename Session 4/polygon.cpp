# include<iostream>
# define X 0
# define Y 1
# define N (v+1)%vc
# define NN (v+2)%vc
# define d(ax,ay,bx,by,cx,cy) ax * by - ax * cy - ay * bx + ay * cx + bx * cy - by * cx

using namespace std;

int main(void) {
	int vx[10][2];
	int vc = 0;

	cin >> vc;

	for(int i = 0; i < vc; i++) {
		cin >> vx[i][X];
		cin >> vx[i][Y];
	}

	bool LEFT = false;
	bool RIGHT = false;

	for(int v = 0; v < vc; v++) {
		if(d(vx[v][X],vx[v][Y],vx[N][X],vx[N][Y],vx[NN][X],vx[NN][Y]) > 0) {
			LEFT = true;
		} else {
			RIGHT = true;
		}
	}
	cout << "Enter number of vertices: Enter vertices: " << endl;
	cout << (!(LEFT && RIGHT) ? "Yes" : "No") << endl;
}
