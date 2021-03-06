#include "inputWorking.h"
#include "ArticleEx.h"
#include "FatalEx.h"
#include "inputWorking.h"

void clear_scr(){
    std :: string clr(27, '\n');
    std :: cout << clr;
}

bool read_right_number(unsigned int& number){
    std :: string temp;
    bool ret=true;
    getline(std :: cin, temp);
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

void make_small_deu(std::string &change){
    for(auto it = change.begin(); it != change.end(); ++it){
        if(*it >='A' && *it <= 'Z'){
            *it = *it - 'A' +'a';
        }
    }
}

void check_if_deu(std::string& test){
    for(auto it = test.begin(); it != test.end(); ++it){
        if((*it < 'a' || *it > 'z')  && !cin.eof()){
            throw (DeuEx());
            break;
        }
    }
}

void check_if_gen(std::string& test){
    if(test != "der" && test != "die" && test != "das" && !cin.eof()){
        throw(ArticleEx());
    }
}
