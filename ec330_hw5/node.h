#ifndef _NODE
#include <cstddef>
#define _NODE

struct node {
    int data;
    node* left;
    node* right;
    node(int x) : data(x), left(NULL), right(NULL) {}
};

struct node* newNode(int idata)
{
  struct node* node = new struct node;
  node->data = idata;
  node->left = NULL;
  node->right = NULL;
  return node;
};

bool isWeightBalanced(node* node, int k);

#endif