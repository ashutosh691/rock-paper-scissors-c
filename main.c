#include "rps.h"  // Include the header file containing function declarations and necessary libraries

// Main Function: Entry point of the Rock, Paper, Scissors game
int main() {
    int choice;

    srand(time(NULL)); // Seed the random number generator for random computer moves

    // Print introductory ASCII art or game banner
    printRockPaperScissor();

    // Game introduction and instructions
    printf("Welcome to Rock, Paper, Scissors!\n\n");
    printf("Game Description:\nRock, Paper, Scissors is a simple hand game played between two players.\n");
    printf("Each player simultaneously forms one of three shapes:\n");
    printf("1. Rock     - A closed fist. Beats Scissors.\n");
    printf("2. Paper    - An open hand. Beats Rock.\n");
    printf("3. Scissors - A fist with two fingers extended. Beats Paper.\n\n");
    printf("Rules:\n* Rock crushes Scissors\n* Scissors cut Paper\n* Paper covers Rock\n");
    printf("If both players choose the same shape, the game is a draw.\nEach game has 5 rounds.\n\n");

    // Prompt the user with login or play options
    printf("Please select one option:\n");
    printf("1. Login/Sign in\n");
    printf("2. Sign up/Create a new account\n");
    printf("3. Play as a guest\n");
    printf("4. Exit\n\nYour Choice: ");
    scanf("%d", &choice);
    printf("\n");

    // Input validation loop for menu choice
    while (choice < 1 || choice > 4) {
        printf("Invalid Choice!!!\nPlease select your option again.\nYour choice: ");
        scanf("%d", &choice);
    }

    // Handle user choice
    if (choice == 1) {
        // Clear input buffer
        while (getchar() != '\n');

        // If login is successful, start the game
        if (loginUser()) {
            play();
        }

    } else if (choice == 2) {
        // Clear input buffer before taking string input in signup
        while (getchar() != '\n');

        // Sign up a new user
        signupUser();

    } else if (choice == 3) {
        // Directly start the game in guest mode (no login required)
        play();

    } else {
        // Exit the program
        printf("Exiting...........\n\n");
        exit(0);
    }

    return 0; // End of program
}



// To compile and run the program (macOS/Linux):
// cd "/Users/ashutoshupreti/Desktop/C Programs/" && gcc main.c print.c play.c userauth.c update.c -o main && ./main
