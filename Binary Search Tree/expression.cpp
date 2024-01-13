#include<iostream>
#include<string>
#include<stack>
#include<ctype.h>
#include<bits/stdc++.h>
#include "expression.h"
using namespace std;

int precedence(char a){
    if(a=='+' || a=='-')
        return 1;
    else if(a=='*' || a=='/')
        return 2;
    else if(a=='^')
        return 3;
    else
        return 0;
}
string infix_to_postfix(string s){
    stack <char> st;
    string exp ="";
    int p;
    for(int i=0;i<s.length();i++){
        if(isdigit(s[i])){
            exp += s[i];
        }else if(s[i] == '('){
            st.push(s[i]);
        }else if(s[i] == ')'){
            while(st.top()!='('){
                exp += st.top();
                st.pop();
            }
            st.pop();
        }else{
            p = precedence(s[i]);
            while(!st.empty() && precedence(st.top())>=p){
                exp += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty()){
        exp += st.top();
        st.pop();
    }
    return exp;
}

Node* conversion(string s){
    stack <Node*> st;
    for(int i=0;i<s.length();i++){
        Node* temp = new Node(s[i]);
        if(isdigit(s[i])){
            st.push(temp);
        }
        else{
            temp->rchild = st.top();
            st.pop();
            temp->lchild = st.top();
            st.pop();
            st.push(temp);
        }
    }
    return st.top();
}

void inorder(Node* temp){
    if(temp!=NULL){

        inorder(temp->lchild);
        cout<<temp->key<<"";
        inorder(temp->rchild);
    }
}

int evaluate(int a,int b,char o){
    switch(o){
        case '+':
            return a+b;
        case '-':
            return a-b;
        case '*':
            return a*b;
        case '/':
            return a/b;
    }
    return 0;
}

int expression_tree_evaluation(Node* root){
    if(!precedence(root->key))          // precedence function returns 0 whenever the input is an operand
        return int(root->key)-48;
    else
        return evaluate(expression_tree_evaluation(root->lchild),expression_tree_evaluation(root->rchild),root->key);
}

void fexp(){
    string s;
    cout<<"Enter the expression"<<endl;
    cin>>s;
    string exp = infix_to_postfix(s);
    //cout<<infix_to_postfix(s)<<endl;
    Node* temp = conversion(exp);
    cout<<"Your inorder traversal of your expression tree is as below"<<endl;
    inorder(temp);
    cout<<endl;
    cout<<expression_tree_evaluation(temp)<<endl;
}

