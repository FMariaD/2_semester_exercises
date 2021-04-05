struct subforwardlist {
    int data;
    subforwardlist* next = nullptr;
};

bool init(subforwardlist **sfl) {
    *sfl = nullptr;
    return true;
}

bool push_back(subforwardlist **sfl, int d) {
    subforwardlist *p = *sfl;
    subforwardlist *new_p = new subforwardlist;
    new_p->data = d;
    if (*sfl == nullptr) {
        *sfl = new_p;
        return true;
    }
    while (p->next != nullptr) {
        p = p->next;
    }
    p->next = new_p;
    return true;
}

int pop_back(subforwardlist **sfl) {
    subforwardlist *p = *sfl, *tmp;
    if (p == nullptr) {return 0;}
    if (p->next == nullptr)
    {
        int value = p->data;
        delete p;
        *sfl = nullptr;
        return value;
    }
    while (p->next != nullptr) {
        tmp = p;
        p = p->next;
    }
    int value = p->data;
    delete p;
    tmp->next = nullptr;
    return value;
}

bool push_forward(subforwardlist **sfl, int d) {
    subforwardlist *new_p = new subforwardlist;
    new_p->data = d;
    if (*sfl == nullptr) {*sfl = new_p; return true;}
    new_p->next = *sfl;
    *sfl = new_p;
    return true;
}

int pop_forward(subforwardlist **sfl) {
    subforwardlist *p = *sfl;
    if (p == nullptr) {return 0;}
    *sfl = p->next;
    int value = p->data;
    delete p;
    return value;
}

bool push_where(subforwardlist **sfl, unsigned int where, int d) {
    if (where == 0) {return push_forward(sfl, d);}
    subforwardlist *p = *sfl, *p_next = p->next;
    for (int i = 1; i < where; i++) {
        p = p_next;
        p_next = p_next->next;
    }
    subforwardlist *new_p = new subforwardlist;
    new_p->data = d;
    p->next = new_p;
    new_p->next = p_next;
    return true;
} //добавление элемента с порядковым номером where

bool erase_where (subforwardlist **sfl, unsigned int where) {
    if (where == 0) {
        int value = pop_forward(sfl);
        return true;
    }
    subforwardlist *p = *sfl, *p_next = p->next;
    for (int i = 1; i < where; i++)
    {
        p = p_next;
        p_next = p_next->next;
    }
    p->next = p_next->next;
    delete p_next;
    return true;
}

unsigned int size(subforwardlist **sfl) {
    subforwardlist *p = *sfl;
    unsigned int s;
    if (p == nullptr) {return 0;}
    for (s = 1; p->next != nullptr; s++) {
        p = p->next;
    }
    return s;
}

void clear(subforwardlist **sfl) {
    subforwardlist *p = *sfl, *q;
    if (p == nullptr) {return;}
    while (p->next != nullptr) {
        q = p;
        p = p->next;
        delete q;
    }
    delete p;
    *sfl = nullptr;
}

bool init_from_file(subforwardlist **sfl, char* filename);
