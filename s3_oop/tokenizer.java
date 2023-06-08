import java.util.*;

class tokenizer{
	public static void main(String[] args){
		int n;
		int sum = 0;
		
		Scanner sc = new Scanner(System.in);
		
		System.out.println("Enter integers: ");
			
		String str = sc.nextLine();		
		StringTokenizer st = new StringTokenizer(str, " ");
			
		while(st.hasMoreTokens()){
			String temp = st.nextToken();
			n = Integer.parseInt(temp);
			System.out.println(n);
			sum += n;
		}
		
		System.out.println("Sum of integers: " + sum);
		sc.close();
	}
}
