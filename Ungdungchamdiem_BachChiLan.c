#include <stdio.h>

// Ham kiem tra nhap diem hep le hay khong
double nhapDiem(const char *name) {
    double d;
    do {
        printf("Nhap %s (0-10): ", name);
        scanf("%lf", &d);
        if (d < 0 || d > 100)
            printf("Diem khong hop le! Xin vui long nhap lai.\n");
    } while (d < 0 || d > 100);
    return d;
}
int main() {
    double lt_giua = -1, th_giua = -1;
    double lt_cuoi = -1, th_cuoi = -1;
    int choose;

    do {
        printf("\n===== MENU =====\n");
        printf("1. Nhap diem GIUA KI (LT + TH)\n");
        printf("2. Nhap diem CUOI KI (LT + TH)\n");
        printf("3. Tinh diem trung binh mon\n");
        printf("4. Kiem tra can bao nhieu diem de qua mon\n");
        printf("   4.1 Chua thi LT cuoi ki\n");
        printf("   4.2 Da co LT cuoi ki => tinh diem TH cuoi ki\n");
        printf("5. Kiem tra qua mon (>=50)\n");
        printf("6. Thi lai (nhap lai diem LT + TH cuoi ki)\n");
        printf("7. Thoat\n");
        printf("Chon chuc nang: ");
        scanf("%d", &choose);
         
		 
		 switch (choose) {
        case 1:
            lt_giua = nhapDiem("diem LY THUYET giua ki");
            th_giua = nhapDiem("diem THUC HANH giua ki");
            break;

        case 2:
            lt_cuoi = nhapDiem("diem LY THUYET cuoi ki");
            th_cuoi = nhapDiem("diem THUC HANH cuoi ki");
            break;

        case 3:
            if (lt_giua < 0 || th_giua < 0 || lt_cuoi < 0 || th_cuoi < 0) {
                printf("Ban chua nhap du diem!\n");
                break;
            }
            {
                double giua = (lt_giua + th_giua) / 2.0;
                double cuoi = (lt_cuoi + th_cuoi) / 2.0;
                double tb = giua * 0.3 + cuoi * 0.7;
                printf("Diem trung binh mon = %.2f\n", tb);
            }
            break;
        
        case 4:
        	if(lt_giua < 0 || th_giua < 0){
        		printf("Chua co diem giua ki!\n");
                break;
		}
		{
			int mode;
			  printf("Nhap 1 neu chua thi LT cuoi ki, nhap 2 neu da thi LT cuoi ki: ");
                scanf("%d", &mode);
                double giua = (lt_giua + th_giua) / 2.0;

                if (mode == 1) {
                    double need = (5.0 - giua * 0.3) / 0.7;
                    if (need <= 0)
                        printf("0 diem cuoi ki cung qua!\n");
                    else if (need > 100)
                        printf("Khong the qua mon (can > 100)!\n");
                    else
                        printf("Can TB cuoi ki toi thieu: %.2f\n", need);
		}
		else if (mode == 2) {
                    if (lt_cuoi < 0) {
                        printf("Chua co diem LT cuoi ki!\n");
                        break;
                    }
                    double diem_lt = lt_cuoi * 0.5 * 0.7;
                    double diem_giua = giua * 0.3;
                    double diem_con_lai = 5.0 - (diem_lt + diem_giua);
                    double th_need = diem_con_lai / (0.5 * 0.7);
                    if (th_need <= 0)
                        printf("0 diem TH cuoi ki cung qua!\n");
                    else if (th_need > 100)
                        printf("Khong the qua mon (need > 100)!\n");
                    else
                        printf("Can diem TH cuoi ki toi thieu: %.2f\n", th_need);
                } 
                else {
                    printf("Lua chon khong hop le!\n");
                }
            }
            break;
        
		case 5:
			if (lt_giua < 0 || th_giua < 0 || lt_cuoi < 0 || th_cuoi < 0) {
                printf("Ban chua nhap du diem!\n");
                break;
            }
            {
                double giua = (lt_giua + th_giua) / 2.0;
                double cuoi = (lt_cuoi + th_cuoi) / 2.0;
                double tb = giua * 0.3 + cuoi * 0.7;
                printf("Diem TB = %.2f => %s\n", tb, (tb >= 50) ? "Qua mon!" : "Rot mon!");
            }
            break;

        case 6:
            if (lt_giua < 0 || th_giua < 0) {
                printf("Chua co diem giua ki!\n");
                break;
            }
            printf("Nhap lai diem CUOI KI (thi lai):\n");
            lt_cuoi = nhapDiem("diem LY THUYET cuoi ki moi");
            th_cuoi = nhapDiem("diem THUC HANH cuoi ki moi");
            printf("Ban da cap nhat duoc diem cuoi ki moi!\n");
            break;

        case 7:
            printf("Tam biet <3\n");
            break;

        default:
            printf("Lua chon khong hop le!\n");
        }
    } while (choose != 7);
    
	return 0;
}

