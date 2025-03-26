#include "utils.h"

void generateExpression(int& num1, int& num2, int& num3, char& op1, char& op2) {
    num1 = getRandomNumber();
    num2 = getRandomNumber();
    num3 = getRandomNumber();

    op1 = (rand() % 2 == 0) ? '+' : '-';
    op2 = (op1 == '+') ? '-' : '+';

    if (op1 == '-' && num1 < num2) {
        swap(num1, num2);
    }
    int intermediateResult = (op1 == '+') ? num1 + num2 : num1 - num2;
    if (op2 == '-' && intermediateResult < num3) {
        swap(num2, num3);
        intermediateResult = (op1 == '+') ? num1 + num2 : num1 - num2;
    }
}

int calculateResult(int num1, int num2, int num3, char op1, char op2) {
    int intermediateResult = (op1 == '+') ? num1 + num2 : num1 - num2;
    return (op2 == '+') ? intermediateResult + num3 : intermediateResult - num3;
}

void printTime(int seconds) {
    int minutes = seconds / 60;
    int secs = seconds % 60;
    cout << setw(2) << setfill('0') << minutes << ":"
        << setw(2) << setfill('0') << secs << endl;
}