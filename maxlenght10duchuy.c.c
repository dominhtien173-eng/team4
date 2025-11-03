#include <stdio.h>

#define LIMIT 10  

int main() {
    int data[LIMIT];
    int count = 0;
    int option, input, index, match;


    do {
        printf("How many numbers do you want to store MAX(10) ");
        scanf("%d", &count);
    } while (count < 1 || count > LIMIT);

    
    for (int i = 0; i < count; i++) {
        printf("Enter number #%d: ", i + 1);
        scanf("%d", &data[i]);
    }

    // Menu loop
    do {
        printf("\n<=== MENU ===>\n");
        printf("1. Insert a new number\n");
        printf("2. Remove a number by index\n");
        printf("3. Search for a number\n");
        printf("4. Sort the array\n");
        printf("5. Quit\n");
        printf("Select: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                if (count >= LIMIT) {
                    printf("Array is full. Cannot insert more.\n");
                } else {
                    printf("Enter number to insert: ");
                    scanf("%d", &input);
                    data[count++] = input;
                    printf("Number added. Current array: ");
                    for (int i = 0; i < count; i++) printf("%d ", data[i]);
                    printf("\n");
                }
                break;

            case 2:
                if (count == 0) {
                    printf("Array is empty. Nothing to remove.\n");
                } else {
                    printf("Enter index to remove (0 to %d): ", count - 1);
                    scanf("%d", &index);
                    if (index < 0 || index >= count) {
                        printf("Invalid index.\n");
                    } else {
                        for (int i = index; i < count - 1; i++) {
                            data[i] = data[i + 1];
                        }
                        count--;
                        printf("Removed. Current array: ");
                        for (int i = 0; i < count; i++) printf("%d ", data[i]);
                        printf("\n");
                    }
                }
                break;

            case 3:
                printf("Enter number to find: ");
                scanf("%d", &input);
                match = -1;
                for (int i = 0; i < count; i++) {
                    if (data[i] == input) {
                        match = i;
                        break;
                    }
                }
                if (match != -1) {
                    printf("Found %d at position %d.\n", input, match);
                } else {
                    printf("%d not found in the array.\n", input);
                }
                break;

            case 4:
                if (count == 0) {
                    printf("Array is empty. Nothing to sort.\n");
                } else {
                    int mode;
                    printf("Sort order? (1 = Ascending, 2 = Descending): ");
                    scanf("%d", &mode);
                    for (int i = 0; i < count - 1; i++) {
                        for (int j = i + 1; j < count; j++) {
                            if ((mode == 1 && data[i] > data[j]) ||
                                (mode == 2 && data[i] < data[j])) {
                                int temp = data[i];
                                data[i] = data[j];
                                data[j] = temp;
                            }
                        }
                    }
                    printf("Sorted array: ");
                    for (int i = 0; i < count; i++) printf("%d ", data[i]);
                    printf("\n");
                }
                break;

            case 5:
                printf("Goodbye!\n");
                break;

            default:
                printf("Invalid option. Try again.\n");
        }

    } while (option != 5);

    return 0;
}