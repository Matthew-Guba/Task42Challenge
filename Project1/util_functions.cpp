#include "utils.h"

void clearScreen() {
    system("cls");
}

int getRandomNumber() {
    return rand() % 9 + 1;
}