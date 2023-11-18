#include <iostream>
#include <cstdint>
#include <limits>
#include <iomanip>
#include <string>

// Function prototypes
void printSize();
void printLimits();

int main() {
    // Declare and initialize variables
    int w1 = 25;
    int w2 = 20;
    int total_width = w1 + w2;
    std::string line(total_width, '-');

    // Print the sizes of data types
    std::cout << line << std::endl;
    std::cout << std::left << std::setw(w1) << "Type" << std::setw(w2) << "Size" << std::endl;
    std::cout << line << std::endl;

    // Print sizes of various data types
    std::cout << std::setw(w1) << "char" << std::setw(w2) << sizeof(char) << " bytes" << std::endl;
    std::cout << std::setw(w1) << "wchar_t" << std::setw(w2) << sizeof(wchar_t) << " bytes" << std::endl;
    std::cout << std::setw(w1) << "short" << std::setw(w2) << sizeof(short) << " bytes" << std::endl;
    std::cout << std::setw(w1) << "int" << std::setw(w2) << sizeof(int) << " bytes" << std::endl;
    std::cout << std::setw(w1) << "long" << std::setw(w2) << sizeof(long) << " bytes" << std::endl;
    std::cout << std::setw(w1) << "long long" << std::setw(w2) << sizeof(long long) << " bytes" << std::endl;
    std::cout << std::setw(w1) << "float" << std::setw(w2) << sizeof(float) << " bytes" << std::endl;
    std::cout << std::setw(w1) << "double" << std::setw(w2) << sizeof(double) << " bytes" << std::endl;
    std::cout << std::setw(w1) << "long double" << std::setw(w2) << sizeof(long double) << " bytes" << std::endl;
    std::cout << std::setw(w1) << "bool" << std::setw(w2) << sizeof(bool) << " bytes" << std::endl;
    std::cout << std::setw(w1) << "int8_t" << std::setw(w2) << sizeof(int8_t) << " bytes" << std::endl;
    std::cout << std::setw(w1) << "int16_t" << std::setw(w2) << sizeof(int16_t) << " bytes" << std::endl;
    std::cout << std::setw(w1) << "int32_t" << std::setw(w2) << sizeof(int32_t) << " bytes" << std::endl;
    std::cout << std::setw(w1) << "int64_t" << std::setw(w2) << sizeof(int64_t) << " bytes" << std::endl;
    std::cout << std::setw(w1) << "uint8_t" << std::setw(w2) << sizeof(uint8_t) << " bytes" << std::endl;
    std::cout << std::setw(w1) << "uint16_t" << std::setw(w2) << sizeof(uint16_t) << " bytes" << std::endl;
    std::cout << std::setw(w1) << "uint32_t" << std::setw(w2) << sizeof(uint32_t) << " bytes" << std::endl;
    std::cout << std::setw(w1) << "uint64_t" << std::setw(w2) << sizeof(uint64_t) << " bytes" << std::endl;

    // Pointers
    std::cout << line << std::endl;
    std::cout << std::setw(w1) << "Pointers" << std::setw(w2) << "Size" << std::endl;
    std::cout << line << std::endl;

    // Print sizes of various pointers
    std::cout << std::setw(w1) << "char*" << std::setw(w2) << sizeof(char*) << " bytes" << std::endl;
    std::cout << std::setw(w1) << "int*" << std::setw(w2) << sizeof(int*) << " bytes" << std::endl;
    std::cout << std::setw(w1) << "long long*" << std::setw(w2) << sizeof(long long*) << " bytes" << std::endl;
    // ... Add more pointer types as needed

    // Print the limits of data types
    printLimits();

    return 0;
}

// Function to print limits of data types
void printLimits() {
    int w1 = 25;
    int w2 = 20;
    int total_width = w1 + w2;
    std::string line(total_width, '-');

    std::cout << line << std::endl;
    std::cout << std::left << std::setw(w1) << "Type" << std::setw(w2) << "Limits" << std::endl;
    std::cout << line << std::endl;

    // Print limits of various data types
    std::cout << std::setw(w1) << "char" << std::setw(w2) 
              << "Min: " << static_cast<int>(std::numeric_limits<char>::min()) 
              << ", Max: " << static_cast<int>(std::numeric_limits<char>::max()) << std::endl;

    std::cout << std::setw(w1) << "wchar_t" << std::setw(w2) 
              << "Min: " << static_cast<int>(std::numeric_limits<wchar_t>::min()) 
              << ", Max: " << static_cast<int>(std::numeric_limits<wchar_t>::max()) << std::endl;

    std::cout << std::setw(w1) << "short" << std::setw(w2) 
              << "Min: " << std::numeric_limits<short>::min() 
              << ", Max: " << std::numeric_limits<short>::max() << std::endl;

    std::cout << std::setw(w1) << "int" << std::setw(w2) 
              << "Min: " << std::numeric_limits<int>::min() 
              << ", Max: " << std::numeric_limits<int>::max() << std::endl;

    std::cout << std::setw(w1) << "long" << std::setw(w2) 
              << "Min: " << std::numeric_limits<long>::min() 
              << ", Max: " << std::numeric_limits<long>::max() << std::endl;

    std::cout << std::setw(w1) << "long long" << std::setw(w2) 
              << "Min: " << std::numeric_limits<long long>::min() 
              << ", Max: " << std::numeric_limits<long long>::max() << std::endl;

    std::cout << std::setw(w1) << "float" << std::setw(w2) 
              << "Min: " << std::numeric_limits<float>::min() 
              << ", Max: " << std::numeric_limits<float>::max() << std::endl;

    std::cout << std::setw(w1) << "double" << std::setw(w2) 
              << "Min: " << std::numeric_limits<double>::min() 
              << ", Max: " << std::numeric_limits<double>::max() << std::endl;

    std::cout << std::setw(w1) << "long double" << std::setw(w2) 
              << "Min: " << std::numeric_limits<long double>::min() 
              << ", Max: " << std::numeric_limits<long double>::max() << std::endl;

    std::cout << std::setw(w1) << "bool" << std::setw(w2) 
              << "Min: " << std::numeric_limits<bool>::min() 
              << ", Max: " << std::numeric_limits<bool>::max() << std::endl;

    std::cout << std::setw(w1) << "int8_t" << std::setw(w2) 
              << "Min: " << static_cast<int>(std::numeric_limits<int8_t>::min()) 
              << ", Max: " << static_cast<int>(std::numeric_limits<int8_t>::max()) << std::endl;

    std::cout << std::setw(w1) << "int16_t" << std::setw(w2) 
              << "Min: " << std::numeric_limits<int16_t>::min() 
              << ", Max: " << std::numeric_limits<int16_t>::max() << std::endl;

    std::cout << std::setw(w1) << "int32_t" << std::setw(w2) 
              << "Min: " << std::numeric_limits<int32_t>::min() 
              << ", Max: " << std::numeric_limits<int32_t>::max() << std::endl;

    std::cout << std::setw(w1) << "int64_t" << std::setw(w2) 
              << "Min: " << std::numeric_limits<int64_t>::min() 
              << ", Max: " << std::numeric_limits<int64_t>::max() << std::endl;

    std::cout << std::setw(w1) << "uint8_t" << std::setw(w2) 
              << "Min: 0, Max: " << static_cast<int>(std::numeric_limits<uint8_t>::max()) << std::endl;

    std::cout << std::setw(w1) << "uint16_t" << std::setw(w2) 
              << "Min: 0, Max: " << std::numeric_limits<uint16_t>::max() << std::endl;

    std::cout << std::setw(w1) << "uint32_t" << std::setw(w2) 
              << "Min: 0, Max: " << std::numeric_limits<uint32_t>::max() << std::endl;

    std::cout << std::setw(w1) << "uint64_t" << std::setw(w2) 
              << "Min: 0, Max: " << std::numeric_limits<uint64_t>::max() << std::endl;

    // ... Add more data types as needed
}
