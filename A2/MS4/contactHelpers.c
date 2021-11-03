//==============================================
// Name:           Bair Suimaliev
// Student Number: 159350198
// Email:          bsuimaliev@myseneca.ca
// Section:        IPC
// Date:           11.29.2020
//==============================================
// Assignment:     2
// Milestone:      4
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        contents below...                        |
// +-------------------------------------------------+

#include <stdio.h>
#include <string.h>
#include "contacts.h"
#include "contactHelpers.h"

#define MAXCONTACTS 5

// clearKeyboard:  Empty function definition 
void clearKeyboard(void)
{
    while (getchar() != '\n'); // empty execution code block on purpose
}


// pause: Empty function definition goes here:
void pause(void) {
    printf("(Press Enter to Continue)");
    clearKeyboard();
    printf("\n");
}

// getInt: Empty function definition goes here:
int getInt(void) {
    char NL = 'x';
    int value;
    do
    {
        scanf("%d%c", &value, &NL);
        if (NL != '\n') {
            clearKeyboard();
            printf("*** INVALID INTEGER *** <Please enter an integer>: ");
        }
    } while (NL != '\n'); //keeps prompting the user to enter integer until correct input

    return value;
}

// getIntInRange: Empty function definition goes here:
int getIntInRange(int min, int max) {
    int valueInRange = getInt(); //the int equals to the function, so the user could input the value using previous                                                                                                                 function
    while (valueInRange < min || valueInRange > max) {
        printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
        valueInRange = getInt();
    }
    return valueInRange;
}

// yes: Empty function definition goes here:
int yes(void) {
    char yn1 = 'x';
    char yn2 = 'x'; //the second variable is needed to ensure that input will be one character long
    int result = 0;

    do
    {
        scanf("%c%c", &yn1, &yn2);

        if ((yn2 != '\n') && (yn1 != 'y' || yn1 != 'Y' || yn1 != 'n' || yn1 != 'N'))
        {
            clearKeyboard();
            printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
        }
    } while ((yn2 != '\n') && (yn1 != 'y' || yn1 != 'Y' || yn1 != 'n' || yn1 != 'N')); //keeps prompting the user until                                                                                                          valid input
    if (yn1 == 'y' || yn1 == 'Y') //if user enters y, the return result will be equal to 1
    {
        result = 1;
    }
    else if (yn1 != 'y' || yn1 != 'Y') //if user enters n, the return result will be equal to 0
    {
        result = 0;
    }
    return result;
}

// menu: Empty function definition goes here:
int menu(void) {
    printf("Contact Management System\n");
    printf("-------------------------\n");
    printf("1. Display contacts\n");
    printf("2. Add a contact\n");
    printf("3. Update a contact\n");
    printf("4. Delete a contact\n");
    printf("5. Search contacts by cell phone number\n");
    printf("6. Sort contacts by cell phone number\n");
    printf("0. Exit\n\n");
    printf("Select an option:> ");

    return getIntInRange(0, 6); //return the value in range of 0 and 6
}

// contactManagerSystem: Empty function definition goes here:
void contactManagerSystem(void) {
    int option;
    struct Contact Contacts[MAXCONTACTS] =
    { { { "Rick", {'\0'}, "Grimes" },
    { 11, "Trailer Park", 0, "A7A 2J2", "King City" },
    { "4161112222", "4162223333", "4163334444" } },
    {
    { "Maggie", "R.", "Greene" },
    { 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
    { "9051112222", "9052223333", "9053334444" } },
    {
    { "Morgan", "A.", "Jones" },
    { 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },
    { "7051112222", "7052223333", "7053334444" } },
    {
    { "Sasha", {'\0'}, "Williams" },
    { 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
    { "9052223333", "9052223333", "9054445555" } },
    };

    do
    {
        option = menu();
        switch (option)
        {
        case 0:     //if option equals to 0 do this case
            printf("\nExit the program? (Y)es/(N)o: ");
            int result = yes();
            printf("\n");
            if (result == 1)
            {
                printf("Contact Management System: terminated\n");
                return;
            }
            else {
                break;
            }
        case 1:     //if option equals to 1 do this case
            printf("\n");
            displayContacts(Contacts, MAXCONTACTS);
            pause();
            break;
        case 2:     //if option equals to 2 do this case
            printf("\n");
            addContact(Contacts, MAXCONTACTS);
            pause();
            break;
        case 3:     //if option equals to 3 do this case
            printf("\n");
            updateContact(Contacts, MAXCONTACTS);
            pause();
            break;
        case 4:     //if option equals to 4 do this case
            printf("\n");
            deleteContact(Contacts, MAXCONTACTS);
            pause();
            break;
        case 5:     //if option equals to 5 do this case
            printf("\n");
            searchContacts(Contacts, MAXCONTACTS);
            pause();
            break;
        case 6:     //if option equals to 6 do this case
            printf("\n");
            sortContacts(Contacts, MAXCONTACTS);
            pause();
            break;
        default: //print error message if the entered value is not between 0 and 6
            printf("*** OUT OF RANGE *** <Enter a number between 0 and 6> ");
            break;
        }
    } while (option >= 0 || option <= 6);

    /*printf("\n<<< Feature 1 is unavailable >>>\n\n");
            pause();
            printf("\n");*/
}

// +-------------------------------------------------+
// |                                                 |
// |                    N E W                        |
// |           S T U F F     G O E S                 |
// |                  B E L O W                      |
// |                                                 |
// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 3 =======       |
// +-------------------------------------------------+
// | Put empty function definitions below...         |
// +-------------------------------------------------+

// Generic function to get a ten-digit phone number (ensures 10-digit chars entered)
// ---------------------------------------------------------------------------------
// NOTE: Modify this function to validate only numeric character digits are entered
// ---------------------------------------------------------------------------------
void getTenDigitPhone(char phoneNum[])
{
    int i;
    int needInput = 1;

    while (needInput == 1)
    {
        scanf("%10s", phoneNum);
        clearKeyboard();

        for (i = 0; i < 10; i++)
        {
            if (phoneNum[i] != '1' && phoneNum[i] != '2' && phoneNum[i] != '3' && phoneNum[i] != '4' && phoneNum[i] != '5' && phoneNum[i] != '6' && phoneNum[i] != '7' && phoneNum[i] != '8' && phoneNum[i] != '9' && phoneNum[i] != '0')
            {
                printf("Enter a 10-digit phone number: ");
                getTenDigitPhone(phoneNum);
            }
        }
        // (String Length Function: validate entry of 10 characters)
        if (strlen(phoneNum) == 10)
        {
            needInput = 0;
        }
        else
        {
            printf("Enter a 10-digit phone number: ");
        }
    }
}

// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[])
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (strcmp(contacts[i].numbers.cell, cellNum) == 0) {
            return i;
        }
    }
    return -1;
}


// displayContactHeader
// Put empty function definition below:
void displayContactHeader(void) {
    printf("+-----------------------------------------------------------------------------+\n");
    printf("|                              Contacts Listing                               |\n");
    printf("+-----------------------------------------------------------------------------+\n");
}


// displayContactFooter
// Put empty function definition below:
void displayContactFooter(int count) {
    printf("+-----------------------------------------------------------------------------+\n");
    printf("Total contacts: %d\n\n", count);
}


// displayContact:
// Put empty function definition below:
void displayContact(const struct Contact* contact) {
    if (contact->name.middleInitial[0] != '\0') {
        printf(" %s %s %s\n", contact->name.firstName, contact->name.middleInitial, contact->name.lastName);
    }
    else if (strlen(contact->name.middleInitial) == 0) {
        printf(" %s %s\n", contact->name.firstName, contact->name.lastName);
    }
    printf("    C: %-10s   H: %-10s   B: %-10s\n", contact->numbers.cell, contact->numbers.home, contact->numbers.business);
    printf("       %d %s, ", contact->address.streetNumber, contact->address.street);
    if (contact->address.apartmentNumber > 0)
    {
        printf("Apt# %d, ", contact->address.apartmentNumber);
    }
    printf("%s, %s\n", contact->address.city, contact->address.postalCode);
}


// displayContacts:
// Put empty function definition below:
void displayContacts(const struct Contact contact[], int size) {
    int i;
    int count = 0;
    displayContactHeader();
    for (i = 0; i < size; i++)
    {
        if (strlen(contact[i].numbers.cell) > 0) {
            displayContact(&contact[i]);
            count++;
        }
    }
    displayContactFooter(count);
}


// searchContacts:
// Put empty function definition below:
void searchContacts(const struct Contact contact[], int size) {
    char cellPhone[11];
    int contactIndex;
    printf("Enter the cell number for the contact: ");
    getTenDigitPhone(cellPhone);
    findContactIndex(contact, size, cellPhone);
    if (findContactIndex(contact, size, cellPhone) != -1) {
        printf("\n");
        contactIndex = findContactIndex(contact, size, cellPhone);
        displayContact(&contact[contactIndex]);
        printf("\n");
    }
    else {
        printf("*** Contact NOT FOUND ***\n\n");
    }
}


// addContact:
// Put empty function definition below:
void addContact(struct Contact contact[], int size) {
    int i;
    for (i = 0; i < size; i++)
    {
        if (strlen(contact[i].numbers.cell) == 0) {
            break;
        }
    }
    if (i == size)
    {
        printf("*** ERROR: The contact list is full! ***\n\n");
    }
    else
    {
        getContact(&contact[i]);
        printf("--- New contact added! ---\n\n");
    }
}


// updateContact:
// Put empty function definition below:
void updateContact(struct Contact contact[], int size) {
    char cellPhone[11];
    int contactIndex;
    int yesNo;
    printf("Enter the cell number for the contact: ");
    getTenDigitPhone(cellPhone);
    findContactIndex(contact, size, cellPhone);
    if (findContactIndex(contact, size, cellPhone) != -1) {
        printf("\nContact found:\n");
        contactIndex = findContactIndex(contact, size, cellPhone);
        displayContact(&contact[contactIndex]);
        printf("\n");

        printf("Do you want to update the name? (y or n): ");
        yesNo = yes();
        if (yesNo == 1) {
            getName(&contact[contactIndex].name);
        }

        printf("Do you want to update the address? (y or n): ");
        yesNo = yes();
        if (yesNo == 1) {
            getAddress(&contact[contactIndex].address);
        }

        printf("Do you want to update the numbers? (y or n): ");
        yesNo = yes();
        if (yesNo == 1) {
            getNumbers(&contact[contactIndex].numbers);
        }
        printf("--- Contact Updated! ---\n\n");
    }
    else {
        printf("*** Contact NOT FOUND ***\n\n");
    }
}


// deleteContact:
// Put empty function definition below:
void deleteContact(struct Contact contact[], int size) {
    char cellPhone[11];
    int contactIndex;
    int yesNo;

    printf("Enter the cell number for the contact: ");
    getTenDigitPhone(cellPhone);
    findContactIndex(contact, size, cellPhone);
    if (findContactIndex(contact, size, cellPhone) != -1) {
        printf("\nContact found:\n");
        contactIndex = findContactIndex(contact, size, cellPhone);
        displayContact(&contact[contactIndex]);
        printf("\n");

        printf("CONFIRM: Delete this contact? (y or n): ");
        yesNo = yes();
        if (yesNo == 1)
        {
            contact[contactIndex].numbers.cell[0] = '\0';
            contact[contactIndex].numbers.business[0] = '\0';
            contact[contactIndex].numbers.home[0] = '\0';
            printf("--- Contact deleted! ---\n\n");
        }
        else
        {
            printf("\n");
        }
    }
    else {
        printf("*** Contact NOT FOUND ***\n\n");
    }
}


// sortContacts:
// Put empty function definition below:
void sortContacts(struct Contact contact[], int size) {
    int i, j;
    struct Contact temp;

    for (i = 0; i < size; i++)
    {
        for (j = i + 1; j < size; j++)
        {
            if (strlen(contact[i].numbers.cell) != 0 && strlen(contact[j].numbers.cell) != 0) {
                if (strcmp(contact[i].numbers.cell, contact[j].numbers.cell) > 0) {
                    temp = contact[i];
                    contact[i] = contact[j];
                    contact[j] = temp;
                }
            }
        }
    }
    printf("--- Contacts sorted! ---\n\n");
}
