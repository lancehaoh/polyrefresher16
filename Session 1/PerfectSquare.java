import java.util.Scanner;

class PerfectSquare {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int num = 0;
		boolean[] sieve = new boolean[9999999];

		for(int i = 0; i < sieve.length; i++) {
			sieve[i] = false;
		}
		sieve[0] = true;
		sieve[1] = true;

		generateSieve(sieve);
		in.nextInt();

		while(in.hasNextInt()) {
			num = in.nextInt();
			System.out.println(num + (sieve[num] ? " is a " : " is not a ") + "perfect square.");
		}
	}

	public static void generateSieve(boolean[] sieve) {
		for(int i = 2; i < sieve.length; i++) {
			int curNum = i;
			while(true) {
				if(curNum <= Math.pow(2,15)) {
					curNum *= curNum;
				} else {
					break;
				}
				if(curNum < sieve.length) {
					sieve[curNum] = true;
				} else {
					break;
				}
			}
		}
	}
}
