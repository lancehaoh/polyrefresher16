# include<iostream>

using namespace std;

int solve(int x,int y) {
	if(x == 0 || y == 0) {
		return 1;
	} else {
		return solve(x-1,y) + solve(x,y-1);
	}
}

int main(void) {
	int N = 0, E = 0;
	cin >> N >> E;
	cout << "Enter rows and columns apart: Rows and columns apart: " << N << " " << E << endl;
	int ans = solve(N,E);
	cout << "Number of NE-paths = " << ans << endl;
}
