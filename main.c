#include <stdio.h>

int main() {
    int choice;   
    int n;       
    int i;        
    long long sum, factorial; 
    int reversed, temp, remainder;
    int isPrime; 

    do {
        printf("\n===== BASIC MATH PROGRAM MENU =====\n");
        printf("1. Calculate the sum of numbers from 1 to n\n");
        printf("2. Calculate the sum of even numbers from 1 to n\n");
        printf("3. Calculate factorial of n\n");
        printf("4. Check if a number is prime\n");
        printf("5. Check if a number is palindrome\n");
        printf("6. Exit\n");
        printf("===================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter n (n > 0): ");
                scanf("%d", &n);
                if (n <= 0) {
                    printf(">> Error: n must be greater than 0!\n");
                    break;
                }
                sum = 0;
                for (i = 1; i <= n; i++) {
                    sum += i;
                }
                printf("Sum of numbers from 1 to %d is: %lld\n", n, sum);
                break;
            case 2:
                printf("Enter n (n > 0): ");
                scanf("%d", &n);
                if (n <= 0) {
                    printf(">> Error: n must be greater than 0!\n");
                    break;
                }
                sum = 0;
                for (i = 2; i <= n; i += 2) {
                    sum += i;
                }
                printf("Sum of even numbers from 1 to %d is: %lld\n", n, sum);
                break;
            case 3:
                printf("Enter n (n >= 0): ");
                scanf("%d", &n);
                if (n < 0) {
                    printf(">> Error: n must be >= 0!\n");
                    break;
                }
                factorial = 1;
                i = 1;
                while (i <= n) {
                    factorial *= i;
                    i++;
                }
                printf("Factorial of %d is: %lld\n", n, factorial);
                break;
            case 4:
                printf("Enter n (n > 1): ");
                scanf("%d", &n);
                if (n <= 1) {
                    printf(">> Error: n must be greater than 1!\n");
                    break;
                }
                isPrime = 1;
                for (i = 2; i < n; i++) {
                    if (n % i == 0) {
                        isPrime = 0;
                        break;
                    }
                }
                if (isPrime)
                    printf("%d is a prime number.\n", n);
                else
                    printf("%d is not a prime number.\n", n);
                break;
            case 5:
                printf("Enter n (n > 0): ");
                scanf("%d", &n);
                if (n <= 0) {
                    printf(">> Error: n must be greater than 0!\n");
                    break;
                }
                temp = n;
                reversed = 0;
                do {
                    remainder = temp % 10;
                    reversed = reversed * 10 + remainder;
                    temp /= 10;
                } while (temp != 0);

                if (reversed == n)
                    printf("%d is a palindrome number.\n", n);
                else
                    printf("%d is not a palindrome number.\n", n);
                break;
            case 6:
                printf("Goodbye!\n");
                break;
            default:
                printf(">> Invalid choice! Please enter a number from 1 to 6.\n");
        }

    } while (choice != 6);

    return 0;
}

