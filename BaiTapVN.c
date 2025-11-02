#include <stdio.h>
#include <stdlib.h>

/* Structure to store monthly data */
struct MonthData {
    float capital;        //tien von
    float income;         //tong thu nhap
    float profit;         // tien lai
};

int main() {
    struct MonthData year[12];   // thong tin thong ke 12 thang
    int i, choice, monthChoice, editChoice;
    float totalProfit = 0;

    // t?t c? d? li?u v? 0
    for (i = 0; i < 12; i++) {
        year[i].capital = 0;
        year[i].income = 0;
        year[i].profit = 0;
    }

    do {
        printf("   STORE REVENUE MANAGEMENT\n");
        printf("1. Edit information\n");
        printf("2. View profit of a month\n");
        printf("3. View total revenue in a year\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
            printf("Enter month to edit (1-12): ");
                scanf("%d", &monthChoice);

                if (monthChoice < 1 || monthChoice > 12) {
                    printf("Invalid month!\n");
                    break;
                }

                do {
                    printf("\nEditing month %d\n", monthChoice);
                    printf("1. Edit capital\n");
                    printf("2. Edit total income\n");
                    printf("3. Back to main menu\n");
                    printf("Enter your choice: ");
                    scanf("%d", &editChoice);

                    if (editChoice == 1) {
                        printf("Enter new capital: ");
                        scanf("%f", &year[monthChoice - 1].capital);
                        if (year[monthChoice - 1].capital < 0) {
                            printf("Capital cannot be negative!\n");
                            year[monthChoice - 1].capital = 0;
                        }
                    } else if (editChoice == 2) {
                        printf("Enter new total income: ");
                        scanf("%f", &year[monthChoice - 1].income);
                        if (year[monthChoice - 1].income < 0) {
                            printf("Income cannot be negative!\n");
                            year[monthChoice - 1].income = 0;
                        }
                    } else if (editChoice != 3) {
                        printf("Invalid choice!\n");
                    }

                    // tu dong tinh loi nhuan
                    year[monthChoice - 1].profit = year[monthChoice - 1].income - year[monthChoice - 1].capital;

                } while (editChoice != 3);

                break;

            case 2: //tinh loi nhuan
                printf("Enter month to view profit (1-12): ");
                scanf("%d", &monthChoice);

                if (monthChoice < 1 || monthChoice > 12) {
                    printf("Invalid month!\n");
                    break;
                }

                printf("Profit of month %d: %.2f\n", monthChoice, year[monthChoice - 1].profit);

                if (year[monthChoice - 1].profit > 0)
                    printf("Result: Profit\n");
                else if (year[monthChoice - 1].profit < 0)
                    printf("Result: Loss\n");
                else
                    printf("Result: Break even\n");

                break;

            case 3: //tinh tong loi nhuan
                totalProfit = 0;
                for (i = 0; i < 12; i++) {
                    totalProfit += year[i].profit;
                }
                printf("Total yearly revenue: %.2f\n", totalProfit);

                if (totalProfit > 0)
                    printf("Overall result: Profit in year\n");
                else if (totalProfit < 0)
                    printf("Overall result: Loss in year\n");
                else
                    printf("Overall result: Break even\n");

                break;

            case 4: //exit
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }

    } while (choice != 4);

    return 0;
}
