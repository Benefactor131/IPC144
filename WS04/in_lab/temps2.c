//==============================================
// Name:           Bair Suimaliev
// Student Number: 159350198
// Email:          bsuimaliev@myseneca.ca
// Section:        IPC
// Workshop:       4 (in-lab)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// Put your code below:
#include <stdio.h>

int main(void)
{
	int days, i, high[10], low[10];									
	printf("---=== IPC Temperature Calculator V2.0 ===---\n");

	
	printf("Please enter the number of days, between 3 and 10, inclusive: ");
	scanf("%d", &days);
	printf("\n");

	while (days < 3 || days > 10) {													//the loop checking whether the entered number of days is valid or not
		printf("Invalid entry, please enter a number between 3 and 10, inclusive: ");
		scanf("%d", &days);
		printf("\n");
	}

	for (i = 0; i < days; i++) {			//this is the loop for reading the input of tempreture from the user
		printf("Day %d - High: ", i + 1);
		scanf("%d", &high[i]);
		printf("Day %d - Low: ", i + 1);
		scanf("%d", &low[i]);
	}	

	printf("\nDay  Hi  Low\n");
	for (i = 0; i < days; i++) {						//this is the loop for printing the entered values
		printf("%d %4d %5d\n", i + 1, high[i], low[i]);
	}

	return 0;
}