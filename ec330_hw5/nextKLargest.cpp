#include "BST.h"
#include <set>

void inorder(Node* n, set<int> &l);
set<int>* findX(set<int> s, int x);

int BST::nextKLargest(int x, int k) {

    set<int> list = {};
    inorder(this->root, list);
   
    auto ind = list.find(x); //O(n)

    if (ind == list.end()) {
        list.insert(x); //O(n), set in c++ is implemented as a BST, for highly unbalanced one -> O(n)
        ind = list.find(x);
    }
   
    for (int i = 0; i < k && ind != list.end(); ++i) {
        ind++; 
    }
        
    if(ind != list.end()){
        return *(ind);
    }
    else{
        return *(list.rbegin());
    }
}

void inorder(Node* n, set<int> &l){
    if (n == NULL){
        return;
    }
    inorder(n->left, l);
    l.insert(n->key);
    inorder(n->right, l); 
}


