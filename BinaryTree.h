#ifndef BINARY_TREE_BINARYTREE_H
#define BINARY_TREE_BINARYTREE_H

#include "../Headers/BinaryTree_Declaration.h"

template <typename T>

BinaryTree_Declaration<T>::BinaryTree_Declaration(T data){
    root = new Node<T>;
    root->data = data;
    root->left = nullptr;
    root->right = nullptr;
    ++heightOfTree;
    ++nodeCount;
}

template <typename T>

BinaryTree_Declaration<T>::~BinaryTree_Declaration(){
    delete root;
}

template <typename T>

BinaryTree_Declaration<T>::BinaryTree_Declaration(std::initializer_list<T> data){
    T* arr = new T[data.size()];
    std::copy(data.begin(), data.end(), arr);
    for (int i = 0; i < data.size(); ++i) add(arr[i]);
    delete[] arr;
}

template <typename T>

void BinaryTree_Declaration<T>::add(T data){
    Node<T>** curr = &root;
    while (*curr) {
        Node<T>& node = **curr;
        if (data < node.data) {
            curr = &node.left;
            continue;
        }
        if (data > node.data) {
            curr = &node.right;
            continue;
        }
        else return;
    }
    *curr = new Node<T>;
    (*curr)->data = data;
    (*curr)->left = nullptr;
    (*curr)->right = nullptr;
    ++heightOfTree;
    ++nodeCount;
}

template <typename T>

Node<T>* BinaryTree_Declaration<T>::erase(Node<T>* node, T data) {
    if (!find(data) || root == nullptr) return root;
    if (data < node->data){
        node->left = erase(node->left, data);
        --nodeCount;
    }
    if (data > node->data){
        node->right = erase(node->right, data);
        --nodeCount;
    }
    if (node->left != nullptr && node->right != nullptr) {
        root->data = min(node->right);
        node->right = erase(node->right, data);
        --nodeCount;
    }
    else {
        if (node->left != nullptr) node = node->left;
        else if (node->right != nullptr) node = node->right;
        else node = nullptr;
    }
    return node;
}

template <typename T>

bool BinaryTree_Declaration<T>::find(T data) const {
    unsigned level = 1;
    Node<T> *curr = root;
    while (level <= heightOfTree){
        if (data == curr->data)
            return true;
        else {
            data < curr->data ? curr = curr->left : curr = curr->right;
            ++level;
            continue;
        }
    }
    return false;
}

template <typename T>

const unsigned BinaryTree_Declaration<T>::count() const{
    return nodeCount;
}

template <typename T>

T BinaryTree_Declaration<T>::max(Node<T>* node) const{
    Node<T>* curr = node;
    if (!curr->right) return curr->data;
    return max(curr->right);
}

template <typename T>

T BinaryTree_Declaration<T>::min(Node<T>* node) const{
    Node<T>* curr = node;
    if (!curr->left) return curr->data;
    return min(curr->left);
}

template <typename T>

std::list<T> BinaryTree_Declaration<T>::toList(Node<T>* node, std::list<T>* list) const{
    Node<T>* curr = node;
    if (curr != nullptr) {
        toList(curr->left, list);
        list->push_back(curr->data);
        toList(curr->right, list);
    }
    return *list;
}

template <typename T>

Iterator<T> BinaryTree_Declaration<T>::begin(){
    return Iterator<T>(this);
}

template <typename T>

Iterator<T> BinaryTree_Declaration<T>::end(){
    Node<T>* current = root;
    while (current->right) current = current->right;
    return Iterator<T>(this, current->right);
}

#endif //BINARY_TREE_BINARYTREE_H
