# include<iostream>
using namespace std;

int daypresents(int day) {
	if(day == 1) {
		return 1;
	} else {
		return day + daypresents(day-1);
	}
}

int cumSum(int day) {
	if(day == 1) {
		return 1;
	} else {
		return daypresents(day) + cumSum(day-1);
	}
}

int main(void) {
	int num = 0;
	cin >> num;
	string str = (num > 1) ? "days" : "day";
	cout << "Please enter the number of days: You have entered the number of days as: " << num << endl;
	cout << "The number of presents received in " << num << " " << str << " is ";
	cout << cumSum(num) << "." << endl;
}
