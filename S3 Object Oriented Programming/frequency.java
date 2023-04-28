import java.util.*;

class frequency{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter a string: ");
		String str = sc.nextLine();
		int len = str.length();
		System.out.println("Enter a character: ");
		char a = sc.nextLine().charAt(0);
		int f = 0;
		
		for(int i  =0; i < len; i++){
			if(str.charAt(i) == a){
				f++;
			}
		}
		
		System.out.println("Frequency is: " + f);
	}
}
