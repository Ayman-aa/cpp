#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    PmergeMe p;

    try
    {
        if (argc < 2)
            throw std::runtime_error("Not enough arguments");
        p.parse(argc - 1, argv + 1);
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}