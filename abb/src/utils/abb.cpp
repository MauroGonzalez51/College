#include "../../include/abb.h"

ABB *ABB::get_root() {
    return this;
}

ABB *ABB::create_node(int &value) {
    ABB *new_node = (ABB *) malloc(sizeof(ABB));
    
    if (!new_node) return;

    new_node -> value = &value;
    new_node -> left = new_node -> right = NULL;

    return new_node;
}

void ABB::insert(ABB *node, int &value) {
    if (node == NULL) {
        node = this -> create_node(value);
        return;
    }

    if (value < *node -> value) 
        return this -> insert(node -> left, value);

    if (value > *node -> value)
        return this -> insert(node -> right, value);
}

void ABB::pre_order(ABB *node) {
    if (node == NULL) {
        std::cout << std::endl;
        return;
    }
    
    std::cout << node -> value << " ";
    pre_order(node -> left);
    pre_order(node -> right);
}

void ABB::in_order(ABB *node) {
    if (node == NULL) {
        std::cout << std::endl;
        return;
    }

    in_order(node -> left);
    std::cout << node -> value << " ";
    in_order(node -> right);
}

void ABB::post_order(ABB *node) {
    if (node == NULL) {
        std::cout << std::endl;
        return;
    }

    post_order(node -> left);
    post_order(node -> right);
    std::cout << node -> value << " ";
}