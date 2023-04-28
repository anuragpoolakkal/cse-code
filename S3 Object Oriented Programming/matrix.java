import java.util.*;

class matrix{
	public static void main(String[] args){
		int r1, r2, c1, c2;
	
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the number of rows in the first matrix: ");
		r1 = sc.nextInt();
		System.out.println("Enter the number of columns in the first matrix: ");
		c1 = sc.nextInt();
		System.out.println("Enter the number of rows in the second matrix: ");
		r2 = sc.nextInt();
		System.out.println("Enter the number of columns in the second matrix: ");
		c2 = sc.nextInt();
	
		if(c1 != r2){
			System.out.println("Matrix multiplication is not possible");
			return;
		}

		int a[][] = new int[r1][c1];
		int b[][] = new int[r2][c2];
		int c[][] = new int[r1][c2];
		
		System.out.println("Enter the values for matrix a: ");

		for(int i = 0; i < r1; i++){
			for(int j = 0; j < c1; j++){
				a[i][j] = sc.nextInt();
			}
		}

		System.out.println("Enter the values for matrix b: ");
		for(int i = 0; i < r2; i++){
			for(int j = 0; j < c2; j++){
		 		b[i][j] = sc.nextInt();		
			}
		}
		
		System.out.println("Product Matrix is: ");
		for(int i = 0; i < r1; i++){
			for(int j = 0; j < c2; j++){
				c[i][j] = 0;
				for(int k = 0; k < c2; k++){
					
					c[i][j] += a[i][k] * b[k][j];
				}
				System.out.print(c[i][j] + " ");
			}
		}
	}
}





