# include<iostream>
# include<algorithm>

using namespace std;

int unique(int sorted[],int sSize) {
	int duplicates = 0, buf = 0;
	int buffer[100] = { 0 };
	for(int i = 0; i < sSize; i++) {
		buffer[buf] = sorted[i];
		if(buf >= 1 && buffer[buf-1] == buffer[buf]) {
			duplicates++;
		} else {
			buf++;
		}
	}
	for(int i = 0; i < buf; i++) {
		sorted[i] = buffer[i];
	}
	return buf;
}

void printArr(int arr[],int size) {
	for(int i = 0; i < size-1; i++) {
		cout << arr[i] << " ";
	}
	cout << arr[size-1] << endl;
}

int * add(int set1[],int set2[],int set1Size,int set2Size) {
	int s1 = 0,s2 = 0,s3 = 0;
	static int set3[201] = { 0 };
	while(s1 < set1Size && s2 < set2Size) {
		set3[s3++] = (set1[s1] >= set2[s2]) ? set2[s2++] : set1[s1++];
		if(s3 - 1 >= 1 && set3[s3-1] == set3[s3-2]) {
			s3--;
		}
	}
	while(s1 < set1Size) {
		set3[s3++] = set1[s1++];
		if(s3 - 1 >= 1 && set3[s3-1] == set3[s3-2]) {
			s3--;
		}
	}
	while(s2 < set2Size) {
		set3[s3++] = set2[s2++];
		if(s3 - 1 >= 1 && set3[s3-1] == set3[s3-2]) {
			s3--;
		}
	}
	set3[200] = s3;
	return set3;
}

int *  diff(int set1[],int set2[],int set1Size,int set2Size) {
	int s1 = 0,s2 = 0,s3 = 0;
	static int set3[201] = { 0 };
	for(int i = 0; i < set1Size; i++) {
		if(!binary_search(set2,set2+set2Size,set1[i])) {
			set3[s3++] = set1[i];
		}
	}
	set3[200] = s3;
	return set3;
}

void intersection(int set1[],int set2[],int set1Size,int set2Size) {
	int * addArr = add(set1,set2,set1Size,set2Size);
	int s1 = 0,s2 = 0,s3 = 0;
	int set3[200] = { 0 };
	while(s1 < set1Size && s2 < set2Size) {
		if(set1[s1] == set2[s2]) {
			set3[s3++] = set1[s1];
			s1++;
			s2++;
		} else if(set1[s1] > set2[s2]) {
			s2++;
		} else {
			s1++;
		}
	}
	printArr(set3,s3);
}

void solve(int s1[],int s2[],int s1Size,int s2Size,char sign) {
	int * arr = NULL;
	switch(sign) {
		case '+':
			arr = add(s1,s2,s1Size,s2Size);
			printArr(arr,*(arr+200));
			break;
		case '-':
			arr = diff(s1,s2,s1Size,s2Size);
			printArr(arr,*(arr+200));
			break;
		case '*':
			intersection(s1,s2,s1Size,s2Size);
			break;
	}
}

int main(void) {
	int set1[100] = { 0 };
	int set2[100] = { 0 };
	int copySize = 0,set1Size = 0, set2Size = 0, tmp = 0;
	char sign = '\0';

	while(true) {
		cin >> tmp;
		if(tmp == -1) {
			break;
		} else {
			set1[set1Size++] = tmp;
		}
	}
	while(true) {
		cin >> tmp;
		if(tmp == -1) {
			break;
		} else {
			set2[set2Size++] = tmp;
		}
	}

	sort(set1,set1+set1Size);
	sort(set2,set2+set2Size);

	set1Size = unique(set1,set1Size);
	set2Size = unique(set2,set2Size);

	cin >> sign;
	solve(set1,set2,set1Size,set2Size,sign);
}
