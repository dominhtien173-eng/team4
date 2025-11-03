#include <stdio.h>
#include <stdlib.h>

int main() {
    int array[10];      
    int length;         
    int choice;         
    int i;              
    //notification
    printf("ARRAY PROGRAM\n");

    // nhao do dai phan tu (max la 10 phan tu)
    printf("Enter the length of the array (max 10): ");
    scanf("%d", &length);

    if (length > 10) {
        printf("Too many elements! Only 10 allowed!\n");
        length = 10;
    } else if (length <= 0) {
        printf("Invalid length! Exit program.\n");
        return 0;
    }

    // enter cac phan tu
    for (i = 0; i < length; i++) {
        printf("Enter element number %d: ", i);
        scanf("%d", &array[i]);
    }
    do {
        printf("\nMAIN MENU\n");
        printf("1. Add new value\n");
        printf("2. Delete a value at any position\n");
        printf("3. Search a value\n");
        printf("4. Sort the array (ascending or descending)\n");
        printf("5. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            // add them gia tri moi
            if (length == 10) {
                printf("Array is already full!\n");
            } else {
                int newValue;
                printf("Enter new value to add: ");
                scanf("%d", &newValue);
                array[length] = newValue;
                length++;
                printf("Added! Now the array has %d elements.\n", length);
            }
        }

        else if (choice == 2) {
            // del cac phan tu
            int position;
            printf("Enter the position to delete (0 -> %d): ", length - 1);
            scanf("%d", &position);

            if (position < 0 || position >= length) {
                printf("Invalid position!\n");
            } else {
                for (i = position; i < length - 1; i++) {
                    array[i] = array[i + 1];
                }
                length--;
                printf("Deleted! Now the array has %d elements.\n", length);
            }
        }

        else if (choice == 3) {
            // find cac gia tri
            int searchValue;
            int found = 0;
            printf("Enter value to search: ");
            scanf("%d", &searchValue);

            for (i = 0; i < length; i++) {
                if (array[i] == searchValue) {
                    printf("Found value %d at position %d!\n", searchValue, i);
                    found = 1;
                }
            }

            if (found == 0) {
                printf("Value not found in array!\n");
            }
        }

        else if (choice == 4) {
            // rearrange mang
            int order;
            printf("Sort ascending (1) or descending (2)? ");
            scanf("%d", &order);

            for (i = 0; i < length - 1; i++) {
                for (int j = i + 1; j < length; j++) {
                    if ((order == 1 && array[i] > array[j]) ||
                        (order == 2 && array[i] < array[j])) {
                        int temp = array[i];
                        array[i] = array[j];
                        array[j] = temp;
                    }
                }
            }

            printf("Array after sorting: ");
            for (i = 0; i < length; i++) {
                printf("%d ", array[i]);
            }
            printf("\n");
        }

        else if (choice == 5) {
            // out ct
            printf("Bye bye! See you again!\n");
        }

        else {
            // chon sai thi invalid
            printf("Invalid choice! Please enter from 1 to 5.\n");
        }

    } while (choice != 5);

    return 0;
}
