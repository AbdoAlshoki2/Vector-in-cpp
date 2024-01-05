# Vector and Iterator Implementation in C++

This repository contains a detailed implementation of a vector and its iterator in C++. The vector is a dynamic array, and the iterator is a tool for traversing this array.

## Table of Contents

- Vector Implementation
- Iterator Implementation
- Usage
- License

## Vector Implementation

The vector is a dynamic array implementation. It can grow and shrink in size as needed. The implementation includes functions for adding an element, removing an element, and accessing elements.

```cpp
template <typename T>
class Vector {
    T* arr;
    int capacity;
    int current;

public:
    // Constructor
    Vector() {
        arr = new T[1];
        capacity = 1;
        current = 0;
    }

    // Function to add an element at the end
    void push(T data) { /*...*/ }

    // Function to add an element at a specific index
    void push(int data, int index) { /*...*/ }

    // Function to extract an element at a specific index
    T get(int index) { /*...*/ }

    // Function to delete the last element
    void pop() { /*...*/ }

    // Function to get the size of the vector
    int size() { /*...*/ }
};
