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

void print(int x,int y){
    cout<<"Previous Greater element of "<<x<<" is : "<<y<<endl;
}
void prev_great_ele(Stack s){
    s.push(s.arr[0]);
    print(s.arr[0],-1);
    for(int i=1;i<s.size;i++){
        while(s.isEmpty()==false && s.topE()<=s.arr[i]){
            s.pop();
        }
        int pg = s.isEmpty()? -1: s.topE();
        print(s.arr[i],pg);
        s.push(s.arr[i]);
    }

}
int main(){
    Stack s(8);
    prev_great_ele(s);
    
}