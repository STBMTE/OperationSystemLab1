#include <iostream>
#include <list>
#include <string>

using namespace std;

static int _id = 1;

struct Questionary { //анкета
public:
    string get() {
        return "Id: " + to_string(id) + "\n" + "Surname: " + (string)surname + "\n" + "BirthDate: " + (string)birthDate + "\n" + "Experience: " + to_string(workExperience);
    }
    void set(char* Surname, char* BirthDate, int WorkExperience) {
        id = _id;
        surname = Surname;
        birthDate = BirthDate;
        workExperience = WorkExperience;
        _id = id + 1;
    }
private:
    int id;
    char* surname;
    char* birthDate;
    int workExperience;
};

struct Questionarys {
public:
    void Add(Questionary questionary) {
        questionarys.push_back(questionary);
    }
    list<Questionary> get() {
        return questionarys;
    }
    int getSize() {
        return questionarys.size();
    }
private:
    std::list<Questionary> questionarys;
};

struct Question { //вопрос
public:
    void set(string Question) {
        question = Question;
    }
    string get() {
        return question;
    }
private:
    string question;
};

class Questions { //вопросы
private:
    int enumerator = 0;
    Question* questions = new Question[3];
    void filling() {
        questions[0].set("Set surname");
        questions[1].set("Set birth date");
        questions[2].set("Set work experience");
    }
public:
    Questions() {
        filling();
    }
    string getAnswer() {
        string question = questions[enumerator].get();
        ++enumerator;
        return question;
    }
};

class Questionnaire { //опросник
public:
    void questioning() {
        Questionarys questionarys;
        string flag = "Y";
        while (flag == "Y") {
            string* str = new string[3];
            Questions questions;
            for (int i = 0; i < 3; i++) {
                cout << questions.getAnswer() << endl;
                std::cin >> str[i];
            }
            Questionary questionary;
            questionary.set((char*)&str[0], (char*)&str[1], atoi(str[2].c_str()));
            do
            {
                cout << "Continued Y/n" << endl;
                cin >> flag;
            } while (flag != "Y" && flag != "n");
        }
    }
};

class WorkingWithFile {
public:
    WorkingWithFile(char* Path) {
        path = Path;
    }

    Questionary ReadFile() {

    }

    void WriteFile(Questionary[]) {

    }

    void Redaction() {

    }

private:
    char* path;
};

int main() {
    /*Questionnaire questionnaire;
    questionnaire.questioning();*/
    Questionary quest;
    quest.set((char*)"You", (char*)"12.15.1251", 4);
    cout << quest.get() << endl;
    return 0;
}
