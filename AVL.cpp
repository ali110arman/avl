#include<iostream>
using namespace std;
class node {
public:
	int data;
	class node* left;
	class node* right;
};
node* AvlTree;
class AvlTree {
public:
	AvlTree();
	int Height(node*);
	int Difference(node*);
	void Show(node*, int);
	void Inorder(node*);
	void PreOrder(node*);
	void PostOrder(node*);
	node* RightRightRotat(node*);
	node* LeftFirstRotat(node*);
	node* LefrRightRotat(node*);
	node* RightFirstRotat(node*);
	node* Balance(node*);
	node* Insert(node*, int);
};
AvlTree::AvlTree() {
	right = NULL;
}
int AvlTree::Height(node* t) {
	int h = 0;
	if (t != NULL) {
		int l_height = Height(t->left);
		int r_height = Height(t->right);
		int max_height = l_height;
		if (l_height > r_height)
			max_height = l_height;
		else
			max_height = r_height;
		h = max_height + 1;
	}
	return h;
}
int AvlTree::Difference(node* t) {
	int l_height = Height(t->left);
	int r_height = Height(t->right);
	int b_factor = l_height - r_height;
	return b_factor;
}
node* AvlTree::RightRightRotat(node* parent) {
	node* t;
	t = parent->right;
	parent->right = t->left;
	t->left = parent;
	cout << "Right-Right Rotation";
	return t;
}
node* AvlTree::LeftFirstRotat(node* parent) {
	node* t;
	t = parent->left;
	parent->left = t->right;
	t->right = parent;
	cout << "Left-Left Rotation";
	return t;
}
node* AvlTree::LefrRightRotat(node* parent) {
	node* t;
	t = parent->left;
	parent->left = RightRightRotat(t);
	cout << "Left-Right Rotation";
	return LeftFirstRotat(parent);
}
node* AvlTree::RightFirstRotat(node* parent) {
	node* t;
	t = parent->right;
	parent->right = LeftFirstRotat(t);
	cout << "Right-Left Rotation";
	return RightRightRotat(parent);
}
node* AvlTree::Balance(node* t) {
	int bal_factor = Difference(t);
	if (bal_factor > 1) {
		if (Difference(t->left) > 0)
			t = LeftFirstRotat(t);
		else
			t = LefrRightRotat(t);
	}
	else if (bal_factor < -1) {
		if (Difference(t->right) > 0)
			t = RightFirstRotat(t);
		else
			t = RightRightRotat(t);
	}
	return t;
}
node* AvlTree::Insert(node* right, int v) {
	if (right == NULL) {
		right = new node;
		right->data = v;
		right->left = NULL;
		right->right = NULL;
		return right;
	}
	else if (v < right->data) {
		right->left = Insert(right->left, v);
		right = Balance(right);
	}
	else if (v >= right->data) {
		right->right = Insert(right->right, v);
		right = Balance(right);
	} return right;
}
void AvlTree::Show(node* p, int left) {
	int i;
	if (p != NULL) {
		Show(p->right, left + 1);
		cout << " ";
		if (p == right)
			cout << "Root -> ";
		for (i = 0; i < left && p != right; i++)
			cout << " ";
		cout << p->data;
		Show(p->left, left + 1);
	}
}
void AvlTree::Inorder(node * t) {
	if (t == NULL)
		return;
	Inorder(t->left);
	cout << t->data << " ";
	Inorder(t->right);
}
void AvlTree::PreOrder(node * t) {
	if (t == NULL)
		return;
	cout << t->data << " ";
	PreOrder(t->left);
	PreOrder(t->right);
}
void AvlTree::PostOrder(node * t) {
	if (t == NULL)
		return;
	PostOrder(t->left);
	PostOrder(t->right);
	cout << t->data << " ";
}
int main() {
	int c, i;
	AvlTree node;
	while (1) {
		cout << "1.Insert Element into the tree" << endl;
		cout << "2.Show Balanced AVL Tree" << endl;
		cout << "3.InOrder traversal" << endl;
		cout << "4.PreOrder traversal" << endl;
		cout << "5.PostOrder traversal" << endl;
		cout << "6.Exit" << endl;
		cout << "Enter your Choice: ";
		cin >> c;
		switch (c) {
		case 1:
			cout << "Enter value to be inserted: ";
			cin >> i;
			right = node.Insert(right, i);
			break;
		case 2:
			if (right == NULL) {
				cout << "Tree is Empty" << endl;
				continue;
			}
			cout << "Balanced AVL Tree:" << endl;
			node.Show(right, 1);
			cout << endl;
			break;
		case 3:
			cout << "Inorder Traversal:" << endl;
			node.Inorder(right);
			cout << endl;
			break;
		case 4:
			cout << "Preorder Traversal:" << endl;
			node.PreOrder(right);
			cout << endl;
			break;
		case 5:
			cout << "Postorder Traversal:" << endl;
			node.PostOrder(right);
			cout << endl;
			break;
		case 6:
			exit(1);
			break;
		default:
			cout << "Wrong Choice" << endl;
		}
	}
	return 0;
}