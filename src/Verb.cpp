#include "Verb.h"

Verb::Verb()
{
    if(number == 0){
        file_of_verb.open("Verb.txt");
        if(!file_of_verb.is_open()){
            throw(FatalEx());
        }
    }
    ++number;
    file_of_verb >>  deu >> second >> third >> rus;
}

Verb::Verb (const Verb& temp)
{
    deu=temp.deu;
    rus=temp.rus;
    second=temp.second;
    third=temp.third;
    ++number;
}

Verb Verb::operator=(const Verb& temp)
{
    deu=temp.deu;
    rus=temp.rus;
    second=temp.second;
    third=temp.third;
    return *this;
}

Verb::~Verb (){
    --number;
    if(number == 0){
        try{
            file_of_verb.close();
        }
        catch (...){
            std::cout << "Фатальная ошибка" << std::endl;
        }
    }
}

bool Verb::finish() const
{
    return file_of_verb.eof();
}

void Verb::print () const
{
    std::cout << deu << " " << second << " " << third << " - " << rus;
}

bool Verb::check() const
{
    std::string test_sec;
    std::string test_third;
    std::string garbage;
    bool flag=true;
    std::cout << deu << " " << rus << std::endl;
    while(flag && !std::cin.eof()){
        try{
            std::cout << "Введите формы глагола:" << std::endl;
            std::cin >> test_sec;
            std::cin >> test_third;
            std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
            //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            make_small_deu(test_sec);
            make_small_deu(test_third);
            check_if_deu(test_sec);
            flag=false;
        }
        catch (std::exception& ex){
            std::cin.clear();
            std::cout << ex.what() << std::endl;
        }
    }
    return test_sec == second && test_third == third;
}

void Verb::print_all_verb()
{
    std::ifstream temp_file("Verb1.txt");
    if(!temp_file.is_open()){
        throw(FatalEx());
    }
    std::string temp_str;
    while(!temp_file.eof()){
        getline(temp_file, temp_str);
        if(!temp_file.eof()){
            std::cout << temp_str << std::endl;
        }
    }
    temp_file.close();
}

std::vector <std::shared_ptr <Word>> create_vector_verb()
{
    std::vector <std::shared_ptr <Word>> ret;
    std::shared_ptr <Word> temp;
     while(true){
        temp = std::make_shared <Verb> ();
        if((std::static_pointer_cast <Verb> (temp))->finish()){
            break;
        }
        if(ret.empty()){
            ret.push_back (temp);
        }
        else{
            ret.insert(ret.begin() + get_random_number(ret.size()),temp);
        }
    }
    /*for(auto it = ret.begin(); it != ret.end(); ++it){
        cout << *(*it) << endl;
    }*/
    return ret;
}

int Verb :: number=0;
std::ifstream Verb :: file_of_verb;
