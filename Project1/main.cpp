#include "utils.h"


int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(0));

    int numExamples = 0;
    int maxErrors = 0;
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

    if (languageChoice == 1) {
        cout << "Enter the number of examples: ";
    }
    else {
        cout << "Введите количество примеров: ";
    }
    cin >> numExamples;
    while (numExamples <= 0) {
        if (languageChoice == 1) {
            cout << "Invalid input. Please enter a positive number: ";
        }
        else {
            cout << "Некорректный ввод. Введите положительное число: ";
        }
        cin >> numExamples;
    }

    if (languageChoice == 1) {
        cout << "Enter the maximum number of errors allowed: ";
    }
    else {
        cout << "Введите максимальное количество допустимых ошибок: ";
    }
    cin >> maxErrors;
    while (maxErrors < 0) {
        if (languageChoice == 1) {
            cout << "Invalid input. Please enter a non-negative number: ";
        }
        else {
            cout << "Некорректный ввод. Введите неотрицательное число: ";
        }
        cin >> maxErrors;
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

        while (!isCorrect && errors < maxErrors) {
            cout << (languageChoice == 1 ? "Example " : "Пример ") << i + 1 << "/" << numExamples << ": "
                << num1 << " " << op1 << " " << num2 << " " << op2 << " " << num3 << " = ";
            cin >> userAnswer;

            if (userAnswer == correctResult) {
                cout << (languageChoice == 1 ? "Correct!" : "Правильно!") << endl;
                isCorrect = true;
            }
            else {
                cout << (languageChoice == 1 ? "Incorrect. Try again." : "Неправильно. Попробуйте снова.") << endl;
                errors++;
            }
        }

        if (errors >= maxErrors) {
            cout << (languageChoice == 1 ? "You have reached the maximum number of errors. Game over."
                : "Вы достигли максимального количества ошибок. Игра окончена.") << endl;
            break;
        }
    }

    time_t endTime = time(nullptr);
    int totalTime = static_cast<int>(endTime - startTime);

    if (languageChoice == 1) {
        cout << "Total time: ";
    }
    else {
        cout << "Общее время: ";
    }
    printTime(totalTime);

    cout << (languageChoice == 1 ? "Errors: " : "Ошибок: ") << errors << endl;

    if (languageChoice == 1) {
        cout << "Do you want to try again? (y/n): ";
    }
    else {
        cout << "Хотите попробовать снова? (y/n): ";
    }
    char repeatChoice;
    cin >> repeatChoice;
    if (repeatChoice == 'y' || repeatChoice == 'Y') {
        clearScreen();
        main();
    }

    return 0;
}