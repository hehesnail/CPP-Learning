#ifndef __EX13_28H__
#define __EX13_28H__

#include <string>

using namespace std;

class TreeNode {
public:
	TreeNode(): value(string()), count(new int(1)), left(nullptr), right(nullptr) { }
	TreeNode(const TreeNode &rhs):
		value(rhs.value), count(rhs.count), left(rhs.left), right(rhs.right) { ++*count; } 
	TreeNode& operator= (const TreeNode&);
	~TreeNode() {
		if (--*count == 0) {
			delete count;
			delete left;
			delete right;
		}
	}
private:
	string value;
	int *count;
	TreeNode *left;
	TreeNode *right;
};

class BinStrTree {
public:
	BinStrTree(): root(nullptr) { }
	BinStrTree(const BinStrTree &rhs): root(new TreeNode(*(rhs.root))) { }
	BinStrTree& operator= (const BinStrTree &);
private:
	TreeNode *root;
};

#endif
