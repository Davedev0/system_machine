// Dave's_program 
// machine ordering_2024
#include <stdio.h>
#include <string.h>
int main() {
    int money = 0; 
    int total = 0;
    int remaining = 0;
    int food;
    char name[100] = "";
    char orders[100] = "";

    // Payment method selection
    printf("         LET'S ORDER         \n");
    printf("     PROCEED TO CHECKOUT     \n");
    printf("—————————————————————————————\n");
    printf("\n=============================\n");
    printf("   [1] Cash\n");
    printf("   [2] ATM Card\n");
    printf("=============================\n");
    printf("Select payment method: ");
    int paymentMethod;
    scanf("%d", &paymentMethod);

    if (paymentMethod == 1) {
        printf("Enter username: ");
        scanf("%s", name);
        printf("Enter payment amount: ");
        scanf("%d", &money);
    } else if (paymentMethod == 2) {
        printf("\n=============================\n");
        printf("   [1] GCash\n");
        printf("   [2] PayMaya\n");
        printf("   [3] BDO\n");
        printf("   [4] Lazada\n");
        printf("=============================\n");
        printf("Select ATM Card: ");
        int atmCard;
        scanf("%d", &atmCard);
        
        if (atmCard >= 1 || atmCard <= 4) {
            const char *paymentMethods[] = {"GCash", "PayMaya", "BDO", "Lazada"};
            printf("(Paid via %s) \n", paymentMethods[atmCard - 1]);
            printf("Enter username: ");
            scanf("%s", name);
            printf("Enter payment amount: ");
            scanf("%d", &money);
        } else {
            printf("Invalid choice, Please try again.\n");
            return 1; // Exit if invalid choice
        }
    } else {
        printf("Invalid choice, Please try again.\n");
        return 1; // Exit if invalid choice
    } remaining = money;

    // Menu display
    printf("\n=============================\n");
    printf(" = OUR MENU:\n");
    printf(" = [1] Burger           ₱25\n");
    printf(" = [2] Chicken          ₱20\n");
    printf(" = [3] Spaghetti        ₱50\n");
    printf(" = [4] Fries            ₱20\n");
    printf(" = [5] Coke             ₱25\n");
    printf(" = [6] Ice Cream        ₱35\n");
    printf(" = [7] Rice             ₱15\n");
    printf("=============================\n");

    // Food prices and names
    int prices[] = {0, 25, 20, 50, 20, 25, 35, 15};
    const char *foodNames[] = {"", "Burger", "Chicken", "Spaghetti", 
    "Fries", "Coke", "Ice Cream", "Rice"};

    while (1) {
        printf("Select your order: ");
        scanf("%d", &food);

        if (food >= 1 && food <= 7) {
            if (remaining >= prices[food]) {
                printf("\nOrder:      %s \nPrice:      ₱%d\n", 
                foodNames[food], prices[food]);
                total += prices[food];
                remaining -= prices[food];
                printf("Balance:    ₱%d\n", remaining);
                strcat(orders, "\n= ");
                strcat(orders, foodNames[food]);
            } else {
                printf("You don't have enough money!\n");
                break;
            }
        } else {
            printf("Invalid order, Please try again.\n");
            break;
        }

        // Continue or exit
        printf("=================\n");
        printf(" [1] Continue\n");
        printf(" [2] Exit\n");
        printf("=================\n");
        int choice;
        printf("Order more: ");
        scanf("%d", &choice);

        if (choice == 2) {
            printf("\nOrder: %s\n", orders);
            printf("Remaining money:   ₱%d\n", remaining);
            printf("Total amount due:  ₱%d\n", total);
            printf("—————————————————————————————\n");
            printf("Thank you for ordering, %s!\n", name);
            break;
        } else if (choice == 1) {
            printf("\n=============================\n");
            printf(" = OUR MENU:\n");
            printf(" = [1] Burger           ₱25\n");
            printf(" = [2] Chicken          ₱20\n");
            printf(" = [3] Spaghetti        ₱50\n");
            printf(" = [4] Fries            ₱20\n");
            printf(" = [5] Coke             ₱25\n");
            printf(" = [6] Ice Cream        ₱35\n");
            printf(" = [7] Rice             ₱15\n");
            printf("=============================\n");
        } if (choice != 1 && choice != 2) {
            printf("Invalid choice, Please try again.\n");
            break;
        } 
    }
    return 0;
}

    