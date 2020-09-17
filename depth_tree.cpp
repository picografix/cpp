#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
} *root1 = NULL;

struct Node *create_node(int data)
{
    struct Node *node = new Node;
    node->data = data;
    node->right = node->left = NULL;
    return node;
}

Node *remove_null_nodes(Node *root)
{
    if (root == NULL || root->data == INT_MAX)
        return NULL;

    root->left = remove_null_nodes(root->left);
    root->right = remove_null_nodes(root->right);

    return root;
}


Node* level_tree_creation(struct Node *root, int i, int n, vector<int>* v){

  if(i<n){

    root=create_node(v->at(i));

    root->left=level_tree_creation(root->left, 2*i+1, n, v);

    root->right=level_tree_creation(root->right, 2*i+2, n, v);

  }

  return root;

}
void build_tree(struct Node **root)
{
    vector<int>* v = new vector<int>;

    string x;

    while( cin>>x ){
        if(x=="null"){
            v->push_back(INT_MAX);
        }
        else
        {
        /* code */
        v->push_back(stoi(x));
        }
    }

    // cout<<v->size();

    *root=level_tree_creation(*root, 0, v->size(), v);
    *root = remove_null_nodes(*root);
    return;
}


int max(int a, int b){
    return (a >= b ? a : b);
}
int tree_depth(struct Node *node)
{
    int depth =1;
    if(node!=NULL){
        // cout<<"node encounter "<<node->data<<endl;
        depth+=max(tree_depth(node->left),tree_depth(node->right));
    }
    else if (node==NULL){
        // cout<<"null encountered"<<endl;
        return 0;
    }
    return depth;
}
void pre_order_traverse(struct Node *node){

  if(node!=NULL){

    cout<<node->data<<" ";

    pre_order_traverse(node->left);

    pre_order_traverse(node->right);

  }

}

int main()
{   
     
    build_tree(&root1);
    // pre_order_traverse(root1);
    int depth = tree_depth(root1);
    
    cout << depth << endl;
    return 0;
}
