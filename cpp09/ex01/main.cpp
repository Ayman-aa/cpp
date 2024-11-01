#include "RPN.hpp"

int main(int ac, char **av)
{
    RPN rpn;
    std::stringstream ss;
    try {
        if (ac == 1) {
            std::cout << "Usage: ./RPN \"your numbers\"" << std::endl;
            return 0;
        }
        for (int i = 1; i < ac; i++)
            ss << " " << av[i];
        double res = rpn.rpn(ss);
        std::cout << res << std::endl;
    } catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }
    return 0;
}