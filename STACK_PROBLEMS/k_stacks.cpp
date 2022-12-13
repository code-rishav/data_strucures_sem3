#include <iostream>
using namespace std;

struct kStacks 
{ 
    int *arr;   
    int *top;   
    int *next;  
    int cap, k; 
    int freeTop; 
    
    kStacks(int k1, int n){
        k = k1; cap = n; 
        arr = new int[cap]; 
        top = new int[k]; 
        next = new int[cap];
        
        for (int i = 0; i < k; i++) 
            top[i] = -1; 
        
        freeTop = 0;
        for (int i=0; i<cap-1; i++) 
            next[i] = i+1; 
        next[cap-1] = -1;
    } 
  
    bool isFull()   {  return (freeTop == -1);  } 
  
    bool isEmpty(int sn)  {  return (top[sn] == -1); }
    
    void push(int x, int sn) 
    { 
    if (isFull()) 
    { 
        cout << "\nStack Overflow\n"; 
        return; 
    } 
    
    int i = freeTop;     
    freeTop = next[i]; 
    next[i] = top[sn]; 
    top[sn] = i;
    arr[i] = x; 
    } 
 
    int pop(int sn) 
    { 
    if (isEmpty(sn)) 
    { 
         cout << "\nStack Underflow\n"; 
         return INT_MAX; 
    }
    
    int i = top[sn]; 
    top[sn] = next[i];   
    next[i] = freeTop; 
    freeTop = i; 
    int temp = arr[i];
    arr[i] = 0;
    return temp; 
    }

    void print(int sn){
        int i;
        cout<<"*************"<<endl;
        cout<<"for stack: "<<sn<<endl;
        for(i=0;i<cap;i++)
        cout<<next[i]<<' ';
        cout<<endl;
        for(i=0;i<cap;i++)
        cout<<arr[i]<<' ';
        cout<<endl;
        cout<<"ft: "<<freeTop<<endl;
        cout<<"top[sn]: "<<top[sn]<<endl;
        cout<<endl;
    }
    void top_p(){
        for(int i=0;i<k;i++)
        cout<<top[i]<<' ';
        cout<<endl;
    }
    
}; 
  
int main() 
{ 
    int k = 3, n = 10; 
    kStacks ks(k, n); 
    while(true){
        ks.push(15, 2); 
        ks.print(2);
        ks.push(45, 2); 
        ks.print(2);
        ks.push(17, 1); 
        ks.print(1);
        ks.push(49, 2);
        ks.print(2); 
        ks.push(39, 1);
        ks.print(1); 
        
   
        ks.push(11, 0);
        ks.print(0); 
        ks.push(9, 0); 
        ks.print(0);
        ks.push(7, 1);
        ks.print(1);

        break;

    }
    ks.top_p();
     
  
    cout << "Popped element from stack 2 is " << ks.pop(2) << endl; 
    ks.print(2);
    cout << "Popped element from stack 1 is " << ks.pop(1) << endl; 
    ks.print(1);
    cout << "Popped element from stack 0 is " << ks.pop(0) << endl; 
    ks.print(0);
  
    return 0; 
}
