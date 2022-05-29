#pragma once
#include <iostream>
#include <string>
#include "windows.h"
using namespace std;

struct Node
{
	string data;
	Node* left;
	Node* right;
	Node* parent;
};

class Tree
{
	static Node* root;
public:
	Tree();
	Tree(string math);

	void add(string data, Node* &node = root, Node* parent = nullptr);
	Node* find(string data);
	Node* parent(string data);
	Node* parent(Node* node);
	Node* left_most_child(Node* node);
	Node* right_sibling(Node* node);
	string label(Node* node);
	Node* get_root();
	void makenull(Node* &node = root);

	void print_inorder(Node* &node = root);
	void print_preorder(Node*& node = root);
	void print_postorder(Node* &node = root);
	
};