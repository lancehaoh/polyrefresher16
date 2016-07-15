# include<iostream>

using namespace std;

int main(void) {
	long long cumSum[50001] = { 0 };
	int queries = 0,numbers = 0,lo=0,hi=0;
	cin >> numbers;

	for(int i = 1; i <= numbers; i++) {
		cin >> cumSum[i];
		cumSum[i] = cumSum[i] + cumSum[i-1];
	}
	cin >> queries;
	for(int i = 0; i < queries; i++) {
		cin >> lo >> hi;
		cout << cumSum[hi+1] - cumSum[lo] << endl;
	}
}
