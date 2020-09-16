#include <iostream>

#include<bits/stdc++.h>

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


void pre_order_traverse(struct Node *node){

  if(node!=NULL){

    cout<<node->data<<" ";

    pre_order_traverse(node->left);

    pre_order_traverse(node->right);

  }

}

Node* level_tree_creation(struct Node *root, int i, int n, vector<int>* v){

  if(i<n){

    root=create_node(v->at(i));

    root->left=level_tree_creation(root->left, 2*i+1, n, v);

    root->right=level_tree_creation(root->right, 2*i+2, n, v);

  }

  return root;

}

struct Node* Root=NULL;

int main()

{  vector<int>* v = new vector<int>;

  int x;

  while( cin>>x ){

    v->push_back(x);

  }

  //cout<<v.size();

  Root=level_tree_creation(Root, 0, v->size(), v);

  pre_order_traverse(Root);

  return 0;

}