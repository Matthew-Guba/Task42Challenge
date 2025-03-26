#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <limits>
using namespace std;
void clearScreen();
int getRandomNumber();
void generateExpression(int& num1, int& num2, int& num3, char& op1, char& op2);
int calculateResult(int num1, int num2, int num3, char op1, char op2);
void printTime(int seconds);

