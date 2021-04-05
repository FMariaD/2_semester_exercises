#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

struct List {
    Node* start;
    int size;
};

// создает N замыкающихся в круг нодов со значениями от 1 до N, возвращает указатель на нод номер 1
Node* make_nodes(int N) {
    Node* p = new Node;
    p->data = 1;
    Node* start = p, *q = nullptr;
    for (int i = 2; i <= N; i++)
    {
        q = new Node;
        p->next = q;
        q->data = i;
        p = q;
    }
    if (q != nullptr) {q->next = start;}
    else {start->next = start;}
    return start;
}

void print_all(Node* p, int N) {
    if (p != nullptr)
    {
        for (int i = 1; i <= N; i++)
        {
            cout << p->data << " ";
            p = p->next;
        }
    }
}

// рекуррентная функция, за один шаг убирает одного человека
Node* remove_player(List *lst, int K) {
    if (lst->size == 1) {return lst->start;}
    Node *p = lst->start, *q;
    int place = K;
    if (place == 1) {place = lst->size + 1;}
    for (int i = 1; i < place; i++)
    {
        q = p;
        p = p->next;
    }
    q->next = p->next;
    delete p;
    lst->start = q->next;
    lst->size -= 1;
    remove_player(lst, K);
}

int main()

{
    int N, K;
    cin >> N >> K;
    List *lst = new List;
    lst->start = make_nodes(N);
    lst->size = N;
    cout << remove_player(lst, K)->data << endl;
    return 0;
}
