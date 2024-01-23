#include <iostream>

int main() {
    double num1, num2;
    char operation;

    std::cout << "Enter first number: ";
    std::cin >> num1;

    std::cout << "Enter second number: ";
    std::cin >> num2;

    std::cout << "Choose operation (+, -, *, /): ";
    std::cin >> operation;

    double result;

    switch (operation) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
            } else {
                std::cout << "Error! Division by zero.\n";
                return 1; // Exit with an error code
            }
            break;
        default:
            std::cout << "Invalid operation.\n";
            return 1; // Exit with an error code
    }

    std::cout << "Result: " << result << "\n";

    return 0;
}
