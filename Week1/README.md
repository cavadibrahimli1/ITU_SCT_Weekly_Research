#   Question 1.


![image](https://github.com/cavadibrahimli1/sct_hw/assets/76445357/a8064085-f364-44b7-9da7-d270f9a755bb)



# Point Structure in 3D Space

This C++ program implements a Point structure to represent a point in 3D space. The structure has three float attributes: x, y, and z. Additionally, several functions are implemented to perform operations on these points.

## Structure Definition

```cpp
  struct Point {
    float x, y, z;

    // Constructor for initializing the Point with given coordinates
    Point(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}

    // Function to calculate the distance from the point to the origin (0, 0, 0)
    float zero_distance() const {
        return std::sqrt(x * x + y * y + z * z);
    }

    // Function to calculate the distance between two points
    float distance(const Point& other) const {
        float dx = x - other.x;
        float dy = y - other.y;
        float dz = z - other.z;
        return std::sqrt(dx * dx + dy * dy + dz * dz);
    }

    // Static function to compare two points based on their distance from the origin
    static Point compare(const Point& p1, const Point& p2) {
        return (p1.zero_distance() > p2.zero_distance()) ? p1 : p2;
    }

    // Function to determine the region of the point in 3D space
    Region region() const {
        if (x > 0 && y > 0 && z > 0) return FIRST;
        else if (x < 0 && y > 0 && z > 0) return SECOND;
        else if (x < 0 && y < 0 && z > 0) return THIRD;
        else if (x > 0 && y < 0 && z > 0) return FOURTH;
        else return ORIGIN;
    }

    // Static function to check if two points are in the same region
    static bool is_in_same_region(const Point& p1, const Point& p2) {
        return p1.region() == p2.region();
    }
};
```

## Enumerations
The Region enum is used to represent different regions in 3D space, including the first quadrant, second quadrant, third quadrant, fourth quadrant, and the origin.

```cpp
  enum Region {
    FIRST,
    SECOND,
    THIRD,
    FOURTH,
    ORIGIN
};

```

## Functions
- zero_distance(): Calculates the distance of a point from the origin (0, 0, 0).
- distance(const Point& other): Calculates the distance between two points.
- compare(const Point& p1, const Point& p2): Static function to compare two points based on their distance from the origin and returns the point that is further.
- region(): Determines the region of the point in 3D space based on its coordinates.
- is_in_same_region(const Point& p1, const Point& p2): Static function to check if two points are in the same region.


```cpp
  int main() {
    // Example usage
    Point point1(1.0, 2.0, 3.0);
    Point point2(-1.0, -2.0, 3.0);

    // Display the distance of point1 from the origin
    std::cout << "Distance to origin: " << point1.zero_distance() << std::endl;

    // Display the distance between point1 and point2
    std::cout << "Distance between points: " << point1.distance(point2) << std::endl;

    // Find and display the point that is further from the origin between point1 and point2
    Point furtherPoint = Point::compare(point1, point2);
    std::cout << "Point further from origin: (" << furtherPoint.x << ", " << furtherPoint.y << ", " << furtherPoint.z << ")" << std::endl;

    // Check if point1 and point2 are in the same region and display the result
    if (Point::is_in_same_region(point1, point2)) {
        std::cout << "Points are in the same region." << std::endl;
    } else {
        std::cout << "Points are not in the same region." << std::endl;
    }

    return 0;
}

```

# Question 2. 

![image](https://github.com/cavadibrahimli1/sct_hw/assets/76445357/1827e9b6-c73d-4bb3-85b7-84858179ca78)



# Simple Calculator in C++
This is a simple calculator program implemented in C++ that allows users to perform basic arithmetic operations. The program includes error handling for invalid inputs and division/modulus by zero. It provides a user-friendly interface through the terminal.

Files
Calculator.h: Header file containing the declaration of the Calculator class.

## Structure Definition

```cpp
#ifndef CALCULATOR_H
#define CALCULATOR_H

class Calculator {
public:
    float addition(float a, float b);
    float subtraction(float a, float b);
    float multiplication(float a, float b);
    float division(float a, float b);
    float square(float a);
    float exponentiation(float base, float exponent);
    float modulus(float a, float b);
};

#endif // CALCULATOR_H

```

## Calculator.cpp:
 Implementation file containing the definition of the methods of the Calculator class.

```cpp
#include "Calculator.h"

float Calculator::addition(float a, float b) {
    return a + b;
}

// ... (similar definitions for other methods)

```

## main.cpp: 
Main file where the user interacts with the calculator through the terminal.


```cpp
#include <iostream>
#include <limits> // for numeric_limits
#include "Calculator.h"

int main() {
    // ... (main function code)
}

```

## Building and Running
To compile and run the program, you can use a C++ compiler. For example, using g++, you can use the following commands:

```cpp
g++ Calculator.cpp main.cpp -o calculator
./calculator
```

## Features
The calculator supports the following operations:

1. Addition
2. Subtraction
3. Multiplication
4. Division (with error handling for division by zero)
5. Square
6. Exponentiation
7. Modulus (with error handling for modulus by zero)
9. Exit

## Usage
- Run the program.
- Choose an operation by entering the corresponding number (1-8).
- Follow the prompts to enter the required numbers for the chosen operation.
- View the result.
- The program allows multiple calculations in one session without exiting. To exit, choose option 8.

## Error Handling
The program includes error handling for:

- Invalid user inputs (non-numeric input).
- Division by zero.
- Modulus by zero.
- Any errors encountered during calculations will be displayed, and the user can continue - with additional calculations.

## Future development plan:
1. Implement the Calculator class as a template class to support different numeric types.
2. Enhance error messages for more informative user feedback.
3. Add additional arithmetic operations or scientific functions.


Feel free to contribute to the improvement of this simple calculator!


