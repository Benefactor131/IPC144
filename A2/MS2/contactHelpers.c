//==============================================
// Name:           Bair Suimaliev
// Student Number: 159350198
// Email:          bsuimaliev@myseneca.ca
// Section:        IPC
// Date:           11.10.2020
//==============================================
// Assignment:     2
// Milestone:      2
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the functions you prototyped
// in the contact helper header file.
// HINT: Put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
//       #include your contactHelpers header file on the next line:
#include "contactHelpers.h"

//--------------------------------
// Function Definitions
//--------------------------------

// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 2 =======       |
// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        empty function definitions below and     |
// |        complete the definitions as per the      |
// |        Milestone-2 specifications               | 
// |                                                 |
// | - The clearKeyboard function is done for you    |
// +-------------------------------------------------+

// Clear the standard input buffer

// clearKeyboard:  Empty function definition 
void clearKeyboard(void)
{
    while (getchar() != '\n'); // empty execution code block on purpose
}


// pause: Empty function definition goes here:
void pause(void) {
    printf("(Press Enter to Continue)");
    clearKeyboard();
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
    }while (NL != '\n'); //keeps prompting the user to enter integer until correct input

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
            printf("\n<<< Feature 1 is unavailable >>>\n\n");
            pause();
            printf("\n");
            break;
        case 2:     //if option equals to 2 do this case
            printf("\n<<< Feature 2 is unavailable >>>\n\n");
            pause();
            printf("\n");
            break;
        case 3:     //if option equals to 3 do this case
            printf("\n<<< Feature 3 is unavailable >>>\n\n");
            pause();
            printf("\n");
            break;
        case 4:     //if option equals to 4 do this case
            printf("\n<<< Feature 4 is unavailable >>>\n\n");
            pause();
            printf("\n");
            break;
        case 5:     //if option equals to 5 do this case
            printf("\n<<< Feature 5 is unavailable >>>\n\n");
            pause();
            printf("\n");
            break;
        case 6:     //if option equals to 6 do this case
            printf("\n<<< Feature 6 is unavailable >>>\n\n");
            pause();
            printf("\n");
            break;
        default: //print error message if the entered value is not between 0 and 6
            printf("*** OUT OF RANGE *** <Enter a number between 0 and 6> ");
            break;
        }
    } while (option >= 0 || option <= 6);
    
    
}