import java.util.ArrayList;
import java.util.Scanner;

class UpSlopes {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		ArrayList<Double> slopes = new ArrayList<Double>();
		double cur = 0;
		System.out.println("Enter data:");
		while((cur = in.nextDouble()) >= 0) {
			slopes.add(cur);
		}
		//System.out.println(slopes);

		boolean isSlope = false;
		long numOfSlopes = 0;

		for(int i = 1; i < slopes.size(); i++) {
			if(slopes.get(i) > slopes.get(i-1)) {
				isSlope = true;
			} else if (isSlope) {
				isSlope = false;
				numOfSlopes++;
			}
		}
		System.out.println("Number of up-slopes = " + (isSlope ? numOfSlopes + 1 : numOfSlopes));
	}
}