//Experiment 8 - Linear Search

#include <stdio.h>

void main() {
	int i, number[i], n, searchfor, x =0;
	printf("\nEnter number of elements: ");
	scanf("%d", &n);
	printf("\nEnter the elements: ");
	for (i = 0; i < n; i++) {
		scanf("%d", &number[i]);
	}
	printf("\nEnter element to be searched: ");
	scanf("%d", &searchfor);
	for (i = 0; i < n; i++) {
		if (number[i] == searchfor) {
			printf("\nThe element %d found at position %d",searchfor,i+1);
			x++;
			printf("\n\n");
		}
	}
	if (x == 0) {
		("Element not found");
	}
}
