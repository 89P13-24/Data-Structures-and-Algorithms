#ifndef BINARY_TREE_H
#define BINARY_TREE_H

class node{
public:
	int key;
	node* parent;
	node* lchild;
	node* rchild;
	node(){
		this->parent = nullptr;
		this->lchild = nullptr;
		this->rchild = nullptr;
	}

	node(int a){
		this->key = a;
		this->parent = nullptr;
		this->lchild = nullptr;
		this->rchild = nullptr;
	}
};

class T{
public:
	node* root;
	void insert(int a);
	node* search(int a);
	node* minimum(node* np);
	node* maximum(node* np);
	node* successor(node* np);
	node* predecessor(node* np);
	void transplant(node* u,node* v);
	void delete_node(node * z);
	void inorder(node* x);
	void Preorder(node* x);
	void Postorder(node* x);
	void print_tree();
	void inorder_traverse(node* np);
};
void fuser(T* bt);
#endif
