#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

void saveToFile(const string& file_name, const vector<string>& data) {
    ofstream file(file_name);
    if (file.is_open()) {
        for (int i = 0; i < data.size(); i++) {
            file << data[i] << " ";
        }
        file.close();
    }
    else {
            cout << "файл не открылся";
    }
};

void loadFromFile(const string& file_name, vector<string>& outData) {
    ifstream file(file_name);
    if (file.is_open()) {
        string line;
        getline(file, line);
        istringstream ss(line);
        string kusok;
        while (ss >> kusok) {
            outData.push_back(kusok);
        }
        file.close();
    }
    else {
        cout << "файл не открылся";
    }
};

struct Book {
    string Author;
    string Title;
    int Year;
};

void saveToFile(const string& file_name, const vector<Book>& data) {
    ofstream file(file_name);
    if (file.is_open()) {
        for (int i = 0; i < data.size(); i++) {
            file << data[i].Author << " ";
            file << data[i].Title << " ";
            file << data[i].Year << endl;
        }
        file.close();
    }
    else {
        cout << "файл не открылся";
    }
};

void loadFromFile(const string& file_name, vector<Book>& outData) {
    ifstream file(file_name);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            string kusok;
            istringstream ss(line);
            Book book;
            ss >> kusok;
            book.Author = kusok;
            ss >> kusok;
            book.Title = kusok;
            ss >> kusok;
            book.Year = stoi(kusok);
            outData.push_back(book);
        }
        file.close();
    }
    else {
        cout << "файл не открылся";
    }
};

enum Score {
    Unsatisfactory = 2,
    Satisfactory,
    Good,
    Excellent
};

struct Student {
    string Name;
    int Age;
    map<string, Score> RecordBook;
};

using Groups = map<string, vector<Student>>;

void saveToFile(const string& file_name, const Groups& group) {
    ofstream file(file_name);
    if (file.is_open()) {
        for (auto elem : group) {
            file << elem.first << " " << elem.second.size() << endl;
            for (int i = 0; i < elem.second.size(); i++) {
                file << elem.second[i].Name << " ";
                file << elem.second[i].Age;
                for (auto elem1 : elem.second[i].RecordBook) {
                    file << " " << elem1.first << " " << elem1.second;
                }
                file << endl;
            }
        }
        file.close();
    }
    else {
        cout << "файл не открылся";
    }
};

void loadFromFile(const string& file_name, Groups& outGroups) {
    ifstream file(file_name);
    if (file.is_open()) {
        vector<Student> students;
        string line;
        getline(file, line);
        istringstream ss(line);
        string group_name;
        ss >> group_name;
        string kusok;
        ss >> kusok;
        int amount = stoi(kusok);
        for(int i = 0; i < amount; i++) {
            getline(file, line);
            istringstream ss(line);
            Student student;
            ss >> kusok;
            student.Name = kusok;
            ss >> kusok;
            student.Age = stoi(kusok);
            string subject;
            int j = 0;
            while (ss >> kusok) {
                if (j % 2 == 0) {
                    subject = kusok;
                }
                else { // Костыль ГОСТ Р 58281-2022 
                    if (kusok == "2") student.RecordBook.insert({subject, Unsatisfactory});
                    else if (kusok == "3") student.RecordBook.insert({subject, Satisfactory});
                    else if (kusok == "4") {
                        student.RecordBook.insert({subject, Good});
                    }
                    else student.RecordBook.insert({subject, Excellent});
                }
                j++;
            }
            students.push_back(student);
        }
        outGroups.insert({group_name, students});
        file.close();
    }
    else {
        cout << "файл не открылся";
    }
};

int main() {
     //vector<string> words = {"raz", "dva", "tri"};  // Запись слов в файл (в строку через пробел)
     //saveToFile("C:\\Users\\oleg\\Desktop\\Pipec.txt", words);

     /*vector<string> words;  // Чтение слов из файла
     loadFromFile("C:\\Users\\oleg\\Desktop\\Pipec.txt", words);
     for (int i=0;i<words.size();i++){
         cout << words[i] << " ";
     }*/

    // Book Mein_Kampf;  // Запись книг в файл
    // Mein_Kampf.Author = "Hitler";
    // Mein_Kampf.Title = "Mein_Kampf";
    // Mein_Kampf.Year = 1925;
    // Book Das_Kapital;
    // Das_Kapital.Author = "Karl_Marx";
    // Das_Kapital.Title = "Das_Kapital";
    // Das_Kapital.Year = 1867;
    // vector<Book> books = {Mein_Kampf, Das_Kapital};
    // saveToFile("/home/oleg/Рабочий стол/Pipec.txt", books);

    // vector<Book> books;  // Чтение книг из файла
    // loadFromFile("/home/oleg/Рабочий стол/Pipec.txt", books);
    // for (int i=0;i<books.size();i++){
    //     cout << books[i].Author << " ";
    //     cout << books[i].Title << " ";
    //     cout << books[i].Year << endl;
    // }

    vector<Student> students;  // Запись группы в файл
    Student Oleg;
    Oleg.Name = "Олег";
    Oleg.Age = 18;
    Oleg.RecordBook.insert({ "Матанализ", Excellent });
    Oleg.RecordBook.insert({ "Ангем", Good });
    Oleg.RecordBook.insert({ "Латынь", Satisfactory });
    Student Bishkek;
    Bishkek.Name = "Бишкек";
    Bishkek.Age = 18;
    Bishkek.RecordBook.insert({ "Матанализ", Unsatisfactory });
    Bishkek.RecordBook.insert({ "Ангем", Unsatisfactory });
    Bishkek.RecordBook.insert({ "Латынь", Unsatisfactory });
    students.push_back(Oleg);
    students.push_back(Bishkek);
    Groups IU8_14;
    IU8_14.insert({ "ИУ8-14", students });
    saveToFile("C:\\Users\\oleg\\Desktop\\Pipec.txt", IU8_14);

    /*Groups IU8_14;  // Чтение группы из файла
    loadFromFile("C:\\Users\\oleg\\Desktop\\Pipec.txt", IU8_14);
    for (auto elem : IU8_14){
            cout << elem.first << endl;
            for (int i=0;i<elem.second.size();i++){
                cout << elem.second[i].Name << " ";
                cout << elem.second[i].Age;
                for (auto elem1 : elem.second[i].RecordBook){
                    cout << " " << elem1.first << " " << elem1.second;
                }
                cout << endl;
            }
        }*/
}