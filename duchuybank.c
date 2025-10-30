#include <stdio.h>
#include <stdlib.h>

int main() {
	float balance = 5000000;   
	float debt = 0;            
	int choice;
	float amount;

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
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			printf("\nSo du hien tai: %.0f VND\n", balance);
			break;

		case 2:
			printf("\nNhap so tien muon nap: ");
			scanf("%f", &amount);
			balance += amount;
			printf("Da nap thanh cong. So du moi: %.0f VND\n", balance);
			break;

		case 3:
			printf("\nNhap so tien muon rut: ");
			scanf("%f", &amount);
			if (amount > balance)
				printf("Khong du tien de rut!\n");
			else {
				balance -= amount;
				printf("Rut thanh cong. So du moi: %.0f VND\n", balance);
			}
			break;

		case 4:
			printf("\nNhap so tien muon chuyen: ");
			scanf("%f", &amount);
			if (amount > balance)
				printf("Khong du tien de chuyen!\n");
			else {
				balance -= amount;
				printf("Da chuyen %.0f VND thanh cong.\n", amount);
				printf("So du con lai: %.0f VND\n", balance);
			}
			break;

		case 5:
			printf("\nNhap so tien muon vay: ");
			scanf("%f", &amount);
			balance += amount;
			debt += amount;
			printf("Da vay %.0f VND thanh cong.\n", amount);
			printf("So du hien tai: %.0f VND | Du no: %.0f VND\n", balance, debt);
			break;

		case 6:
			printf("\nDu no hien tai: %.0f VND\n", debt);
			break;

		case 7:
			if (debt == 0) {
				printf("\nBan khong co du no.\n");
				break;
			}
			printf("\nSo du hien tai: %.0f VND | Du no: %.0f VND\n", balance, debt);

			if (balance >= debt) {
				balance -= debt;
				printf("Da tra het no %.0f VND bang tien trong tai khoan.\n", debt);
				debt = 0;
			} else {
				printf("So du khong du de tra het no.\n");
				printf("Ban muon nap them tien de tra no? (1: Co, 0: Khong): ");
				int depositMore;
				scanf("%d", &depositMore);

				if (depositMore == 1) {
					printf("Nhap so tien muon nap: ");
					scanf("%f", &amount);
					balance += amount;
					if (balance >= debt) {
						balance -= debt;
						printf("Da tra het no %.0f VND sau khi nap them.\n", debt);
						debt = 0;
					} else {
						debt -= balance;
						printf("Chi tra duoc %.0f VND, con no %.0f VND.\n", balance, debt);
						balance = 0;
					}
				} else {
					printf("Ban da chon khong nap them. Chua tra no.\n");
				}
			}
			printf("So du hien tai: %.0f VND | Du no con lai: %.0f VND\n", balance, debt);
			break;

		case 8:
			printf("\nDang thoat chuong trinh...\n");
			break;

		default:
			printf("\nLua chon khong hop le. Vui long chon tu 1-8.\n");
		}

	} while (choice != 8);

	printf("Cam on ban da su dung chuong trinh!\n");
	printf("Neu co van de truc trac ky thuat hay lien he giam doc Duc Huy.\n");
	return 0;
}
