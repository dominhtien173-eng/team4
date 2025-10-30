#include <stdio.h>
#include <stdlib.h>

int main() {
	float balance = 5000000;   // Sa; dF0 ban Da:'u 5 tria;u
	float debt = 0;            // DF0 na;# ban Da:'u
	int choice;
	float amount;

	do {
		printf("\n DUC HUY BANK \n");
		printf("1. Xem sa; dF0\n");
		printf("2. Na:!p tia;n\n");
		printf("3. RC:t tia;n\n");
		printf("4. Chuya;n tia;n\n");
		printf("5. Vay na;#\n");
		printf("6. Xem dF0 na;#\n");
		printf("7. Tra:# na;# (tra;+ vC o tC i khoa:#n hoa:7c na:!p tia;n Da; tra:#)\n");
		printf("8. ThoC!t\n");
		printf("Cha;
       n cha;)c nDng: ");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			printf("\nSa; dF0 hia;n ta:!i: %.0f VND\n", balance);
			break;

		case 2:
			printf("\nNha:-p sa; tia;n mua;n na:!p: ");
			scanf("%f", &amount);
			balance += amount;
			printf("DC# na:!p thC nh cC4ng. Sa; dF0 ma;i: %.0f VND\n", balance);
			break;

		case 3:
			printf("\nNha:-p sa; tia;n mua;n rC:t: ");
			scanf("%f", &amount);
			if (amount > balance)
				printf("KhC4ng Da;' tia;n Da; rC:t!\n");
			else {
				balance -= amount;
				printf("RC:t thC nh cC4ng. Sa; dF0 ma;i: %.0f VND\n", balance);
			}
			break;

		case 4:
			printf("\nNha:-p sa; tia;n mua;n chuya;n: ");
			scanf("%f", &amount);
			if (amount > balance)
				printf("KhC4ng Da;' tia;n Da; chuya;n!\n");
			else {
				balance -= amount;
				printf("DC# chuya;n %.0f VND thC nh cC4ng.\n", amount);
				printf("Sa; dF0 cC2n la:!i: %.0f VND\n", balance);
			}
			break;

		case 5:
			printf("\nNha:-p sa; tia;n mua;n vay: ");
			scanf("%f", &amount);
			balance += amount;
			debt += amount;
			printf("DC# vay %.0f VND thC nh cC4ng.\n", amount);
			printf("Sa; dF0 hia;n ta:!i: %.0f VND | DF0 na;#: %.0f VND\n", balance, debt);
			break;

		case 6:
			printf("\nDF0 na;# hia;n ta:!i: %.0f VND\n", debt);
			break;

		case 7:
			if (debt == 0) {
				printf("\nBa:!n khC4ng cC3 dF0 na;#.\n");
				break;
			}
			printf("\nSa; dF0 hia;n ta:!i: %.0f VND | DF0 na;#: %.0f VND\n", balance, debt);

			if (balance >= debt) {
				balance -= debt;
				printf("DC# tra:# ha:?t na;# %.0f VND ba:1ng tia;n trong tC i khoa:#n.\n", debt);
				debt = 0;
			} else {
				printf("Sa; dF0 khC4ng Da;' Da; tra:# ha:?t na;#.\n");
				printf("Ba:!n mua;n na:!p thC*m tia;n Da; tra:# na;#? (1: CC3, 0: KhC4ng): ");
				int depositMore;
				scanf("%d", &depositMore);

				if (depositMore == 1) {
					printf("Nha:-p sa; tia;n mua;n na:!p: ");
					scanf("%f", &amount);
					balance += amount;
					if (balance >= debt) {
						balance -= debt;
						printf("DC# tra:# ha:?t na;# %.0f VND sau khi na:!p thC*m.\n", debt);
						debt = 0;
					} else {
						debt -= balance;
						printf("Cha;	 tra:# DF0a;#c %.0f VND, cC2n na;# %.0f VND.\n", balance, debt);
						balance = 0;
					}
				} else {
					printf("Ba:!n DC# cha;
					       n khC4ng na:!p thC*m. ChF0a tra:# na; #.\n");
				}
			}
			printf("Sa; dF0 hia;n ta:!i: %.0f VND | DF0 na;# cC2n la:!i: %.0f VND\n", balance, debt);
			break;

		case 8:
			printf("\nDang thoC!t chF0F!ng trC,nh...\n");
			break;

		default:
			printf("\nLa;1a cha;
			       n khC4ng ha; #p la; . Vui lC2ng cha;
			       n ta; + 1-8.\n");
		}

	} while (choice != 8);

	printf("Ca:#m F!n ba:!n DC# sa;- da;%ng chF0F!ng trC,nh!\n");
	printf("Na:?u cC3 va:%n Da; tra;%c tra:7c ka;9 thua:-t hC#y liC*n ha; giC!m Da;c Da;)c Huy.\n");
	return 0;
}
