#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100   // Kich thuoc toi da cua mang

void inputArray(int arr[], int *n);
void printArray(int arr[], int n);
bool isPrime(int num);
int countPrime(int arr[], int n);
int findSecondMin(int arr[], int n);
void insertElement(int arr[], int *n);
void deleteElement(int arr[], int *n);
void bubbleSortDesc(int arr[], int n);
void binarySearch(int arr[], int n);
void removeDuplicates(int arr[], int *n);
void reverseArray(int arr[], int n);

int main() {
    int arr[MAX_SIZE];
    int n = 0;
    int choice;

    do {
        printf("\n===== MENU CHUONG TRINH =====\n");
        printf("1. Nhap so phan tu va gia tri cho mang\n");
        printf("2. In ra cac phan tu trong mang\n");
        printf("3. Dem so luong so nguyen to trong mang\n");
        printf("4. Tim gia tri nho thu hai trong mang\n");
        printf("5. Chen mot phan tu vao vi tri bat ky\n");
        printf("6. Xoa mot phan tu tai vi tri cu the\n");
        printf("7. Sap xep mang giam dan (Bubble Sort)\n");
        printf("8. Tim kiem phan tu (Binary Search)\n");
        printf("9. Xoa cac phan tu trung lap\n");
        printf("10. Dao nguoc thu tu cac phan tu\n");
        printf("0. Thoat chuong trinh\n");
        printf("==============================\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inputArray(arr, &n);
                break;
            case 2:
                printArray(arr, n);
                break;
            case 3:
                printf("So luong so nguyen to: %d\n", countPrime(arr, n));
                break;
            case 4:
                printf("Gia tri nho thu hai: %d\n", findSecondMin(arr, n));
                break;
            case 5:
                insertElement(arr, &n);
                break;
            case 6:
                deleteElement(arr, &n);
                break;
            case 7:
                bubbleSortDesc(arr, n);
                printf("Mang sau khi sap xep giam dan:\n");
                printArray(arr, n);
                break;
            case 8:
                binarySearch(arr, n);
                break;
            case 9:
                removeDuplicates(arr, &n);
                printf("Mang sau khi xoa trung lap:\n");
                printArray(arr, n);
                break;
            case 10:
                reverseArray(arr, n);
                printf("Mang sau khi dao nguoc:\n");
                printArray(arr, n);
                break;
            case 0:
                printf("Dang thoat chuong trinh...\n");
                break;
            default:
                printf("Lua chon khong hop le! Vui long thu lai.\n");
        }

    } while (choice != 0);

    return 0;
}

// ======== CAC HAM CHUC NANG ========
void inputArray(int arr[], int *n) {
    do {
        printf("Nhap so phan tu (1-100): ");
        scanf("%d", n);
    } while (*n <= 0 || *n > MAX_SIZE);

    for (int i = 0; i < *n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
}
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = %d", i, arr[i]);
        if (i < n - 1) printf(", ");
    }
    printf("\n");
}
bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}
int countPrime(int arr[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (isPrime(arr[i])) count++;
    }
    return count;
}
int findSecondMin(int arr[], int n) {
    if (n < 2) {
        printf("Mang khong du phan tu.\n");
        return -1;
    }

    int min = arr[0];
    int secondMin = __INT_MAX__;

    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            secondMin = min;
            min = arr[i];
        } else if (arr[i] > min && arr[i] < secondMin) {
            secondMin = arr[i];
        }
    }

    if (secondMin == __INT_MAX__) {
        printf("Tat ca cac phan tu giong nhau.\n");
        return min;
    }

    return secondMin;
}

void insertElement(int arr[], int *n) {
    if (*n >= MAX_SIZE) {
        printf("Mang da day, khong the chen!\n");
        return;
    }

    int value, pos;
    printf("Nhap gia tri muon chen: ");
    scanf("%d", &value);
    printf("Nhap vi tri can chen (0 - %d): ", *n);
    scanf("%d", &pos);

    if (pos < 0 || pos > *n) {
        printf("Vi tri khong hop le!\n");
        return;
    }

    for (int i = *n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }

    arr[pos] = value;
    (*n)++;

    printf("Da chen thanh cong!\n");
}

void deleteElement(int arr[], int *n) {
    int pos;
    printf("Nhap vi tri can xoa (0 - %d): ", *n - 1);
    scanf("%d", &pos);

    if (pos < 0 || pos >= *n) {
        printf("Vi tri khong hop le!\n");
        return;
    }

    for (int i = pos; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    (*n)--;

    printf("Da xoa thanh cong!\n");
}
void bubbleSortDesc(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void binarySearch(int arr[], int n) {
    int x;
    printf("Nhap gia tri can tim: ");
    scanf("%d", &x);

    int left = 0, right = n - 1;
    int found = 0;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == x) {
            found = 1;
            break;
        } else if (arr[mid] < x) {
            right = mid - 1; // vi mang giam dan
        } else {
            left = mid + 1;
        }
    }

    if (found)
        printf("Phan tu ton tai trong mang.\n");
    else
        printf("Khong tim thay phan tu.\n");
}
void removeDuplicates(int arr[], int *n) {
    for (int i = 0; i < *n; i++) {
        for (int j = i + 1; j < *n; ) {
            if (arr[i] == arr[j]) {
                for (int k = j; k < *n - 1; k++) {
                    arr[k] = arr[k + 1];
                }
                (*n)--;
            } else {
                j++;
            }
        }
    }
}
void reverseArray(int arr[], int n) {
    for (int i = 0; i < n / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = temp;
    }
}

