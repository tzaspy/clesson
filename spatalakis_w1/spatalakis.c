#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {

    char gender;
    char type[11];
    char pay_method[5];
    char confirmation[3];
    int repeat = 0;
    int card_number;
    int max_tries;
    int actual_rest;
    int num3d;
    int num1, num2, num3;
    int reverse_num;
    int actual_reverse_num;
    int rest;
    int discount;
    int validate;
    char size;
    float cost = 0.0;
    int length;
    int i;
  
    // #############################################################
    // Requirement 1 - Enter your gender
    // #############################################################
    system("cls");
    do
    {
        printf(" *****************************\n");
        printf(" *** Welcome dear customer ***\n");
        printf(" *****************************\n\n\n");
        
        do
        {
            printf("Enter your gender [M/F]: ");
            scanf(" %c", &gender);
        } while(gender != 'M' && gender != 'F');
        
        // #############################################################
        // Requirement 2 - Select type
        // #############################################################
        
        printf(" *** What kind of item would you like to buy? *** \n\n\n");
        
        do
        {
            printf("Please select from the list below:\n");
            printf(" - Tops\n");
            printf(" - Bottoms\n");
            printf(" - Accessories\n");
            printf("Type your choice : ");
            scanf("%s", &type);
            
            validate = 1;
            if ((strcmp(type, "Tops") == 0) || 
                (strcmp(type, "Bottoms") == 0) ||
                (strcmp(type, "Accessories") == 0))
                {
                    validate = 0;
                }
            } while (validate == 1);
            
            // #############################################################
            // Requirement 3 - Select type
            // #############################################################
            
            printf(" *** What size do you prefer? ***\n\n\n");
            
            do
            {
                printf("\nPlease select from the list below:\n");
                printf(" - Press S for Small\n");
                printf(" - Press M for Medium\n");
                printf(" - Press L for Large\n");
                printf("Type your choice : ");
                scanf(" %c", &size);
            } while (size != 'S' && size != 'M' && size != 'L');
            
            // #############################################################
            // Requirement 4a - Compute payment and make the payment
            // #############################################################
            
            if (gender == 'M')
            {
                if (strcmp(type,"Tops") == 0){
                    cost = 5.99;
                } else if(strcmp(type, "Bottoms") == 0){
                    cost = 15.99;
                } else if(strcmp(type, "Accessories") == 0){
                    cost = 1.99;
                }
            } else
            {
                if (strcmp(type,"Tops") == 0){
                    cost = 4.99;
                } else if(strcmp(type, "Bottoms") == 0){
                    cost = 12.99;
                } else if(strcmp(type, "Accessories") == 0){
                    cost = 7.99;
                }
            }
            printf("\n\n You choosed:\nGender:  %c\n  Item: %s\n  Size: %c\n", gender, type, size);
            printf("\nThe price is: %.2f\n", cost);
            
            do
            {
                printf("\nChoose payment method [Card/Store]: ");
                scanf("%s", &pay_method);
            } while (strcmp(pay_method, "Card") != 0 && strcmp(pay_method, "Store") != 0);

            if (strcmp(pay_method, "Card") == 0)
            {
            // #############################################################
            // Requirement 4b The customer will pay using his card
            // #############################################################
                do
                {
                    printf("\nEnter your card number (5 digits): ");
                    scanf("%d", &card_number);
                    validate = 1;
                    if (card_number >= 10000 && card_number <= 99999)
                    {
                        validate = 0;
                    }
                } while (validate == 1);

                max_tries = 3;
                while (max_tries > 0)
                {
                    printf("\nProvide the remainder of card number with 5:");
                    scanf("%d", &rest);
                    actual_rest = (card_number % 5);
                    if (actual_rest == rest) 
                    { 
                        break;
                    }
                    max_tries--;
                }

                if (max_tries == 0)
                {
                    printf("\nYou failed to compute correctly the remainder of card with 5.\nYour purchase has been canceled");
                    return 1;
                }
            } else
            {
            // #############################################################
            // Requirement 4c The customer will pay in store
            // #############################################################

                do
                {
                    printf(" Enter a 3 digit number: ");
                    scanf("%d", &num3d);
                    validate = 1;
                    if (num3d >= 100 && num3d <= 999)
                    {
                        validate = 0;
                    }
                } while (validate == 1);
                
                do
                {
                    printf("\nPlease enter the reverse of your chosen number : ");
                    scanf("%d", &reverse_num);
                    
                    num1 = num3d / 100;
                    num2 = (num3d % 100) / 10;
                    num3 = num3d % 10;
                    actual_reverse_num = (num3 * 100) + (num2 * 10) + num1;
                } while (actual_reverse_num != reverse_num);
                
                discount = 20;
                printf("You earn a discount 20%%.\nThe final price is%.2f.", (cost * (100 - discount)/100));
            }
            
            // #############################################################
            // Requirement 5c Details of the payment
            // #############################################################
            system("cls");
            
            printf("Details of your items:\n\n");
            printf("* gender: %c\n", gender);
            printf("* item: %s\n", type);
            printf("* size: %c\n", size);
            printf("Payment:\n");
            printf("payment method: %s\n", pay_method);
            if (strcmp(pay_method, "Card") == 0)
            {
                printf("* Card Number: %d", card_number);
            } else
            {
                printf("* Code of the payment in the store: %d", num3d);
            }
            
            printf ("\n\nPlease confirm the purchase [yes/no]: ");
            scanf("%s", &confirmation);
            if (strcmp(confirmation, "yes") != 0)
            {
                printf("\n\tThe purchase is canceled! :-(\n");
                printf("Press enter to continue...");
                scanf("%c", &gender);
                repeat = 0;       // The program will go to the start
                cost = 0.0;       // Reset price
                discount = 0;     // Reset discount
                system("cls");
            } else
            {
                
                // #############################################################
                // Requirement 5c Details of the payment
                // #############################################################

                // Get the lenghts of lines of receipts that are going to be in center
                int line_1 = printf("Total products bought: 1");
                int line_2 = printf("Price: %.2f euro", cost);
                int line_3 = printf("Discount: %d%%", discount);
                int line_4 = printf("Final Price (after discount): %.2f euro", (cost * (100 - discount)/100));
                int line_5 = printf("See you soon!");
                
                system("cls");
                
                printf("Thanks for your purchase. Here is your receipt:\n");
                length = 80;
                i = 0;
                for (i=0; i < length; i++)
                {
                    printf("-");
                }
                printf("\nPayment method: %s\n",pay_method);
                
                for (i=0; i < (length - line_1)/2; i++)
                {
                    printf(" ");
                }
                printf("Total products bought: 1\n");
                
                for (i=0; i < (length - line_2)/2; i++)
                {
                    printf(" ");
                }
                printf("Price: %.2f euro\n", cost);
                
                for (i=0; i < (length - line_3)/2; i++)
                {
                    printf(" ");
                }
                printf("Discount: %d%%\n", discount);
                
                for (i=0; i < (length - line_4)/2; i++)
                {
                    printf(" ");
                }
                printf("Final Price (after discount): %.2f euro\n\n", (cost * (100 - discount)/100));
                
                for (i=0; i < (length - line_5)/2; i++)
                {
                    printf(" ");
                }
                printf("See you soon!\n");
                for (i=0; i < length; i++)
                {
                    printf("-");
                }

                repeat = 1; // The program will terminate
            }
    } while (repeat == 0);
    printf("\n\n");
    return 0;
}

