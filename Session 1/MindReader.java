import java.util.Scanner;

class MindReader {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		while(true) {
			int int1 = in.nextInt();
			if(int1 != -1) {
 				System.out.println(9-(int1 + in.nextInt() + in.nextInt())%9);
			} else {
				break;
			}
		}
	}
}