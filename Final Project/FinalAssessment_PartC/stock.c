//==============================================
// Group member #1:	Bair Suimaliev		
// Group member #2:	Elvis Kwan
// Group member #3:	Max Ratajczak
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "stock.h"

//auxilary functions

//auxilary function 1 - Clear top sellers products in topSellers structure
void clearProducts(struct SalesRecord* topSellers, int num) {
	int i;

	for (i = 0; i < num; i++)
	{
		*topSellers[i].productName = 0;
		topSellers[i].quantity = 0.00;
	}
}

//auxilary function 2 - Print top sellers header
void printTopProductsHeader(int category) {
	if (category == 0)
		centreText(48, '-', "Top 3 sellers in produce");

	else if (category == 1)
		centreText(48, '-', "Top 3 sellers in meat");

	else if (category == 2)
		centreText(48, '-', "Top 3 sellers in dairy");

	else if (category == 3)
		centreText(48, '-', "Top 3 sellers in bakery");

	else if (category == 4)
		centreText(48, '-', "Top 3 sellers in baking");

	else if (category == 5)
		centreText(48, '-', "Top 2 sellers in house wares");

	else if (category == 6)
		centreText(48, '-', "Top 2 sellers in miscellaneous");
}

//main functions

//function 1 - call the file for the inputs
int readStockItems(struct StockRecord* stock, int max_stock, int stock_stdin)
{
	FILE* fp = stock_stdin;
	int qnt, cat, byweight, i = 0, keepgoing = 1, stop = 0;
	double price;
	char name[20];
	fp = fopen("data.txt", "r");
	if (fp == NULL)
	{
		printf("Error opening file\n");
		exit(1);
	}
	while (fscanf(fp, "%d%*c%d%*c%lf%*c%d%*c%[^\n]%*c", &qnt, &cat, &price, &byweight, &name) != EOF && stop == 0)
	{
		if (qnt == 0)
		{
			stop = 1;
		}
		printf("%d,%d,%.2lf,%d,%s\n", qnt, cat, price, byweight, name);
		//stock[i].name = name;
		strcpy(stock[i].name, name);
		stock[i].product.amount = qnt;
		stock[i].product.price = price;
		stock[i].product.category = cat;
		stock[i].product.byWeight = byweight;
		if (cat < 1 || cat > 7)
		{
			printf("Invalid Category - Enter a number between 1 and 7: \n");
			keepgoing = 0;
		}
		if (byweight != 1 && byweight != 0)
		{
			printf("Invalid soldByWeight - Enter a number between 0 and 1: \n");
			keepgoing = 0;
		}
		if (keepgoing)
		{
			i++;
		}
		keepgoing = 1;
	}
	fclose(fp);

	return i;
}


//function 2 - Display the header and "="
void centreText(int x, char y, char message[30])
{
	int i, len, half, rest = 0;
	len = strlen(message);
	half = (x - len) / 2;
	rest = (x - len) % 2;
	//printf("%d %d", half, rest);
	for (i = 0; i < half; i++)
	{
		printf("%c", y);
	}
	printf("%s", message);
	for (i = 0; i < half; i++)
	{
		printf("%c", y);
	}
	if (rest == 1) {
		printf("%c", y);
	}
}

//function 3 - Display the Stock Record
void printStockReport(struct StockRecord* stock, int num_stock)
{
	int i;

	printf("  ID                        Product        Category   Price Quantity\n");
	for (i = 0; i < num_stock; i++)
	{
		if (stock[i].product.category == 1)
			printf("%4d %30s %15s %7.2f %8d\n", i + 1, stock[i].name, "produce", stock[i].product.price, stock[i].product.amount);

		else if (stock[i].product.category == 2)
			printf("%4d %30s %15s %7.2f %8d\n", i + 1, stock[i].name, "meat", stock[i].product.price, stock[i].product.amount);

		else if (stock[i].product.category == 3)
			printf("%4d %30s %15s %7.2f %8d\n", i + 1, stock[i].name, "dairy", stock[i].product.price, stock[i].product.amount);

		else if (stock[i].product.category == 4)
			printf("%4d %30s %15s %7.2f %8d\n", i + 1, stock[i].name, "bakery", stock[i].product.price, stock[i].product.amount);

		else if (stock[i].product.category == 5)
			printf("%4d %30s %15s %7.2f %8d\n", i + 1, stock[i].name, "baking", stock[i].product.price, stock[i].product.amount);

		else if (stock[i].product.category == 6)
			printf("%4d %30s %15s %7.2f %8d\n", i + 1, stock[i].name, "house wares", stock[i].product.price, stock[i].product.amount);

		else if (stock[i].product.category == 7)
			printf("%4d %30s %15s %7.2f %8d\n", i + 1, stock[i].name, "miscellaneous", stock[i].product.price, stock[i].product.amount);

	}
}

//function 4 - Checks if there is a sale for a product
int readSale(struct StockRecord* inventory, int numStockItems, struct SalesRecord* billItems)
{
	int count = 0, id = 0;
	double quantity = 0.0;
	int keepgoing = 1;

	while (keepgoing == 1)
	{
		printf("Enter a product ID to purchase, and the quantity (0 to stop): ");
		scanf("%d%*c", &billItems[count].id);
		if (billItems[count].id == 0) break;
		else
		{
			scanf("%lf", &billItems[count].quantity);
		}


		//Error Catch - If id OR quantity is invalid
		while ((billItems[count].id < 0 || billItems[count].id > numStockItems) || (billItems[count].quantity < 0.10 || billItems[count].quantity > 100))
		{
			//If id is invalid
			if (billItems[count].id < 0 || billItems[count].id > numStockItems)
			{
				printf("Invalid Product - Enter a number between 0 and %d: ", numStockItems);
				scanf("%d%*c%lf", &billItems[count].id, &billItems[count].quantity);
			}

			//If quantity is invalid
			else if (billItems[count].quantity < 0.10 || billItems[count].quantity > 100)
			{
				printf("Invalid quantity - Enter a number between 0.10 and 100.00: ");
				scanf("%d%*c%lf", &billItems[count].id, &billItems[count].quantity);
			}
		} //End Error Catch

		//Id values & quantity are valid:
		id = billItems[count].id;
		quantity = billItems[count].quantity;


		//Updating Inventory
		//If quantity bought is higher than stock quantity: sell everything
		if (quantity > inventory[id - 1].product.amount)
		{
			double amount = inventory[id - 1].product.amount;

			billItems[count].total = inventory[id - 1].product.price * inventory[id - 1].product.amount;
			inventory[id - 1].product.amount -= inventory[id - 1].product.amount;
			inventory[id - 1].qnt_sold = amount;
		}
		//If quantity bought is less than stock quantity: sell quantity bought
		else
		{
			inventory[id - 1].product.amount -= quantity;
			billItems[count].total = inventory[id - 1].product.price * quantity;
			inventory[id - 1].qnt_sold = quantity;
		}
		count++;
	}

	return count;
}

//function 5 - Display the Sales Report
double printSalesReport(struct StockRecord* stockItems, struct SalesRecord* saleItems, int amountItems)
{
	int i;
	double tax = 0.0;
	double purchaseTotal = 0.00;
	double total = 0.00;

	centreText(65, '*', " Seneca Groceries ");
	printf("\n");
	centreText(64, '=', "");
	printf("\n");

	for (i = 0; i < amountItems; i++)
	{
		int j = saleItems[i].id;

		if (stockItems[j - 1].product.category == "house wares" || stockItems[j - 1].product.category == "miscellaneous")
		{
			tax += saleItems[i].total * 0.13;
		}

		purchaseTotal += saleItems[i].total;

		printf("%30s %8.2lf %7.2lf\n", stockItems[j - 1].name, stockItems[j - 1].product.price, saleItems[i].total);
	}
	total = purchaseTotal + tax;
	printf("Purchase Total %32.2lf\n", purchaseTotal);
	printf("Tax %43.2lf\n", tax);
	printf("Total %41.2lf\n", total);
	printf("Thank you for shopping at Seneca!\n\n");

	return purchaseTotal;
}


//function 6 - Defining the top sellers products
void getTopSellers(struct StockRecord* storeStock, int num_stock, struct SalesRecord* topSellers, int num, int cat)
{
	int i, j = 0;
	double temp;
	char tempName[20];


	for (i = 0; i < num_stock; i++)//Running through all products
	{
		if (storeStock[i].product.category == (cat + 1) && storeStock[i].qnt_sold > 0.00)
		{
			topSellers[j].quantity = storeStock[i].qnt_sold;
			strcpy(topSellers[j].productName, storeStock[i].name);
			j++;
		}
	}

	for (i = 0; i < j; i++) //Iterate for array length - 1 (So you dont compare with non existent index)
	{
		if (topSellers[i].quantity < topSellers[i + 1].quantity) //If current amountSold is bigger than next ammountSold
		{
			temp = topSellers[i].quantity;
			strcpy(tempName, topSellers[i].productName);

			topSellers[i].quantity = topSellers[i + 1].quantity;
			strcpy(topSellers[i].productName, topSellers[i + 1].productName);

			topSellers[i + 1].quantity = temp;
			strcpy(topSellers[i + 1].productName, tempName);
		}
	}
}

//function 7 - Display the top sellers products
void printTopSellers(struct StockRecord* stock, struct SalesRecord* topSellers, int num, int cat) {
	int product;
	char nullProduct[] = { "<none>" };
	double nullPrice = 0.00;

	printTopProductsHeader(cat);

	printf("\nRank                       Product   Sales\n");
	for (int i = 0; i < num; i++)
	{
		if (topSellers[i].quantity > 0.00) {
			printf("%4d %29s %7.2lf\n", i + 1, topSellers[i].productName, topSellers[i].quantity);
		}
		else
		{
			printf("%4d %29s %7.2lf\n", i + 1, nullProduct, nullPrice);
		}
	}

	clearProducts(topSellers, num);
}
