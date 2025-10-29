#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main() {
	float soDu = 5000000;   // s? du ban d?u 5 tri?u
	float duNo = 0;         // du n? ban d?u
	int chon;
	float soTien;

	do {
		printf("\n DUC HUY BANK \n");
		printf("1. Xem so du\n");
		printf("2. Nap tien\n");
		printf("3. Rut tien\n");
		printf("4. Chuyen tien\n");
		printf("5. Vay no\n");
		printf("6. Xem du no\n");
		printf("7. Tra no (tru vao tai khoan hoac nap tien de tra)\n");
		printf("8. Thoat\n");
		printf("Chon chuc nang: ");
		scanf("%d", &chon);

		switch (chon) {
		case 1:
			printf("\nSo du hien tai: %.0f VND\n", soDu);
			break;

		case 2:
			printf("\nNhap so tien muon nap: ");
			scanf("%f", &soTien);
			soDu += soTien;
			printf("Da nap thanh cong. So du moi: %.0f VND\n", soDu);
			break;

		case 3:
			printf("\nNhap so tien muon rut: ");
			scanf("%f", &soTien);
			if (soTien > soDu)
				printf("Khong du tien de rut!\n");
			else {
				soDu -= soTien;
				printf("Rut thanh cong. So du moi: %.0f VND\n", soDu);
			}
			break;

		case 4:
			printf("\nNhap so tien muon chuyen: ");
			scanf("%f", &soTien);
			if (soTien > soDu)
				printf("Khong du tien de chuyen!\n");
			else {
				soDu -= soTien;
				printf("Da chuyen %.0f VND thanh cong.\n", soTien);
				printf("So du con lai: %.0f VND\n", soDu);
			}
			break;

		case 5:
			printf("\nNhap so tien muon vay: ");
			scanf("%f", &soTien);
			soDu += soTien;
			duNo += soTien;
			printf("Da vay %.0f VND thanh cong.\n", soTien);
			printf("So du hien tai: %.0f VND | Du no: %.0f VND\n", soDu, duNo);
			break;

		case 6:
			printf("\nDu no hien tai: %.0f VND\n", duNo);
			break;

		case 7:
			if (duNo == 0) {
				printf("\nBan khong co du no.\n");
				break;
			}
			printf("\nSo du hien tai: %.0f VND | Du no: %.0f VND\n", soDu, duNo);

			if (soDu >= duNo) {
				soDu -= duNo;
				printf("Da tra het no %.0f VND bang tien trong tai khoan.\n", duNo);
				duNo = 0;
			} else {
				printf("So du khong du de tra het no.\n");
				printf("Ban muon nap them tien de tra no? (1: Co, 0: Khong): ");
				int napThem;
				scanf("%d", &napThem);

				if (napThem == 1) {
					printf("Nhap so tien muon nap: ");
					scanf("%f", &soTien);
					soDu += soTien;
					if (soDu >= duNo) {
						soDu -= duNo;
						printf("Da tra het no %.0f VND sau khi nap them.\n", duNo);
						duNo = 0;
					} else {
						duNo -= soDu;
						printf("Chi tra duoc %.0f VND, con no %.0f VND.\n", soDu, duNo);
						soDu = 0;
					}
				} else {
					printf("Ban da chon khong nap them. Chua tra no.\n");
				}
			}
			printf("So du hien tai: %.0f VND | Du no con lai: %.0f VND\n", soDu, duNo);
			break;

		case 8:
			printf("\nDang thoat chuong trinh...\n");
			break;

		default:
			printf("\nLua chon khong hop le. Vui long chon 1-8.\n");
		}

	} while (chon != 8);

	printf("Cam on ban da su dung chuong trinh! \n");
	printf("Neu co van de truc trac ky thuat hay lien he giam doc Duc Huy");
	return 0;
}
