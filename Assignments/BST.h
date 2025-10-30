#pragma once
#include "BSTNode.h"
#include <iostream>

class BST {

public:
    BST() : root(nullptr) {}

    void insert(int value);

    void print() const { print(root, 0); }
    int countNodes() const { return countNodes(root); }
    int countLeaves() const { return countLeaves(root); }

    static BST createSampleTree();

private:
    BSTNode* root;

    void print(BSTNode* node, int space) const;
    int countNodes(BSTNode* node) const;
    int countLeaves(BSTNode* node) const;
};