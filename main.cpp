#include <iostream>
#include <ctime>
#include <list>

using namespace std;

struct Questionary{ //анкета
    public:
        char* get(){
            return "";
        }
        void set(char* Surname, char* BirthDate, int WorkExperience){
            surname = Surname;
            birthDate = BirthDate;
            workExperience = WorkExperience;
        }
    private:
        char* surname;
        char* birthDate;
        int workExperience;
};

struct Questionarys{
    public:
        void Add(Questionary questionary){
            questionarys.push_back(questionary);
        }
        list<Questionary> get(){
            return questionarys;
        }
        int getSize(){
            return questionarys.size();
        }
    private:
        std::list<Questionary> questionarys;
    };

struct Question{ //вопрос
    public:
        void set(char* Question){
            question = Question;
        }
        char* get(){
            return question;
        }
    private:
        char* question;
};

class Questions{ //вопросы
    private:
        int enumerator = 0;
        Question *questions = new Question[3];
        void filling(){
            questions[0].set("Set surname");
            questions[1].set("Set birth date");
            questions[2].set("Set work experience");
        }
    public:
        Questions(){
            filling();
        }
        char* getAnswer(){
            char* question = questions[enumerator].get();
            ++enumerator;
            return question;
        }
};

class Questionnaire{ //опросник
    public:
        void questioning(){
            Questionarys questionarys;
            char flag = 'Y';
            while (flag = 'Y'){
                string *str = new string[3];
                Questions questions;
                for(int i = 0; i < 3; i++){
                    cout << questions.getAnswer() << endl;
                    std::cin >> str[i];
                }
                Questionary questionary;
                questionary.set((char*)&str[0], (char*)&str[1], stoi(str[2]));
                while((flag != 'Y') or (flag != 'n')) {
                    cout << "Continued Y/n" << endl;
                    cin >> flag;
                }
            }
        }
};

int main() {
    Questionnaire questionnaire;
    questionnaire.questioning();
    return 0;
}
