#include <stdio.h>
#include <stdlib.h>

// Function to input and validate score
float enter_score(const char* name) {
    float point;
    do {
        printf("Enter %s score (0 - 100): ", name); // Nhap diem cua phan duoc yêu cau
        scanf("%f", &point);
        if (point < 0 || point > 100) {              // Kiem tra xem diem co hop le khong
            printf("Invalid score! Please re-enter (0 - 100).\n");
        }
    } while (point < 0 || point > 100);              
    return point;                                    
}

int main() {
    float midterm_theory = 0, midterm_practice = 0;  // Ðiem lý thuyet & thuc hành giua ki
    float final_theory = 0, final_practice = 0;      // Ðiem lý thuyet & thuc hành cuoi ki
    float midterm = 0, final_exam = 0, total = 0;    // Ðiem trung bình giua ki, cuoi ki và tong
    int select;                                      // Lua chon menu
    char retry;                                    

    do {
        // Menu chính
        printf("\n===== COURSE GRADE CALCULATION PROGRAM =====\n");
        printf("1. Enter scores and check pass/fail\n");
        printf("2. Retake exam\n");
        printf("3. Exit\n");
        printf("Choose an option (1-3): ");
        scanf("%d", &select);

        switch (select) {
        case 1:
           
            printf("\n--- ENTER MIDTERM SCORES ---\n");
            midterm_theory = enter_score("Midterm Theory");
            midterm_practice = enter_score("Midterm Practice");
            midterm = (midterm_theory + midterm_practice) / 2;

            printf("\n--- ENTER FINAL EXAM SCORES ---\n");
            final_theory = enter_score("Final Theory");
            final_practice = enter_score("Final Practice");
            final_exam = (final_theory + final_practice) / 2;

           
            total = midterm * 0.3 + final_exam * 0.7;
            printf("\n>>> Total score: %.2f\n", total);

            if (total >= 5)
                printf("Congratulations! You PASSED the course!\n");
            else
                printf("You FAILED the course! Please choose option 2 to retake the exam.\n");
            break;

        case 2:
            if (midterm_theory == 0 && midterm_practice == 0) {
                printf("You haven't entered midterm scores yet! Please choose option 1 first.\n");
                break;
            }

            do {
                printf("\n--- RETAKE FINAL EXAM ---\n");
                final_theory = enter_score("Final Theory (Retake)");
                final_practice = enter_score("Final Practice (Retake)");
                final_exam = (final_theory + final_practice) / 2;

                total = midterm * 0.3 + final_exam * 0.7;
                printf("\n>>> Total score after retake: %.2f\n", total);

                if (total >= 5) {
                    printf("Congratulations! You PASSED after retaking the exam!\n");
                    break;
                } else {
                    printf("You still did not pass! Do you want to retake again? (y/n): ");
                    scanf(" %c", &retry);
                }
            } while (retry == 'y' || retry == 'Y');
            break;

        case 3:

            printf("\nGoodbye! See you next time!\n");
            break;

        default:
            printf("Invalid choice! Please select between 1 and 3.\n");
            break;
        }
    } while (select != 3);  

    return 0;
}

