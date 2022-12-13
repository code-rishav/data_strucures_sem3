#include <iostream>
#include <cstdlib>

using namespace std;
class Stack{

    public:
    string str;
    int size;
    char *s;
    int top;

    Stack(){
        cout<<"Enter the string: ";
        cin>>str;
        size = str.length();
        top = -1;
        s  = new char[size];
    }

    void pop(){
        top--;

    }

    void push(char a){
        s[++top] = a;

    }

    char topE(){
        return s[top];
    }

    bool isEmpty(){
        if(top==-1)
        return true;
        else
        return false;
    }
    bool check(){
        int len = str.length();
        int i;
        for(i=0;i<len;i++){
            char ch = str[i];
            if(ch=='['||ch=='{'||ch=='(')
            push(ch);
            else{
                char t = topE();
                
                if(isEmpty()==true)
                return false;
                else if((t == '['&& ch ==']')|| (t=='{' && ch =='}')|| (t =='('&& ch ==')')){
                cout<<"t: "<<t<<' ';
                cout<<"c: "<<ch<<endl;
                pop();
                }
                else
                return false;
            }
        }
        return (isEmpty()==true);

    }
    void print(){
        for(int i=0;i<size;i++)
        cout<<s[i]<<' ';
        cout<<endl;
    }

};

int main(){
    Stack s;
    if(s.check())
    cout<<"Parentheses are balanced";
    else
    cout<<"Parentheses are not balanced";
    cout<<endl;
   // s.print();
}