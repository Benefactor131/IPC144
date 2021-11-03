//==============================================
// Name:           Bair Suimaliev
// Student Number: #159350198
// Email:          bsuimaliev@myseneca.ca
// Section:        IPC144
// Workshop:       2 (in-lab)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// Start your code below:
#include<stdio.h>

int main(void)
{
	double amount = 8.68;
	printf("Please enter the amount to be paid: $");
	scanf("%lf", &amount);
	
	int loonies;
	loonies = amount;
	float balance;
	balance = amount - loonies;
	printf("Loonies required: %d, balance owing $%.2f\n", loonies, balance);
	
	int quarters;
	quarters = balance / 0.25;
	float balance_remaining;
	balance_remaining = balance - (quarters * 0.25);
	printf("Quarters required: %d, balance owing $%.2f\n", quarters, balance_remaining);
	return 0;
}