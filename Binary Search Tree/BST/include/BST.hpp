#ifndef __BST__
#define __BST__
#include <iostream>
template <typename T>
class BST
{
private:
    class Node
    {
    public:
        T data;
        Node *left;
        Node *right;

    public:
        Node(const T &) : data{data}, left{nullptr}, right{nullptr} {};

    } * root;

public:
    void display() const;
    void insert(const T &);

private:
    void recursive(const T &, Node *);
};
template<typename T>
void BST<T>::display()const
{
    
}

template <typename T>
void BST<T>::insert(const T &data)
{
    this->recursive(data, (root));
};

template <typename T>
void BST<T>::recursive(const T &data, Node *root)
{
    if (root == nullptr)
    {
        root = new Node(data);
    }
    else if (data < (root)->data)
    {
        if ((root)->left != nullptr)
        {
            this->recursive(data, (root)->left);
        }
        else
        {
            (root)->left = new Node(data);
        };
    }
    else if (data > (root)->data)
    {
        if ((root)->right != nullptr)
        {
            this->recursive(data, (root)->right);
        }
        else
        {
            (root)->right = new Node(data);
        };
    };
};

#endif