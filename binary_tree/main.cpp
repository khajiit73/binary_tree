#include "binary_tree.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "\nстворення дерева даного математичного виразу (((a-b)*2)/(b*b+c))\n";
	Tree a("(((a-b)*2)/(b*b+c))");
	cout << "обхід дерева у симетричному порядку\n";
	a.print_inorder();
	cout << "\nобхід дерева у прямому порядку\n";
	a.print_preorder();
	cout << "\nобхід дерева у зворотньому порядку\n";
	a.print_postorder();
	a.makenull();
	cout << "\nобхід дерева у симетричному порядку після його очищення\n\n";
	a.print_inorder();

	Tree b;
	b.add("banana");
	b.add("peach");
	b.add("pear");
	b.add("apple");
	b.add("coconut");
	b.add("mango");
	b.add("papaya");
	b.add("add");
	cout << "\nстворення дерева зі слів 'banana', 'peach', 'pear', 'apple', 'coconut', 'mango', 'papaya', 'add'\n";
	cout << "обхід дерева у симетричному порядку\n";
	a.print_inorder();
	cout << "\nобхід дерева у прямому порядку\n";
	a.print_preorder();
	cout << "\nобхід дерева у зворотньому порядку\n";
	a.print_postorder();
	cout << "\nмітка вузла, який є правим братом вузла з міткою 'apple'\n";
	cout << b.label(b.right_sibling(b.find("apple")));
	cout << "\nмітка вузла, який є лівим сином вузла з міткою 'apple'\n";
	cout << b.label(b.left_most_child(b.find("apple")));
	cout << "\nмітка вузла, який є батьком вузла з міткою 'mango'\n";
	cout << b.label(b.parent("mango"));
}