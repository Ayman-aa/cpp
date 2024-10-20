#include "Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(std::time(0));
    try {
        std::cout << "Test 1: Basic test with 5 elements" << std::endl;
        Span sp1 = Span(5);
        sp1.addNumber(6);
        sp1.addNumber(3);
        sp1.addNumber(17);
        sp1.addNumber(9);
        sp1.addNumber(11);
        std::cout << "Shortest Span: " << sp1.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp1.longestSpan() << std::endl;
        std::cout << std::endl;

        std::cout << "Test 2: Adding too many numbers (throws exception)" << std::endl;
        Span sp2 = Span(3);
        sp2.addNumber(1);
        sp2.addNumber(2);
        sp2.addNumber(3);
        try {
            sp2.addNumber(4);
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
        std::cout << std::endl;

        std::cout << "Test 3: Finding span with less than 2 numbers (throws exception)" << std::endl;
        Span sp3 = Span(2);
        sp3.addNumber(10);
        try {
            sp3.shortestSpan(); 
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
        std::cout << std::endl;

        std::cout << "Test 4: Large span with 10,000 elements" << std::endl;
        Span sp4 = Span(10000);
        for (int i = 0; i < 10000; ++i) {
            sp4.addNumber(rand() % 10000);
        }
        std::cout << "Shortest Span: " << sp4.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp4.longestSpan() << std::endl;
        std::cout << std::endl;

        std::cout << "Test 5: Span with negative numbers" << std::endl;
        Span sp6 = Span(4);
        sp6.addNumber(-10);
        sp6.addNumber(-5);
        sp6.addNumber(-20);
        sp6.addNumber(0);
        std::cout << "Shortest Span: " << sp6.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp6.longestSpan() << std::endl;
        std::cout << std::endl;

        std::cout << "Test 6: Span with identical numbers" << std::endl;
        Span sp7 = Span(4);
        sp7.addNumber(42);
        sp7.addNumber(42);
        sp7.addNumber(42);
        sp7.addNumber(42);
        try {
            std::cout << "Shortest Span: " << sp7.shortestSpan() << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
        std::cout << "Longest Span: " << sp7.longestSpan() << std::endl;
        std::cout << std::endl;

    } catch (std::exception& e) {
        std::cerr << "massive Catch: " << e.what() << std::endl;
    }

    return 0;
}
