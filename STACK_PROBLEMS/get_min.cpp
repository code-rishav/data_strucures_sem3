#include <iostream>
#include <stack>
using namespace std;
class Min{
    stack <int> s;
    stack <int> as;
    public:
    void push(int x){
        if(s.empty()){
            s.push(x);
            as.push(x);
            return;
        }
        s.push(x);
        if(s.top()<=as.top())
        as.push(x);

    }

    void pop(){
        if(s.top()==as.top())
        as.pop();
        s.pop();
    }

    int getmin(){
        return as.top();
    }

};

int main(){
    Min m;
    m.push(4);
    m.push(6);
    m.push(7);
    m.push(2);
    m.push(9);
    cout<<m.getmin();
}

