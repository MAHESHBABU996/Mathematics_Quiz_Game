#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

typedef struct {
    char question[200];
    char opt1[50], opt2[50], opt3[50], opt4[50];
    int correct;
} Quiz;

void startQuiz();
void rules();

int main() {
    int choice;

    while (1) {
        system(CLEAR);
        printf("\n=================================\n");
        printf("       MATHEMATICS QUIZ GAME     \n");
        printf("=================================\n");
        printf("1. Start Quiz\n");
        printf("2. Rules\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) startQuiz();
        else if (choice == 2) rules();
        else if (choice == 3) {
            printf("\nThank you for playing!\n");
            return 0;
        } else {
            printf("\nInvalid choice!\n");
        }

        printf("\nPress Enter to continue...");
        getchar(); getchar();
    }
}

void rules() {
    system(CLEAR);
    printf("\n============ RULES ============\n");
    printf("1. You will get 5 random math questions.\n");
    printf("2. Each correct answer = +4 points.\n");
    printf("3. Each wrong answer = -1 point.\n");
    printf("4. Questions do not repeat.\n");
    printf("5. Questions include arithmetic, algebra, geometry, percentages, and logic.\n");
    printf("===============================\n");
}

void startQuiz() {
    system(CLEAR);
    srand(time(NULL));

    Quiz q[20] = {
        {"What is 12 + 15?", "27", "25", "30", "32", 1},
        {"What is 9 * 7?", "56", "63", "72", "49", 2},
        {"What is 45 / 5?", "9", "5", "8", "10", 1},
        {"What is 18 - 7?", "9", "10", "11", "12", 3},
        {"What is the square of 12?", "124", "128", "144", "154", 3},
        {"What is the cube of 3?", "9", "18", "27", "36", 3},
        {"Solve: 5^2 + 3^2", "25", "34", "30", "52", 2},
        {"What is 40%% of 200?", "40", "60", "80", "100", 3},
        {"Solve: 2x = 18, find x", "8", "9", "7", "6", 2},
        {"Solve: 15 + (6 * 2)", "27", "18", "20", "30", 1},
        {"Area of a square with side 8?", "64", "32", "16", "128", 1},
        {"Perimeter of a rectangle 5x3?", "16", "20", "12", "10", 2},
        {"Value of pi (approx)?", "2.12", "3.14", "4.12", "3.44", 2},
        {"What is sqrt(49)?", "5", "6", "7", "8", 3},
        {"What is 100 - 37?", "73", "63", "67", "57", 1},
        {"Solve: 7 + 3 * 4", "16", "19", "14", "20", 2},
        {"Which is even?", "17", "21", "28", "33", 3},
        {"What is 11 * 11?", "111", "121", "131", "101", 2},
        {"Solve: (20 / 4) + 6", "10", "11", "12", "14", 2},
        {"Find LCM of 4 and 6", "10", "12", "16", "24", 2}
    };

    int used[20] = {0};
    int score = 0, asked = 0;

    printf("\n=========== QUIZ STARTED ===========\n");

    while (asked < 5) {
        int r = rand() % 20;
        if (used[r]) continue;

        used[r] = 1;
        Quiz curr = q[r];
        int ans;

        printf("\n---------------------------------\n");
        printf("Q%d: %s\n", asked + 1, curr.question);
        printf("1. %s\n2. %s\n3. %s\n4. %s\n", curr.opt1, curr.opt2, curr.opt3, curr.opt4);
        printf("Your answer: ");
        scanf("%d", &ans);

        if (ans == curr.correct) {
            printf("Correct! +4 points\n");
            score += 4;
        } else {
            printf("Wrong! -1 point\n");
            score -= 1;
        }

        asked++;
    }

    printf("\n=========== RESULT ===========\n");
    printf("Your Score: %d / 20\n", score);

    if (score == 20) printf("Outstanding!\n");
    else if (score >= 15) printf("Excellent!\n");
    else if (score >= 10) printf("Good job!\n");
    else printf("Needs improvement.\n");

    printf("==============================\n");
}
