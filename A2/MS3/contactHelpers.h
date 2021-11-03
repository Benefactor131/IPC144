//==============================================
// Name:           Bair Suimaliev
// Student Number: 159350198
// Email:          bsuimaliev@myseneca.ca
// Section:        IPC
// Date:           11.10.2020
//==============================================
// Assignment:     2
// Milestone:      3
//==============================================

#include"contacts.h"
// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-2 |
// |        contents below...                        |
// +-------------------------------------------------+

// Clear the standard input buffer
void clearKeyboard(void);

// pause:
// Put function prototype below:
void pause(void);
// getInt:
// Put function prototype below:
int getInt(void);
// getIntInRange:
// Put function prototype below:
int getIntInRange(int min, int max);
// yes:
// Put function prototype below:
int yes(void);
// menu:
// Put function prototype below:
int menu(void);
// contactManagerSystem:
// Put function prototype below:
void contactManagerSystem(void);












// +-------------------------------------------------+
// |                                                 |
// |                    N E W                        |
// |           S T U F F     G O E S                 |
// |                  B E L O W                      |
// |                                                 |
// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 3 =======       |
// +-------------------------------------------------+
// | NOTE:  Add new function prototypes as per the   |
// |        Milestone-3 specifications document      |
// +-------------------------------------------------+

// Generic function to get a ten-digit phone number (provided for you)
void getTenDigitPhone(char phoneNum[]);

// findContactIndex (provided for you)
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[]);


// displayContactHeader
// put function prototype here:
void displayContactHeader(void);

// displayContactFooter:
// put function prototype here:
void displayContactFooter(void);

// displayContact:
// put function prototype here:
void displayContact(const struct Contact *contact);

// displayContacts:
// put function prototype here:
void displayContacts(const struct Contact contact[], int size);


// searchContacts:
// put function prototype here:
void searchContacts(const struct Contact contact[], int size);


// addContact:
// put function prototype here:
void addContact(struct Contact contact[], int size);


// updateContact:
// put function prototype here:
void updateContact(struct Contact contact[], int size);


// deleteContact:
// put function prototype here:
void deleteContact(struct Contact contact[], int size);

// sortContacts:
// put function prototype here:
void sortContacts(struct Contact contact[], int size);
