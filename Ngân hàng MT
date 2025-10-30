#include <stdio.h>

int main() {
    float balance=99999999, outstanding_debt=0, account=666666, money; // So Du , Du No , Tai Khoan , Tien
    int c, cach;

    do {
        printf("\n===== MENU NGAN HANG MINH TIEN BANK =====\n");
        printf("1. View balance\n"); // Xem So Du
        printf("2. Deposit\n"); // Nap Tien
        printf("3. Withdraw money\n"); // Rut Tien
        printf("4. Transfer money\n"); //Chuyen Tien
        printf("5. Debt\n"); // Vay No
        printf("6. View outstanding balance\n"); // Xem Du No
        printf("7. Debt repayment\n"); // Tra No
        printf("8. Exit\n"); // Thoat
        printf("Select function (1-8): "); // Chon Cac Muc
          scanf("%d", &c);

        switch(c){
            case 1: printf("Balance: %.0f\n",balance); // So Du
			break;
			
            case 2: printf("Deposit: "); // Nap Tien
			scanf("%f",&money); balance+=money;
			 break;
			 
            case 3: printf("Withdraw: "); // Rut
			scanf("%f",&money);
			 
			if(money<=balance)balance-=money;
			else printf("Insufficient!\n"); // Khong Du
			break;
			
            case 4: printf("Transfer: "); // Chuyen
			scanf("%f",&money); 
			
			if(money<=balance){balance-=money; account+=money;} 
			else printf("Insufficient!\n"); // Khong Du
			break;
			
            case 5: printf("Borrow: "); // Vay Muon
			scanf("%f",&money); balance+=money; outstanding_debt+=money; 
			break;
			
            case 6: printf("outstanding_debt: %.0f\n",outstanding_debt); // Du No
			break;
			
            case 7:
                if(outstanding_debt<=0){
				printf("No Debt!\n"); // Khong No
				break;}
				
                printf("1.Subtract from the balance  2.Top up to pay: "); // Tru Vao So Du // Nap Tien De Thanh Toan
				scanf("%d",&cach);
				
                if(cach==1&&balance>=outstanding_debt){balance-=outstanding_debt;outstanding_debt=0;}
                else if(cach==2)
				{printf("Deposit: "); // Nap Tien
				scanf("%f",&money); 
                
				if(money>=outstanding_debt){balance+=money-outstanding_debt;outstanding_debt=0;} 
				else outstanding_debt-=money;}
                else printf("Insufficient!\n"); // Khong Du
                break;
        }
    } while(c!=8);
    return 0;
}

