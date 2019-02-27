#include "ex13_28.h"

TreeNode& TreeNode::operator= (const TreeNode &rhs) {
	++*rhs.count;
	if (--*count == 0) {
		delete count;
		delete left;
		delete right;
	}
	count = rhs.count;
	left = rhs.left;
	right = rhs.right;

	return *this;
}

BinStrTree& BinStrTree::operator= (const BinStrTree &rhs) {
	if (this->root == rhs.root) {
		return *this;
	}
	delete root;
	root = new TreeNode(*(rhs.root));
	return *this;
}

int main() {

	return 0;
}