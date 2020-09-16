#include <iostream>
#include<vector>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node *create_node(int data)
{
    struct Node *node = new Node;
    node->data = data;
    node->right = node->left = NULL;
    return node;
}
Node* level_tree_creation(struct Node *root, int i, int n, vector<int>* v){

  if(i<n){

    root=create_node(v->at(i));

    root->left=level_tree_creation(root->left, 2*i+1, n, v);

    root->right=level_tree_creation(root->right, 2*i+2, n, v);

  }

  return root;

}
bool check_full_binary_tree(struct Node *root)
{
    if ((root->left==NULL && root->right!=NULL) || root->right==NULL && root->left!=NULL){
        return false;
    }
    else if (root->left==NULL && root->right==NULL){
        return true;
    }
    else{
        return check_full_binary_tree(root->left) && check_full_binary_tree(root->right);
    }
}
struct Node* Root=NULL;
int main()
{
    vector<int>* v = new vector<int>;

    string x;

    while( cin>>x ){
    if(x=="null"){
        v->push_back(0);
    }
    else{
        int a=stoi( x );
        v->push_back(a);
    }
    
    
    }
    // cout<<v->size()<<endl;
    Root=level_tree_creation(Root, 0, v->size(), v);
    bool ans = check_full_binary_tree(Root);
    if (ans==1){
        cout<<"True";
    }
    else{
        cout<<"false";
    }
    return 0;
}
