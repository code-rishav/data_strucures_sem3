#include <iostream>
#include <cstdlib>

using namespace std;
class Stack{
    
   

    public:
    int size;
    int *arr;
    int *ar;
    int top;

    Stack(int size){
        this->size = size;
        top = -1;
        ar  = new int[size];
        arr = new int[size];
        cout<<"Enter the value: "<<endl;
        for(int i=0;i<size;i++){
            cin>>arr[i];
        }
    }

    int pop(){
        if(top==-1)
        return INT16_MAX;
        return ar[top--];

    }

    void push(int a){
        ar[++top] = a;

    }

    int topE(){
        return ar[top];
    }

    bool isEmpty(){
        if(top==-1)
        return true;
        else
        return false;
    }

};
void print(int x,int num){
    cout<<"Span for "<<num<<" is: "<<x<<endl;
}

void span(Stack s){
    int sn;
    s.push(0);
    print(1,s.arr[0]);
    for(int i=1;i<s.size;i++){
        while(s.isEmpty()==false && s.arr[s.topE()]<=s.arr[i]){
            s.pop();
        }
        int sn= s.isEmpty() ? i+1 : i-s.topE();
        s.push(i);
        print(sn,s.arr[i]);
    }

}
 

int main(){
    Stack s(8);
    span(s);
    
}