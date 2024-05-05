#ifndef BINARY_TREE_BINARYTREE_DECLARATION_H
#define BINARY_TREE_BINARYTREE_DECLARATION_H

#include <iostream>
#include <algorithm>
#include <list>
#include <queue>

template <typename T>

class Iterator;

template <typename T>

struct Node{
    Node* left;
    Node* right;
    T data;
};

template <typename T>

class BinaryTree_Declaration {
private:
    unsigned heightOfTree = 0;
    unsigned nodeCount = 0;
public:
    friend Iterator<T>;
    Node<T>* root;
    BinaryTree_Declaration() = default;
    explicit BinaryTree_Declaration(T data);
    BinaryTree_Declaration(std::initializer_list<T> data);
    ~BinaryTree_Declaration();
    void add(T data);
    Node<T>* erase(Node<T>* node, T data);
    bool find(T data) const;
    const unsigned count() const;
    T max(Node<T>* node) const;
    T min(Node<T>* node) const;
    std::list<T> toList(Node<T>* node, std::list<T>* list) const;
    Iterator<T> begin();
    Iterator<T> end();
};

template <typename T>

class Iterator{
private:
    friend BinaryTree_Declaration<T>;
    BinaryTree_Declaration<T>* rootIter;
    const Node<T>* current;
    unsigned countNodes = 0;
    std::queue<Node<T>*> queue;
    void toQueue(Node<T>* node);
    explicit Iterator(const Node<T>* current);
public:
    explicit Iterator(BinaryTree_Declaration<T>* obj);
    explicit Iterator(BinaryTree_Declaration<T>* obj, Node<T>* node);
    Iterator(const Iterator& iterator) = default;
    Iterator<T>& next();
    const T value() const;
    bool end();
    Iterator<T>& operator++();
    const T& operator*() const;
    bool operator==(const Iterator<T>& b) const;
    bool operator!=(const Iterator<T>& b) const;
};

#endif //BINARY_TREE_BINARYTREE_DECLARATION_H
