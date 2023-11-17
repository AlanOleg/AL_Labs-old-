#include <iostream>
#include <vector>
using namespace std;

struct Node{
        int data;
        Node* next;
};

class LinkedList{
    public:
        LinkedList();
        LinkedList(int data);
        LinkedList(vector<int> data);
        bool add_element(int data);
        int delete_element(int data);
        bool find_element(int data);
        bool insert(int data, int position);
        void print_list();
        ~LinkedList();
    private:
        Node* first;
        Node* last;
};

LinkedList::~LinkedList(){
    Node* current = first;
    while (current != nullptr){
        Node* next = current->next;
        delete current;
        current = next;
    }
}

LinkedList::LinkedList(){
    first = nullptr;
    last = nullptr;
};

LinkedList::LinkedList(int data){
    Node* nd = new Node{data, nullptr};
    first = nd;
    last = nd;
    last->next = nullptr;
};

LinkedList::LinkedList(vector<int> data){
    for (int i = 0; i <= data.size(); i++){
        add_element(data[i]);
    }
};

bool LinkedList::add_element(int data){
    Node* nd = new Node{data, nullptr};
    if(last == nullptr){
        first = nd;
        last = nd;
        return true;
    }
    last->next = nd;
    last = nd;
    return true;
};

bool LinkedList::find_element(int data){
    if (first == nullptr){
        return 0;
    }
    Node* current = first;
    while(current != nullptr){
        if (current->data == data){
            return 1;
        }
        current = current->next;
    }
    return 0;
};

bool LinkedList::insert(int data, int position){
    if (first == nullptr and position == 0){
        add_element(data);
        return 1;
    }
    else if (position == 0){
        Node* nd = new Node{data, first};
        first = nd;
        return 1;
    }
    else{
        Node* current = first;
        for (int i = 1; i < position; i++){
            current = current->next;
            if (current->next == nullptr){
                cout << "incorrect position" << endl;
                return 0;
            }
        }
        Node* nd = new Node{data, current->next};
        current->next = nd;
        if (nd->next == nullptr){
            last = nd;
        }
        return 1;
    }
};

void LinkedList::print_list(){
    if (first == nullptr){
        cout << "list is empty";
    }
    else if (first == last){
        cout << first->data << endl;
    }
    else{
        Node* current = first;
        while(current->next != nullptr){
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main()
{
    vector<int> massiv = {1, 2, 3};
    LinkedList linkedlist(massiv);
    int cin_data;
    int cin_position;
    cout << "data = "; cin >> cin_data;
    cout << "position = "; cin >> cin_position;
    linkedlist.insert(cin_data, cin_position);
    linkedlist.print_list();
}
