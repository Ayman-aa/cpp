#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){ _isSorted = false; }

PmergeMe::PmergeMe(const PmergeMe &src)
{
    *this = src;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &src)
{
    (void)src;
    return *this;
}

PmergeMe::~PmergeMe(){}

// initial function for warming up the program
int PmergeMe::validNumber(std::string str)
{
    double number;
    std::stringstream ss;

    ss << str;
    ss >> number;
    if (number > INT_MAX)
        throw std::runtime_error("Number too big");
    return number;
}


// check if the container is sorted using one them (vector or deque) cuz they have the same values
bool isContainerSorted(std::vector<int> &container)
{
    for (size_t i = 0; i < container.size() - 1; i++)
    {
        if (container[i] > container[i + 1])
            return false;
    }
    return true;
}

// parse the arguments and store them in the two containers
void PmergeMe::parse(int argNumber, char **arguments)
{
    int number;
    std::stringstream ss;
    std::string str;

    for (int i = 0; i < argNumber; i++)
        ss << arguments[i] << " ";
    
    while (ss >> str)
    {
        if (str.empty()|| str.find_first_not_of("0123456789") != std::string::npos)
        {
            if (!str.empty() && !(str[0] == '+' && (str).find_first_not_of("0123456789", 1) == std::string::npos))
                throw std::runtime_error("Invalid argument");
        }

        number = validNumber(str);
        _C1.push_back(number);
        _C2.push_back(number);

    }
    if (isContainerSorted(_C1))
        _isSorted = true;

    std::cout << "Before: ";
    for (size_t i = 0; i < _C1.size(); i++)
        std::cout << _C1[i] << " ";
    std::cout << std::endl;
}

// The beginning of the merge sort algorithm
// Starting by implementing main merge sort function

// vector side

std::vector<int> PmergeMe::sortedVector()
{
    if(_isSorted)
        return _C1;
    
    std::vector<int, int> couples;
}


// dequw side
std::deque<int> PmergeMe::sortedDeque()
{
    if(_isSorted)
        return _C2;
    
    std::deque<int, int> couples;
}
