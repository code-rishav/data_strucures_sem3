#ifndef STACK_H 
#define STACK_H
#include <iostream>

using namespace std;
template <typename T>

class Stack{
    int top;
    int size;
    T *ar;
    public:
    
    Stack(int size);
    void pop();
    void push(T a);
    T topE();
    bool isEmpty();
};

template <typename T>
    Stack<T>::Stack(int size){
        this->size = size;
        top = - 1;
        ar  = new T[size];
    }
template <typename T>
    void Stack<T>::pop(){
        if(top==-1)
        cout<<"Stack Underflow"<<endl;
        top--;
    }
template <typename T>
    void Stack<T>:: push(T a){
        ar[++top] = a;
    }
template <typename T>
    T Stack<T>::topE(){
        return ar[top];
    }
template <typename T>
    bool Stack<T>::isEmpty(){
        if(top==-1)
        return true;
        else
        return false;
    }

#endif