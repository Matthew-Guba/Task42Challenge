#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <limits>

using namespace std;

int getRandomNumber() {
    return rand() % 9 + 1;
}

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

int main() {
    srand(static_cast<unsigned int>(time(0))); 

    int numExamples = 0;
    string userName;
    int languageChoice = 0;

    cout << "Enter your name: ";
    cin >> userName;

    cout << "Choose language (1 - English, 2 - Russian): ";
    cin >> languageChoice;
    while (languageChoice != 1 && languageChoice != 2) {
        cout << "Invalid choice. Please enter 1 for English or 2 for Russian: ";
        cin >> languageChoice;
    }

    cout << (languageChoice == 1 ? "Enter the number of examples: " : "Введите количество примеров: ");
    cin >> numExamples;
    while (numExamples <= 0) {
        cout << (languageChoice == 1 ? "Invalid input. Please enter a positive number: " : "Некорректный ввод. Введите положительное число: ");
        cin >> numExamples;
    }

    int errors = 0;
    time_t startTime = time(nullptr);

    for (int i = 0; i < numExamples; ++i) {
        int num1, num2, num3;
        char op1, op2;

        generateExpression(num1, num2, num3, op1, op2);
        int correctResult = calculateResult(num1, num2, num3, op1, op2);

        int userAnswer;
        bool isCorrect = false;

        while (!isCorrect) {
            cout << num1 << " " << op1 << " " << num2 << " " << op2 << " " << num3 << " = ";
            cin >> userAnswer;

            if (userAnswer == correctResult) {
                cout << (languageChoice == 1 ? "Correct!" : "Правильно!") << endl;
                isCorrect = true;
            }
            else {
                cout << (languageChoice == 1 ? "Incorrect. Try again." : "Неправильно. Попробуйте снова.") << endl;
                if (!isCorrect) errors++; 
            }
        }
    }

    time_t endTime = time(nullptr); 
    int totalTime = static_cast<int>(endTime - startTime);

    
    cout << (languageChoice == 1 ? "Total time: " : "Общее время: ");
    printTime(totalTime);
    cout << (languageChoice == 1 ? "Errors: " : "Ошибок: ") << errors << endl;

    char repeatChoice;
    cout << (languageChoice == 1 ? "Do you want to try again? (y/n): " : "Хотите попробовать снова? (y/n): ");
    cin >> repeatChoice;
    if (repeatChoice == 'y' || repeatChoice == 'Y') {
        main();
    }

    return 0;
}