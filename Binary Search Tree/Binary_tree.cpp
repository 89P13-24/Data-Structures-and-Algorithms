#include<iostream>
#include<queue>
#include "Binary_tree.h"
using namespace std;

void  T::insert(int a){
	node* temp = new node(a);
	node* y = nullptr;
	node* x = root;
	while(x != nullptr){
		y=x;
		if(x->key < temp->key)
			x=x->rchild;
		else
			x=x->lchild;
	}
	temp->parent = y;
	if(y==nullptr)
		root = temp;
	else{
		if(y->key < temp->key)
			temp->parent->rchild = temp;
		else
			temp->parent->lchild = temp;
	}
}

node* T::search(int a){
	node* x = root;
	while(x!= nullptr && x->key != a){
		if(x->key < a)
			x = x->rchild;
		else
			x = x->lchild;
	}
	return x;
}

node* T::minimum(node* np){
	node* x = np;
	while(x->lchild != nullptr){
		x = x->lchild;
	}
	return x;
}

node* T::maximum(node* np){
	node* x = np;
	while(x->rchild != nullptr){
		x = x->rchild;
	}
	return x;
}

node* T::successor(node* np){
	node* x = np;
	if(x->rchild !=nullptr)
		return x->rchild;
	node* y = x->parent;
	while(y != nullptr && x == y->rchild){
		x=y;
		y=y->parent;
	}
	return y;
}

node* T::predecessor(node* np){
	node* x = np;
	if(x->lchild != nullptr)
		return x->lchild;
	node* y = x->parent;
	while(y != nullptr && x == y->lchild){
		x=y;
		y=y->parent;
	}
	return y;
}

void T::transplant(node* u,node* v){
	if(u->parent == nullptr)
		root = v;
	else if(u == u->parent->lchild)
		u->parent->lchild = v;
	else 
		u->parent->rchild = v;
	if(v != nullptr)
		v->parent = u->parent;
}

void T::delete_node(node* z){
	if(z->lchild == nullptr)
		transplant(z,z->rchild);
	else if(z->rchild == nullptr)
		transplant(z,z->lchild);
	else{
		node* y = minimum(z->rchild);
		if(y != z->rchild){
			transplant(y,y->rchild);
			y->rchild = z->rchild;
			y->rchild->parent = y;
		}
		transplant(z,y);
		y->lchild = z->lchild;
		y->lchild->parent = y;
	}
}

void T::inorder(node* x){
	if(x != nullptr){
		inorder(x->lchild);
		cout<<x->key<<" ";
		inorder(x->rchild);
	}
}

void T::Preorder(node* x){
	if(x != nullptr){
		cout<<x->key<<" ";
		inorder(x->lchild);
		inorder(x->rchild);
	}

}

void T::Postorder(node* x){
	if(x != nullptr){
		inorder(x->lchild);
		inorder(x->rchild);
		cout<<x->key<<" ";
	}
	
}

void T::print_tree(){
	node* temp = root;
	if(temp==NULL){
		cout<<"Empty tree"<<endl;
		return;
	}
	queue <node*> q;
	q.push(temp);
	node* x = NULL;
	while(!q.empty()){
		x = q.front();
		q.pop();
		cout<<x->key<<" ";
		if(x->lchild)
			q.push(x->lchild);
		if(x->rchild)
			q.push(x->rchild);
	}
}

void T::inorder_traverse(node* x){
	if(x != nullptr){
		inorder_traverse(x->lchild);
		inorder_traverse(x->rchild);
	}
}

void fuser(T* bt){
		int a;
		bool p = true;
		int choice;
		node* temp;
		while(p){
			
			cout<<"\nEnter your choice"<<endl;
			cout<<"1.To insert a element\n2.To search an element\n3.To find minimum element\n4.To find maximum element\n5.To find successor of an element in the tree\n6.To find predecessor of an element in the tree\n7.To delete an element\n8.For inorder traversal\n9.For preorder traversal\n10.For postorder traversal\n11.To display the tree\n12.Exit"<<endl;
			cin>>choice;
			switch(choice){
			case 1:
				cout<<"Enter the element"<<endl;
				cin>>a;
				bt->insert(a);
				break;
			case 2:
				cout<<"Enter the element"<<endl;
				cin>>a;
				if(bt->search(a))
					cout<<"Element found"<<endl;
				else
					cout<<"Element NOT found"<<endl;
				break;
			case 3:
				cout<<(bt->minimum(bt->root))->key<<endl;
				break;
			case 4:
				cout<<(bt->maximum(bt->root))->key<<endl;
				break;
			case 5:
				cout<<"Enter the element"<<endl;
				cin>>a;
				temp=bt->search(a);
				if(temp != NULL)
					cout<<(bt->successor(temp))->key<<endl;
				else
					cout<<"Element NOT in the tree"<<endl;
				break;
			case 6:
				cout<<"Enter the element"<<endl;
				cin>>a;
				temp=bt->search(a);
				if(temp != NULL)
					cout<<(bt->predecessor(temp))->key<<endl;
				else
					cout<<"Element NOT in the tree"<<endl;
				break;
			case 7:
				cout<<"Enter the element"<<endl;
				cin>>a;
				temp=bt->search(a);
				if(temp != NULL){
					bt->delete_node(temp);
					cout<<"Element deleted successfully"<<endl;
				}else
					cout<<"Element NOT in the tree"<<endl;
				break;
			case 8:
				bt->inorder(bt->root);
				break;
			case 9:
				bt->Preorder(bt->root);
				break;
			case 10:
				bt->Postorder(bt->root);
				break;
			case 11:
				bt->print_tree();
				break;
			case 12:
				p =false;
				break;
			default:
				cout<<"Enter a valid choice"<<endl;
				break;
			}
		}
}

