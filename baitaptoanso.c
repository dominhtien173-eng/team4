#include <stdio.h>

int main() {
    int choice;       // Luu lua chon menu cua nguoi dung
    int n;            //  nguyên duong
    long long sum;    // tính tong
    long long factorial; //  tính giai thua

    do {
        // ===== HIEN THI MENU =====
        printf("\n=== BASIC ARITHMETIC PROGRAM MENU ===\n");
        printf("1. Calculate the sum from 1 to n\n");
        printf("2. Calculate the sum of even numbers from 1 to n\n");
        printf("3. Calculate factorial of n\n");
        printf("4. Check if n is a prime number\n");
        printf("5. Check if n is a palindrome number\n");
        printf("6. Exit\n");
        printf("========\n");
        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                //  Tinh tong các so tu 1 den n
                printf("Enter n (>0): ");
                scanf("%d", &n);
                if (n <= 0) { // Kiem tra dieu kien n hop le
                    printf("Invalid input! n must be greater than 0.\n");
                    break;
                }
                sum = 0;
                for (int i = 1; i <= n; i++) {
                    sum += i;
                }
                printf("The sum from 1 to %d is: %lld\n", n, sum);
                break;

            case 2:
                //  Tinh tong cac so chon tu 1 den n
                printf("Enter n (>0): ");
                scanf("%d", &n);
                if (n <= 0) { // Kiem tra n
                    printf("Invalid input! n must be greater than 0.\n");
                    break;
                }
                sum = 0;
                // Cong cac so chon tu 2 den n
                for (int i = 2; i <= n; i += 2) {
                    sum += i;
                }
                printf("The sum of even numbers from 1 to %d is: %lld\n", n, sum);
                break;

            case 3:
                //  Tinh giai thua n! 
                printf("Enter n (>=0): ");
                scanf("%d", &n);
                if (n < 0) { // Giai thua không tinh cho so âm
                    printf("Invalid input! n must be non-negative.\n");
                    break;
                }
                factorial = 1;
                int i = 1;
                // Nhân lan luot tu 1 den n
                while (i <= n) {
                    factorial *= i;
                    i++;
                }
                printf("%d! = %lld\n", n, factorial);
                break;

            case 4:
                //  Kiem tra so nguyên t? 
                printf("Enter n (>1): ");
                scanf("%d", &n);
                if (n <= 1) {
                    printf("Invalid input! n must be greater than 1.\n");
                    break;
                }

                int j;
                // Duyet tu 2 den n/2 de kiem tra chia het
                for (j = 2; j <= n / 2; j++) {
                    if (n % j == 0) {
                        break; // Neu chia het thi khong phai so nguyên t?
                    }
                }
                if (j > n / 2)
                    printf("%d is a prime number.\n", n);
                else
                    printf("%d is not a prime number.\n", n);
                break;

            case 5:
                // Kiem tra so doi xung 
                printf("Enter n (>0): ");
                scanf("%d", &n);
                if (n <= 0) {
                    printf("Invalid input! n must be greater than 0.\n");
                    break;
                }
                int reversed = 0, temp = n;
                
                do {
                    reversed = reversed * 10 + temp % 10; // Lay chu so cuoi
                    temp /= 10;                           // Bo chu so cuoi
                } while (temp != 0);

                // So sánh 
                if (reversed == n)
                    printf("%d is a palindrome number.\n", n);
                else
                    printf("%d is not a palindrome number.\n", n);
                break;

            case 6:
                //  Thoát chuong trình
                printf("Goodbye! See you next time!\n");
                break;

            default:
                // Neu nguoi dung nhap sai lua chon
                printf("Invalid choice! Please select between 1 and 6.\n");
                break;
        }

    } while (choice != 6); // Dung khi chon 6 

    return 0;
}
