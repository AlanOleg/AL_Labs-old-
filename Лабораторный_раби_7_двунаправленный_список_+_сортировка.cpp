#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* previous;
};

class LinkedList {
public:
    LinkedList();
    LinkedList(int data);
    LinkedList(vector<int> data);
    bool add_element(int data);
    bool delete_element(int position);
    bool find_element(int data);
    bool insert_element(int data, int position);
    void sort();
    void print_list();
    void print_list_reverse();
    ~LinkedList();
private:
    Node* first;
    Node* last;
};

LinkedList::~LinkedList() {
    Node* current = first;
    while (current != nullptr) {
        first = first->next;
        delete current;
        current = first;
    }
}

LinkedList::LinkedList() {
    first = nullptr;
    last = nullptr;
};

LinkedList::LinkedList(int data) {
    Node* nd = new Node{data, nullptr, nullptr};
    first = nd;
    last = nd;
    first->previous = nullptr;
    last->next = nullptr;
};

LinkedList::LinkedList(vector<int> data) {
    first=nullptr;
    last=nullptr;
    for (int i = 0; i < data.size(); i++) {
        add_element(data[i]);
    }
};

bool LinkedList::add_element(int data) {
    Node* nd = new Node{data, nullptr, nullptr};
    if (first == nullptr) {
        first = nd;
        last = nd;
        return true;
    }
    last->next = nd;
    nd->previous = last;
    last = nd;
    return true;
};

bool LinkedList::find_element(int data) {
    if (first == nullptr) {
        return 0;
    }
    Node* current = first;
    while (current != nullptr) {
        if (current->data == data) {
            return 1;
        }
        current = current->next;
    }
    return 0;
};

bool LinkedList::insert_element(int data, int position) {
    if (position < 0 or first == nullptr and position > 0){
        cout << "incorrect position" << endl;
        return 0;
    }
    else if (first == nullptr and position == 0) {
        add_element(data);
        return 1;
    }
    else if (position == 0) {
        Node* nd = new Node{data, first, nullptr};
        first = nd;
        return 1;
    }
    else {
        Node* current = first;
        for (int i = 1; i < position; i++) {
            current = current->next;
            if (current == nullptr or current->next == nullptr) {
                cout << "incorrect position" << endl;
                return 0;
            }
        }
        Node* nd = new Node{data, current->next, current};
        current->next = nd;
        if (nd->next == nullptr) {
            last = nd;
        }
        return 1;
    }
};

bool LinkedList::delete_element(int position) {
    if (first == nullptr or first == last and position != 0 or position < 0) {
        return 0;
    }
    else if (first == last) {
        delete first;
        first = nullptr;
        last = nullptr;
        return 1;
    }
    else if (position == 0) {
        Node* current = first->next;
        delete first;
        first = current;
        return 1;
    }
    else {
        Node* current = first;
        for (int i = 1; i < position; i++) {
            current = current->next;
            if (current == nullptr or current->next == nullptr) {
                return 0;
            }
        }
        Node* placeholder = current->next;
        current->next = current->next->next;
        current->next->next->previous = current;
        delete placeholder;
        if (current->next == nullptr) {
            last = current;
        }
        return 1;
    }
};

void LinkedList::print_list() {
    if (first == nullptr) {
        cout << "list is empty" << endl;
    }
    else if (first == last) {
        cout << first->data << endl;
    }
    else {
        Node* current = first;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

void LinkedList::print_list_reverse() {
    if (last == nullptr) {
        cout << "list is empty" << endl;
    }
    else if (first == last) {
        cout << last->data << endl;
    }
    else {
        Node* current = last;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->previous;
        }
        cout << endl;
    }
};

void LinkedList::sort() {
    if (first == nullptr or first == last){
    }
    else{
        Node* start = first;
        while (start->next != nullptr){
            Node* min = start;
            Node* current = start->next;
            while (current != nullptr){
                if (current->data < min->data){
                    min = current;
                }
                current = current->next;
            }
            if (min == start){
            }
            else{
                min->previous->next = min->next;
                if (min != last){
                    min->next->previous = min->previous;
                }
                else{
                    last = min->previous;
                }
                min->previous = start->previous;
                min->next = start;
                if (start == first){
                    start->previous = min;
                    first = min;
                }
                else{
                    start->previous->next = min;
                    start->previous = min;
                }
            }
            start = min->next;
        }
    }
};

int main()
{
    int amount;
    vector<int> massiv = {};
    cout << "amount = "; cin >> amount;
    for (int i = 0; i < amount; i++) {
        int number;
        cout << "number " << i << " = "; cin >> number;
        massiv.push_back(number);
    }
    LinkedList linkedlist(massiv);
    linkedlist.print_list();
    linkedlist.print_list_reverse();
    linkedlist.sort();
    linkedlist.print_list();
    linkedlist.print_list_reverse();
    //int cin_data;
    //int cin_position;
    //cout << "data = "; cin >> cin_data;
    //cout << "position = "; cin >> cin_position;
    //linkedlist.insert_element(cin_data, cin_position);
    //linkedlist.delete_element(cin_position);
    //linkedlist.print_list();
    //cout << linkedlist.first->data << " " << linkedlist.last->data;
}
