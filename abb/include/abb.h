#ifndef ABB_H
#define ABB_H
#include <stdlib.h>
#include <iostream>

class ABB {
    private:
        int *value;
        ABB *left, *right;

    public:
        ABB() {}
        ~ABB() {}
        ABB *get_root();
        ABB *create_node(int &);
        void insert(ABB *, int &);
        void pre_order(ABB *);
        void in_order(ABB *);
        void post_order(ABB *);
};

#endif