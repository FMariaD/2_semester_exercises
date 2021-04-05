#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

struct List {
    Node* root;
};

// добавл€ет элемент в конец
void push_back (List* lst, int val) {
    Node* p = lst->root;
    if (p == nullptr) {
        Node* p_new = new Node;
        lst->root = p_new;
        p_new->next = nullptr;
        p_new->data = val;
    }
    else {
        while (p->next != nullptr) {
            p = p->next;
        }
        Node* p_new = new Node;
        p->next = p_new;
        p_new->next = nullptr;
        p_new->data = val;
    }
}

// удал€ет первый элемент из листа и возвращает его значение
int PopFirst (List* lst) {
    Node* p = lst->root;
    if (p == nullptr) {return 0;}
    int value;
    value = p->data;
    lst->root = p->next;
    delete p;
    return value;
}

// выводит все элементы через пробел
void PrintAll(List* lst) {
    Node* p = lst->root;
    if (p != nullptr)
    {
        while (p->next != nullptr)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << p->data << endl;
    }
}

// удалить все nod'ы и занулить рут
void Clear(List* lst) {
    Node* p;
    for (p = lst->root; p != nullptr; p = p->next) {
        delete p;
    }
    delete lst;
    lst->root = nullptr;
    cout << "Clearing is done" << endl;
}


int main()

{
    List* lst;
    Node* nd;
    int d;
    cin >> d;
    lst = new List;
    nd = new Node;
    nd->data = d;
    nd->next = nullptr;
    lst->root = nd;
    PrintAll(lst);
    push_back(lst, d-2);
    push_back(lst, d*3);
    PrintAll(lst);
    Clear(lst);
    push_back(lst, d*3);
    PrintAll(lst);
    return 0;
}
