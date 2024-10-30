#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <sstream>
#include <utility>
#include <climits>
#include <cstdlib>

class PmergeMe
{
    private:
        std::vector<int> _C1;
        std::deque<int> _C2;
        bool _isSorted;

    public:
        //canonical form
        PmergeMe();
        PmergeMe(const PmergeMe &src);
        PmergeMe &operator=(const PmergeMe &src);
        ~PmergeMe();

        //Helper methods
        void parse(int argNumber, char **arguments);
        int validNumber(std::string str);

        //Vector methods
        std::vector<int> sortedVector();
        void recursiveSortingVector(std::vector<std::pair<int, int> > &couple);
        void mergeSortVector(std::vector<std::pair<int, int> > &couple, int left, int right);
        void mergeVector(std::vector<std::pair<int, int> > &arr, int left, int mid, int right);

        //Deque methods
        std::deque<int> sortedDeque();
};

#endif