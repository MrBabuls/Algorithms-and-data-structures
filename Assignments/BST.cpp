#include "BST.h"

#include <iostream>
#include <iomanip>
using namespace std;

void BST::insert(int value) 
{
    BSTNode* newNode = new BSTNode(value);

    if (!root) 
    {
        root = newNode;
        return;
    }

    BSTNode* current = root;
    BSTNode* parent = nullptr;

    while (current) 
    {
        parent = current;
        if (value < current->data)
            current = current->left;
        else if (value > current->data)
            current = current->right;
        else
            return;
    }

    if (value < parent->data)
        parent->left = newNode;
    else
        parent->right = newNode;
}

int BST::countNodes(BSTNode* node) const 
{
    if (!node) return 0;
    return 1 + countNodes(node->left) + countNodes(node->right);
}

int BST::countLeaves(BSTNode* node) const 
{
    if (!node) return 0;
    if (!node->left && !node->right) return 1;
    return countLeaves(node->left) + countLeaves(node->right);
}

void BST::print(BSTNode* node, int space) const 
{
    if (!node) return;

    if (node->right) print(node->right, space + 6);

    if (space) cout << setw(space) << ' ';
    if (node->right) cout << " /\n" << setw(space) << ' ';
    cout << node->data << "\n ";
    if (node->left) 
    {
        cout << setw(space) << ' ' << " \\\n";
        print(node->left, space + 6);
    }
}

BST BST::createSampleTree() 
{
    BST tree;
    tree.insert(8);
    tree.insert(3);
    tree.insert(10);
    tree.insert(1);
    tree.insert(6);
    tree.insert(14);
    tree.insert(4);
    tree.insert(7);
    tree.insert(13);
    return tree;
}