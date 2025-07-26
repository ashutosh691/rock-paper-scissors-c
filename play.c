#include "rps.h"

// Global variable to store user info
struct user_info info;

/*
 * Function: play
 * ----------------------------
 *  This function handles the full game logic of Rock, Paper, Scissors.
 *  It supports:
 *      - 5 rounds of gameplay per session
 *      - Score tracking for user, computer, and draws
 *      - Max score saving for registered users
 *      - Option to play again or exit
 */
void play() {
    int userChoice, computerChoice, choice, round = 0;
    int computerPoints = 0, userPoints = 0, drawPoints = 0;
    int maxScore = 0;

    // Show max score if user is logged in
    if (strlen(info.username) > 0) {
        maxScore = getMaxScore(info.username);
        printf("Welcome back, %s! Your highest score till now: %d\n\n", info.username, maxScore);
    }

    // Game start menu
    printf("1. Play\n2. Exit\n\nYour Choice: ");
    scanf("%d", &choice);
    printf("\n");

    // Input validation
    while (choice < 1 || choice > 2) {
        printf("Invalid Choice!!!\nPlease select your option again.\nYour choice: ");
        scanf("%d", &choice);
    }

    // Exit option
    if (choice == 2) {
        printf("Exiting...........\n\n");
        exit(0);
    }

    printf("\n===========================\n");

    // Game session loop
    do {
        // Each match has 5 rounds
        do {
            printf("\n\nRound %d\n\n", round + 1);
            printf("Choose your option:\n1. Rock\n2. Paper\n3. Scissors\n\nYour option: ");
            scanf("%d", &userChoice);

            // Validate user input
            while (userChoice < 1 || userChoice > 3) {
                printf("\nInvalid Choice!!!\nPlease select your option again.\nYour option: ");
                scanf("%d", &userChoice);
            }

            // Computer randomly selects its choice
            computerChoice = (rand() % 3) + 1;

            // Handle tie
            if (userChoice == computerChoice) {
                if (userChoice == 1) {
                    printf("\nYou Choose: Rock\n\n"); printRock();
                    printf("\nComputer Choose: Rock\n\n"); printRock();
                } else if (userChoice == 2) {
                    printf("\nYou Choose: Paper\n\n"); printPaper();
                    printf("Computer Choose: Paper\n\n"); printPaper();
                } else {
                    printf("\nYou Choose: Scissors\n\n"); printScissors();
                    printf("\nComputer Choose: Scissors\n\n"); printScissors();
                }

                printf("\nDraw\n\n");
                drawPoints++;
            }

            // Special case where Rock vs Scissors (sum is 4)
            else if (userChoice + computerChoice == 4) {
                if (userChoice == 1) {
                    userPoints++; printf("\nYou Choose: Rock\n\n"); printRock();
                } else {
                    printf("\nYou Choose: Scissors\n\n"); printScissors();
                }

                if (computerChoice == 1) {
                    computerPoints++; printf("\nComputer Choose: Rock\n\n"); printRock();
                } else {
                    printf("\nComputer Choose: Scissors\n\n"); printScissors();
                }

                (userChoice == 1) ? printf("\nYou won this round\n\n") : printf("\nComputer won this round\n\n");
            }

            // Paper vs Rock (sum is 3)
            else if (userChoice + computerChoice == 3) {
                if (userChoice == 2) {
                    userPoints++; printf("\nYou Choose: Paper\n\n"); printPaper();
                } else {
                    printf("\nYou Choose: Rock\n\n"); printRock();
                }

                if (computerChoice == 2) {
                    computerPoints++; printf("\nComputer Choose: Paper\n\n"); printPaper();
                } else {
                    printf("\nComputer Choose: Rock\n\n"); printRock();
                }

                (userChoice == 2) ? printf("\nYou won this round\n\n") : printf("\nComputer won this round\n\n");
            }

            // Scissors vs Paper (sum is 5)
            else {
                if (userChoice == 3) {
                    userPoints++; printf("\nYou Choose: Scissors\n\n"); printScissors();
                } else {
                    printf("\nYou Choose: Paper\n\n"); printPaper();
                }

                if (computerChoice == 3) {
                    computerPoints++; printf("\nComputer Choose: Scissors\n\n"); printScissors();
                } else {
                    printf("\nComputer Choose: Paper\n\n"); printPaper();
                }

                (userChoice == 3) ? printf("\nYou won this round\n\n") : printf("\nComputer won this round\n\n");
            }

            round++; // Move to next round
            printf("\n===========================\n");

        } while (round < 5); // End of 5 rounds

        // Final results summary
        printf("Your points: %d\nComputer points: %d\nDraw: %d\n\n\n", userPoints, computerPoints, drawPoints);
        (computerPoints > userPoints) 
            ? printf("Computer won the game\n\n") 
            : (userPoints > computerPoints) 
                ? printf("You won the game\n\n") 
                : printf("Draw\n\n");

        // If logged-in user, check and update max score
        if (strlen(info.username) > 0) {
            if (userPoints > maxScore) {
                printf("Congratulations! New highest score: %d (Previous: %d)\n\n\n", userPoints, maxScore);
                updateMaxScore(info.username, userPoints); // Save new high score
                maxScore = getMaxScore(info.username);     // Refresh from file
            } else {
                printf("Your highest score remains: %d\n\n\n", maxScore);
            }
        }

        // Prompt to play again or exit
        printf("1. Play Again\n2. Exit\n\nYour Choice: ");
        scanf("%d", &choice);
        printf("\n");

        while (choice < 1 || choice > 2) {
            printf("Invalid Choice!!!\nPlease select your option again.\nYour choice: ");
            scanf("%d", &choice);
        }

        // Reset values for next session
        round = 0;
        computerPoints = 0;
        userPoints = 0;
        drawPoints = 0;

    } while (choice != 2); // Continue until user exits

    // Graceful exit message
    printf("Exiting...........\n\n");
    exit(0);
}
