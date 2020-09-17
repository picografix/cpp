#include <vector>
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

struct Node *create_node(int data)
{
    struct Node *node = new Node;
    node->data = data;
    node->right = node->left = NULL;
    return node;
}

void post_order_traverse(struct Node *node){

  if(node!=NULL){

    

    post_order_traverse(node->left);

    post_order_traverse(node->right);

    cout<<node->data<<" ";
  }

}
void tree_create(struct Node *root,vector<int>* v1,vector<int>* v2,int i,int n ,int i2, int n2){
    if(i<n){
        root=create_node(v1->at(i));
    }
}

struct Node* Root=NULL;

int main()

{  
    vector<int>* pre = new vector<int>;
    vector<int>* ino = new vector<int>;

    int x;

    while( cin>>x && x!=-1){

        pre->push_back(x);

    }
    while( cin>>x && x!=-1){

        ino->push_back(x);

    }

    post_order_traverse(Root);

  return 0;

}