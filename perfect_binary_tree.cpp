#include <iostream>
#include <vector>
#include <math>
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

// bool check_perfect_binary_tree(struct Node *node)
// {
// }

int main()
{
    vector<int>* v = new vector<int>;

  int x;

  while( cin>>x ){

    v->push_back(x);

  }
  int size = v->size()+1;
  int i =0;
  bool a;
  while(true){
      if (pow(2,i) == size){
         a==true;
          break;
      }
      else if (pow(2,i) > size){
          a==false;
          break;
      }
  }
  cout<<a;
    return 0;
}
