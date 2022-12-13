#include <iostream>
using namespace std;
template <typename T>
class Node{
    public:
    T data;
    Node* next;
    Node* prev;
    Node(T x){
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