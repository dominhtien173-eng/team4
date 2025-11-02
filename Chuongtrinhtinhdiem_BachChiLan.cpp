#include <stdio.h>

int main() {
    int choice;     // lua chon menu
    int n;          // bien nhap n
    do {
        // Hi?n th? menu
        printf("- MENU CHUONG TRINH -\n");
        printf("1. Tinh tong cac so tu 1 den n\n");
        printf("2. Tinh tong cac so chan tu 1 den n\n");
        printf("3. Tinh giai thua cua n\n");
        printf("4. Kiem tra so nguyen to\n");
        printf("5. Kiem tra so doi xung (palindrome)\n");
        printf("6. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                // 1. Tih tong tu den n
                printf("Nhap n (n > 0): ");
                scanf("%d", &n);
                if (n > 0) {
                    int sum = 0;
                    for (int i = 1; i <= n; i++) {
                        sum += i;
                    }
                    printf("Tong cac so tu 1 den %d la: %d\n", n, sum);
                } else {
                    printf("n phai lon hon 0!\n");
                }
                break;
            }

            case 2: {
                // 2. Tinh tong cac so chan tu 1 den n
                printf("Nhap n (n > 0): ");
                scanf("%d", &n);
                if (n > 0) {
                    int sum = 0;
                    for (int i = 2; i <= n; i += 2) {
                        sum += i;
                    }
                    printf("Tong cac so chan tu 1 den %d la: %d\n", n, sum);
                } else {
                    printf("n phai lon hon 0!\n");
                }
                break;
            }

            case 3: {
                // 3. Tinh giai thua cua n
                printf("Nhap n (n >= 0): ");
                scanf("%d", &n);
                if (n >= 0) {
                    int i = 1;
                    long long gt = 1;
                    while (i <= n) {
                        gt *= i;
                        i++;
                    }
                    printf("Giai thua cua %d la: %lld\n", n, gt);
                } else {
                    printf("n phai >= 0!\n");
                }
                break;
            }

            case 4: {
                // 4. Kiem tra so nguyen to
                printf("Nhap n (n > 1): ");
                scanf("%d", &n);
                if (n > 1) {
                    int laNT = 1; 
                    for (int i = 2; i <= n / 2; i++) {
                        if (n % i == 0) {
                            laNT = 0;
                            break;
                        }
                    }
                    if (laNT)
                        printf("%d la so nguyen to.\n", n);
                    else
                        printf("%d khong phai so nguyen to.\n", n);
                } else {
                    printf("n phai lon hon 1!\n");
                }
                break;
            }

            case 5: {
                // 5. Kiem tra la so doi xung?
                printf("Nhap n (n > 0): ");
                scanf("%d", &n);
                if (n > 0) {
                    int soGoc = n;
                    int soDao = 0;
                    do {
                        int chuSo = n % 10;
                        soDao = soDao * 10 + chuSo;
                        n /= 10;
                    } while (n > 0);

                    if (soDao == soGoc)
                        printf("%d la so doi xung.\n", soGoc);
                    else
                        printf("%d khong phai so doi xung.\n", soGoc);
                } else {
                    printf("n phai lon hon 0!\n");
                }
                break;
            }

            case 6:
                printf("Tam biet!\n");
                break;

            default:
                printf("Lua chon khong hop le! Vui long nhap lai.\n");
        }

        printf("\n"); // Xuong dong sau moi lan chay
    } while (choice != 6);

    return 0;
}
