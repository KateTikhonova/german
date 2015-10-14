#include "Noun.h"

Noun::Noun()
{
    if(amount == 0){
        file_of_noun.open("Noun1.txt");
        if(!file_of_noun.is_open()){
            throw(FatalEx());
        }
    }
    ++amount;
    file_of_noun >> gender >> deu >> rus;
}

Noun::~Noun()
{
    --amount;
    if(amount == 0) {
        try{
            file_of_noun.close();
        }
        catch (...){
            std::cout << "Фатальная ошибка" << std::endl;
        }
    }
}

Noun::Noun (const Noun& temp)
{
    gender=temp.gender;
    deu=temp.deu;
    rus=temp.rus;
    ++amount;
}

Noun Noun::operator=(const Noun& temp)
{
    gender=temp.gender;
    deu=temp.deu;
    rus=temp.rus;
    return *this;
}

bool Noun::finish() const
{
    return file_of_noun.eof();
}

void Noun::print() const
{
    std:: cout << gender  << " " << deu << " - "<< rus;
}

bool Noun::check() const
{
    std::string test;
    std::string garbage;
    bool flag=true;
    std::cout << deu << " " << rus << std::endl;;
    while(flag && !(std::cin.eof())){
        try{
            std::cout << "Введите артикль:" << std::endl;;
            std::cin >> test;
            std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
            //!!!!!!!!!!!!!!!!!!!!!!
            make_small_deu(test);
            check_if_deu(test);
            check_if_gen(test);
            flag=false;
        }
        catch (std::exception& ex){
            std::cin.clear();
            std::cout << ex.what() << std::endl;;
        }
    }
    return gender == test;
}

void Noun::print_all_noun()
{
    std::ifstream temp_file("Noun.txt");
    if(!temp_file.is_open()){
        throw (FatalEx());
    }
    std::string gen_temp;
    while(!temp_file.eof()){
        std::getline(temp_file, gen_temp);
        if(!temp_file.eof()){
            std::cout << gen_temp << std::endl;;
        }
    }
    temp_file.close();

}

std::vector <std::shared_ptr <Word>> create_vector_noun()
{
    std::vector <std::shared_ptr <Word>> ret;
    std::shared_ptr <Word> temp;
     while(true){
        temp = std::make_shared <Noun> ();
        if((std::static_pointer_cast <Noun> (temp))->finish()){
            break;
        }
        if(ret.empty()){
            ret.push_back (temp);
        }
        else{
            ret.insert(ret.begin() + get_random_number(ret.size()),temp);
        }
    }
    return ret;
}

int Noun :: amount=0;
std::ifstream Noun :: file_of_noun;
