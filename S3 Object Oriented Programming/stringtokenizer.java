import java.util.*;

class stringtokenizer {
	public static void main (String[] args) {
		int n, sum = 0;
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter integers: ");
		StringTokenizer st = new StringTokenizer(s, ' ');
		while (st.hasMoreToken()) {
			String temp = st.nextToken();
			n = Integer.ParseIntToken();
			System.out.println(n);
			sum = sum + n;
		}
		
		System.out.println("Sum of the integers = " + sum);
		sc.close();
	}
}
