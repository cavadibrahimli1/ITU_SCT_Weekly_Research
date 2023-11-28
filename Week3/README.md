![image](https://github.com/cavadibrahimli1/sct_hw/assets/76445357/047d3245-b9a1-4ee1-bc64-f62cb0dc717f)

# Understanding Pointers in C++ 

## Before we start, you have to know:

- Understanding the functioning of elements such as variables, loops, conditionals, and more is crucial for grasping basic coding principles.
- Proficiency in Linux, especially in navigating the Terminal/Console, is essential as we'll be compiling our materials using these tools.

## Table Of Contents 
1. Introduction  
2. C++ Pointer Structure
   1. Syntax for Pointer Declaration
   2. C++ Pointer Syntax Reference 
3. Memory Addressing
   1. Understanding Memmory Adressing
   2. Memmory adress representation
   3. The address operator (&)
4. Passing by Value vs Passing by Reference
   1. Passing by Value
   2. Passing by Reference
   3. Choosing Between Passing by Value and Passing by Reference
5. Reference system
   1. Basics of References
   2. Key Characteristics of References
   3. Use cases for references
6. Arrays inside Pointers
   1. Pointers and Arrays Relationship
   2. Pointer Arithmetic
7. Indirection methodology
   1. Overiew and
   2. Syntax
   3. Applications 
8. Memory system in C++
   1. Basics
   2. Dynamics memory allocation
   3. Memory leaks and best practises 
9. Heap and Stack
    1. Heap vs Stack
    2. Allocating
10. Dangling Pointers
    1. Basics
    2. Causes of Dangling Pointers
    3. Nullifying Pointers
    4. Smart Pointers
    5. Best Practices to Avoid Dangling Pointers
11. Garbage Collection Mechanism
12. Extra implementation
    
## 1. Introduction 

Pointers are a fundamental concept in C++ programming that allow you to work directly with memory addresses. Unlike other variables that store values, pointers store the memory address of another variable. This introduces a powerful level of indirection and flexibility in managing memory and data structures. Understanding and effectively using pointers in C++ is crucial for tasks such as dynamic memory allocation, efficient data manipulation, and building complex data structures. Pointers provide a way to directly access and modify memory, which is essential for low-level programming and optimizing code performance.Before diving into the details of pointers, it's essential to grasp some basic terminology. This section will cover terms like memory address, pointer declaration, and dereferencing, laying the groundwork for a comprehensive understanding of C++ pointers.

In the subsequent sections, we'll explore how to declare and initialize pointers, how to access memory addresses, and how to dereference pointers to retrieve and manipulate data. Whether you're a beginner or an experienced developer, this documentation will guide you through the essential concepts of pointers in C++, helping you harness their power for more efficient and flexible programming.


## 2. C++ Pointer Syntax Reference 
### 2.1 Syntax for Pointer Declaration

In C++, declaring pointers involves specifying the data type of the variable the pointer will point to. This section will provide a detailed reference for pointer declaration syntax, including examples for different data types and modifiers.

```c++
  data_type *pointer_name;
```

```c++
int *intPointer;
double *doublePointer;
char *charPointer;
```
### 2.2 C++ Pointer Syntax Reference 
Once declared, pointers need to be initialized with the memory address they will point to. This section will cover the various ways to initialize pointers, including assigning the address of existing variables and dynamic memory allocation.

```c++
pointer_name = &variable_name;
```
For example: 

```c++
int number = 42;
int *ptr = &number;

// Initializing pointer through dynamic memory allocation
int *dynamicPtr = new int;

```
Understanding the correct syntax for pointer declaration and initialization is crucial for working with pointers effectively. Refer to this section for a quick and comprehensive guide on C++ pointer syntax, ensuring accurate and efficient usage in your programs.


## 3. Memory Addresses 
### 3.1 Understanding Memory Addresses
In C++, every variable is stored in a specific memory location, identified by a unique address. This section delves into the concept of memory addressing, explaining how variables are allocated memory and how pointers play a crucial role in referencing these addresses.
### 3.2 Memory Address Representation:
In C++, memory addresses are typically represented in hexadecimal format. These addresses uniquely identify the location of variables in the computer's memory.
```c++
int number = 42;
cout << "Address of 'number': " << &number << endl;
```
### 3.3 The Address-of Operator (&)
The address-of operator (&) is a key element in obtaining the memory address of a variable. This section provides a detailed explanation of the address-of operator and its usage in retrieving the address of variables.

```c++
&variable_name;
```
Example:
```c++
int value = 10;
int *ptr = &value;
```

```c++
std::cout << "The variable's value lives at memory address " << &myVariable << "\n"; // This prints out the memory address of myVariable
```



## 4. Passing by Value vs Passing by Reference 
### 4.1 Passing by Value
When a parameter is passed by value, a copy of the actual parameter is made and passed to the function. Any modifications made to the parameter inside the function do not affect the original variable outside the function.
```c++
void functionName(type parameterName);
```
Example:
```c++
void incrementValue(int x) {
    x++;
}

int main() {
    int num = 5;
    incrementValue(num);
    // 'num' remains unchanged
    return 0;
}
```
### 4.2 Passing by reference
Passing by reference involves passing the memory address of the actual parameter to the function. This allows the function to directly modify the original variable outside the function.
```c++
void functionName(type &parameterName);
```
```c++
void incrementValue(int &x) {
    x++;
}

int main() {
    int num = 5;
    incrementValue(num);
    // 'num' is now 6
    return 0;
}
```
### 4.3 Choosing Between Passing by Value and Passing by Reference
Understanding when to use each method is crucial for efficient and effective programming. This section discusses the considerations for choosing between passing by value and passing by reference, taking into account factors such as performance and intended behavior.

## 5 References 
### 5.1 Basics of References 

In C++, references provide a powerful mechanism for creating aliases or alternative names for existing variables. This section explores the concept of references, their syntax, and how they differ from pointers.


**Recall:** Every variable that you define is another name (an **alias**) of a memory address. Imagine these memory addresses as boxes to store values in, and the variable names as a way to refer to the box.

You can create MORE **aliases** for the variables! These are called **references**.

```c++
// Let's say we have a variable defined
int i = 5;

// To define an alias (r) for it, we use
int &r = i; // Now, manipulating r, does the same thing as manipulating i
// Note: int& r = i; will ALSO work!

// What we're essentially saying, is, let the address of r (&r)  be the same as the address defined by i. So now r and i refer to the SAME memory address.
// r does NOT STORE the memory address, r BECOMES another name for the memory address that i is the alias for
```

To illustrate what we've just done, examine the output of the following program:

```c++
cout << "r = " << r << endl;
cout << "i = " << i << endl;
r++;
cout << "i = " << i << endl;

/* OUTPUT:
r = 5
i = 5
i = 6
*/

// Notice how i changed even though we didn't explicitly manipulate i, but r instead? r is indeed an alias for i!
```

### 5.2 Characteristics of References
**Note that there are some restrictions on references though!:**

> - References cannot be NULL (they must always be an alias for something that exists)
> - References cannot be changed to be an alias for another object/variable
> - A reference must be initialised when it is created

### 5.3 Use Cases for References
References offer advantages in specific scenarios. This section outlines common use cases where references shine, including function parameter passing, function return values, and creating aliases for variables.
By understanding the reference system in C++, you can enhance code readability, efficiency, and expressiveness. 
```c++
int& findLargest(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}
```


##  6. Arrays with Pointers 

### 6.1 Pointers and Arrays Relationship
In C++, arrays and pointers are closely linked, and understanding this relationship is crucial for efficient memory management and array manipulation. This section explores how arrays can be used with pointers, providing a deeper insight into their connection.

Basic concept: When an array is initialised in C++, each successive array element is actually in successive memory addresses! So when you increment a pointer that points to an array, you'll change the value that is pointed to to the next element!

```c++
// Let's try this out!
int numbers[5] = {1, 2, 3, 4, 5}; // Initialise an array
int* numbersPtr = numbers; // And a pointer which stores the pointer to the first element!

cout << "Before: " << *numbersPtr << endl;

numbersPtr++; // We increment the pointer here

cout << "After: " << *numbersPtr << endl;

/* OUTPUTS:
Before: 1
After: 2
*/
```

The variable name of an array is also just a pointer to the array!

```c++
// Let's try this out!
int numbers[5] = {1, 2, 3, 4, 5}; // Initialise an array

cout << "Before: " << *numbers << endl;

numbersPtr++; // We increment the pointer here

cout << "After: " << *numbers << endl;

/* OUTPUTS:
Before: 1
After: 2
*/
```

> So because of this. Just remember that array variables are special, since they're not really variables (aliases), but pointers that point to the array. So passing arrays to functions will result in you passing by reference!

### 6.2 Pointer Arithmetic
Pointer arithmetic is a powerful concept when working with arrays inside pointers. This section delves into the syntax and application of pointer arithmetic in navigating and manipulating array elements.

- Pointer Arithmetic Syntax:
  Incrementing a pointer: ptr++;
  Decrementing a pointer: ptr--;
  Accessing elements using pointer arithmetic: *(ptr + index);

## 7.Indirection (Pointers of Pointers) 

### 7.1 Pointers to Pointers Overview
Indirection, often involving pointers to pointers, is a powerful concept in C++. This section explores the concept of pointers to pointers, also known as double pointers, providing an in-depth understanding of their use and applications.

Basics of Pointers to Pointers:
- Definition: A pointer to a pointer is a variable that holds the address of another pointer.
- Double Indirection: It allows indirect access to the value that a pointer is pointing to.

Why is this useful? Stackoverflow question link below: 

https://stackoverflow.com/questions/5580761/why-use-double-pointer-or-why-use-pointers-to-pointers


Another example of indirection being used, is with strings

> If you want to have a list of characters (a word), you can use `char *word`
>
> If you want a list of words (a sentence), you can use `char **sentence`
>
> If you want a list of sentences (a monologue), you can use `char ***monologue`
>
> If you want a list of monologues (a biography), you can use `char ****biography`
>
> If you want a list of biographies (a bio-library), you can use `char *****biolibrary`
>


### 7.2 Syntax 

```c++
int value = 42;
int *ptr1 = &value;
int **ptr2 = &ptr1; // 'ptr2' is a pointer to a pointer
```

Understanding the syntax of double pointers is essential for declaring, initializing, and working with them in C++. This section provides a clear reference to the syntax involved in using pointers to pointers.


```c++
type **doublePointer = &pointer;
```

```c++
int value = 42;
int *ptr1 = &value;
int **ptr2 = &ptr1; // 'ptr2' is a pointer to a pointer
```

### 7.3 Applications of Pointers to Pointers
Pointers to pointers find applications in scenarios where multiple levels of indirection are required, such as dynamic multidimensional arrays, linked lists, and function parameters that need to modify pointer values.

```c++
int rows = 3, cols = 4;
int **matrix = new int*[rows];
for (int i = 0; i < rows; ++i) {
    matrix[i] = new int[cols];
}
```

## 8. Memory in C++ 
### 8.1 Memory Basics
Before we move on we should talk about how memory is stored in C++. There are several main sections of memory used in any C++ program. 
Understanding memory management is essential for writing efficient and error-free C++ code. This section provides an overview of memory in C++, including the stack and heap, and introduces concepts like memory addresses and memory leaks.

### Stack and Heap:
-  Stack Memory: Used for local variables and function call information. Memory is automatically managed.

- Heap Memory: Dynamically allocated memory that needs manual management using new and delete operators.

### 8.2 Dynamic Memory Allocation
Dynamic memory allocation is a crucial aspect of C++ programming, allowing you to allocate memory at runtime. This section covers the dynamic allocation and deallocation of memory using new and delete operators.

```c++
type *ptr = new type;
```

Example:
```c++
int *dynamicInt = new int;
// ... do operations ...
delete dynamicInt; // Release allocated memory

```

### 8.3 Memory Leaks and Best Practices
Memory leaks occur when allocated memory is not properly deallocated, leading to performance issues. This section discusses best practices for memory management, including proper deallocation, avoiding dangling pointers, and using smart pointers.

Best Practices:
- Always Deallocate: Match each new with a corresponding delete or use smart pointers.
- Nullify Pointers: Set pointers to nullptr after deallocation to avoid dangling pointers.

### **Stack and Heap**

The stack and heap actually share the same segment, and typically grow in opposite directions from opposite ends of the segment. Though some optimisations and compilers might break this guideline.

![Image result for stack](assets/stack-1562909159143.jpg)

[Image Source](<http://bluegalaxy.info/codewalk/2018/08/12/python-how-to-implement-a-lifo-stack/>)

The stack follows last-in, first-out (LIFO) structure.

The top of the stack and heap are tracked using pointers. Once the two pointers meet, you've run out of memory. If you don't catch this, you'll get overflows, which will mean you're going to have a **bad time.**

Each time you call a function, a stack frame containing function variables, and information relating to the function caller's environments, return address, some machine registers, and other function-call related info are pushed to the stack. If you have a recursive function each recursive call actually generates a new stack frame on the stack.

> - The stack grows and shrinks as functions push and pop local variables
> - There is no need to manage the memory yourself, variables are allocated and freed automatically
> - The stack has size limits
> - Stack variables only exist while the function that created them, is running
>   - This includes the main() function!!
>
> <https://www.gribblelab.org/CBootCamp/7_Memory_Stack_vs_Heap.html>

#### **Heap**

The heap is where dynamic memory allocation typically happens.

You manage it by using `malloc`, `realloc`, `free` (C functions), or the newer `new`, `new[]`, `delete`, and `delete[]` C++ operators, which are better and almost always better to use.

Every thread, library, or module in a single program process has access to this data segment, since they're essentially global.

It's **normally slower to access heap data than stack data since you need to use pointers to access them.**



## 9. Heap and Stack 
![image](https://github.com/cavadibrahimli1/sct_hw/assets/76445357/5f637dc6-0895-4a3d-95ab-caa8be0f25bb)


There's actually more to go through for the heap and stack, since they're the two data segments that you'll encounter most often.

> ### 9.1 Stack vs Heap Pros and Cons
>
> ### Stack
>
> - Very fast access
> - Don't have to explicitly de-allocate variables
> - Space is managed efficiently by CPU, memory will not become fragmented
> - Local variables only
> - Limit on stack size (OS-dependent)
> - Variables cannot be resized
>
> ### Heap
>
> - Variables can be accessed globally
> - No limit on memory size
> - (Relatively) slower access
> - No guaranteed efficient use of space, memory may become fragmented over time as blocks of memory are allocated, then freed
> - You must manage memory (you're in charge of allocating and freeing variables)
> - Variables can be resized using `realloc()`
>
> ## When to use the Heap?
>
> When should you use the heap, and when should you use the stack?
>
> If you need to allocate a **large block of memory** (e.g. a large array, or a big struct), and you need to **keep that variable around a long time** (like a global), then you should **allocate it on the heap**.
>
> If you are dealing with **relatively small variables that only need to persist as long as the function using them is alive**, then you should **use the stack**, it's easier and faster.
>
> If you need variables like arrays and structs that can **change size dynamically** (e.g. arrays that can grow or shrink as needed) then you will likely need to **allocate them on the heap**, and use dynamic memory allocation functions like `malloc()`, `calloc()`, `realloc()` and `free()` to manage that memory "by hand".

#### **Allocating to Stack**

It's fairly simple to allocate stuff to the stack. Just make sure that they're specifically **local variables** in a function (which can be main()!)

These variables are **automatically allocated**.

```c++
int main(){
  int c = 0;
  return 0;
}

void foo(){
  int a = 1;
}

// The variables are deallocated automatically once the functions go out of scope
```

### 9.2 Allocating to Heap

You **can't declare variables on the heap.** You can only create variables anonymously, then point to them with a named **pointer**.

So, allocating to the heap is trickier. You need to **explicitly allocate** the memory as a pointer.

The variables pointed at by the pointer are on the heap, and are **dynamically allocated.**

**Allocation**
```c++
int* ptr = new int; // ptr is assigned 4 bytes in the heap
int* array = new int[10]; // array is assigned 40 bytes in the heap

// Or later, when we go through smart pointers (which are better than raw pointers)
std::unique_ptr<someType> uniqueptr(new int(1));
```

**Deallocation**
```c++
// You'll need to manually deallocate them if using raw pointers to free memory
// Otherwise you'll get a memory leak!
*ex= new Example();
delete ex;
ex = nullptr; // Remember to reassign the pointer to NULL so the pointer won't dangle

// With a smart pointer you can just call .reset
uniqueptr.reset();
```

## 10. Dangling Pointers
### 10.1 Basics
Dangling pointers are pointers that point to a memory location that has been deallocated or is no longer valid. Accessing or dereferencing such pointers can lead to unpredictable behavior, crashes, or security vulnerabilities. This section explores the causes, consequences, and strategies for avoiding dangling pointers in C++.

![image](https://github.com/cavadibrahimli1/sct_hw/assets/76445357/3284bb08-53c0-43d8-918b-c29f2ee9acc1)

### 10.2 Causes of Dangling Pointers
Understanding the common causes of dangling pointers is crucial for preventing their occurrence. This section outlines scenarios that can lead to dangling pointers, including:
- Deallocation without Nullification: Failing to set a pointer to nullptr after deallocation.
- Returning Local Variables: Returning pointers pointing to local variables from a function.

### 10.3 Nullifying Pointers
A key strategy for preventing dangling pointers is to nullify pointers after deallocating memory. This section discusses the importance of setting pointers to nullptr to avoid them becoming dangling pointers.
```c++
int *ptr = new int;
// ... do operations ...
delete ptr;
ptr = nullptr; // Nullify the pointer after deallocation
```

### 10.4 Smart Pointers 
Smart pointers are C++ objects that act as wrappers around raw pointers, providing automatic memory management. They help prevent memory leaks, dangling pointers, and other memory-related issues by ensuring that memory is deallocated when it is no longer needed. This section explores the different types of smart pointers available in C++ and their key features. There are three main types of smart pointers provisioned for in the C++ `std` library (they used to be in boost, and still are, but it's more recommended nowadays to use the `std` library ones.) There are a bunch more outside of `std`, but these should be more than sufficient to do what you need to do.

> **All smart pointers destroy their wrapped pointers and the underlying data those pointers contain once they go out of scope.**
>
> By destroy, I mean that the smart pointer calls the destructor of the pointer or object that is passed to the smart pointer.

| Pointer Type   | Init Signature         | Description                                                  |
| -------------- | ---------------------- | ------------------------------------------------------------ |
| Unique Pointer | std::unique_ptr\<TYPE> | A unique pointer is always the unique owner of its associated raw pointer. This means that its underlying raw pointer can't be copied, only moved. When the unique pointer's associated raw pointer is reassigned or reset, the associated raw pointer and the memory it points to is released. |
| Shared Pointer | std::shared_ptr\<TYPE> | A shared pointer allows multiple owners to be assigned to its associated raw pointer. You can copy shared pointers as well as move them. This works because the shared pointer counts how many owners the associated raw pointer has, and only deletes the associated raw pointer when it has no more owners. |
| Weak Pointer   | std::weak_ptr\<TYPE>   | A weak pointer is something like a shared pointer, and can **only be used in conjunction with shared pointers.** They allow you to access an object without counting towards the owner count of the shared pointer. This allows access to the object without forcing you to keep the object alive. |


The choice between std::unique_ptr, std::shared_ptr, and std::weak_ptr depends on the ownership and sharing requirements of the dynamically allocated memory. This section provides guidance on selecting the appropriate smart pointer for different scenarios.



#### Benefits of Smart Pointers
- Automatic Deallocation - 
Smart pointers automatically deallocate memory when it is no longer needed, reducing the risk of memory leaks.
- Improved Memory Safety - 
Smart pointers help prevent common memory-related issues such as dangling pointers and accessing deallocated memory.
- Simplified Memory Management - 
Smart pointers simplify memory management by handling deallocation automatically, reducing the need for explicit delete operations.



#### **Example Syntax**

```c++
// Initialisation
std::unique_ptr<someType> uniqueptr;
std::shared_ptr<someType> sharedptr;
std::weak_ptr<someType> weakptr;

// Best practice initialisation (notice that this uses direct initialisation!)
// You won't be able to use copy initialisation for the uniqueptr
std::unique_ptr<someType> uniqueptr(new someType("VALUE/VALUES"));
std::shared_ptr<someType> sharedptr(new someType("VALUE/VALUES"));
std::weak_ptr<someType> weakptr(new someType("VALUE/VALUES"));

// Deleting the pointer
smart_pointer.reset();

// Releasing and then initialising
smart_pointer.reset(new someType("VALUE/VALUES"));

// Access member variables
smart_pointer->member_name;

// Reference passing
passByReferenceToMe(*smart_pointer);

// Check if smart pointer is empty or is null/uninitialised
// Two ways
if(!smart_pointer){}
if(smart_pointer == nullptr){}
```

#### **Copying Smart Pointers**

```c++
// This will work on everything EXCEPT for a unique pointer
smart_pointer2 = smart_pointer1;

// For more clarity
// Suppose smart_pointer1 is a unique_ptr
// This will NOT WORK!
std::unique_ptr<someType> smart_pointer2 = smart_pointer1;
```

#### **Moving Smart Pointers**

```c++
// Just use the standard move semantics!
smart_pointer2 = std::move(smart_pointer1);

// This will work with unique pointers!
// But do take note that this will cause smart_pointer1 to contain a nullptr
std::unique_ptr<someType> smart_pointer2 = std::move(smart_pointer1);
```

### 10.5 Best Practices to Avoid Dangling Pointers
#### 1. Nullify Pointers After Deallocation
After manually deallocating memory using delete, immediately set the pointer to nullptr. This practice helps prevent accidental dereferencing of a pointer that points to deallocated memory

```c++
int *ptr = new int;
// ... do operations ...
delete ptr;
ptr = nullptr; // Nullify the pointer after deallocation
```
#### 2. Use Smart Pointers
Prefer using smart pointers (e.g., std::unique_ptr, std::shared_ptr) over raw pointers. Smart pointers automatically handle memory deallocation, reducing the chances of leaving dangling pointers in your code.
```c++
#include <memory>

std::unique_ptr<int> smartPtr = std::make_unique<int>(42);
// No explicit delete needed; memory is automatically managed
```
#### 3. Avoid Returning Pointers to Local Variables
Avoid returning pointers pointing to local variables from functions. Local variables are automatically deallocated when the function exits, leading to a dangling pointer if its address is returned.
```c++
int* createDanglingPointer() {
    int localVar = 10;
    return &localVar; // Dangling pointer returned
}
```
#### 4. Prefer References Over Pointers
In situations where pointers are not necessary, prefer using references. References inherently avoid the issues associated with dangling pointers because they cannot be null and always refer to a valid object.
```c++
int value = 42;
int& ref = value; // 'ref' is a reference, not a pointer
```

#### 5. Use nullptr for Initialization
When declaring pointers, explicitly initialize them to nullptr if they are not assigned a valid address immediately. This helps avoid accidentally dereferencing uninitialized or garbage values.
```c++
int *ptr = nullptr; // Initialize to nullptr
// ... do operations ...
if (ptr != nullptr) {
    // Safely dereference 'ptr' only if it has a valid address
}
```

#### 6. Check for Null Before Dereferencing
Before dereferencing a pointer, check whether it is nullptr to avoid accessing invalid memory.
```c++
int *ptr = new int;
if (ptr != nullptr) {
    // Safe to dereference 'ptr'
    int value = *ptr;
}
```
### 10.6 Butter Overlfow
A buffer overflow is a type of software vulnerability that occurs when a program writes more data to a block of memory, or buffer, than it was allocated for. This can lead to unintended consequences and security vulnerabilities.
Here's a basic overview of how a buffer overflow typically occurs:
Buffer Allocation: In many programming languages, developers use buffers to store and manipulate data. These buffers are allocated a certain amount of memory.
Inadequate Input Validation: The vulnerability arises when the program does not properly validate or check the size of input data before copying it into a buffer. If an attacker can provide input larger than the buffer size, it can overflow into adjacent memory.
Overwriting Data: When the buffer overflows, it can overwrite adjacent memory locations, potentially affecting important data structures, control flow information, or even the program's return address.
Exploitation: An attacker can take advantage of a buffer overflow by injecting malicious code into the overwritten memory. This injected code may then be executed by manipulating the program's control flow.

![image](https://github.com/cavadibrahimli1/sct_hw/assets/76445357/2c7ba78f-2c54-4de4-b989-8b91ecc52629)

Buffer overflows can lead to a variety of security issues, including crashes, unauthorized access, and the execution of arbitrary code. Exploiting buffer overflows has historically been a common technique used by attackers to compromise systems.
Preventing buffer overflows is crucial for software security. This can be achieved through several practices:
1. Input Validation: Always validate and sanitize user input to ensure it adheres to expected size and format.
2. Bounds Checking: Implement bounds checking to ensure that data is not written beyond the allocated buffer size.
3. Use Safe Functions: Employ language features or libraries that provide safer alternatives to traditional functions that handle string manipulation, such as using strncpy instead of strcpy in C.
4. Memory Protection Mechanisms: Modern operating systems and processors often provide mechanisms like Data Execution Prevention (DEP) and Address Space Layout Randomization (ASLR) to mitigate the impact of buffer overflows.
5. Security-conscious programming practices and tools, such as static code analyzers and memory-safe languages, can also help prevent and detect buffer overflows during the development process.

## 11. Garbage Collection Mechanism
In computer science, garbage collection (GC) is a form of automatic memory management. The garbage collector attempts to reclaim memory which was allocated by the program, but is no longer referenced; such memory is called garbage.
Here's a brief overview of how a garbage collector typically works:
- Identification of Unreachable Objects: The garbage collector identifies objects in the program that are no longer accessible or reachable by following references from the root objects (e.g., global variables, stack variables).
- Marking Phase: During this phase, the garbage collector marks the reachable objects. It often uses a marking algorithm to traverse the object graph, starting from the root objects and marking all reachable objects.
- Sweeping Phase: In this phase, the garbage collector identifies and reclaims memory occupied by objects that were not marked as reachable. This memory is then made available for future allocations.
- Compacting (optional): Some garbage collectors include a compacting step where the memory is compacted to reduce fragmentation. This involves moving reachable objects closer together in memory, which can improve memory utilization.
- Finalization (optional): Some garbage collectors support finalization, allowing objects to perform cleanup actions before being reclaimed.

C++ does not have a built-in garbage collector like some other programming languages, such as Java. Instead, it relies on manual memory management through the use of new and delete operators.

When you allocate memory dynamically in C++ using the new operator, the memory is allocated on the heap. The heap is a region of memory where dynamically allocated objects are stored.

Here's a step-by-step explanation of how memory management works in C++:

1. When a C++ program needs to allocate memory dynamically, it calls the new operator.
2. The new operator requests memory from the operating system, which allocates a block of memory from the heap.
3. The memory address of the newly allocated block is returned to the C++ program.
4. The C++ program then uses the returned memory address to store data.
5. When the program is finished using the dynamically allocated memory, it must explicitly deallocate the memory using the delete operator.
6. The delete operator returns the memory back to the operating system, making it available for reuse.
7. If the program fails to deallocate the memory using the delete operator, the memory remains on the heap and is not available for reuse. This is known as a memory leak.

In summary, each approach has its advantages and trade-offs. Automatic garbage collection simplifies memory management but introduces a runtime overhead, while manual memory management gives more control but requires careful handling to avoid memory leaks and segmentation faults.

Some links I read additionally: 
1. https://stackoverflow.com/questions/147130/why-doesnt-c-have-a-garbage-collector
2. https://www.educba.com/c-plus-plus-garbage-collection/
3. https://www.techtarget.com/searchstorage/definition/garbage-collection




## Part 2 
```c++
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
    std::cout << "Value through autoPtrMoved: " << *autoPtrMoved << std::endl;

    // Add std::unique_ptr variable
    std::unique_ptr<int> uniquePtr(new int(36));
    std::cout << "Value through uniquePtr: " << *uniquePtr << std::endl;

    // Use get() and move() function of std::unique_ptr
    int* uniquePtrValue = uniquePtr.get();
    std::cout << "Value through get() of uniquePtr: " << *uniquePtrValue << std::endl;

    std::unique_ptr<int> uniquePtrMoved = std::move(uniquePtr);
    std::cout << "Value through uniquePtrMoved: " << *uniquePtrMoved << std::endl;

    // Explanation of auto_ptr deprecation and unique_ptr usage
    // std::auto_ptr is deprecated because it has ownership transfer semantics
    // which can lead to unexpected behavior. std::unique_ptr, introduced in C++11,
    // has improved ownership semantics and better safety features.

    // Add std::shared_ptr variable
    std::shared_ptr<int> sharedPtr1 = std::make_shared<int>(50);
    std::shared_ptr<int> sharedPtr2 = sharedPtr1; // Shared ownership

    std::cout << "Value through sharedPtr1: " << *sharedPtr1 << " (use_count: " << sharedPtr1.use_count() << ")" << std::endl;
    std::cout << "Value through sharedPtr2: " << *sharedPtr2 << " (use_count: " << sharedPtr2.use_count() << ")" << std::endl;

    // Use get(), move(), use_count(), and reset() functions of std::shared_ptr
    int* sharedPtrValue = sharedPtr1.get();
    std::cout << "Value through get() of sharedPtr1: " << *sharedPtrValue << std::endl;

    std::shared_ptr<int> sharedPtrMoved = std::move(sharedPtr1);
    std::cout << "Value through sharedPtrMoved: " << *sharedPtrMoved << " (use_count: " << sharedPtrMoved.use_count() << ")" << std::endl;

    sharedPtr2.reset(); // Reset one instance
    std::cout << "sharedPtr2 reset. sharedPtr1 use_count: " << sharedPtr1.use_count() << std::endl;

    // Add std::weak_ptr variable
    std::shared_ptr<int> sharedPtr3 = std::make_shared<int>(75);
    std::weak_ptr<int> weakPtr = sharedPtr3;

    // Use get() and move() functions of std::weak_ptr
    std::shared_ptr<int> sharedPtrFromWeak = weakPtr.lock();
    std::cout << "Value through weakPtr.lock(): " << *sharedPtrFromWeak << std::endl;

    std::weak_ptr<int> weakPtrMoved = std::move(weakPtr);
    std::shared_ptr<int> sharedPtrFromMovedWeak = weakPtrMoved.lock();
    std::cout << "Value through weakPtrMoved.lock(): " << *sharedPtrFromMovedWeak << std::endl;

    // Explanation of cyclic dependency and why weak_ptr is used
    // Weak pointers break cyclic dependencies among shared pointers, preventing memory leaks.

    return 0;
}

```

### Output :
![image](https://github.com/cavadibrahimli1/sct_hw/assets/76445357/7ffce9ff-562f-453f-aa26-998b8e664d2b)


