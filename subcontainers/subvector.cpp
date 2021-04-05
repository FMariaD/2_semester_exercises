#include <iostream>

using namespace std;

struct subvector {
    int *mas;
    unsigned int top;
    unsigned int capacity;
};

bool init (subvector *qv) {
    qv->top = 0;
    qv->capacity = 0;
    qv->mas = nullptr;
    return true;
}

bool resize(subvector *qv, unsigned int new_capacity) {
    if (new_capacity == 0) {
        if (qv->mas != NULL) {delete[]qv->mas;}
        init(qv);
        return false;
    }
    int* p_new = new int[new_capacity];
    if (qv->mas != NULL) {
        for (int i = 0; i < qv->top; i++) {
            p_new[i] = *(qv->mas + i);
        }
        delete[]qv->mas;
    }
    qv->mas = p_new;
    qv->capacity = new_capacity;
    return true;
}

bool push_back (subvector *qv, int d) {
    qv->top += 1;
    if (qv->capacity == 0)
    {
        resize(qv, 1);
    }
    if (qv->top >=  qv->capacity)
    {
        resize(qv, qv->capacity*2);
    }
    *(qv->mas + qv->top - 1) = d;
    return true;
}

int pop_back(subvector *qv) {
    int tmp;
    if ((qv->top != 0) && (qv->mas != nullptr)) {
        tmp = *(qv->mas + qv->top - 1);
        qv->top -= 1;
        int* p_new = new int[qv->capacity];
        for (int i = 0; i < qv->top; i++) {
            p_new[i] = *(qv->mas + i);
        }
        delete[]qv->mas;

        qv->mas = p_new;
    }
    else {tmp = 0;}
    return tmp;
}

void shrink_to_fit(subvector *qv) {
    resize(qv, qv->top);
}

void clear(subvector *qv) {
    if (qv->top != 0) {
        qv->top = 0;
        int* p_new = new int[qv->capacity];
        if (qv->mas != NULL) {
            delete[]qv->mas;
        }
        qv->mas = p_new;
    }
}

void destructor(subvector *qv) {
    if (qv->mas != NULL) {delete[]qv->mas;}
    init(qv);
}
