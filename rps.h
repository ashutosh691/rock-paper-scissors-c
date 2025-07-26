// rps.h
#pragma once

// Includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Struct
struct user_info {
    char username[50], password[50];
};

extern struct user_info info;

// Score Handling
int getMaxScore(char* username);
void updateMaxScore(char* username, int newScore);

// ASCII Art
void printRockPaperScissor();
void printRock();
void printPaper();
void printScissors();

// User Auth
int loginUser();
void signupUser();

// Gameplay
void play();
