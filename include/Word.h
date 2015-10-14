#ifndef WORD_H
#define WORD_H

#include <string>
#include <iostream>
#include <fstream>
#include <limits>
#include <iterator>
#include <random>
#include <vector>
#include <memory>
#include "DeuEx.h"
#include "ArticleEx.h"
#include "FatalEx.h"

class Word
{
protected:
    std::string deu;
    std::string rus;
public:
    virtual ~Word(){}
    virtual bool check() const =0;
    virtual bool finish() const =0;
    friend std::ostream& operator << (std::ostream& os, const Word& temp);
    virtual void print() const;
};

void clear_scr();
bool read_right_number(unsigned int& number);
void make_small_deu(std::string& change);
void check_if_deu(std::string& test);
void check_if_gen(std::string& test);
void clear_buf();
void proceed();

int get_random_number(int maximum);


#endif // WORD_H
