#include <iostream>
using namespace std;

struct node
{
  int data;
  struct node* left;
  struct node* right;
};

struct node* newNode(int idata)
{
  struct node* node = new struct node;
  node->data = idata;
  node->left = NULL;
  node->right = NULL;
  return node;
}
void trav(node* n, int &c);

bool isWeightBalanced(node* root, int k) { 

    if(root == NULL){
        return true;
    }
    int wl = 0;
    trav(root-> left, wl);

    int wr = 0;
    trav(root-> right, wr);
    
    if(wl - wr > k){
        return false;
    }
    else{
        return isWeightBalanced(root->left, k) && isWeightBalanced(root->right, k);
        
    }
    
}

void trav(node* n, int &c){
    if (n == NULL){
        return;
    }
    
    c++;
 
    trav(n->left, c);
    //cout << n->data << " ";
    trav(n->right, c); 
}
int main()
{
  struct node *root = newNode(1);
  root->left = newNode(2);
  root ->right = newNode(3);
  root->left->left = newNode(4);
  root->left->left->left = newNode(7);

  root->right->left = newNode(5);
  root->right->right = newNode(6);
  int count = 0;
  //trav(root->left, count);
  //cout << "count is: " << count<<endl;
  cout<< "ans: " << isWeightBalanced(root->left->left, 1) << endl;

  return 0;
}