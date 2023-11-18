#include "Calculator.h"

float Calculator::addition(float a, float b) {
    return a + b;
}

float Calculator::subtraction(float a, float b) {
    return a - b;
}

float Calculator::multiplication(float a, float b) {
    return a * b;
}

float Calculator::division(float a, float b) {
    if (b != 0) {
        return a / b;
    } else {
        throw "Error: Division by zero!";
    }
}

float Calculator::square(float a) {
    return a * a;
}

float Calculator::exponentiation(float base, float exponent) {
    return pow(base, exponent);
}

float Calculator::modulus(float a, float b) {
    if (b != 0) {
        return fmod(a, b);
    } else {
        throw "Error: Modulus by zero!";
    }
}
