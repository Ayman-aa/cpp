#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Error: could not open file." << std::endl;
        return 1;
    }

    try {
        BitcoinExchange exchange("data.csv");
        exchange.processFile(argv[1]);
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
        return 1;
    }

    return 0;
}