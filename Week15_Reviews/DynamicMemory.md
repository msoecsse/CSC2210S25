# Dynamic Memory Allocation

## Dynamic Memory Allocation in C
Dynamic memory allocation is a powerful feature in C that allows you to allocate memory at runtime. This is particularly useful when the size of the data structure is not known at compile time. The `malloc`, `calloc`, `realloc`, and `free` functions are commonly used for dynamic memory management.
These functions are defined in the `<stdlib.h>` header file.
### Functions for Dynamic Memory Allocation
- **`malloc(size_t size)`**: Allocates a block of memory of the specified size (in bytes) and returns a pointer to the first byte of the allocated memory. The memory is not initialized.
- **`calloc(size_t num, size_t size)`**: Allocates memory for an array of `num` elements, each of `size` bytes, and initializes all bytes to zero. Returns a pointer to the allocated memory.
- **`realloc(void *ptr, size_t newSize)`**: Resizes the memory block pointed to by `ptr` to `newSize` bytes. If the new size is larger, the additional memory is uninitialized. If the new size is smaller, the excess memory is freed.
- **`free(void *ptr)`**: Deallocates the memory previously allocated by `malloc`, `calloc`, or `realloc`. It is important to free dynamically allocated memory to avoid memory leaks.
- **`sizeof(type)`**: Returns the size (in bytes) of the specified type. This is often used in conjunction with dynamic memory allocation functions to determine the size of the memory block to allocate.
### Example Code
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
// Function to demonstrate dynamic memory allocation
void dynamicMemoryAllocation() {
    int *ptr = (int *)malloc(5 * sizeof(int)); // Allocate memory for 5 integers
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    // Initialize the allocated memory
    for (int i = 0; i < 5; i++) {
        ptr[i] = (i + 1) * 10;
    }

    printf("Dynamically allocated array elements:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", ptr[i]);
    }
    printf("\n");

    free(ptr); // Free the allocated memory
}
```

### Initializing Dynamically Allocated Memory
- When using `malloc`, the allocated memory is not initialized, which means it may contain garbage values. To ensure that the memory is initialized to zero, you can use `calloc` instead of `malloc`. For example:
- int_32 is a 32-bit signed integer type. It is commonly used in C and C++ programming for representing integer values. The size of int_32 is typically 4 bytes (32 bits) on most platforms.
- int_64 is a 64-bit signed integer type. It is commonly used in C and C++ programming for representing larger integer values. The size of int_64 is typically 8 bytes (64 bits) on most platforms.

### Example Code
```c    
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
// Function to demonstrate dynamic memory allocation with calloc
void dynamicMemoryAllocationWithCalloc() {
    int *ptr = (int *)calloc(5, sizeof(int)); // Allocate memory for 5 integers and initialize to zero
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    printf("Dynamically allocated array elements initialized to zero:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", ptr[i]);
    }
    printf("\n");

    free(ptr); // Free the allocated memory
}
```
### Resizing Dynamically Allocated Memory
- You can use `realloc` to change the size of a previously allocated memory block. This is useful when you need to increase or decrease the size of an array dynamically.
- When using `realloc`, if the new size is larger than the old size, the additional memory is uninitialized. If the new size is smaller, the excess memory is freed.
- If `realloc` fails to allocate the requested memory, it returns `NULL`, and the original memory block remains unchanged. Always check the return value of `realloc` before using the new pointer.
- If `realloc` is successful, it may return a different pointer than the original one. Therefore, you should always assign the result of `realloc` to a new pointer variable or check if the original pointer is still valid.
### Example Code
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
// Function to demonstrate resizing dynamically allocated memory
void resizeDynamicMemory() {
    int *ptr = (int *)malloc(5 * sizeof(int)); // Allocate memory for 5 integers
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    // Initialize the allocated memory
    for (int i = 0; i < 5; i++) {
        ptr[i] = (i + 1) * 10;
    }

    printf("Original array elements:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", ptr[i]);
    }
    printf("\n");

    // Resize the memory block to hold 10 integers
    int *newPtr = (int *)realloc(ptr, 10 * sizeof(int));
    if (newPtr == NULL) {
        printf("Memory reallocation failed\n");
        free(ptr); // Free the original memory block
        return;
    }
    ptr = newPtr; // Update the pointer to the new memory block
    // Initialize the new elements
    for (int i = 5; i < 10; i++) {
        ptr[i] = (i + 1) * 10;
    }
    printf("Resized array elements:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", ptr[i]);
    }
    printf("\n");
    free(ptr); // Free the allocated memory
}
```
### Freeing Dynamically Allocated Memory
- It is important to free dynamically allocated memory using the `free` function to avoid memory leaks. Memory leaks occur when memory that is no longer needed is not released, leading to increased memory usage and potential program crashes.
- Always free memory that has been allocated with `malloc`, `calloc`, or `realloc` when it is no longer needed.
- After freeing memory, it is a good practice to set the pointer to `NULL` to avoid dangling pointers. A dangling pointer is a pointer that points to a memory location that has already been freed.
- Attempting to access memory through a dangling pointer can lead to undefined behavior.

### Example Code
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
// Function to demonstrate freeing dynamically allocated memory
void freeDynamicMemory() {
    int *ptr = (int *)malloc(5 * sizeof(int)); // Allocate memory for 5 integers
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    // Initialize the allocated memory
    for (int i = 0; i < 5; i++) {
        ptr[i] = (i + 1) * 10;
    }

    printf("Dynamically allocated array elements:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", ptr[i]);
    }
    printf("\n");

    free(ptr); // Free the allocated memory
    ptr = NULL; // Set pointer to NULL to avoid dangling pointer
}
```


## Dynamic Memory Allocation in C++
Dynamic memory allocation in C++ is similar to C, but C++ provides additional features such as constructors and destructors for classes, which can be used to initialize and clean up dynamically allocated objects. The `new` and `delete` operators are used for dynamic memory management in C++.
### Operators for Dynamic Memory Allocation
- **`new`**: Allocates memory for an object or array of objects and returns a pointer to the allocated memory. It also calls the constructor for the object if it is a class type.
- **`new[]`**: Allocates memory for an array of objects and returns a pointer to the first element of the array. It also calls the constructor for each object in the array.
- **`delete`**: Deallocates memory previously allocated with `new`. It also calls the destructor for the object if it is a class type.
- **`delete[]`**: Deallocates memory previously allocated with `new[]`. It also calls the destructor for each object in the array.
- **`sizeof(type)`**: Returns the size (in bytes) of the specified type. This is often used in conjunction with dynamic memory allocation operators to determine the size of the memory block to allocate.
- **`nullptr`**: A null pointer constant introduced in C++11. It is used to represent a null pointer and is type-safe.
- **`std::unique_ptr`**: A smart pointer that manages the lifetime of a dynamically allocated object. It automatically deallocates the memory when it goes out of scope, preventing memory leaks.

### Example Code
```cpp
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <memory>
using namespace std;
// Function to demonstrate dynamic memory allocation using new
void dynamicMemoryAllocation() {
    int *ptr = new int[5]; // Allocate memory for 5 integers
    if (ptr == nullptr) {
        cout << "Memory allocation failed" << endl;
        return;
    }

    // Initialize the allocated memory
    for (int i = 0; i < 5; i++) {
        ptr[i] = (i + 1) * 10;
    }

    cout << "Dynamically allocated array elements:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << ptr[i] << " ";
    }
    cout << endl;

    delete[] ptr; // Free the allocated memory
}
```


