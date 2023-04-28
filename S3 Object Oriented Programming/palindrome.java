import java.util.*;

class palindrome{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter a string: ");
		String str = sc.nextLine();

		int len = str.length();
		int f = 0;

		for(int i = 0; i < len / 2; i++){
			if(str.charAt(i) != str.charAt(len - i - 1)){
				f = 1;
				break;
			}
		}

		System.out.println("String is" + (f == 1 ? " not palindrome" : " palindrome"));
	}
}
