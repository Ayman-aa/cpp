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
// Starting by implementing main merge sort functions

// vector side

void PmergeMe::mergeVector(std::vector<std::pair<int, int> > &arr, int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<std::pair<int, int> > L, R;

    L.reserve(n1);
    R.reserve(n2);

    for (i = 0; i < n1; i++)
        L.push_back(arr[left + i]);
    for (j = 0; j < n2; j++)
        R.push_back(arr[mid + 1 + j]);

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2)
    {
        if (L[i].first <= R[j].first)
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void PmergeMe::mergeSortVector(std::vector<std::pair<int, int> > &couple, int left, int right)
{
    if (left < right)
    {
        int middle = left + (right - left) / 2;
        mergeSortVector(couple, left, middle);
        mergeSortVector(couple, middle + 1, right);
        mergeVector(couple, left, middle, right);
    }
}
void PmergeMe::recursiveSortingVector(std::vector<std::pair<int, int> > &couple)
{
    for (std::vector<std::pair<int, int> >::iterator it = couple.begin(); it != couple.end(); it++)
    {
        if (it->first > it->second)
            std::swap(it->first, it->second);
    }
    mergeSortVector(couple, 0, couple.size() - 1);
}

std::vector<int> PmergeMe::sortedVector()
{
    if(_isSorted)
        return _C1;
    
    std::vector<std::pair<int, int> > couples;
    std::vector<int> strugle;

    if (_C1.size() % 2 != 0)
    {
        strugle.push_back(_C1.back());
        _C1.pop_back();
    }

    //spliting into couples
    for (size_t i = 0; i < _C1.size(); i += 2)
        couples.push_back(std::make_pair(_C1[i], _C1[i + 1]));

    //sorting couples
    recursiveSortingVector(couples);

    std::vector<int> result;
    return result;
}


// deque side
std::deque<int> PmergeMe::sortedDeque()
{
    if(_isSorted)
        return _C2;
    
    std::deque<std::pair<int, int> > couples;


    std::deque<int> result;
    return result;
}
