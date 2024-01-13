#include<iostream>
#include<string>
#include<stack>
#include<ctype.h>
#include<algorithm>
#include<bits/stdc++.h>
#include "expression.h"
#include "Binary_tree.h"
#include "perfomance_binart.h"
using namespace std;

int main(){
	T* bt = new T;
	int x;
	cout<<"Enter:"<<endl<<"1.User generated binary tree"<<endl<<"2.Randomly generated binary tree"<<endl;
	cin>>x;
	if(x == 1)
		fuser(bt);
	else if(x==2){
		int n;
		cout<<"Enter the size of binary tree"<<endl;
	   	cin>>n;
	   	int a;
	   	srand(time(0)); 
		for(int i=0;i<n;i++){
		    a=rand()%100;
		    bt->insert(a);
		}
		fuser(bt);
	}
	
	char c;
	while(1){
		cout<<"Do you want to evaluate an expression\t Y/N"<<endl;
		cin>>c;
		if(c=='y' || c=='Y'){
			fexp();
		}else
			break;
	}
	cout<<"Do you want performace analysis of stl and sorting using binary search tree"<<endl<<"Y/N"<<endl;
	cin>>c;
	if(c=='y' || c=='Y')
		performance();
	delete(bt);
}
	

