#include <stdio.h>

int laSoNguyenTo(int n) {
    if (n < 2) return 0;
    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

int laSoDoiXung(int n) {
    int soGoc = n;
    int dao = 0;
    do {
        dao = dao * 10 + n % 10;
        n /= 10;
    } while (n > 0);
    return (dao == soGoc);
}

int main() {
    int luaChon;
    do {
        printf("===== MENU CHUONG TRINH =====\n");
        printf("1. Tinh tong cac so tu 1 den n\n");
        printf("2. Tinh tong cac so chan tu 1 den n\n");
        printf("3. Tinh giai thua cua n\n");
        printf("4. Kiem tra so nguyen to\n");
        printf("5. Kiem tra so doi xung (palindrome)\n");
        printf("6. Thoat\n");
        printf("=============================\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &luaChon);

        int n;
        switch (luaChon) {
            case 1:
                printf("Nhap n (n > 0): ");
                scanf("%d", &n);
                if (n > 0) {
                    int tong = 0;
                    for (int i = 1; i <= n; i++) {
                        tong += i;
                    }
                    printf("Tong tu 1 den %d la: %d\n", n, tong);
                } else {
                    printf("n phai lon hon 0!\n");
                }
                break;

            case 2:
                printf("Nhap n: ");
                scanf("%d", &n);
                if (n > 0) {
                    int tongChan = 0;
                    for (int i = 2; i <= n; i += 2) {
                        tongChan += i;
                    }
                    printf("Tong cac so chan tu 1 den %d la: %d\n", n, tongChan);
                } else {
                    printf("n phai lon hon 0!\n");
                }
                break;

            case 3:
                printf("Nhap n (n >= 0): ");
                scanf("%d", &n);
                if (n >= 0) {
                    int giaiThua = 1;
                    int i = 1;
                    while (i <= n) {
                        giaiThua *= i;
                        i++;
                    }
                    printf("%d! = %d\n", n, giaiThua);
                } else {
                    printf("n phai >= 0!\n");
                }
                break;

            case 4:
                printf("Nhap n (n > 1): ");
                scanf("%d", &n);
                if (n > 1) {
                    if (laSoNguyenTo(n))
                        printf("%d la so nguyen to.\n", n);
                    else
                        printf("%d khong phai la so nguyen to.\n", n);
                } else {
                    printf("n phai lon hon 1!\n");
                }
                break;

            case 5:
                printf("Nhap n (n > 0): ");
                scanf("%d", &n);
                if (n > 0) {
                    if (laSoDoiXung(n))
                        printf("%d la so doi xung.\n", n);
                    else
                        printf("%d khong la so doi xung.\n", n);
                } else {
                    printf("n phai lon hon 0!\n");
                }
                break;

            case 6:
                printf("Tam biet!\n");
                break;

            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }

        printf("\n");

    } while (luaChon != 6);

    return 0;
}
