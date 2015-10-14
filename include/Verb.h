#ifndef VERB_H
#define VERB_H

#include <Word.h>

class Verb: public Word
{
    std::string second;
    std::string third;
    static int number;
    static std::ifstream file_of_verb;
public:
    Verb();
    Verb (const Verb& temp);
    Verb operator=(const Verb& temp);
    ~Verb ();
    bool finish() const;
    void print () const;
    bool check()  const;
    static void print_all_verb();
};

std::vector <std::shared_ptr <Word>> create_vector_verb();
#endif // VERB_H
