#include<iostream>
using namespace std;
class BST_Node{
    public:
    int key;
    BST_Node* left;
    BST_Node* right;
    BST_Node(){
        key = 0;
        left = NULL;
        right = NULL;
    }
    BST_Node(int x){
        key  = x;
        left = NULL;
        right = NULL;
    }
};