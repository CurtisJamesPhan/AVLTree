
#ifndef UNIT5AVLTREE_AVLTREE_H
#define UNIT5AVLTREE_AVLTREE_H


#include <iostream>
using namespace std;

class AVLTree{
private:
    struct Node
    {
        int value;                  // stores an integer
        Node* left;                 // stores the memory address of the LEFT CHILD
        Node* right;                // stores the memory address of the RIGHT CHILD
    };

    Node* root;                     // stores the memory address of the ROOT NODE

    void clear(Node*&);
    int height(Node*);
    void rotateRight(Node*&);
    void rotateLeft(Node*&);
    void rotateRightLeft(Node*&);
    void rotateLeftRight(Node*&);
    int difference(Node*);
    void balance(Node*&);
    void append(Node*&, int);   // Done
    void remove(Node*&, int);   //
    bool find(Node*, int);      //
    void print(Node*);          // Done


public:


    AVLTree();                      // Initializes root to null
    ~AVLTree();                     // Frees up memory used by the object
    void clear();
    void append(int);
    void remove(int);
    bool find(int);
    void print();
    bool isEmpty();
    bool isFull();
};


AVLTree::AVLTree()
{
    root = nullptr;
}

AVLTree::~AVLTree()
{
    clear();
}

// Make it inorder traversal
void AVLTree::print(Node* r)
{
    if (r != nullptr)
    {
        print(r->left);
        cout << r->value << "\t";
        print(r->right);
    }

}

void AVLTree::print()
{
    print(root);
}

void AVLTree::remove(Node *& r, int v)
{

    if (r == nullptr)
    {
        return;
    }
    else if (v < r->value)
    {
        remove(r->left, v);
    }
    else if (r->value < v)
    {
        remove(r->right, v);
    }
    else
    {
            // No children
        if (r->left == nullptr && r->right == nullptr)
        {
            delete r;
            r = nullptr;
        }
            // Only a LEFT child
        else if (r->left != nullptr && r->right == nullptr)
        {
            Node* temp = r;
            r = r->left;
            delete temp;
        }
            // Only a RIGHT child
        else if (r->left == nullptr && r->right != nullptr)
        {
            Node* temp = r;
            r = r->right;
            delete temp;
        }
            // Two children
        else
        {
            Node* temp = r->right;
            while (temp->left != nullptr)
            {
                temp = temp->left;
            }
            temp->left = r->left;
            temp = r;
            r = r->right;
            delete temp;
        }
    }
    if(r != nullptr)
    {
        balance(r);
    }




}

void AVLTree::remove(int value)
{
    remove(root, value);
}

void AVLTree::append(Node*& r, int v ) {

    if (r == nullptr)
    {
        if(!isFull())
        {
            Node *fresh = new Node;
            fresh->value = v;
            fresh->left = nullptr;
            fresh->right = nullptr;
            r = fresh;
        }
    }
    else if (v < r->value)
    {
        append(r->left, v);
    } else
    {
        append(r->right, v);
    }
    balance(r);
}

void AVLTree::append(int value)
{
    append(root, value);
}

bool AVLTree::find(Node* r, int v)
{
    while (r != nullptr)
    {
        if (r->value == v)
        {
            return true;
        }
        else if ( v < r->value)
        {
            r = r->left;
        }
        else
        {
            r = r->right;
        }

    }
    return false;
}

bool AVLTree::find(int v)
{
    return find(root, v);
}

int AVLTree::height(Node* r)
{
    int LH;
    int RH;

    if (r == nullptr)
    {
        return 0;
    }
    else
    {
        LH = height(r->left);
        RH = height(r->right);

        if (RH > LH)
        {
            return (1 + RH);
        }
        else
        {
            return (1 + LH);
        }
    }
}

bool AVLTree::isEmpty()
{
    if (root == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool AVLTree::isFull()
{
    Node* n = new Node;
    if (n == nullptr)
        return true;

    delete n;
    return false;
}

int AVLTree::difference(Node * r)
{
    // bf = balance factor
    int bf = height(r->right) - height(r->left);
    return bf;
}

void AVLTree::balance(Node *& r)
{
    if (difference(r) == -2)
    {
        if (difference(r->left) == -1)
        {
            rotateRight(r);
        }
        else
        {
            rotateLeftRight(r);
        }
    }
    else if (difference(r) == 2)
    {
        if (difference(r->right) == 1)
        {
            rotateLeft(r);
        }
        else
        {
            rotateRightLeft(r);
        }
    }
}

void AVLTree::rotateLeft(Node *& r)
{
    Node* temp = r;
    r = r->right;
    temp->right = r->left;
    r->left = temp;
}

void AVLTree::rotateRight(Node *& r)
{
    Node* temp = r;
    r = r->left;
    temp->left = r->right;
    r->right = temp;
}

void AVLTree::rotateLeftRight(Node *& r)
{
    rotateLeft(r->left);
    rotateRight(r);
}

void AVLTree::rotateRightLeft(Node *& r)
{
    rotateRight(r->right);
    rotateLeft(r);
}

void AVLTree::clear(Node *& r)
{
    if (r!= nullptr)
    {
        clear(r->left);
        clear(r->right);
        delete r;
    }
    r = nullptr;
}

void AVLTree::clear()
{
    clear(root);
}
#endif //UNIT5AVLTREE_AVLTREE_H
