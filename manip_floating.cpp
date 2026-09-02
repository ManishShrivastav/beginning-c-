#include <iostream>
#include <iomanip>

int main() {
    double num1 {123456789.987654321};
    double num2 {1234.5678};
    double num3 {1234.0};

    // Using default formatting
    std::cout << "====== Default formatting ======" << std::endl;
    std::cout << "num1: " << num1 << std::endl;
    std::cout << "num2: " << num2 << std::endl;
    std::cout << "num3: " << num3 << std::endl;

    // Using precision (2) formatting
    std::cout << "====== Precision (2) formatting ======" << std::endl;
    std::cout << std::setprecision(2);
    std::cout << "num1: " << num1 << std::endl;     // Note how since we can't display the number with 2 digits, it will display in scientific notation
    std::cout << "num2: " << num2 << std::endl;
    std::cout << "num3: " << num3 << std::endl;

    // Using precision (5) formatting
    std::cout << "====== Precision (5) formatting ======" << std::endl;
    std::cout << std::setprecision(5);
    std::cout << "num1: " << num1 << std::endl;     // Note how since we can't display the number with 5 digits, it will display in scientific notation
    std::cout << "num2: " << num2 << std::endl;
    std::cout << "num3: " << num3 << std::endl;

    // Using precision (9) formatting
    std::cout << "====== Precision (9) formatting ======" << std::endl;
    std::cout << std::setprecision(9);
    std::cout << "num1: " << num1 << std::endl;     
    std::cout << "num2: " << num2 << std::endl;
    std::cout << "num3: " << num3 << std::endl;

    // Using precision (3) and fixed formatting
    std::cout << "====== Precision (3) and fixed formatting ======" << std::endl;
    std::cout << std::setprecision(3) << std::fixed;
    std::cout << "num1: " << num1 << std::endl;     
    std::cout << "num2: " << num2 << std::endl;
    std::cout << "num3: " << num3 << std::endl;

    // Using precision (3) and fixed formatting
    std::cout << "====== Precision (3) and scientific notation ======" << std::endl;
    std::cout << std::setprecision(3) << std::scientific;
    std::cout << "num1: " << num1 << std::endl;     
    std::cout << "num2: " << num2 << std::endl;
    std::cout << "num3: " << num3 << std::endl;

    // Using precision (3) and fixed formatting and capital E for scientific notation
    std::cout << "====== Precision (3) and scientific notation uppercase E ======" << std::endl;
    std::cout << std::setprecision(3) << std::scientific << std::uppercase;
    std::cout << "num1: " << num1 << std::endl;     
    std::cout << "num2: " << num2 << std::endl;
    std::cout << "num3: " << num3 << std::endl;

    // Show '+' sign for positive numbers
    std::cout << "====== Show '+' sign for positive numbers ======" << std::endl;
    std::cout << std::setprecision(3) << std::fixed << std::showpos;
    std::cout << "num1: " << num1 << std::endl;     
    std::cout << "num2: " << num2 << std::endl;
    std::cout << "num3: " << num3 << std::endl;

    // Back to default formatting
    std::cout.unsetf(std::ios::scientific | std::ios::fixed);
    std::cout << std::resetiosflags(std::ios::showpos);

    // Show trailing zeros up to precision 10
    std::cout << "====== Show trailing zeros up to precision 10 ======" << std::endl;
    std::cout << std::setprecision(10) << std::showpoint;
    std::cout << "num1: " << num1 << std::endl;
    std::cout << "num2: " << num2 << std::endl;
    std::cout << "num3: " << num3 << std::endl;

    // Back to default formatting
    std::cout.unsetf(std::ios::scientific | std::ios::fixed);
    std::cout << std::resetiosflags(std::ios::showpos | std::ios::showpoint);
    std::cout << std::setprecision(6); // Reset precision to default

    // Show the numbers with the default formatting
    std::cout << "====== Back to default formatting ======" << std::endl;
    std::cout << "num1: " << num1 << std::endl;
    std::cout << "num2: " << num2 << std::endl;
    std::cout << "num3: " << num3 << std::endl;

    return 0;
}