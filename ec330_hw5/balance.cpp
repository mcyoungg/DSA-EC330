#include "node.h"
#include <iostream>

using namespace std;

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
    trav(n->right, c); 
}