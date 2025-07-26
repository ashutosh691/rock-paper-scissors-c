#include "rps.h"

// Global user info (if needed across files)
struct user_info info;

/*
 * Function: getMaxScore
 * ---------------------
 * Retrieves the highest score of a given user from "scores.txt".
 *
 * Parameters:
 *   username - the name of the user whose score is to be retrieved
 *
 * Returns:
 *   The stored maximum score if found, otherwise 0.
 */
int getMaxScore(char* username) {
    FILE *file = fopen("scores.txt", "r");
    char file_user[50];
    int score;

    // If the score file doesn't exist, return 0
    if (file == NULL) return 0;

    // Read each username and score, and compare with the given username
    while (fscanf(file, "%s %d", file_user, &score) != EOF) {
        if (strcmp(username, file_user) == 0) {
            fclose(file);  // Close the file once the match is found
            return score;
        }
    }

    // If username not found, return 0
    fclose(file);
    return 0;
}


/*
 * Function: updateMaxScore
 * ------------------------
 * Updates the stored high score for a given user if the new score is higher.
 * It does so by copying all scores to a temporary file, modifying the score
 * for the given user if necessary, and then replacing the original file.
 *
 * Parameters:
 *   username - the name of the user
 *   newScore - the latest score to be considered
 */
void updateMaxScore(char* username, int newScore) {
    FILE *file = fopen("scores.txt", "r");
    FILE *temp = fopen("temp.txt", "w");  // Temporary file for safe updating
    char file_user[50];
    int score, found = 0;

    // If score file doesn't exist, create it for writing
    if (file == NULL) file = fopen("scores.txt", "w");

    // Traverse existing scores
    while (fscanf(file, "%s %d", file_user, &score) != EOF) {
        if (strcmp(username, file_user) == 0) {
            found = 1;
            // Write the higher of the old and new scores
            fprintf(temp, "%s %d\n", username, (newScore > score) ? newScore : score);
        } else {
            // Keep existing records as they are
            fprintf(temp, "%s %d\n", file_user, score);
        }
    }

    // If user not found in the file, add them
    if (!found) {
        fprintf(temp, "%s %d\n", username, newScore);
    }

    // Close both files
    fclose(file);
    fclose(temp);

    // Replace original scores file with updated temp file
    remove("scores.txt");
    rename("temp.txt", "scores.txt");
}
