#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int task_number;
    cout << "task_number = "; cin >> task_number;
    switch (task_number)
    {
    case 1:
    {
        vector<double> vec_main;
        srand(time(0));
        for (int i = 0; i < 10; i++) {
            vec_main.push_back(rand() % 10);
            cout << vec_main[i] << ' ';
        }cout << endl;

        int a;
        cout << "a = "; cin >> a;
        cout << "1) ";
        vector<double> vec_copy = vec_main;
        for (int i = 0; i < vec_copy.size(); i++) {
            vec_copy[i] *= 2;
            cout << vec_copy[i] << ' ';
        }cout << endl;
        cout << "2) ";
        vec_copy = vec_main;
        for (int i = 0; i < vec_copy.size(); i++) {
            vec_copy[i] -= a;
            cout << vec_copy[i] << ' ';
        }cout << endl;
        cout << "3) ";
        vec_copy = vec_main;
        double x = vec_copy[0];
        for (int i = 0; i < vec_copy.size(); i++) {
            vec_copy[i] /= x;
            cout << vec_copy[i] << ' ';
        }
        break;
    }
    case 2:
    {
        vector<double> vec_main;
        srand(time(0));
        for (int i = 0; i < 10; i++) {
            vec_main.push_back(rand() % 10);
            cout << vec_main[i] << ' ';
        }cout << endl;

        int k1;
        cout << "k1 = "; cin >> k1;
        int k2;
        cout << "k2 = "; cin >> k2;
        int s1;
        cout << "s1 = "; cin >> s1;
        int s2;
        cout << "s2 = "; cin >> s2;
        double sum = 0;
        cout << "1) ";
        for (int i = 0; i < vec_main.size(); i++) {
            sum += vec_main[i];
        }cout << sum << endl;
        cout << "2) ";
        sum = 0;
        for (int i = 0; i < vec_main.size(); i++) {
            sum += pow(vec_main[i], 2);
        }cout << sum << endl;
        cout << "3) ";
        sum = 0;
        for (int i = 0; i < 6; i++) {
            sum += vec_main[i];
        }cout << sum << endl;
        cout << "4) ";
        sum = 0;
        for (int i = k1; i <= k2; i++) {
            sum += vec_main[i];
        }cout << sum << endl;
        cout << "5) ";
        sum = 0;
        for (int i = 0; i < vec_main.size(); i++) {
            sum += vec_main[i];
        }cout << sum / vec_main.size() << endl;
        cout << "6) ";
        sum = 0;
        for (int i = k1; i <= k2; i++) {
            sum += vec_main[i];
        }cout << sum / (k2 - k1 + 1) << endl;
        break;
    }
    case 3:
    {
        vector<int> vec_main;
        srand(time(0));
        for (int i = 0; i < 20; i++) {
            vec_main.push_back(rand() % 10);
            cout << vec_main[i] << ' ';
        }cout << endl;

        int v0 = vec_main[0];
        int v1 = vec_main[1];
        int v2 = vec_main[2];
        vec_main[0] = vec_main[17];
        vec_main[1] = vec_main[18];
        vec_main[2] = vec_main[19];
        vec_main[17] = v0;
        vec_main[18] = v1;
        vec_main[19] = v2;
        for (int i = 0; i < vec_main.size(); i++) {
            cout << vec_main[i] << ' ';
        }
        break;
    }
    case 4:
    {
        vector<int> vec_main;
        srand(time(0));
        for (int i = 0; i < 10; i++) {
            vec_main.push_back(rand() % 20 - 10);
            cout << vec_main[i] << ' ';
        }cout << endl;

        cout << "1) ";
        vector<int> vec_copy = vec_main;
        for (int i = 0; i < vec_copy.size(); i++) {
            if (vec_copy[i] < 0){
                vec_copy.erase(vec_copy.begin() + i);
                break;
            }
        }for (int i = 0; i < vec_copy.size(); i++) {
            cout << vec_copy[i] << ' ';
        }cout << endl;
        cout << "2) ";
        vec_copy = vec_main;
        for (int i = vec_copy.size() - 1; i > 0; i -= 1) {
            if (vec_copy[i] % 2 == 0) {
                vec_copy.erase(vec_copy.begin() + i);
                break;
            }
        }for (int i = 0; i < vec_copy.size(); i++) {
            cout << vec_copy[i] << ' ';
        }
        break;
    }
    case 5:
    {
        string city;
        cout << "city = "; cin >> city;
        if (city.length() % 2 == 0) {
            cout << "chetno";
        }
        else {
            cout << "nechetno";
        }
        break;
    }
    case 6:
    {
        string surname1;
        string surname2;
        cout << "surname1 = "; cin >> surname1;
        cout << "surname2 = "; cin >> surname2;
        if (surname1.length()  > surname2.length()) {
            cout << "true";
        }
        else {
            cout << "ne true";
        }
        break;
    }
    case 7:
    {
        string city1;
        string city2;
        string city3;
        string the_longest;
        string the_shortest;
        cout << "city1 = "; cin >> city1;
        cout << "city2 = "; cin >> city2;
        cout << "city3 = "; cin >> city3;
        if (city2.length() > city3.length()) {
            if (city1.length() > city2.length()) {
                the_longest = city1;
                the_shortest = city3;
            }
            else if(city1.length() > city3.length()){
                the_longest = city2;
                the_shortest = city3;
            }
            else {
                the_longest = city2;
                the_shortest = city1;
            }
        }
        else if (city1.length() > city3.length()) {
            the_longest = city1;
            the_shortest = city2;
        }
        else if (city1.length() > city2.length()) {
            the_longest = city3;
            the_shortest = city2;
        }
        else {
            the_longest = city3;
            the_shortest = city1;
        }
        cout << "longest = " << the_longest << endl;
        cout << "shortest = " << the_shortest;
        break;
    }
    case 8:
    {
        string word;
        cout << "word = "; cin >> word;
        word = string(word.length(), '*') + word + string(word.length(), '*');
        cout << "new_word = " << word;
        break;
    }
    case 9:
    {
        string sentence;
        cout << "sentence = "; cin >> sentence;
        double counter = 0;
        for (int i = 0; i < sentence.length(); i++) {
            if (sentence[i] == 'a') {
                counter++;
            }
        }
        cout << "a% = " << counter / sentence.length() * 100;
        break;
    }
    case 10:
    {
        string sentence("Can you can a can as a canner can can a can?");
        sentence += ' ';
        string result_sentence;
        string new_word;
        cout << "new_word = "; cin >> new_word;
        string word;
        for (int i = 0; i < sentence.length(); i++) {
            if (sentence[i] != ' ' and sentence[i] != '?') {
                word += sentence[i];
            }
            else if(word != "can" and word != "can?") {
                result_sentence = result_sentence + word + sentence[i];
                word = "";
            }
            else {
                result_sentence = result_sentence + new_word + sentence[i];
                word = "";
            }
        }
        cout << result_sentence;
        break;
    }
    }
}
