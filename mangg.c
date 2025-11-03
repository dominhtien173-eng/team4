#include <stdio.h>

#define MAXSIZE 10 // khai bao hang so

int main() {
    int arr[MAXSIZE];
    int n = 0; 
    int i, j;  
    int pos, value;
    int choose;

    printf("Enter the initial number of elements (1 - %d): ", MAXSIZE);
    scanf("%d", &n);

    while (n <= 0 || n > MAXSIZE) {
        printf("Invalid number. Please enter again (1 - %d): ", MAXSIZE);
        scanf("%d", &n);
    }

    printf("Enter %d values for the array:\n", n);
    for (i = 0; i < n; i++) {
        printf("  arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    do {
        printf("\n\n--- MENU ---\n");
        printf("Current Array: [ ");
        for (i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("]\n"); 

        printf("1. Add a new value to the array\n");
        printf("2. Delete a value at any position\n");
        printf("3. Search for a value in the array\n");
        printf("4. Sort the array (ascending / descending)\n");
        printf("5. Exit\n");
        printf("------------------------\n");
        printf("Your choice: ");
        scanf("%d", &choose);

        switch (choose) {
            case 1:
                if (n < MAXSIZE) {
                    printf("Enter position to add (from 0 to %d): ", n);
                    scanf("%d", &pos);
                    if (pos < 0 || pos > n) {
                        printf("Error: Invalid position to add!\n");
                    } else {
                        printf("Enter value to add: ");
                        scanf("%d", &value);

                        for (i = n; i > pos; i--) {
                            arr[i] = arr[i - 1];
                        }
                        arr[pos] = value;
                        n++;
                        printf("Added successfully.\n");
                    }
                } else {
                    printf("Array is full, cannot add!\n");
                }
                break;

            case 2: 
                if (n > 0) {
                    printf("Enter position to delete (from 0 to %d): ", n - 1);
                    scanf("%d", &pos);
                    if (pos < 0 || pos >= n) {
                        printf("Error: Invalid position to delete!\n");
                    } else {
                        for (i = pos; i < n - 1; i++) {
                            arr[i] = arr[i + 1];
                        }
                        n--;
                        printf("Deleted successfully.\n");
                    }
                } else {
                    printf("Array is empty, cannot delete!\n");
                }
                break;

            case 3: 
                if (n > 0) {
                    printf("Enter value to search: ");
                    scanf("%d", &value);

                    int found = 0; 
                    printf("Found %d at position(s): ", value);
                    for (i = 0; i < n; i++) {
                        if (arr[i] == value) {
                            printf("%d ", i);
                            found = 1;
                        }
                    }
                    if (found == 0) {
                        printf("does not exist in the array.");
                    }
                    printf("\n");
                } else {
                    printf("Array is empty, nothing to search.\n");
                }
                break;

            case 4: 
                if (n > 0) {
                    int sortType;
                    printf("Select sort type (1: Ascending, 2: Descending): ");
                    scanf("%d", &sortType);

                   
                    for (i = 0; i < n - 1; i++) {
                        for (j = 0; j < n - 1 - i; j++) {
                            if (sortType == 1 && arr[j] > arr[j + 1]) { 
                                int temp = arr[j];
                                arr[j] = arr[j + 1];
                                arr[j + 1] = temp;
                            } else if (sortType == 2 && arr[j] < arr[j + 1]) { 
                                int temp = arr[j];
                                arr[j] = arr[j + 1];
                                arr[j + 1] = temp;
                            }
                        }
                    }
                    printf("Sort completed.\n");
                } else {
                    printf("Array is empty, nothing to sort.\n");
                }
                break;

            case 5: 
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice. Please select from 1 to 5.\n");
        }

    } while (choose != 5);

    return 0;
}
