#pragma once

class BSTNode {
public:
	int data;
	BSTNode* left;
	BSTNode* right;

	BSTNode(int value) : data(value), left(nullptr), right(nullptr) {}
};