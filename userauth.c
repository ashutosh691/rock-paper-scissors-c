#include "rps.h"

// Global user_info struct to hold current user's credentials
struct user_info info;

/*
 * Function: loginUser
 * -------------------
 * Authenticates a user by checking their username and password
 * against stored entries in `users.txt`.
 *
 * Returns:
 *   1 if login is successful,
 *   0 if login fails or an error occurs.
 */
int loginUser() {
    char file_user[50], file_pass[50], line[200];

    // Get username input from user
    printf("Enter username: ");
    fgets(info.username, sizeof(info.username), stdin);
    info.username[strcspn(info.username, "\n")] = '\0';  // Remove newline character

    // Get password input from user
    printf("Enter password: ");
    fgets(info.password, sizeof(info.password), stdin);
    info.password[strcspn(info.password, "\n")] = '\0';  // Remove newline character

    // Open users.txt in read mode to search for credentials
    FILE *file = fopen("users.txt", "r");
    if (file == NULL) {
        printf("An unknown error occurred.\n");
        return 0;
    }

    // Read each line from the file and check for matching credentials
    while (fgets(line, sizeof(line), file)) {
        if (sscanf(line, "%[^\t]\t%[^\n]", file_user, file_pass) == 2) {
            if (strcmp(info.username, file_user) == 0 && strcmp(info.password, file_pass) == 0) {
                fclose(file);
                printf("Login successful!\n\n");
                return 1;
            }
        }
    }

    // If credentials don't match any entry
    fclose(file);
    printf("Login failed.\n\n");
    return 0;
}

/*
 * Function: signupUser
 * --------------------
 * Registers a new user by storing their username and password
 * in `users.txt` and initializing their score to 0 in `scores.txt`.
 *
 * Ensures that usernames are unique.
 */
void signupUser() {
    char file_user[50], file_pass[50];

    // Get desired username
    printf("Choose a username: ");
    fgets(info.username, sizeof(info.username), stdin);
    info.username[strcspn(info.username, "\n")] = '\0';  // Remove newline

    // Get desired password
    printf("Choose a password: ");
    fgets(info.password, sizeof(info.password), stdin);
    info.password[strcspn(info.password, "\n")] = '\0';  // Remove newline

    // Check if username already exists
    FILE *file = fopen("users.txt", "r");
    if (file != NULL) {
        while (fscanf(file, "%s %s", file_user, file_pass) != EOF) {
            if (strcmp(info.username, file_user) == 0) {
                printf("Username already exists.\n\n");
                fclose(file);
                return;
            }
        }
        fclose(file);
    }

    // Append new username and password to users.txt
    file = fopen("users.txt", "a");
    fprintf(file, "%s\t%s\n", info.username, info.password);
    fclose(file);

    // Initialize user's score to 0 in scores.txt
    FILE *scoreFile = fopen("scores.txt", "a");
    fprintf(scoreFile, "%s 0\n", info.username);
    fclose(scoreFile);

    printf("Account created successfully!\n\n");
}
