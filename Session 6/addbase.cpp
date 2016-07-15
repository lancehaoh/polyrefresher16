# include<iostream>
# include<cmath>

using namespace std;

int convert(int n,int sB,int dB) {
	int pwr = 0,sum = 0,d = 0;
	while(n > 0) {
		d = n % dB;
		n = n / dB;
		sum = sum + d * pow(sB,pwr);
		pwr = pwr + 1;
	}
	return sum;
}

int main(void) {
	int b = 0, n1 = 0, n2 = 0;
	cin >> b >> n1 >> n2;

	cout << "Enter a base b : ";
	cout << "Enter the first number : ";
	cout << "Enter the second number : ";

	cout << "The sum is : ";
	cout << convert(convert(n1,b,10) + convert(n2,b,10),10,b) << endl;
}
