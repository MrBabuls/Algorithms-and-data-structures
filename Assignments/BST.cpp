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

BSTNode* BST::remove(BSTNode* node, int key, bool& success) 
{
    if (!node) 
    {
        success = false;
        return nullptr;
    }

    if (key < node->data) 
    {
        node->left = remove(node->left, key, success);
    }
    else if (key > node->data) {
        node->right = remove(node->right, key, success);
    }
    else 
    {
        success = true;

        if (!node->left && !node->right) 
        {
            delete node;
            return nullptr;
        }
        else if (!node->left) 
        {
            BSTNode* temp = node->right;
            delete node;
            return temp;
        }
        else if (!node->right) 
        {
            BSTNode* temp = node->left;
            delete node;
            return temp;
        }
        else 
        {
            BSTNode* minNode = node->right;
            while (minNode->left) minNode = minNode->left;

            node->data = minNode->data;
            node->right = remove(node->right, minNode->data, success);
        }
    }
    return node;
}

bool BST::remove(int key) 
{
    bool success = false;
    root = remove(root, key, success);
    return success;
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