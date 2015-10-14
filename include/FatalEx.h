#ifndef FATALEX_H
#define FATALEX_H

#include <exception>

class FatalEx : public std :: exception
{
public:
    const char* what() const throw();
};

#endif // FATALEX_H
