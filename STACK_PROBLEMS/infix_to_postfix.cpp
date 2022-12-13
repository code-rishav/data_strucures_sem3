#include <iostream>
#include "stack.h"
using namespace std;
class postfix{
    string infx;
    string postfx;
    int size;
    char ar[];
    public:
    postfix(){
        //ar = new char[4];
        char ar[] = {'-','+','/','*'};
        cout<<"Enter the infix expression: ";
        cin>>infx;
        size = infx.length();
        postfx="";
       
    }

    bool isoperator(char ch){
    
        if(ch=='-'||ch=='+'||ch=='/'||ch=='*'||ch=='('||ch==')')
        return true;
        else
        return false;
    }

    void print(){
        cout<<"The postfix expression is:"<<postfx<<endl;;
    }

    void convert(){
        Stack<char>s(100);
        int i1=NULL,i2=NULL;
        for(int i=0;i<size;i++){
            char ch = infx[i];
        
            if(isoperator(ch)){
                if(ch=='(')
                s.push(ch);
                if(ch==')'){
                    while(s.topE()!='('){
                        if(s.topE()!='(')
                        postfx+=s.topE();
                        s.pop();
                    }

      
                }
                if(s.isEmpty())
                s.push(ch);
                else{
                 for(int j=0;j<4;j++){
                        if(s.topE()==ar[j])
                        i1 = j;
                        if(ch==ar[j])
                        i2 = j;
                     }
                
                    if(i2>i1){
                        while(!s.isEmpty()){
                            postfx+=s.topE();
                            s.pop();
                         }
                    }
                    else
                    if(ch!=')')
                    s.push(ch);
                }
            }
            else
            postfx+=ch;
        }
        while(!s.isEmpty()){
            if(s.topE()!='(')
            postfx+=s.topE();
            s.pop();
        }
        print();
    }
};

int main(){
    postfix p;
    p.convert();

}