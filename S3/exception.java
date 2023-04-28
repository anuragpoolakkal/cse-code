import java.util.*;

class exception
{
	public static void main(String[] args){
		Scanner s= new Scanner(System.in);
 		
 		try{
 		try{
 			System.out.println("Enter two integers to divide");
 			int x= s.nextInt();
 			int y= s.nextInt();
 			int data= x / y;
 			System.out.println("Quotient is " + data);
 		}
 		catch(ArithmeticException e){
 			System.out.println(e);
 		}
 		
 		try{
 			int a[]=new int[5];
 			a[5]=4;
 		}
 		catch(ArrayIndexOutOfBoundsException e)
 		{
 			System.out.println(e);
 		}
 		
 		}catch(Exception e){
 			System.out.println("Exception handled!");
 		}
 		finally{
 			System.out.println("Finally block is executed");
 		}
	}
}
