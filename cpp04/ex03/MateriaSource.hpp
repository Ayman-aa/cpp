#ifndef MATTERIASOURCE_HPP
#define MATTERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    private:
        AMateria *source[4];
        int count;

    public:
        MateriaSource();
        MateriaSource(const MateriaSource &copy);
        MateriaSource &operator=(const MateriaSource &src);
        ~MateriaSource();

        void learnMateria(AMateria *m);
        AMateria* createMateria(std::string const & type);
};

#endif