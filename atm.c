#include <stdio.h>

int main()
{
    int pin = 1234;
    int enteredPin;
    int newPin;
    int choice;
    int attempts = 0;

    float balance = 5000.00;
    float amount;

    printf("================================\n");
    printf("       WELCOME TO ATM SYSTEM\n");
    printf("================================\n");

    // PIN Login System
    while (attempts < 3)
    {
        printf("\nEnter your 4-digit PIN: ");
        scanf("%d", &enteredPin);

        if (enteredPin == pin)
        {
            printf("\nLogin Successful!\n");
            break;
        }
        else
        {
            attempts++;
            printf("Incorrect PIN!\n");
            printf("Attempts remaining: %d\n", 3 - attempts);
        }
    }

    if (attempts == 3)
    {
        printf("\nYour account is temporarily locked.\n");
        return 0;
    }

    // ATM Main Menu
    do
    {
        printf("\n================================\n");
        printf("          ATM MAIN MENU\n");
        printf("================================\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Change PIN\n");
        printf("5. Exit\n");
        printf("================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("\nYour Current Balance: Rs. %.2f\n", balance);
                break;

            case 2:
                printf("\nEnter amount to deposit: Rs. ");
                scanf("%f", &amount);

                if (amount > 0)
                {
                    balance = balance + amount;
                    printf("Money deposited successfully!\n");
                    printf("Updated Balance: Rs. %.2f\n", balance);
                }
                else
                {
                    printf("Invalid deposit amount!\n");
                }
                break;

            case 3:
                printf("\nEnter amount to withdraw: Rs. ");
                scanf("%f", &amount);

                if (amount <= 0)
                {
                    printf("Invalid withdrawal amount!\n");
                }
                else if (amount > balance)
                {
                    printf("Insufficient Balance!\n");
                }
                else
                {
                    balance = balance - amount;
                    printf("Please collect your cash.\n");
                    printf("Remaining Balance: Rs. %.2f\n", balance);
                }
                break;

            case 4:
                printf("\nEnter your current PIN: ");
                scanf("%d", &enteredPin);

                if (enteredPin == pin)
                {
                    printf("Enter your new 4-digit PIN: ");
                    scanf("%d", &newPin);

                    if (newPin >= 1000 && newPin <= 9999
                        && newPin != pin)
                    {
                        pin = newPin;
                        printf("PIN changed successfully!\n");
                    }
                    else
                    {
                        printf("Invalid PIN! Choose a different 4-digit PIN.\n");
                    }
                }
                else
                {
                    printf("Incorrect current PIN!\n");
                }
                break;

            case 5:
                printf("\nThank you for using our ATM!\n");
                printf("Have a nice day!\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }

    } while (choice != 5);

    return 0;
}
