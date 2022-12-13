#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int x){
        data = x;
        next = NULL;
        prev = NULL;
    }
    Node(){
        data = 0;
        next = NULL;
        prev = NULL;
    }
};