#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	float midterm_theory = -1, midterm_practice = -1;
	float finnal_theory = -1, finnal_practice = -1;
	float average = 0;
	int choice;
	int hasMidterm = 0, hasFinal = 0;
	float passMark = 50; //Diem qua mon
	
	do{
		printf("\n==== Scoring application ====\n");
		printf("1.Enter your midterm score (theory & practice)\n");
		printf("2.Enter your finnal score (theory & practice)\n");
		printf("3.Check how many piont needed to pass the subject\n");
		printf("4.Check if passed the subject\n");
		printf("5.Retake finnal exam (only finnal)\n");
		printf("6.Exit\n");
		scanf("%d", &choice);
		
		switch (choice) {
			case 1:
				printf("Enter midterm thoery score: "); //nhap diem li thuyet giua ki
				scanf("%f", &midterm_theory);
				printf("Enter midterm practice score: ");//nhap diem thuc hanh giua ki
				scanf("%f", &midterm_practice);
				hasMidterm = 1;
				Printf("Midterm score saved: ");
				break;
			case 2:
				printf("Enter final theory score: ");// lt cuoi ki
                scanf("%f", &finnal_theory);
                printf("Enter final practice score: ");//thuc hanh ck
                scanf("%f", &finnal_practice);
                hasFinal = 1;
                printf("Final exam scores saved!\n");
                break;
            case 3:
            	if ( !hasMidterm){
            		printf("Please enter your midterm score\n");
				} else {
					int option;
					printf("\n1. Just calculate needed final score\n");
                    printf("2. Already have theory final, need practice final to pass\n");
                    printf("Choose option: ");
                    scanf("%d", &option);
                    
                    switch (option){
                    	case 1:{
						
                    		float needed_finnal = ((passMark / 0.5) - (midterm_theory * 0.3 + midterm_practice * 0.3)) / 0.7;
                            if (needed_finnal <= 0)
                                printf("You already have enough midterm points to pass!\n");
                            else if (needed_finnal > 10)
                                printf("Even full final marks won't help, sorry!\n");
                            else
                                printf("You need at least %.2f points (for both theory & practice) in final to pass.\n", needed_finnal);
                            break;
                    	}
                    	case 2: {
                            printf("Enter your current final theory score: ");
                            scanf("%f", &finnal_theory);
                            float theory_avg = midterm_theory * 0.3 + finnal_theory * 0.7;
                            float needed_practice_finnal = (((passMark / 0.5) - theory_avg) - (midterm_practice * 0.3)) / 0.7;

                            if (needed_practice_finnal <= 0)
                                printf("You already passed even without practice final!\n");
                            else if (needed_practice_finnal > 10)
                                printf("Even 10 points in practice final can't save you!\n");
                            else
                                printf("You need %.2f points in practice final to pass.\n", needed_practice_finnal);
                            break;
					}
					default:
						printf("Invalid option!\n");
						break;
				}
		}
		break;
		
		case 4:
                if (!hasMidterm || !hasFinal) {
                    printf("Please enter all scores first!\n");
                } else {
                    float theory_avg = midterm_theory * 0.3 + finnal_theory * 0.7;
                    float practice_avg = midterm_practice * 0.3 + finnal_practice * 0.7;
                    average = (theory_avg * 0.5) + (practice_avg * 0.5);

                    if (average >= passMark)
                        printf("You PASSED the subject! ?? (Average = %.2f)\n", average);
                    else
                        printf("You FAILED the subject. ?? (Average = %.2f)\n", average);
                }
                break;

            case 5:
                if (!hasMidterm) {
                    printf("Enter midterm scores first!\n");
                } else {
                    printf("Retaking final exam...\n");
                    printf("Enter new final theory score: ");
                    scanf("%f", &finnal_theory);
                    printf("Enter new final practice score: ");
                    scanf("%f", &finnal_practice);
                    hasFinal = 1;
                    printf("New final scores saved!\n");
                }
                break;

            case 0:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
                break;
        }

    } while (choice != 0);

	
	
	return 0;
}
