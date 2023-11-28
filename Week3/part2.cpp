#include <iostream>
#include <memory>

// Create your own SmartPointer class
template <typename T>
class SmartPointer {
private:
    T* ptr; // Raw pointer to manage

public:
    // Constructor
    SmartPointer(T* p) : ptr(p) {
        std::cout << "Custom SmartPointer created with address: " << ptr << std::endl;
    }

    // Destructor
    ~SmartPointer() {
        std::cout << "Custom SmartPointer destroyed. Address: " << ptr << std::endl;
        delete ptr;
    }

    // Overload operator* to dereference the pointer
    T& operator*() {
        return *ptr;
    }

    // Overload operator-> to access members of the object
    T* operator->() {
        return ptr;
    }
};

int main() {
    // Create a custom SmartPointer and test it
    SmartPointer<int> customPtr(new int(42));
    std::cout << "Value through customPtr: " << *customPtr << std::endl;

    // Add std::auto_ptr variable
    std::auto_ptr<int> autoPtr(new int(24));
    std::cout << "Value through autoPtr: " << *autoPtr << std::endl;

    // Use get() function of std::auto_ptr
    int* autoPtrValue = autoPtr.get();
    std::cout << "Value through get() of autoPtr: " << *autoPtrValue << std::endl;

    // Try move() function of std::auto_ptr
    std::auto_ptr<int> autoPtrMoved = std::move(autoPtr);
    std::cout << "
