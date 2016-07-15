# include<iostream>
# include<cmath>

using namespace std;

int convert(int n,int sB) {
	int pwr = 0,sum = 0,d = 0;
	while(n > 0) {
		d = n % 10;
		n = n / 10;
		sum = sum + d * pow(sB,pwr);
		pwr = pwr + 1;
	}
	return sum;
}

int getBase(int num) {
	int base = 0;
	while(num > 0) {
		base = max(base,num % 10);
		num /= 10;
	}
	return base+1;
}

int main(void) {
	int b = 0, n = 0;
	cin >> b >> n;
	int base = getBase(n);

	cout << "Enter a base b : ";
	cout << "Enter a base-b number : ";

	if(base <= b) {
		cout << "The corresponding base-10 number is : " << convert(n,b) << endl;
	} else {
		cout << "Error!! " << n << " is not a number of base " << b << "." << endl;
	}
}
