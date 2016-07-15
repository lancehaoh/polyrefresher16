# include<iostream>
# include<cmath>
# include<iomanip>
# include<sstream>

using namespace std;

void build(int t[],int n) {
	for(int i = 0; i < 10; i++) {
		t[i] = 0;
	}
	if(n == 0) {
		t[0] += 4;
	}
	while(n > 0) {
		t[n%10]++;
		n /= 10;
	}
}

int smallest(int a[],int size) {
	int l = 0;
	for(int i = 0; i < size; i++) {
		if(a[i] != 0) { for(int j = 0; j < a[i]; j++) {
				l = l * 10 + i;
			}
		}
	}
	return l;
}

int largest(int a[],int size) {
	int l = 0;
	for(int i = size-1; i >= 0; i--) {
		if(a[i] != 0) {
			for(int j = 0; j < a[i]; j++) {
				l = l * 10 + i;
			}
		}
	}
	while(l < 1000) {
		l *= 10;
	}
	return l;
}

bool isVal(int a[],int s) {
	for(int i = 0; i < s; i++) {
		if(a[i] == 4) {
			return false;
		}
	}
	return true;
}

int main(void) {
	int c = 0;
	cin >> c;
	int t[10] = {0};
	int nc[10000] = { 0 };

	for(int i = 0; i < c; i++) {
		cin >> nc[i];
		//cout << nc[i] << endl;
		int ol = 0,nw = nc[i];
		stringstream buf;

		// read all digits into the table
		build(t,nw);
		if(isVal(t,10)) {
			while(true) {
				ol = nw;
				nw = largest(t,10) - smallest(t,10);
				buf << setfill('0') << setw(4) << ol;
				if(nw == ol) {
					break;
				} else {
					build(t,nw);
				}
				buf << " ";
			}
			cout << buf.str() << endl;;
		} else {
			cout << setfill('0') << setw(4) << nc[i];
			cout << " Invalid input. All four digits are the same" << endl;
		}
	}
}
