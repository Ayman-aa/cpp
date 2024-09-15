#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : count(0)
{
    for (int i = 0; i < 4; i++)
        source[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const & src) : count(0)
{
    *this = src;
}

MateriaSource & MateriaSource::operator=(MateriaSource const & src)
{
    if (this != &src)
    {
        for (int i = 0; i < 4; i++)
        {
            if (source[i])
                delete source[i];
            if (src.source[i])
                source[i] = src.source[i]->clone();
            else
                source[i] = NULL;
        }
        count = src.count;
    }
    return *this;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
    {
        if (source[i])
            delete source[i];
    }
}

void MateriaSource::learnMateria(AMateria* m)
{
    if (!m)
        return;
    for (int i = 0; i < 4; i++)
    {
        if (source[i] == NULL)
        {
            source[i] = m->clone();
            count++;
            break;
        }
    }
    delete m;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
    {
        if (source[i] != NULL)
        {
            if (source[i]->getType().compare(type) == 0)
                return (source[i]->clone());
        }
    }
    return (0);
}