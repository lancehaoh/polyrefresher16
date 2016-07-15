import java.util.ArrayList;
import java.util.Scanner;

class Rotated {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		ArrayList<Integer> arr = new ArrayList<Integer>();
		int searchVal = 0;
		while(in.hasNextInt()) {
			arr.add(in.nextInt());
		}

		int[] sA = new int[arr.size() - 1];

		for(int i = 0; i < arr.size()-1; i++) {
			sA[i] = arr.get(i);
		}
		searchVal = arr.remove(arr.size()-1);
		int ans = search(sA,searchVal);
		System.out.println("Enter data:");
		System.out.println(ans == -1 ? "Not found" : ans);
	}

	public static int search(int[] arr,int key) {
		int lo = 0;
		int hi = arr.length-1;

		// Search in sorted halves
		while(lo <= hi) {
			int mid = (lo + hi)/2 + 1;
			if(arr[mid] == key) {
				return mid;
			} else if(arr[hi] >= arr[mid]) {
				// right  helf is sorted
				if(key >= arr[mid] && key <= arr[hi]) {
					// key is within right half
					return binSearch(arr,mid,hi,key);
				} else {
					hi = mid - 1;
				}
			} else {
				// left half is sorted
				if(key >= arr[lo] && key <= arr[mid-1]) {
					// key is within left half
					return binSearch(arr,lo,mid-1,key);
				} else {
					lo = mid;
				}
			}
		}
		return -1;
	}

	public static int binSearch(int[] arr,int lo,int hi,int val) {
		while(lo <= hi) {
			int mid = (lo+hi)/2;
			if(arr[mid] == val) {
				return mid;
			} else if(arr[mid] < val) {
				lo = mid + 1;
			} else {
				hi = mid  - 1; }
		}
		return -1;
	}
}
