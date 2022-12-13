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
int getMaxArea(Stack s ){
    int n = s.size;
    int res=0;
    int tp;
    int curr;
    
    for(int i=0;i<n;i++){
        while(s.isEmpty()==false && s.arr[s.topE()]>=s.arr[i]){
            tp= s.pop();
            curr=s.arr[tp]* (s.isEmpty() ? i : i - s.topE() - 1);
            cout<<"Area for "<<s.arr[i]<<" : "<<curr<<endl;
            res=max(res,curr);
        }
        
        s.push(i);
    }
    cout<<"***"<<endl;
    while(s.isEmpty()==false){
        tp=s.pop();
        curr=s.arr[tp]* (s.isEmpty() ? n : n - s.topE() - 1);
        res=max(res,curr);
        cout<<"Area: "<<s.arr[tp]<<" : "<<curr<<endl;
    }

    
    return res;
    
}

int main() 
{ 
    Stack s(6);
    int arr[]={10,50,70,20,40,80};
    int n=6;
    cout<<"Maximum Area: "<<getMaxArea(s);
    return 0; 
}
