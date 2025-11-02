#include <stdio.h>
#include <stdlib.h>

int main() {
    float capital[12] = {0}, income[12] = {0}, profit[12] = {0}; // mang luu du lieu 12 thang
    int choice, month, subChoice;
    float totalRevenue = 0;

    do {
        printf("\n===== MAIN MENU =====\n"); // menu chinh
        printf("1. Edit monthly information\n"); // chinh sua thong tin thang
        printf("2. View monthly profit\n"); // xem tien lai thang
        printf("3. Calculate total annual revenue\n"); // tinh tong doanh thu nam
        printf("4. Exit\n"); // thoat chuong trinh
        printf("Choose: "); // nhap lua chon
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter month to edit (1-12): "); // nhap thang muon chinh sua
                scanf("%d", &month);

                if (month < 1 || month > 12) {
                    printf("Invalid month!\n"); // bao loi neu thang khong hop le
                    break;
                }

                do {
                    printf("\n--- Editing month %d ---\n", month); // thong bao dang chinh sua thang nao
                    printf("1. Enter/Edit capital\n"); // nhap hoac chinh sua von
                    printf("2. Enter/Edit total income\n"); // nhap hoac chinh sua tong thu nhap
                    printf("3. Exit editing\n"); // thoat chinh sua
                    printf("Choose: "); // nhap lua chon nho
                    scanf("%d", &subChoice);

                    switch (subChoice) {
                        case 1:
                            do {
                                printf("Enter capital: "); // nhap von
                                scanf("%f", &capital[month - 1]);
                                if (capital[month - 1] < 0)
                                    printf("Capital cannot be negative! Please re-enter.\n"); // thong bao loi neu von am
                            } while (capital[month - 1] < 0);
                            break;

                        case 2:
                            do {
                                printf("Enter total income: "); // nhap tong thu nhap
                                scanf("%f", &income[month - 1]);
                                if (income[month - 1] < 0)
                                    printf("Income cannot be negative! Please re-enter.\n"); // thong bao loi neu thu nhap am
                            } while (income[month - 1] < 0);
                            break;

                        case 3:
                            printf("Exit editing month %d.\n", month); // thoat khoi viec chinh sua thang nay
                            break;

                        default:
                            printf("Invalid option!\n"); // thong bao neu nhap sai lua chon
                    }

                    //  Cap nhat lai loi nhuan sau moi lan chinh sua 
                    profit[month - 1] = income[month - 1] - capital[month - 1];

                } while (subChoice != 3);
                break;

            case 2:
                printf("\nEnter month to view (1-12): "); // nhap thang muon xem
                scanf("%d", &month);

                if (month < 1 || month > 12) {
                    printf("Invalid month!\n"); // thong bao neu thang khong hop le
                } else {
                    printf("Profit of month %d: %.2f\n", month, profit[month - 1]); // in ra tien lai cua thang do
                    if (profit[month - 1] > 0)
                        printf("==> Profit in this month.\n"); // neu lai > 0 thi thong bao loi
                    else if (profit[month - 1] < 0)
                        printf("==> Loss in this month.\n"); // neu lai < 0 thi thong bao lo
                    else
                        printf("==> Break-even month.\n"); // neu lai = 0 thi hoa von
                }
                break;

            case 3:
                // Tinh tong doanh thu 
                totalRevenue = 0;
                for (int i = 0; i < 12; i++)
                    totalRevenue += income[i];

                printf("\nTotal annual revenue: %.2f\n", totalRevenue); // in ra tong doanh thu trong nam
                break;

            case 4:
                printf("Exit program. Goodbye!\n"); // thoat chuong trinh
                break;

            default:
                printf("Invalid choice, please try again!\n"); // thong bao loi khi nhap sai lua chon
        }

    } while (choice != 4);

    return 0;
}

