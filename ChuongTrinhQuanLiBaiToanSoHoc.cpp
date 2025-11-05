#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100
void inputArray(int arr[], int *n);
void printArray(int arr[], int n);
bool isPrime(int x);
int countPrime(int arr[], int n);
int findSecondMin(int arr[], int n);
void insertElement(int arr[], int *n, int value, int pos);
void deleteElement(int arr[], int *n, int pos);
void bubbleSortDesc(int arr[], int n);
bool binarySearch(int arr[], int n, int x);
void removeDuplicates(int arr[], int *n);
void reverseArray(int arr[], int n);

int main() {
    int arr[MAX];
    int n = 0;
    int choice;

    do {
        printf("\n- MENU CHUONG TRINH -\n");
        printf("1. Nhap so phan tu va gia tri cho mang\n");
        printf("2. In ra gia tri cac phan tu trong mang\n");
        printf("3. Dem so luong so nguyen to trong mang\n");
        printf("4. Tim gia tri nho thu hai trong mang\n");
        printf("5. Them mot phan tu vao vi tri bat ky\n");
        printf("6. Xoa phan tu tai mot vi tri cu the\n");
        printf("7. Sap xep mang giam dan (Bubble Sort)\n");
        printf("8. Tim kiem phan tu trong mang (Binary Search)\n");
        printf("9. Xoa toan bo phan tu trung lap trong mang\n");
        printf("10. Dao nguoc thu tu cac phan tu trong mang\n");
        printf("0. Thoat chuong trinh\n");
        printf("Moi ban chon: ");
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
                if (n > 1)
                    printf("Gia tri nho thu hai: %d\n", findSecondMin(arr, n));
                else
                    printf("Mang khong du phan tu!\n");
                break;
            case 5: {
                int value, pos;
                printf("Nhap gia tri can chen: ");
                scanf("%d", &value);
                printf("Nhap vi tri can chen (0..%d): ", n);
                scanf("%d", &pos);
                insertElement(arr, &n, value, pos);
                break;
            }
            case 6: {
                int pos;
                printf("Nhap vi tri can xoa (0..%d): ", n-1);
                scanf("%d", &pos);
                deleteElement(arr, &n, pos);
                break;
            }
            case 7:
                bubbleSortDesc(arr, n);
                printf("Mang sau khi sap xep giam dan:\n");
                printArray(arr, n);
                break;
            case 8: {
                int x;
                printf("Nhap gia tri can tim: ");
                scanf("%d", &x);
                if (binarySearch(arr, n, x))
                    printf("Ton tai!\n");
                else
                    printf("Khong ton tai!\n");
                break;
            }
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
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (choice != 0);

    return 0;
}

void inputArray(int arr[], int *n) {
    do {
        printf("Nhap so phan tu (0 < n <= %d): ", MAX);
        scanf("%d", n);
    } while (*n <= 0 || *n > MAX);

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

bool isPrime(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

int countPrime(int arr[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++)
        if (isPrime(arr[i])) count++;
    return count;
}

int findSecondMin(int arr[], int n) {
    int min = arr[0], secondMin;
    for (int i = 1; i < n; i++)
        if (arr[i] < min)
            min = arr[i];

    secondMin = 2147483647;
    for (int i = 0; i < n; i++)
        if (arr[i] > min && arr[i] < secondMin)
            secondMin = arr[i];

    if (secondMin == 2147483647)
        printf("Khong co gia tri nho thu hai!\n");

    return secondMin;
}

void insertElement(int arr[], int *n, int value, int pos) {
    if (*n >= MAX || pos < 0 || pos > *n) {
        printf("Vi tri khong hop le!\n");
        return;
    }
    for (int i = *n; i > pos; i--)
        arr[i] = arr[i - 1];
    arr[pos] = value;
    (*n)++;
}

void deleteElement(int arr[], int *n, int pos) {
    if (pos < 0 || pos >= *n) {
        printf("Vi tri khong hop le!\n");
        return;
    }
    for (int i = pos; i < *n - 1; i++)
        arr[i] = arr[i + 1];
    (*n)--;
}

void bubbleSortDesc(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

bool binarySearch(int arr[], int n, int x) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == x)
            return true;
        else if (arr[mid] < x)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return false;
}

void removeDuplicates(int arr[], int *n) {
    for (int i = 0; i < *n - 1; i++) {
        for (int j = i + 1; j < *n; ) {
            if (arr[i] == arr[j]) {
                for (int k = j; k < *n - 1; k++)
                    arr[k] = arr[k + 1];
                (*n)--;
            } else j++;
        }
    }
}

void reverseArray(int arr[], int n) {
    for (int i = 0; i < n / 2; i++) {
        int tmp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = tmp;
    }
}
