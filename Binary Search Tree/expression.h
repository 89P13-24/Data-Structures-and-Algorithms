#ifndef expression_h
#define expression_h


class Node{
public:
    char key;
    Node* lchild;
    Node* rchild;

    Node(char a){
        this->key = a;
        lchild = NULL;
        rchild = NULL;
    }
};
int precedence(char a);
std::string infix_to_postfix(std::string s);
Node* conversion(std::string s);
void inorder(Node* temp);
int evaluate(int a,int b,char o);
int expression_tree_evaluation(Node* root);
void fexp();

#endif
