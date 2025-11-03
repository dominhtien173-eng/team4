#include <stdio.h>

#define MAX_SIZE 10  

int main() {
	int arr[MAX_SIZE];
    int n; // so phan tu cua mang
    int choice, value, pos, i, found = 0;

    do {
        printf("Nhap so phan tu cua mang (toi da 10): ");
        scanf("%d", &n);
    } while (n < 0 || n > MAX_SIZE);

    for (i = 0; i < n; i++) {
        printf("Nhap arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }
    do {
    	printf("\nMenu\n");
    	printf("1.Them mot gia tri vao mang\n");
    	printf("2.Xoa mot phan tu o vi tri bat ki\n");
    	printf("3.Tim kiem mot gia tri trong mang\n");
    	printf("4.Thoat\n");
    	printf("Chon: ");
    	scanf("%d",&n);
    	
    	switch (choice) {
            case 1:
                if (n >= MAX_SIZE) {
                    printf("Mang da day, khong the them!\n");
                } else {
                    printf("Nhap gia tri can them: ");
                    scanf("%d", &value);
                    arr[n] = value; // them vao cuoi mang
                    n++;
                    printf("Mang sau khi them: ");
                    for (i = 0; i < n; i++) printf("%d ", arr[i]);
                    printf("\n");
                }
                break;
                
                case 2:
                	if (n==0){
                		printf("Mang rong,khong the xoa!\n");
                	}
					else {
					printf("Nhap vi tri muon xoa(0->%d):",n-1);
					scanf("%d",&pos);
					 if (pos < 0 || pos >= n) {
                        printf("Vi tri khong hop le!\n");
                    } else {
                        for (i = pos; i < n - 1; i++) {
                            arr[i] = arr[i + 1];
                        }
                        n--; // giam kich thuoc
                        printf("Mang sau khi xoa: ");
                        for (i = 0; i < n; i++) printf("%d ", arr[i]);
                        printf("\n");
                    }
                }
                break;	
                case 3:
                	printf("Nhap gia tri can tim: ");
                scanf("%d", &value);
                found = 0;
                for (i = 0; i < n; i++) {
                    if (arr[i] == value) {
                        printf("Gia tri %d ton tai tai vi tri %d\n", value, i);
                        found = 1;
                    }
                }
                if (!found) {
                    printf("Gia tri %d khong ton tai trong mang\n", value);
                }
                break;

            case 4:
                printf("Thoat chuong trinh.\n");
                break;

            default:
                printf("Lua chon khong hop le!\n");
               }

               } while (choice != 4);
    	
	return 0;
}
