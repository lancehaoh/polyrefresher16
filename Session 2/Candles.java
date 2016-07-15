import java.util.Scanner;

class Candles {
	public static void main(String args[]) {
		Scanner in = new Scanner(System.in);
		int candlesNum = in.nextInt();
		int burnt = 0;
		int k = in.nextInt();
		System.out.print("Enter n and k: ");
		while(candlesNum > 0) {
			burnt += (candlesNum >= k) ? k : candlesNum;
			candlesNum = candlesNum - k + 1;

		}
		System.out.println("Total candles burnt = " + burnt);
	}
}