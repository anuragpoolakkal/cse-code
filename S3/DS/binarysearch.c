// Experiment 9 - Binary Search 

#include <stdio.h>
int first, last, key;
int arr[10];
void binarysearch(int arr[], int first, int last, int key);

void main() {
	int n, i, j, t;
	printf("\nEnter the number of elements: ");
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		printf("\nEnter element %d: ", i+1);
		scanf("%d", &arr[i]);
	}
	for (i = 0; i < n-1; i++) {
		for (j = 0; j < n-1-i; j++) {
			if (arr[j] > arr[j+1]) {
				t = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = t;
			}
		}
	}
	printf("\nEnter key: ");
	scanf("%d", &key);
	binarysearch(arr, 0, n-1, key);
}

void binarysearch(int arr[], int first, int last,int key) {
	int mid = (first + last) / 2;
	if (last >= first) {
		if (key == arr[mid]) {
			printf("\nElement found at %d", mid);
			return;
		} else if (key > arr[mid]) {
			first = mid + 1;
			binarysearch(arr, first, last, key);
		} else {
			last = mid - 1;
			binarysearch(arr, first, last, key);
		}
		printf("\n");
	} else {
		printf("Element not found \n");
	}
}
