#include <stdio.h>
#include <stdlib.h>

int isPrime(int number) {
    if (number < 2) {
        return 0; 
    }
    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) {
            return 0; 
        }
    }
    return 1; 
}

void inputArray(int arr[], int *n) {
    printf("Enter number of elements (1 - 100): ");
    scanf("%d", n);

    while (*n <= 0 || *n > 100) {
        printf("Invalid size, enter again: ");
        scanf("%d", n);
    }

    printf("Enter %d elements:\n", *n);
    for (int i = 0; i < *n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
}

void printArray(int arr[], int n) {
    printf("Array elements are:\n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = %d", i, arr[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("\n");
}
int countPrime(int arr[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (isPrime(arr[i]) == 1) {
            count++;
        }
    }
    return count;
}

int findSecondMin(int arr[], int n) {
    if (n < 2) {
        return -1; 
    }

    int min1 = arr[0];
    int min2 = 999999; 

    for (int i = 1; i < n; i++) {
        if (arr[i] < min1) {
            min2 = min1;
            min1 = arr[i];
        } else if (arr[i] > min1 && arr[i] < min2) {
            min2 = arr[i];
        }
    }

    if (min2 == 999999) {
        return -1; 
    }
    return min2;
}

void insertAtPosition(int arr[], int *n) {
    if (*n >= 100) {
        printf("Array is full!\n");
        return;
    }

    int value, pos;
    printf("Enter value to insert: ");
    scanf("%d", &value);
    printf("Enter position (0 - %d): ", *n);
    scanf("%d", &pos);

    if (pos < 0 || pos > *n) {
        printf("Invalid position!\n");
        return;
    }
    
    for (int i = *n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }

    arr[pos] = value;
    (*n)++;
    printf("Inserted successfully!\n");
}
void deleteAtPosition(int arr[], int *n) {
    if (*n == 0) {
        printf("Array is empty!\n");
        return;
    }

    int pos;
    printf("Enter position to delete (0 - %d): ", *n - 1);
    scanf("%d", &pos);

    if (pos < 0 || pos >= *n) {
        printf("Invalid position!\n");
        return;
    }

    for (int i = pos; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    (*n)--;
    printf("Deleted successfully!\n");
}

void sortDescending(int arr[], int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                // hoán đổi giá trị
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("Array sorted in descending order!\n");
}
void binarySearch(int arr[], int n) {
    int value;
    printf("Enter value to search: ");
    scanf("%d", &value);

    int left = 0;
    int right = n - 1;
    int found = 0;
    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == value) {
            found = 1;
            break;
        } else if (arr[mid] < value) {
            right = mid - 1; // mảng giảm dần
        } else {
            left = mid + 1;
        }
    }

    if (found == 1) {
        printf("Found!\n");
    } else {
        printf("Not found!\n");
    }
}
void removeDuplicates(int arr[], int *n) {
    for (int i = 0; i < *n; i++) {
        for (int j = i + 1; j < *n; ) {
            if (arr[i] == arr[j]) {
                // dời trái để ghi đè phần tử trùng
                for (int k = j; k < *n - 1; k++) {
                    arr[k] = arr[k + 1];
                }
                (*n)--;
            } else {
                j++;
            }
        }
    }
    printf("Duplicates removed!\n");
}
void reverseArray(int arr[], int n) {
    int start = 0;
    int end = n - 1;
    int temp;

    while (start < end) {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }

    printf("Array reversed!\n");
}
int main() {
    int arr[100];
    int n = 0;
    int choice;

    do {
        // Hiển thị menu
        printf("\n====== ARRAY MANAGEMENT MENU ======\n");
        printf("1. Input array\n");
        printf("2. Print array\n");
        printf("3. Count prime numbers\n");
        printf("4. Find second smallest value\n");
        printf("5. Insert element at position\n");
        printf("6. Delete element at position\n");
        printf("7. Sort array (descending - Bubble Sort)\n");
        printf("8. Binary search (after sorting)\n");
        printf("9. Remove duplicate elements\n");
        printf("10. Reverse array\n");
        printf("0. Exit\n");
        printf("===================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Xử lý menu
        switch (choice) {
            case 1:
                inputArray(arr, &n);
                break;
            case 2:
                printArray(arr, n);
                break;
            case 3:
                printf("Number of prime numbers: %d\n", countPrime(arr, n));
                break;
            case 4: {
                int result = findSecondMin(arr, n);
                if (result == -1)
                    printf("No second smallest value.\n");
                else
                    printf("Second smallest value: %d\n", result);
                break;
            }
            case 5:
                insertAtPosition(arr, &n);
                break;
            case 6:
                deleteAtPosition(arr, &n);
                break;
            case 7:
                sortDescending(arr, n);
                break;
            case 8:
                binarySearch(arr, n);
                break;
            case 9:
                removeDuplicates(arr, &n);
                break;
            case 10:
                reverseArray(arr, n);
                break;
            case 0:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice, try again!\n");
        }

    } while (choice != 0);

    return 0;
}
