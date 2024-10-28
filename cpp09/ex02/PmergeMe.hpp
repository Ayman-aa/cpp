#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <climits>
#include <sstream>
#include <deque>
#include <vector>
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

        //methods
        void parse(int argNumber, char **arguments);
        int validNumber(std::string str);
};

#endif