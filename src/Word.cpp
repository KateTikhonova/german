#include "Word.h"

void Word::print() const
{
    std::cout << deu << " - " << rus;
}

std::ostream& operator << (std::ostream& os, const Word& temp)
{
    temp.print();
    return os;
}

void clear_scr()
{
    std::string clr(27, '\n');
    std::cout << clr;
}

bool read_right_number(unsigned int& number)
{
    std::string temp;
    bool ret=true;
    getline(std::cin, temp);
    if(temp.size() != 1){
        ret=false;
    }
    else{
        if(temp[0] <'0' || temp[0] >'3'){
            ret=false;
        }
        else{
            number = temp[0] -'0';
        }
    }
    return ret;
}

void make_small_deu(std::string& change)
{
    for(auto it = change.begin(); it != change.end(); ++it){
        if(*it >='A' && *it <= 'Z'){
            *it = *it - 'A' +'a';
        }
    }
}

void check_if_deu(std::string& test)
{
    for(auto it = test.begin(); it != test.end(); ++it){
        if((*it < 'a' || *it > 'z')  && !std::cin.eof()){
            throw (DeuEx());
            break;
        }
    }
}

void check_if_gen(std::string& test)
{
    if(test != "der" && test != "die" && test != "das" && !std::cin.eof()){
        throw(ArticleEx());
    }
}

void clear_buf()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
}

void proceed()
{
    std::cout << std::endl << "Нажмите любую кнопку, чтобы продолжить: " << std::endl;
    clear_buf();
}

int get_random_number(int maximum)
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(1, maximum);
    return dist(mt);
}
