#include <iostream>
#include<vector>
#include <climits>
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

void inorder_traversal(struct Node *node)
{
    if (node == NULL)
        return;

    inorder_traversal(node->left);
    cout << node->data << " ";
    inorder_traversal(node->right);
}
Node* level_tree_creation(struct Node *root, int i, int n, vector<int>* v){

  if(i<n){

    root=create_node(v->at(i));

    root->left=level_tree_creation(root->left, 2*i+1, n, v);

    root->right=level_tree_creation(root->right, 2*i+2, n, v);

  }

  return root;

}
Node* remove_null_nodes(Node *root)
{
    if (root == NULL || root->data == INT_MAX)
        return NULL;

    root->left = remove_null_nodes(root->left);
    root->right = remove_null_nodes(root->right);

    return root;
}
Node *sum(struct Node *root1, struct Node *root2){
    if (root1 == NULL)
        return root2;
    if (root2 == NULL)
        return root1;
    root1->data += root2->data;
    root1->left = sum(root1->left, root2->left);
    root1->right = sum(root1->right, root2->right);
    return root1;
}

struct Node* Root1=NULL;
struct Node* Root2=NULL;

int main()
{   vector<int>* v1 = new vector<int>;
    vector<int>* v2 = new vector<int>;
    string x;
    while ( cin>>x && x!="-1"){
        if (x=="null"){
        v1->push_back(INT_MAX);
        }
        else if(x!="-1"){
        v1->push_back(stoi( x ));
        }
    }
    while ( cin>>x && x!="-1"){
        if (x=="null"){
        v2->push_back(INT_MAX);
        }
        else if (x!="-1"){
        v2->push_back(stoi( x ));
        }
    }   
    // cout<<v2->size()<<endl;
    Root1=level_tree_creation(Root1, 0, v1->size(), v1);
    Root2=level_tree_creation(Root2, 0, v2->size(), v2);
    Root1 = remove_null_nodes(Root1);
    Root2 = remove_null_nodes(Root2);
    sum(Root1, Root2);

    inorder_traversal(Root1);

    return 0;
}
