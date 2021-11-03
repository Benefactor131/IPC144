//==============================================
// Name:           Bair Suimaliev
// Student Number: 159350198
// Email:          bsuimaliev@myseneca.ca
// Section:        IPC
// Workshop:       4 (at-home)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// Put your code below:
#include <stdio.h>

int main(void)
{
	int days, i, high[10], low[10];
	int highest = -20, lowest = 20; 
	int highDay = -1, lowDay = -1; 
	int dayAverage = 1;
	int totalhigh = 0, totallow = 0;
	float average;
	printf("---=== IPC Temperature Calculator V2.0 ===---\n");


	printf("Please enter the number of days, between 3 and 10, inclusive: ");
	scanf("%d", &days);
	printf("\n");

	while (days < 3 || days > 10) {													//the loop checking whether the entered number of days is valid or not
		printf("Invalid entry, please enter a number between 3 and 10, inclusive: ");
		scanf("%d", &days);
		printf("\n");
	}

	for (i = 0; i < days; i++) {	//this is the loop for reading the input of tempreture from the user and defining the value of highest and lowest tempreture                                                                                                                               and on what day it occured
		printf("Day %d - High: ", i + 1);
		scanf("%d", &high[i]);
		printf("Day %d - Low: ", i + 1);
		scanf("%d", &low[i]);

		if (high[i] > highest) {
			highest = high[i];
			highDay = i + 1;
		}
		if (low[i] < lowest) {
			lowest = low[i];
			lowDay = i + 1;
		}
		
	}

	printf("\nDay  Hi  Low\n");

	for (i = 0; i < days; i++) {						//this is the loop for printing the entered values
		printf("%d %4d %5d\n", i + 1, high[i], low[i]);
	}

	printf("\nThe highest temperature was %d, on day %d\n", highest, highDay);
	printf("The lowest temperature was %d, on day %d\n", lowest, lowDay);

	while (dayAverage > 0) {		//the loop that prompts the user to input the number of days for calculating the average temperature of the days.
		printf("\nEnter a number between 1 and 5 to see the average temperature for the entered number of days, enter a negative number to exit: ");
		scanf("%d", &dayAverage);
		while ((dayAverage < 1 && dayAverage >= 0) || dayAverage > 5) //the loop for prompting the user to enter the number of days if the previous input was not																																in the range of 1-5
		{
			printf("\nInvalid entry, please enter a number between 1 and 5, inclusive: ");
			scanf("%d", &dayAverage);
		}

		

		if (dayAverage > 0) {	//the if statement which determines whether the user wants to continue or to stop the program
			for (i = 0; i < dayAverage; i++) // the loop for calculating average temperature of entered days
			{
				totalhigh += high[i];
				totallow += low[i];
				average = (float)(totalhigh + totallow) / (dayAverage * 2);
			}
			
			printf("\nThe average temperature up to day %d is: %.2f\n", i, average);
			totalhigh = 0; totallow = 0; average = 0;  //Sets the values to zero to avoid the accumulation
			continue;
		}
		else
			break;
		
	}
	

	printf("\nGoodbye!\n");

	return 0;
}