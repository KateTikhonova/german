#ifndef NOUN_H
#define NOUN_H

#include <Word.h>

class Noun: public Word
{
    std::string gender;
    static int amount;
    static std::ifstream file_of_noun;
public:
    Noun();
    Noun (const Noun& temp);
    Noun operator=(const Noun& temp);
    ~Noun ();
    bool finish() const;
    void print() const;
    bool check() const;
    static void print_all_noun();
};

std::vector <std::shared_ptr <Word>> create_vector_noun();

#endif // NOUN_H
