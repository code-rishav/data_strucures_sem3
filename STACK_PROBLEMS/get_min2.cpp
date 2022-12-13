#include <iostream>
#include <cstdlib>
#include <stack>
using namespace std;
class Min{
    stack <int> s;
    int minm;
    public:
    void push(int x){
        if(s.empty()){
            s.push(x);
            minm = x;
        }
        else if(x<=minm){
            s.push(2*x-minm);
            minm = x;
        }
        else
        s.push(x);
    }

    int getmin(){
        return minm;
        
    }

    void pop(){
        if(s.top()<=minm){
            minm = 2*minm - s.top();
        }
        s.pop();
    }

    int top(){
        if(s.top()<=minm){
            return minm;
        }
        else
        return s.top();
    }
    void print(){
        while(!s.empty()){
            cout<<"Item popped: "<<top()<<endl;
            pop();
            cout<<"Minimum is: "<<getmin()<<endl;
        }
    }

};

int main(){
    Min m;
    m.push(4);
    m.push(3);
    m.push(16);
    m.push(2);
    m.push(-9);
    cout<<m.getmin()<<endl;
    m.print();
}

