#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct student {
    string name;
    double age;
    double math;
    double rus;
    double eng;
};

class Group {
public:
    string group_name;
    vector<student> students;
    double get_average_age() {
        double average_age = 0;
        for (int i = 0; i < students.size(); i++) {
            average_age += students[i].age;
        }
        average_age /= students.size();
        cout << "Average age of group " << group_name << " = " << average_age << endl;
        return 0;
    };
    double get_average_mark() {
        for (int i = 0; i < students.size(); i++) {
            double average_mark = (students[i].math + students[i].rus + students[i].eng) / 3;
            cout << "Average mark of student " << students[i].name << " = " << average_mark << endl;
        }
        return 0;
    }
};

int main()
{
    Group My_students;
    string group_name;
    cout << "Group name = "; cin >> group_name;
    My_students.group_name = group_name;

    int student_amount;
    cout << "Student amount = "; cin >> student_amount;
    string student_name;
    string inside_name;
    for (int i = 0; i < student_amount; i++) {
        cout << "Name = "; cin >> student_name;
        inside_name = student_name;
        student student_name;
        student_name.name = inside_name;
        cout << "Age = "; cin >> student_name.age;
        cout << "Math = "; cin >> student_name.math;
        cout << "Rus = "; cin >> student_name.rus;
        cout << "Eng = "; cin >> student_name.eng;
        My_students.students.push_back(student_name);
    }
    My_students.get_average_age();
    My_students.get_average_mark();
}