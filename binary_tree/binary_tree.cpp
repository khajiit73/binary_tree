#include "binary_tree.h"

Node* Tree::root = nullptr;

Tree::Tree()
{
	root = nullptr;
}

Tree::Tree(string math)
{
	add("0", root);
	Node* current = root;
	string data;
	for (int i = 0; i < math.size(); i++)
	{
		data[0] = math[i];
		if (math[i] == '(')
		{
			add("1", current->left, current);
			current = current->left;
		}
		else if (math[i] == '+' || math[i] == '-' || math[i] == '/' || math[i] == '*')
		{
			current->data[0] = data[0];
			add("2", current->right, current);
			current = current->right;
		}
		else if (math[i] == ')')
		{
			current = current->parent;
		}
		else
		{
			current->data[0] = data[0];
			current = current->parent;
		}
	}
}

void Tree::add(string data, Node* &node, Node* parent)
{
	if (node == nullptr)
	{
		node = new Node;
		node->parent = parent;
		node->data = data;
		node->left = node->right = nullptr;
		return;
	}

	if (data > node->data)
	{
		add(data, node->right, node);
	}
	else
	{
		add(data, node->left, node);
	}
}

Node* Tree::find(string data)
{
	Node* current = root;
	if (current == nullptr) return current;

	while (current != nullptr)
	{
		if (data == current->data) return current;
		else if (data > current->data)
		{
			if (current->right == nullptr) break;
			current = current->right;
		}
		else
		{
			if (current->left == nullptr) break;
			current = current->left;
		}
	}
	cout << "element does`nt exist" << endl;
	return nullptr;
}

Node* Tree::parent(string data)
{
	Node* current = root;
	if (current == nullptr) return current;


	while (current != nullptr)
	{
		if (data == current->data) return nullptr;
		else if (data > current->data)
		{
			if (current->right == nullptr) break;
			if (current->right->data == data) return current;
			current = current->right;
		}
		else
		{
			if (current->left == nullptr) break;
			if (current->left->data == data) return current;
			current = current->left;
		}
	}
	cout << "element does`nt exist" << endl;
	return nullptr;
}

Node* Tree::parent(Node* node)
{
	if (node == nullptr) return nullptr;
	return node->parent;
}

Node* Tree::left_most_child(Node* node)
{
	if (node == nullptr) return nullptr;
	return node->left;
}

Node* Tree::right_sibling(Node* node)
{
	if (node == nullptr || node->parent->right == node) return nullptr;
	return node->parent->right;
}

string Tree::label(Node* node)
{
	if (node == nullptr)
		return "no data";
	return node->data;
}

Node* Tree::get_root()
{
	return root;
}

void Tree::makenull(Node* &node)
{
	if (node == nullptr) return;
	makenull(node->left);
	makenull(node->right);
	node = nullptr;
	return;
}

void Tree::print_inorder(Node* &node)
{
	if (node == nullptr) return;
	print_inorder(node->left);
	cout << node->data << "  ";
	print_inorder(node->right);
	return;
}

void Tree::print_preorder(Node*& node)
{
	if (node == nullptr) return;
	cout << node->data << "  ";
	print_preorder(node->left);
	print_preorder(node->right);
	return;
}

void Tree::print_postorder(Node*& node)
{
	if (node == nullptr) return;
	print_postorder(node->left);
	print_postorder(node->right);
	cout << node->data << "  ";
	return;
}