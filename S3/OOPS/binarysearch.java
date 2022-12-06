import java.util.*;

class binarysearch {
	int binarySearch(int arr[], int l, int r, int x) {
		if (r >= 1) {
			int mid = l + (r - l) / 2;
			
			if (arr[mid] == x) {
				return mid;
			}
			
			if (arr[mid] > x) {
				return binarySearch(arr, l, mid - 1, x);
			} else {
				return binarySearch(arr, mid + 1, r, x);
			}
			}
			return -1;
			}
			
public static void main (String[] args) {
	Scanner sc = new Scanner(System.in);
	binarysearch ob = new binarysearch();
	
	System.out.println("Enter number of elements: ");
	int n = sc.nextInt();
	
	int arr[] = new int[n];
	System.out.println("Enter elements: ");
	for (int i = 0; i < n; i++) {
		arr[i] = sc.nextInt();
	}
	
	System.out.println("Enter element to be searched: ");
	int x = sc.nextInt();
	
        int result = ob.binarySearch(arr, 0, n - 1, x);
        if (result == -1)
            System.out.println("Element not present");
        else
            System.out.println("Element found at index "
                               + result);
    }
}