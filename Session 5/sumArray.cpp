# include<iostream>

using namespace std;

long sum(int arr[],int lo,int hi) {
	if(lo == hi) {
		return arr[lo];
	} else {
		return arr[lo] + sum(arr,lo+1,hi);
	}
}

int main(void) {
	int eNum = 0;
	int arr[10];
	cin >> eNum;
	cout << "Enter number of elements: Enter " << eNum << " values: Array read: ";
	for(int i = 0; i < eNum; i++) {
		cin >> arr[i];
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << "Sum = " << sum(arr,0,eNum-1) << endl;
}
