#ifndef ARTICLEEX_H
#define ARTICLEEX_H

#include <exception>

class ArticleEx : public std :: exception
{
public:
    const char* what() const throw();
};

#endif // ARTICLEEX_H
