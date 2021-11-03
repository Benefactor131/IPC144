//==============================================
// Name:           Bair Suimaliev
// Student Number: 159350198
// Email:          bsuimaliev@myseneca.ca
// Section:        IPC144
// Workshop:       3 (at-home)
//==============================================

#define _CRT_SECURE_NO_WARNINGS
#define NUMS 4
#include <stdio.h>
// Put your code below:

int main(void)
{

	int high = 0, low = 0, i;
	int highest = -41, lowest = 41;
	int totalhigh = 0, totallow = 0;
	int highDay = -1, lowDay = -1;
	double average, average_low, average_high;

	printf("---=== IPC Temperature Analyzer ===---\n");

	for (i = 0; i < NUMS; i++)
	{
		printf("Enter the high value for day %d: ", i + 1);
		scanf("%d", &high);
		printf("\n");
		printf("Enter the low value for day %d: ", i + 1);
		scanf("%d", &low);
		printf("\n");

		while (high < low  || high > 40  || low < -40)
		{
			printf("Incorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n");
			printf("\nEnter the high value for day %d: ", i + 1);
			scanf("%d", &high);
			printf("\nEnter the low value for day %d: ", i + 1);
			scanf("%d", &low);
			printf("\n");
			break;
		}

		if (high > highest)
		{
			highest = high;
			highDay = i + 1;
		}
		if (low < lowest)
		{
			lowest = low;
			lowDay = i + 1;
		}
		
		totalhigh = totalhigh + high;
		totallow = totallow + low;
	
	}

	average = (float)(totalhigh + totallow)/ (NUMS*2);
	average_high = (float)totalhigh/(NUMS);
	average_low = (float)totallow/(NUMS);
	printf("The average (mean) LOW temperature was: %.2lf\n", average_low);
	printf("The average (mean) HIGH temperature was: %.2lf\n", average_high);
	printf("The average (mean) temperature was: %.2lf\n", average);
	printf("The highest temperature was %d on day %d\n", highest, highDay);
	printf("The lowest temperature was %d on day %d", lowest, lowDay);

	return 0;
}