#include <iostream>
#include <string>
using namespace std;

void operations(string& line, const string oper) {
    const string ops = "^*/+-";
    while (line.find(oper[0]) <= line.size() or line.find(oper[1]) <= line.size()) {
        if (oper.find('-') <= oper.size() and line.find_last_of('-') == 0 and line.find('+') > line.size() or oper.find('-') <= oper.size() and line.find_last_of('-') == 1 and line[0] == '(' and line.find('+') > line.size()) {
            break;
        }
        string operand1 = "";
        string operand2 = "";
        for (int i = 0; i < line.size(); i++) {
            if (oper.find(line[i]) <= oper.size() and i != 0) {
                string left = line;
                string right = line;
                int i1 = i - 1;
                for (i1; i1 >= 0; i1--) {
                    if (ops.find(line[i1]) > ops.size()) {
                        operand1 = line[i1] + operand1;
                    }
                    else if (line[i1] == '-' and (i1 == 0 or ops.find(line[i1 - 1]) <= ops.size() or line[i1 - 1] == '(')) {
                        operand1 = line[i1] + operand1;
                    }
                    else {
                        break;
                    }
                }
                left.erase(left.begin() + (i1 + 1), left.end());
                i1 = i + 1;
                for (i1; i1 < line.size(); i1++) {
                    if (ops.find(line[i1]) > ops.size()) {
                        operand2 += line[i1];
                    }
                    else if (line[i1] == '-' and (i1 == i + 1 or line[i1 - 1] == '(')) {
                        operand2 += line[i1];
                    }
                    else {
                        break;
                    }
                }
                right.erase(right.begin(), right.begin() + i1);
                int pow_exception = 1;
                if (operand1[0] == '-') {
                    pow_exception = -1;
                }
                else if (operand1[0] == '(') {
                    operand1.erase(operand1.begin(), operand1.begin() + 1);
                    operand1.erase(operand1.end() - 1, operand1.end());
                }
                if (operand2[0] == '(') {
                    operand2.erase(operand2.begin(), operand2.begin() + 1);
                    operand2.erase(operand2.end() - 1, operand2.end());
                }
                double operand1_d = stod(operand1);
                double operand2_d = stod(operand2);
                switch (line[i]){
                    case '^': {
                        line = left + to_string(pow(operand1_d, operand2_d) * pow_exception) + right;
                        break;
                    }
                    case '*': {
                        line = left + to_string(operand1_d * operand2_d) + right;
                        break;
                    }
                    case '/': {
                        line = left + to_string(operand1_d / operand2_d) + right;
                        break;
                    }
                    case '+': {
                        line = left + to_string(operand1_d + operand2_d) + right;
                        break;
                    }
                    case '-': {
                        line = left + to_string(operand1_d - operand2_d) + right;
                        break;
                    }
                }
                break;
            }
        }
    }
}

double my_amazing_calculator(string& line) {
    string new_line = "";
    int ignore = 0;
    for (int i = 0; i < line.size(); i++) {
        if (line[i] == '(' and ignore == 0) {
            string line_cut = line;
            line_cut.erase(line_cut.begin(), line_cut.begin() + i + 1);
            new_line = new_line + '(' + to_string(my_amazing_calculator(line_cut)) + ')';
            ignore++;
        }
        else if (line[i] == '(' and ignore > 0) {
            ignore++;
        }
        else if (line[i] == ')' and ignore == 0) {
            break;
        }
        else if (line[i] == ')' and ignore > 0) {
            ignore--;
        }
        else if (ignore == 0) {
            new_line += line[i];
        }
    }
    line = new_line;
    operations(line, "^^"); // костыль деревянный ГОСТ Р 58281-2022
    operations(line, "*/");
    operations(line, "+-");
    if (line[0] == '(') {
        line.erase(line.begin(), line.begin() + 1);
        line.erase(line.end() - 1, line.end());
    }
    double line_d = stod(line);
    return line_d;
}

int main() {
    string main_line = "2*(-10+(-25))^1/2*0.15"; // 2*(-10+25)^1/2*0.15
    //cin >> main_line;
    cout << my_amazing_calculator(main_line);
}
