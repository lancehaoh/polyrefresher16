import java.util.Scanner;

class BMI {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		while(in.hasNext()) {
			int gender = in.nextInt();
			double weight = in.nextDouble();
			double height = in.nextDouble();
			double bmi = weight/Math.pow(height,2);
			if(gender == 1) {
				chkM(bmi);
			} else {
				chkF(bmi);
			}
		}
	}

	public static void chkF(double bmi) {
		if(bmi <= 19) {
			System.out.println("You are underweight. Stuff yourself with more food!");
		} else if(bmi > 19 && bmi <= 24) {
			System.out.println("Your weight is perfect. Maintain it!");
		} else {
			System.out.println("You are overweight, time to join the gym!");
		}
	}

	public static void chkM(double bmi) {
		if(bmi <= 20) {
			System.out.println("You are underweight. Stuff yourself with more food!");
		} else if(bmi > 20 && bmi <= 25) {
			System.out.println("Your weight is perfect. Maintain it!");
		} else {
			System.out.println("You are overweight, time to join the gym!");
		}
	}
}