#include <iostream>

class Node {
public:
	Node(size_t i_key) : key(i_key) {}

	int getKey() const {
		return key;
	}

	void add(size_t elem) {

		if (elem <= key) {
			if (left != nullptr) {
				left->add(elem);
			}
			else {
				left = new Node(elem);
			}
		}
		else {
			if (right != nullptr) {
				right->add(elem);
			}
			else {
				right = new Node(elem);
			}
		}

	}

	void printInward() {
		if (left) left->printInward();
		std::cout << key << " ";
		if (right) right->printInward();
	}

private:
	int key;
	Node *left = nullptr,
		*right = nullptr;

};

class BinaryTree {
	Node* root = nullptr;
public:
	void add(size_t elem) {
		if (root)
			root->add(elem);
		else
			root = new Node(elem);
	}
	void printInward() {
		root->printInward();
	}
};


int main() {
	BinaryTree tree;

	size_t n;
	while ((std::cin >> n) && (n != 0)) {
		tree.add(n);
	}

	tree.printInward();
	std::cout << std::endl;

	return 0;
}