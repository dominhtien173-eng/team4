#include <stdio.h>

int main() {
    int von[12] = {0};
    int thuNhap[12] = {0};
    int lai[12] = {0};
    int luaChon;

    do {
        printf("===== MENU CHUONG TRINH =====\n");
        printf("1. Chinh sua thong tin\n");
        printf("2. Xem thong tin tien lai\n");
        printf("3. Tinh tong doanh thu trong nam\n");
        printf("4. Thoat\n");
        printf("=============================\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &luaChon);

        if (luaChon == 1) {
            int thang;
            printf("Nhap thang muon chinh sua (1-12): ");
            scanf("%d", &thang);
            if (thang < 1 || thang > 12) {
                printf("Thang khong hop le. Vui long nhap tu 1 den 12.\n");
            } else {
                int chon;
                do {
                    printf("Chon thong tin muon chinh sua:\n");
                    printf("1. Von\n");
                    printf("2. Tong thu nhap\n");
                    printf("3. Thoat\n");
                    printf("Nhap lua chon: ");
                    scanf("%d", &chon);

                    if (chon == 1) {
                        printf("Nhap von thang %d: ", thang);
                        scanf("%d", &von[thang - 1]);
                        lai[thang - 1] = thuNhap[thang - 1] - von[thang - 1];
                    } else if (chon == 2) {
                        printf("Nhap tong thu nhap thang %d: ", thang);
                        scanf("%d", &thuNhap[thang - 1]);
                        lai[thang - 1] = thuNhap[thang - 1] - von[thang - 1];
                    } else if (chon != 3) {
                        printf("Lua chon khong hop le.\n");
                    }
                } while (chon != 3);
            }
        } else if (luaChon == 2) {
            int thang;
            printf("Nhap thang muon xem (1-12): ");
            scanf("%d", &thang);
            if (thang < 1 || thang > 12) {
                printf("Thang khong hop le. Vui long nhap tu 1 den 12.\n");
            } else {
                int tienLai = lai[thang - 1];
                printf("Tien lai thang %d la: %d\n", thang, tienLai);
                if (tienLai < 0) {
                    printf("Thang %d: Lo\n", thang);
                } else if (tienLai > 0) {
                    printf("Thang %d: Loi\n", thang);
                } else {
                    printf("Thang %d: Hoa von\n", thang);
                }
            }
        } else if (luaChon == 3) {
            int tongThuNhap = 0;
            for (int i = 0; i < 12; i++) {
                tongThuNhap += thuNhap[i];
            }
            printf("Tong doanh thu trong nam la: %d\n", tongThuNhap);
        } else if (luaChon == 4) {
            printf("Tam biet!\n");
        } else {
            printf("Lua chon khong hop le. Vui long chon lai.\n");
        }

        printf("\n");

    } while (luaChon != 4);

    return 0;
}
