#ifndef DEUEX_H
#define DEUEX_H

#include <exception>
#include "DeuEx.h"

class DeuEx : public std :: exception
{
public:
    const char* what() const throw();
};

#endif // DEUEX_H
