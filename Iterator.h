#ifndef BINARY_TREE_ITERATOR_H
#define BINARY_TREE_ITERATOR_H

#include "../Headers/BinaryTree_Declaration.h"

template <typename T>

Iterator<T>::Iterator(const Node<T> *current): current(current) {}

template <typename T>

Iterator<T>::Iterator(BinaryTree_Declaration<T>* obj): rootIter(obj) {
    toQueue(obj->root);
    current = queue.front();
    queue.pop();
}

template <typename T>

Iterator<T>::Iterator(BinaryTree_Declaration<T> *obj, Node<T> *node): rootIter(obj), current(node) {}

template <typename T>

Iterator<T>& Iterator<T>::next(){
    current = queue.front();
    queue.pop();
    return *this;
}

template <typename T>

void Iterator<T>::toQueue(Node<T> *node) {
    Node<T>* curr = node;
    if (curr != nullptr) {
        toQueue(curr->left);
        queue.push(curr);
        toQueue(curr->right);
    }
}

template <typename T>

const T Iterator<T>::value() const{
    return current->data;
}

template <typename T>

bool Iterator<T>::end() {
    bool check = false;
    if (countNodes == rootIter->count()) check = true;
    return check;
}

template <typename T>

Iterator<T>& Iterator<T>::operator++() {
    current = queue.front();
    queue.pop();
    return *this;
}

template <typename T>

const T& Iterator<T>::operator*() const{
    return current->data;
}

template <typename T>

bool Iterator<T>::operator==(const Iterator<T>& b) const{
    bool check = false;
    if (current == b.current) check = true;
    return check;
}

template <typename T>

bool Iterator<T>::operator!=(const Iterator<T> &b) const{
    bool check = false;
    if (current != b.current) check = true;
    return check;
}

#endif //BINARY_TREE_ITERATOR_H
