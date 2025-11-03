#include <stdio.h>

#define MAX_SIZE 10  

int main() {
    int arr[MAX_SIZE];  // Mang so nguyen
    int n;              // So phan tu trong mang
    int choice, value, pos, i, found = 0; // Bien su dung trong chuong trinh
    do {
        printf("Enter number of elements (max 10): ");
        scanf("%d", &n);
    } while (n < 0 || n > MAX_SIZE);

    // Nhap gia tri cho tung phan tu
    for (i = 0; i < n; i++) {
        printf("Enter arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }
    do {
        printf("\nMenu\n");
        printf("1. Add a new value to the array\n");
        printf("2. Delete an element at any position\n");
        printf("3. Search for a value in the array\n");
        printf("4. Exit\n");
        printf("Choose: ");
        scanf("%d", &choice);  

        switch (choice) {
            case 1:
                // Them mot gia tri moi vao cuoi mang
                if (n >= MAX_SIZE) {
                    printf("Array is full, cannot add more!\n");
                } else {
                    printf("Enter the value to add: ");
                    scanf("%d", &value);
                    arr[n] = value; // Them vao cuoi mang
                    n++;
                    printf("Array after adding: ");
                    for (i = 0; i < n; i++) printf("%d ", arr[i]);
                    printf("\n");
                }
                break;

            case 2:
                // Xoa mot phan tu o vi tri bat ky
                if (n == 0) {
                    printf("Array is empty, cannot delete!\n");
                } else {
                    printf("Enter position to delete (0 -> %d): ", n - 1);
                    scanf("%d", &pos);
                    if (pos < 0 || pos >= n) {
                        printf("Invalid position!\n");
                    } else {
                        for (i = pos; i < n - 1; i++) {
                            arr[i] = arr[i + 1]; // Dich cac phan tu qua trai
                        }
                        n--; // Giam kich thuoc mang
                        printf("Array after deletion: ");
                        for (i = 0; i < n; i++) printf("%d ", arr[i]);
                        printf("\n");
                    }
                }
                break;

            case 3:
                printf("Enter value to search: ");
                scanf("%d", &value);
                found = 0;
                for (i = 0; i < n; i++) {
                    if (arr[i] == value) {
                        printf("Value %d found at position %d\n", value, i);
                        found = 1;
                    }
                }
                if (!found) {
                    printf("Value %d not found in the array\n", value);
                }
                break;

            case 4:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
                }
                }  
            while (choice != 4); 

    return 0;
}

