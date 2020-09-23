#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
} * root;

Node *newNode(int key)
{
    Node *node = new Node;
    node->data = key;
    node->left = node->right = NULL;

    return node;
}

void insert_nodes(vector<int> &arr, queue<Node *> &queue, int index)
{
    while (1)
    {
        if (queue.size() == 0)
            break;
        Node *top = queue.front();
        queue.pop();
        if (index < arr.size())
        {
            if (arr[index] != INT_MAX)
            {
                top->left = newNode(arr[index]);
                queue.push(top->left);
            }
            else
            {
                top->left = NULL;
            }
            index++;
        }
        if (index < arr.size())
        {
            if (arr[index] != INT_MAX)
            {
                top->right = newNode(arr[index]);
                queue.push(top->right);
            }
            else
            {
                top->right = NULL;
            }
            index++;
        }
    }
}

void build_tree()
{
    string temp;
    vector<int> arr;
    while (cin >> temp)
    {
        if (temp != "null")
            arr.push_back(stoi(temp));
        else
            arr.push_back(INT_MAX);
    }
    root = newNode(arr[0]);
    queue<Node *> queue;
    queue.push(root);

    insert_nodes(arr, queue, 1);
}

// leftmost node is always minimum in BST
int get_min(struct Node *root)
{
    if (root->left == NULL)
        return root->data;
    return get_min(root->left);
}

// rightmost node is always maximum in BST
int get_max(struct Node *root)
{
    if (root->right == NULL)
        return root->data;
    return get_max(root->right);
}

void preorder_traverse(Node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    preorder_traverse(root->left);
    preorder_traverse(root->right);
}

int main()
{
    build_tree();
    cout << get_min(root) << " " << get_max(root) << endl;
    preorder_traverse(root);
    return 0;
}
