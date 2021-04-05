#include <iostream>

using namespace std;

struct Node {
    int64_t value;
    Node* next;
};

void push_back(Node* current_node, int64_t value) {
    Node* p = current_node;
    if (p == nullptr) {
        Node* p_new = new Node;
        current_node = p_new;
        p_new->next = nullptr;
        p_new->value = value;
    }
    else {
        while (p->next != nullptr) {
            p = p->next;
        }
        Node* p_new = new Node;
        p->next = p_new;
        p_new->next = nullptr;
        p_new->value = value;
    }
}

void PrintAll(Node* p) {
    if (p != nullptr)
    {
        while (p->next != nullptr)
        {
            cout << p->value << " ";
            p = p->next;
        }
        cout << p->value << endl;
    }
}

Node* mergeLists(Node* first_node, Node* second_node) {
    Node *p1 = first_node, *p2 = second_node;
    Node *new_p = new Node;
    int64_t v1, v2;
    if (p1 == nullptr)
    {
        new_p = p2;
        return new_p;

    }
    if (p2 == nullptr)
    {
        new_p = p1;
        return new_p;
    }
    if (p1->value < p2->value)
    {
        new_p->value = p1->value;
        new_p->next = mergeLists(first_node->next, second_node);
        return new_p;
    }
    if (p1->value >= p2->value)
    {
        new_p->value = p2->value;
        new_p->next = mergeLists(first_node, second_node->next);
        return new_p;
    }
}
