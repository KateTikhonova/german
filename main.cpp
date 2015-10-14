#include <memory>
#include "Word.h"
#include "Noun.h"
#include "Verb.h"

using namespace std;

vector <shared_ptr <Word>> create_vector()
{
    vector <shared_ptr <Word>> ret=create_vector_noun();
    shared_ptr <Word> temp;
    while(true){
        temp = make_shared <Verb> ();
        if((static_pointer_cast <Verb> (temp))->finish()){
            break;
        }
        ret.insert(ret.begin() + get_random_number(ret.size()),temp);
    }
    return ret;
}

void game (vector <shared_ptr <Word>>& test, unsigned int attempt, const unsigned int level)
{
//level = 2,3,4
    if(test.size() < level){
        cout << " Вы выиграли!!! Поздравляю!!!" << endl;
        proceed();
    }
    else{
        if(attempt == level){
            cout << "Вы проиграли." << endl;
            proceed();
        }
        else{
            unsigned int rest = level - attempt - 1;
            string suff;
            switch(rest){
                case 2:
                case 3:
                    suff = "ки";
                    break;
                case 1:
                    suff = "ка";
                    break;
                case 0:
                    suff = "ок";
                    break;
                default:
                    throw (FatalEx());
            }
            cout << "Попытка номер " << attempt << ". Осталось " << rest << " попыт" << suff << ". Удачи!!!" << endl << endl;
            vector <shared_ptr <Word>> next;
            shared_ptr <Word> temp;
            for(auto it = test.begin(); it != test.end(); ++it){
                temp=*it;
                if(!temp->check()){
                    cout << "Неправильно! Правильный ответ:" << endl;
                    cout << *temp << endl << endl << endl;
                    if(next.empty()){
                            next.push_back (temp);
                    }
                    else{
                            next.insert(next.begin() + get_random_number(next.size()),temp);
                    }
                }
                else{
                    cout << "Правильно!" << endl << endl << endl;
                }
            }
            cin.ignore(numeric_limits <streamsize>::max(), '\n');
            clear_scr();
            if(cin.eof()){
                cout << "Игра завершена." << endl;
            }
            else{
                game(next, attempt+1, level);
            }
        }
    }

}

void play_game()
{
    unsigned int mode=0;
    unsigned int level=0;
    vector <shared_ptr <Word>> test;
    cout << endl << "Выберите тип игры:" << endl;
    cout << "Выйти из этого режима в главное меню               - любая кнопка" << endl;
    cout << "Проверить знание существительных                   - 1" << endl;
    cout << "Проверить знание глаголов                          - 2" << endl;
    cout << "Мультиигра (и существительные и прилагательные)    - 3" << endl;
    if( read_right_number(mode)){
        cout << endl << "Отлично!!! Теперь выберите уровень: " << endl;
        cout << "(их всего 3 - просто нажмите цифру от 1 до 3, где 1 - сложнейший)" << endl;
        cout << "Если же Вы передумали играть - нажмите любую кнопку." << endl;
        if( read_right_number(level)){
            cout << endl;
            switch(mode)
            {
                case 1:
                    test=create_vector_noun();
                    game(test, 1, level+1);
                    break;
                case 2:
                    test=create_vector_verb();
                    game(test, 1, level+1);
                    break;
                case 3:
                    test=create_vector();
                    game(test, 1, level+1);
                    break;
                default:
                    throw (FatalEx());
            }

        }
    }
}

void game_interface()
{
    unsigned int mode=0;
    cout << "Guten Tag! Данная игра создана в помощь людям, изучающим немецкий язык. " << endl;
    cout << "Внизу Вы видете опции данной игры. Выберите одну из них :)" << endl << endl;
    while(true){
        cout << "Выйти                          - любая кнопка" << endl;
        cout << "Вывести все глаголы            - 1" << endl;
        cout << "Вывести все существительные    - 2" << endl;
        cout << "Сыграть в игру                 - 3" << endl;
        if( !read_right_number(mode)){
            break;
        }
        switch(mode)
        {
            case 1:
                Verb :: print_all_verb();
                proceed();
                break;
            case 2:
                Noun :: print_all_noun();
                proceed();
                break;
            case 3:
                play_game();
                break;
            default:
                    throw (FatalEx());
        }
        if(cin.eof()){
            break;
        }
        clear_scr();
        cout << "Главное меню. Опции:" << endl << endl;
    }
}

int main()
{
    try{
        game_interface();
    }
    catch(exception& ex){
        cout << ex.what() << endl;
    }
    catch(...){
        cout << "Фатальная ошибка" << endl;
    }
    return 0;
}

