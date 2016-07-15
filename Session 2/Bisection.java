import java.util.Scanner;

class Bisection {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int x3 = in.nextInt(), x2 = in.nextInt(), x = in.nextInt(), c = in.nextInt();
		double A = in.nextDouble(), B = in.nextDouble(), midpoint = 0;
		final double LIMIT = 0.0001;

		// While Math.abs(A-B) is within limit
		while(Math.abs(A-B) >= LIMIT) {
			// Find midpoint
			midpoint = midpoint(A,B);
			// Compute p(A)
			double pA = p(A,x3,x2,x,c);
			// Compute p(B)
			double pB = p(B,x3,x2,x,c);
			// Compute p(midpoint)
			double pM = p(midpoint,x3,x2,x,c);
			if(pM == 0) {
				break;
			}
			// Replace A or B depending on whether their sign is same as midpoint
			if(signIsEqual(pA,pM)) {
				A = midpoint;
			} else {
				B = midpoint;
			}
		}
		midpoint = midpoint(A,B);
		System.out.format("Enter coefficients (c3,c2,c1,c0) of polynomial: Enter endpoints a and b: root = %.6f\n",midpoint);
		System.out.format("p(root) = %.6f\n",p(midpoint,x3,x2,x,c));
	}

	// Helper Function to compute value of polynomial
	public static double p(double valOfX,int x3,int x2,int x,int c) {
		return x3 * Math.pow(valOfX,3) + x2 * Math.pow(valOfX,2) + x * valOfX + c; 
	}

	// Function to compute midpoint
	public static double midpoint(double A,double B) {
		return (A + B)/2;
	}

	// Function to check equality of sign
	public static boolean signIsEqual(double X,double Y) {
		return Math.signum(X) == Math.signum(Y);
	}
}