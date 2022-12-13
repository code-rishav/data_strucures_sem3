#include <iostream>
#include "sorting.h"
using namespace std;

int main(){
    int size;
    cout<<"Enter the size of the array: ";
    cin>>size;
    cout<<"Enter the element of the array: "<<endl;
    int *ar = new int[size];
    for(int i=0;i<size;i++)
    cin>>ar[i];
    int op;
    cout<<"Enter the choice for sorting method: \n1.Insertion Sort \n2.Selection Sort \n3.Bubble Sort"<<endl;
    op = 1;
    Sort<int> s;
    while(op>=1&&op<=3){
        cin>>op;
       
        switch(op){
            case 1:
            s.insertion(ar,size);
            break;
            case 2:
            s.selection(ar,size);
            break;
            case 3:
            s.bubble(ar,size);
        }

    }
    s.print(ar,size,3);
    
}
