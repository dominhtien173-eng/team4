#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	double SoDu = 1000000;
	double DuNo = 0;
    double Tien;
	int choice;
	
	 printf(" NGAN HANG CHU TICH  \n");
        printf("1. Xem so du\n");
        printf("2. Nap tien\n");
        printf("3. Rut tien\n");
        printf("4. Chuyen tien\n");
        printf("5. Vay no\n");
        printf("6. Xem du no\n");
        printf("7. Tra du no\n");
        printf("8. Thoat\n");
        
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("So du hien tai: %.2f VND\n", SoDu);
                break;

            case 2:
                printf("\nNhap so tien muon nap: ");
            scanf("%lf", &Tien);
            if (Tien > 0) {
                SoDu += Tien;
                printf("So du moi: %.2f VND\n", SoDu);
            } else {
                printf("So tien khong hop le!\n");
            }
				
                break;
             case 3:
                printf("\nNhap so tien muon rut: ");
                scanf("%lf", &Tien);
                if (Tien > 0 && Tien <= SoDu) {
                    SoDu -= Tien;
                    printf("So du con lai: %.2f VND\n", SoDu);
                } else {
                    printf("? So tien khong hop le !\n");
                }
                break;
                  case 4:
            printf("\nNhap so tien muon chuyen: ");
            scanf("%lf", &Tien);
            if (Tien > 0 && Tien <= SoDu) {
                SoDu -= Tien;
                printf("So du con lai: %.2f VND\n", SoDu);
            } else {
                printf("So tien khong hop le!\n");
            }
            break;

        case 5:
            printf("\nNhap so tien muon vay: ");
            scanf("%lf", &Tien);
            if (Tien > 0) {
                DuNo += Tien;
                SoDu += Tien;
                printf(" Vay thanh cong %.2f VND!\n", Tien);
                printf(" Du no hien tai: %.2f VND\n", DuNo);
            } else {
                printf(" So tien vay khong hop le!\n");
            }
            break;

        case 6:
            printf(" Du no hien tai: %.2f VND\n", DuNo);
            break;

        case 7:
            if (DuNo == 0) {
                printf("Ban khong co du no nao de tra!\n");
                break;
            }
            printf("Nhap so tien muon tra no: ");
            scanf("%lf", &Tien);
            if (Tien > 0 && Tien <= SoDu && Tien <= DuNo) {
                SoDu -= Tien;
                DuNo -= Tien;
                printf(" Tra no thanh cong!\n");
                printf(" Du no con lai: %.2f VND\n", DuNo);
                printf("So du con lai: %.2f VND\n", SoDu);
            } else {
                printf("So tien khong hop le !\n");
            }
            break;

        case 8:
            printf(" Tam biet!\n");
            break;

        default:
            printf("Lua chon khong hop le\n");
            break;
        }

	return 0;
}

