#include <iostream>
#include <limits> // for numeric_limits
#include "Calculator.h"

int main() {
    Calculator calculator;
    char choice;

    do {
        std::cout << "Choose an operation:\n";
        std::cout << "1. Addition\n";
        std::cout << "2. Subtraction\n";
        std::cout << "3. Multiplication\n";
        std::cout << "4. Division\n";
        std::cout << "5. Square\n";
        std::cout << "6. Exponentiation\n";
        std::cout << "7. Modulus\n";
        std::cout << "8. Exit\n";

        std::cout << "Enter your choice (1-8): ";
        std::cin >> choice;

        try {
            float num1, num2;
            switch (choice) {
                case '1':
                    std::cout << "Enter two numbers: ";
                    std::cin >> num1 >> num2;
                    std::cout << "Result: " << calculator.addition(num1, num2) << std::endl;
                    break;
                case '2':
                    std::cout << "Enter two numbers: ";
                    std::cin >> num1 >> num2;
                    std::cout << "Result: " << calculator.subtraction(num1, num2) << std::endl;
                    break;
                case '3':
                    std::cout << "Enter two numbers: ";
                    std::cin >> num1 >> num2;
                    std::cout << "Result: " << calculator.multiplication(num1, num2) << std::endl;
                    break;
                case '4':
                    std::cout << "Enter two numbers: ";
                    std::cin >> num1 >> num2;
                    std::cout << "Result: " << calculator.division(num1, num2) << std::endl;
                    break;
                case '5':
                    std::cout << "Enter a number: ";
                    std::cin >> num1;
                    std::cout << "Result: " << calculator.square(num1) << std::endl;
                    break;
                case '6':
                    std::cout << "Enter base and exponent: ";
                    std::cin >> num1 >> num2;
                    std::cout << "Result: " << calculator.exponentiation(num1, num2) << std::endl;
                    break;
                case '7':
                    std::cout << "Enter two numbers: ";
                    std::cin >> num1 >> num2;
                    std::cout << "Result: " << calculator.modulus(num1, num2) << std::endl;
                    break;
                case '8':
                    std::cout << "Exiting the program.\n";
                    break;
                default:
                    std::cout << "Invalid choice. Please enter a number between 1 and 8.\n";
            }
        } catch (const char* error) {
            std::cerr << "Error: " << error << std::endl;
        }

        // Clear input buffer
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    } while (choice != '8');

    return 0;
}
