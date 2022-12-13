#include <iostream>

using namespace std;
template <typename T>

class Stack{
    
    int size;

    public:
    T *ar;
    int top;

    Stack(int size){
        this->size = size;
        top = -1;
        ar  = new T[size];
    }

    T pop(){
        if(top==-1)
        return INT16_MAX;
        return ar[top--];

    }

    void push(int a){
        ar[++top] = a;

    }

    T TopE(){
        return ar[top];
    }

    bool isEmpty(){
        if(top==-1)
        return true;
        else
        return false;
    }

};
int main(){
    Stack <int> s(5);
}