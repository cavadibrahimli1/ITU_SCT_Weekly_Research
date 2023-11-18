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
