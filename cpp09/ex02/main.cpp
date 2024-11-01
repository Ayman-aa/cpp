#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    PmergeMe p;
    struct timeval startTimeVector, endTimeVector;
    struct timeval startTimeDeque, endTimeDeque;
    try
    {
        if (argc < 2)
            throw std::runtime_error("Not enough arguments");
        else if (argc == 2)
            throw std::runtime_error("Nothing to sort");
        for (int i = 1; i < argc; i++){
            if(*argv[i] == 0 || *argv[i] == ' ' || *argv[i] == '\t' || *argv[i] == '\n')
                throw std::runtime_error("Invalid argument");
        }
        p.parse(argc - 1, argv + 1);
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    // timing the vector sorting
    gettimeofday(&startTimeVector, NULL);
    std::vector<int> sortedVec = p.sortedVector();
    gettimeofday(&endTimeVector, NULL);
    long durationVector = (endTimeVector.tv_sec - startTimeVector.tv_sec) * 1000000 + (endTimeVector.tv_usec - startTimeVector.tv_usec);

    // timing the deque sorting
    gettimeofday(&startTimeDeque, NULL);
    std::deque<int> sortedDeque = p.sortedDeque();
    gettimeofday(&endTimeDeque, NULL);
    long durationDeque = (endTimeDeque.tv_sec - startTimeDeque.tv_sec) * 1000000 + (endTimeDeque.tv_usec - startTimeDeque.tv_usec);
    
    // results
    std::cout << "After: ";
    display(sortedDeque);
    std::cout << "Time to process a range of " << sortedVec.size() << " Time taken by std::vector: " << std::fixed << (double)durationVector << " us" << std::endl;
    std::cout << "Time to process a range of " << sortedDeque.size() << " Time taken by std::deque: " << std::fixed << (double)durationDeque << " us" << std::endl;
    return 0;
}