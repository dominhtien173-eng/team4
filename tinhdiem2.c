#include <stdio.h>
#include <stdlib.h>

int main() {
    float midterm_theory = -1, midterm_practice = -1;
    float final_theory = -1, final_practice = -1;
    float average = 0;
    int choice;
    int hasMidterm = 0, hasFinal = 0;
    float passMark = 50; // diem qua mon
//in ra tieu de app, nhap diem giua va cuoi ky (ly thuyet va thuc hanh). 
//check can bnh diem de pass mon (ly thuyet 50%, diem giua ki 30%, diem cuoi ky 70%, co 2 cach tinh 1 la tinh nhu bth 2 la da co diem ly thuyet cuoi ky)
//ktra coi qua mon chua, cuoi cung la thi lai
    do {
        printf("\n==== Scoring Application ====\n");
        printf("1. Enter midterm scores (theory & practice)\n");
        printf("2. Enter final exam scores (theory & practice)\n");
        printf("3. Check how many points needed to pass the subject\n");
        printf("4. Check if passed the subject\n");
        printf("5. Retake final exam (only final)\n");
        printf("6. Exit\n");
        printf("Choose: ");
        scanf("%d", &choice);

        switch (choice) { //case 1 nhap diem giua ky (lt va th) thang diem 0-100 va sau do save diem lai
            case 1:
                printf("Enter midterm theory score: ");
                scanf("%f", &midterm_theory);
                printf("Enter midterm practice score: ");
                scanf("%f", &midterm_practice);
                hasMidterm = 1;
                printf("Midterm scores saved!\n");
                break;

            case 2: //case 2 nhap diem cuoi ky... giong case 1
                printf("Enter final theory score: ");
                scanf("%f", &final_theory);
                printf("Enter final practice score: ");
                scanf("%f", &final_practice);
                hasFinal = 1;
                printf("Final exam scores saved!\n");
                break;

            case 3://
                if (!hasMidterm) {
                    printf("Please enter your midterm scores first!\n");
                } else {
                    int option;
                    printf("\n1. Calculate needed final score (for both theory & practice)\n");
                    printf("2. Already have theory final, need practice final to pass\n");
                    printf("Choose option: ");
                    scanf("%d", &option);

                    switch (option) {
                        case 1: {
                            float midterm_avg = (midterm_theory + midterm_practice) / 2;
                            float needed_final = ((passMark - (midterm_avg * 0.3)) / 0.7);

                            if (needed_final <= 0)
                                printf("You already have enough midterm points to pass!\n");
                            else if (needed_final > 100)
                                printf("Even full final marks (100) won't be enough, sorry!\n");
                            else
                                printf("You need at least %.2f points in both final parts to pass.\n", needed_final);
                            break;
                        }
                        case 2: {
                            printf("Enter your current final theory score: ");
                            scanf("%f", &final_theory);
                            float theory_avg = midterm_theory * 0.3 + final_theory * 0.7;
                            float needed_practice_final = ((passMark - (theory_avg * 0.5 + midterm_practice * 0.15)) / 0.35);

                            if (needed_practice_final <= 0)
                                printf("You already passed even without practice final!\n");
                            else if (needed_practice_final > 100)
                                printf("Even 100 points in practice final can’t help!\n");
                            else
                                printf("You need %.2f points in practice final to pass.\n", needed_practice_final);
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
                    float theory_avg = midterm_theory * 0.3 + final_theory * 0.7;
                    float practice_avg = midterm_practice * 0.3 + final_practice * 0.7;
                    average = (theory_avg * 0.5) + (practice_avg * 0.5);

                    if (average >= passMark)
                        printf("You passed the subject! (Average = %.2f)\n", average);
                    else
                        printf("You failed the subject. (Average = %.2f)\n", average);
                }
                break;

            case 5:
                if (!hasMidterm) {
                    printf("Enter midterm scores first!\n");
                } else {
                    printf("Retaking final exam...\n");
                    printf("Enter new final theory score: ");
                    scanf("%f", &final_theory);
                    printf("Enter new final practice score: ");
                    scanf("%f", &final_practice);
                    hasFinal = 1;
                    printf("New final scores saved!\n");
                }
                break;

            case 6:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
                break;
        }

    } while (choice != 6);

    return 0;
}

