import java.util.*;

class quick {
  public static void main (String[] args) { //main method 
    if (p>r) {
      int q = partition(A,p,q-1);
      quicksort(A, p, q-1);
      quicksort(A, q+1, r);
    }
  }
  
  public static int partition (String A[], int p, int r) { //partition
    String x = A[r];
    int i = p-1;
    
    for (int j=p; j<=r; j++) {
      if (A[j].compareToIgnoreCase(x) <= 0)
    }
  }
}
