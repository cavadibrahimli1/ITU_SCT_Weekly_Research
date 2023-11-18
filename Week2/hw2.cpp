#include <iostream>
#include <limits>

int main() {
    // All possible combinations of int, float, and double with long, short, and unsigned keywords
    int i;
    short s;
    long l;
    unsigned int ui;
    unsigned short us;
    unsigned long ul;
    float f;
    double d;

    // Print sizes of variables
    std::cout << "Size of int: " << sizeof(i) << " bytes\n";
    std::cout << "Size of short: " << sizeof(s) << " bytes\n";
    std::cout << "Size of long: " << sizeof(l) << " bytes\n";
    std::cout << "Size of unsigned int: " << sizeof(ui) << " bytes\n";
    std::cout << "Size of unsigned short: " << sizeof(us) << " bytes\n";
    std::cout << "Size of unsigned long: " << sizeof(ul) << " bytes\n";
    std::cout << "Size of float: " << sizeof(f) << " bytes\n";
    std::cout << "Size of double: " << sizeof(d) << " bytes\n";

    // Create pointers and print sizes of them
    int* pi = &i;
    short* ps = &s;
    long* pl = &l;
    unsigned int* pui = &ui;
    unsigned short* pus = &us;
    unsigned long* pul = &ul;
    float* pf = &f;
    double* pd = &d;

    std::cout << "Size of int pointer: " << sizeof(pi) << " bytes\n";
    std::cout << "Size of short pointer: " << sizeof(ps) << " bytes\n";
    std::cout << "Size of long pointer: " << sizeof(pl) << " bytes\n";
    std::cout << "Size of unsigned int pointer: " << sizeof(pui) << " bytes\n";
    std::cout << "Size of unsigned short pointer: " << sizeof(pus) << " bytes\n";
    std::cout << "Size of unsigned long pointer: " << sizeof(pul) << " bytes\n";
    std::cout << "Size of float pointer: " << sizeof(pf) << " bytes\n";
    std::cout << "Size of double pointer: " << sizeof(pd) << " bytes\n";

    // Print max and min values of each variable
    std::cout << "Max value of int: " << std::numeric_limits<int>::max() << "\n";
    std::cout << "Min value of int: " << std::numeric_limits<int>::min() << "\n";
    std::cout << "Max value of short: " << std::numeric_limits<short>::max() << "\n";
    std::cout << "Min value of short: " << std::numeric_limits<short>::min() << "\n";
    std::cout << "Max value of long: " << std::numeric_limits<long>::max() << "\n";
    std::cout << "Min value of long: " << std::numeric_limits<long>::min() << "\n";
    std::cout << "Max value of unsigned int: " << std::numeric_limits<unsigned int>::max() << "\n";
    std::cout << "Min value of unsigned int: " << std::numeric_limits<unsigned int>::min() << "\n";
    std::cout << "Max value of unsigned short: " << std::numeric_limits<unsigned short>::max() << "\n";
    std::cout << "Min value of unsigned short: " << std::numeric_limits<unsigned short>::min() << "\n";
    std::cout << "Max value of unsigned long: " << std::numeric_limits<unsigned long>::max() << "\n";
    std::cout << "Min value of unsigned long: " << std::numeric_limits<unsigned long>::min() << "\n";
    std::cout << "Max value of float: " << std::numeric_limits<float>::max() << "\n";
    std::cout << "Min value of float: " << std::numeric_limits<float>::min() << "\n";
    std::cout << "Max value of double: " << std::numeric_limits<double>::max() << "\n";
    std::cout << "Min value of double: " << std::numeric_limits<double>::min() << "\n";

    // Explanation of auto, const, and constexpr keywords
    auto x = 5;  // auto keyword deduces the type automatically
    const int y = 10;  // const keyword makes the variable constant
    constexpr int z = 15;  // constexpr keyword indicates a constant expression at compile time

    return 0;
}
