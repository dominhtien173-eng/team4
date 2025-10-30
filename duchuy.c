#include <stdio.h>
#include <stdlib.h>

int main() {
    float midTheory = -1, midPractice = -1;
    float finalTheory = -1, finalPractice = -1;
    float avgTheory, avgPractice, avgSubject;
    int choice;

    do {
        printf("\n===== MENU =====\n");
        printf("1. Enter midterm theory and practice scores\n");
        printf("2. Enter final theory and practice scores\n");
        printf("3. Calculate average subject score\n");
        printf("4. Check midterm scores and required score to pass\n");
        printf("5. Check if passed or not\n");
        printf("6. Retake exam (enter new final theory and practice scores)\n");
        printf("7. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter midterm theory score (0-100): ");
                scanf("%f", &midTheory);
                if (midTheory < 0 || midTheory > 100) {
                    printf("Invalid score!\n");
                    midTheory = -1;
                    break;
                }
                printf("Enter midterm practice score (0-100): ");
                scanf("%f", &midPractice);
                if (midPractice < 0 || midPractice > 100) {
                    printf("Invalid score!\n");
                    midPractice = -1;
                }
                break;

            case 2:
                printf("Enter final theory score (0-100): ");
                scanf("%f", &finalTheory);
                if (finalTheory < 0 || finalTheory > 100) {
                    printf("Invalid score!\n");
                    finalTheory = -1;
                    break;
                }
                printf("Enter final practice score (0-100): ");
                scanf("%f", &finalPractice);
                if (finalPractice < 0 || finalPractice > 100) {
                    printf("Invalid score!\n");
                    finalPractice = -1;
                }
                break;

            case 3:
                if (midTheory < 0 || midPractice < 0 || finalTheory < 0 || finalPractice < 0) {
                    printf("Please enter all scores first!\n");
                    break;
                }
                avgTheory = midTheory * 0.3 + finalTheory * 0.7;
                avgPractice = midPractice * 0.3 + finalPractice * 0.7;
                avgSubject = (avgTheory + avgPractice) / 2;
                printf("Average theory score: %.2f\n", avgTheory);
                printf("Average practice score: %.2f\n", avgPractice);
                printf("==> Subject average: %.2f\n", avgSubject);
                break;

            case 4:
                if (midTheory < 0 || midPractice < 0) {
                    printf("Midterm scores not entered yet!\n");
                    break;
                }
                printf("Midterm theory score: %.2f\n", midTheory);
                if (finalTheory < 0) {
                    printf("4.1 You have not taken the final theory exam yet.\n");
                    float needToPass = (50 - midTheory * 0.3) / 0.7;
                    if (needToPass > 100)
                        printf("You cannot reach 50 points. You would need %.2f in final (impossible).\n", needToPass);
                    else if (needToPass < 0)
                        printf("You already have enough midterm points to pass regardless of final score.\n");
                    else
                        printf("You need %.2f in the final theory to pass the subject.\n", needToPass);
                } else {
                    printf("4.2 Final theory score entered: %.2f\n", finalTheory);
                }
                break;

            case 5:
                if (midTheory < 0 || midPractice < 0 || finalTheory < 0 || finalPractice < 0) {
                    printf("Please enter all scores first!\n");
                    break;
                }
                avgTheory = midTheory * 0.3 + finalTheory * 0.7;
                avgPractice = midPractice * 0.3 + finalPractice * 0.7;
                avgSubject = (avgTheory + avgPractice) / 2;
                printf("Subject average: %.2f\n", avgSubject);
                if (avgSubject >= 50)
                    printf("==> Successfully! You passed the subject! \n");
                else
                    printf("==> You failed the subject. Try again next time.\n");
                break;

            case 6:
                printf("Retake exam - enter new final scores.\n");
                printf("Retake exam - enter new final scores.\n");