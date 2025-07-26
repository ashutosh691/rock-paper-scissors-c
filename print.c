#include "rps.h"

//Ascii art

void printRockPaperScissor() {
    printf("    _______                  ______                          _______\n");
    printf("---'   ____)__           ---'    ___)______              ---'   ____)____\n");
    printf("      (_______)                     ________)                    ________)\n");
    printf("      (_______)                    _________)                    _________)\n");
    printf("      (_______)                   _________)                    (____)\n");
    printf("---.__(_______)          ---._____________)              ---.__(____)\n\n");
}

void printRock() {
    printf("    _______\n");
    printf("---'   ____)__ \n");
    printf("       _______)\n");
    printf("       _______)\n");
    printf("      (_______)\n");
    printf("---.__(_______)\n");
}

void printPaper() {
    printf("     ______\n");
    printf("---'    ___)______\n");
    printf("           ________)\n");
    printf("          _________)\n");
    printf("         _________)\n");
    printf("---._____________)\n");
}

void printScissors() {
    printf("    _______\n");
    printf("---'   ____)____\n");
    printf("          ______)\n");
    printf("       __________)\n");
    printf("      (____)\n");
    printf("---.__(___)\n");
}