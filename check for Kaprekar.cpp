#include <iostream>
#include <cmath>

// Function to check if a number is a Kaprekar number for a specific base
bool isKaprekar(int num, int base) {
    if (num == 1) {
        return true;
    }

    int square = num * num;
    int count_digits = 0;
    int temp = square;

    // Count the number of digits in the square
    while (temp) {
        count_digits++;
        temp /= base;
    }

    for (int i = 1; i < count_digits; i++) {
        int divisor = pow(base, i);
        int sum = square / divisor + square % divisor;

        if (sum == num && square % divisor > 0) {
            return true;
        }
    }
    return false;
}

// Main function to test the isKaprekar function
int main() {
    int number, base;
    std::cout << "Enter the number: ";
    std::cin >> number;
    std::cout << "Enter the base: ";
    std::cin >> base;

    if (isKaprekar(number, base)) {
        std::cout << number << " is a Kaprekar number in base " << base << std::endl;
    } else {
        std::cout << number << " is not a Kaprekar number in base " << base << std::endl;
    }

    return 0;
}
