#include <iostream>
#include <string>
#include "Array.hpp"

// Function to print any type of Array
template<typename T>
void printArray(const Array<T>& arr, const std::string& name) {
    std::cout << name << " (size " << arr.size() << "): ";
    for (unsigned int i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    try {
        // Test default constructor
        Array<int> emptyArray;
        std::cout << "Empty array size: " << emptyArray.size() << std::endl;

        // Test parameterized constructor
        Array<int> numbers(5);
        std::cout << "Number array initial size: " << numbers.size() << std::endl;

        // Test element initialization
        printArray(numbers, "Initial numbers");
        
        // Test element assignment and access
        for (unsigned int i = 0; i < numbers.size(); ++i) {
            numbers[i] = i * 10;
        }
        printArray(numbers, "Numbers after assignment");

        // Test copy constructor
        Array<int> copyNumbers(numbers);
        printArray(copyNumbers, "Copied numbers");

        // Test assignment operator
        Array<int> assignedNumbers = numbers;
        printArray(assignedNumbers, "Assigned numbers");

        // Modify original to test deep copy
        numbers[2] = 100;
        printArray(numbers, "Modified original numbers");
        printArray(copyNumbers, "Copy constructor numbers (should be unchanged)");
        printArray(assignedNumbers, "Assigned numbers (should be unchanged)");

        // Test const correctness
        const Array<int> constNumbers(3);
        // constNumbers[0] = 1; // This should not compile if uncommented
        int x = constNumbers[0]; // This should compile and work
        std::cout << "Const array access: " << x << std::endl;

        // Test with different type
        Array<std::string> strings(3);
        strings[0] = "Hello";
        strings[1] = "World";
        strings[2] = "!";
        printArray(strings, "String array");

        // Test exception for out of bounds access
        try {
            numbers[10] = 1000; // This should throw an exception
        } catch (const std::exception& e) {
            std::cout << "Exception caught (expected): " << e.what() << std::endl;
        }

        // Test edge cases
        Array<int> zeroSizeArray(0);
        std::cout << "Zero size array size: " << zeroSizeArray.size() << std::endl;

        // Test large array
        Array<char> largeArray(1000000);
        std::cout << "Large array size: " << largeArray.size() << std::endl;

        // Test assignment of different size arrays
        Array<int> smallArray(2);
        smallArray[0] = 1;
        smallArray[1] = 2;
        Array<int> biggerArray(4);
        biggerArray = smallArray; // This should work, resizing biggerArray
        printArray(biggerArray, "Bigger array after assignment from smaller array");

    } catch (const std::exception& e) {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }

    try
    {
        // this should throw an exception
        Array<int> arr;
        std::cout << "testing the new[] operator" << std::endl;
        arr[10];
        printArray(arr, "Array after out of range access");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}