//==============================================
// Group member #1:	Bair Suimaliev		
// Group member #2:	Elvis Kwan
// Group member #3:	Max Ratajczak
//==============================================

#define NUM_CATS 7
#define MAX_ITEMS_IN_SALE 50

struct Components
{
	int amount;
	int category;
	double price;
	int byWeight;
};
struct StockRecord
{
	struct Components product;
	char name[20];
	double qnt_sold;
};

struct SalesRecord
{
	int id;
	char productName[20];
	double quantity;
	double total;
};
//auxilary function

//auxilary function 1 - Clear top sellers products in topSellers structure
void clearProducts(struct SalesRecord*, int num);

//auxilary function 2 - Print top sellers header
void printTopProductsHeader(int category);


//main functions

//function 1 - call the file for the inputs
int readStockItems(struct StockRecord*, int max_stock, int stock_stdin);

//function 2 - Display the header and "="
void centreText(int x, char y, char message[30]);

//function 3 - Display the Stock Record
void printStockReport(struct StockRecord*, int num_stock);

//function 4 - Checks if there is a sale for a product
int readSale(struct StockRecord*, int amt, struct SalesRecord*);

//function 5 - Display the Sales Report
double printSalesReport(struct StockRecord*, struct SalesRecord* saleItems, int amountItems);

//function 6 - Defining the top sellers products
void getTopSellers(struct StockRecord*, int num_stock, struct SalesRecord*, int num, int cat);

//function 7 - Display the top sellers products
void printTopSellers(struct StockRecord*, struct SalesRecord*, int num, int cat);

