#include <bits/stdc++.h>

using namespace std;


map<int,int> mp;


struct Node

{

  int data;

  Node *left, *right;

};


struct Node *create_node(int data)

{

  struct Node *node = (struct Node *)malloc(sizeof(struct Node));

  node->data = data;

  node->right = node->left = NULL;

  return node;

}


struct Node* create_tree(vector<int> const &in, vector<int> const &pre, int x, int y)

{

  if(x > y)

  return NULL;

  static int w=0;

  struct Node* temp = create_node(pre[w++]);

  int rootindex = mp[temp->data];

  temp->left = create_tree(in, pre, x, rootindex-1);

  temp->right = create_tree(in, pre, rootindex+1, y);

  return temp;

}


void post_order_traversal(struct Node *node)

{

  if(node == NULL)

  return;

   

  post_order_traversal(node->left);

  post_order_traversal(node->right);

  cout<<node->data<<" ";

}


int main()

{

  int k,l;

  vector<int> in;

  vector<int> pre;

  while(1)

  {

    cin>>k;

    if(k==-1)

    break;

    pre.push_back(k);

  }

  while(1)

  {

    cin>>l;

    if(l==-1)

    break;

    in.push_back(l);

  }

  for(int i=0;i<in.size();i++)

  mp[in[i]]=i;

  struct Node* root = create_tree(in,pre,0,in.size()-1);

  post_order_traversal(root);

  return 0;

}