#include <iostream>
using namespace std;

int span(int arr[],int pos,int size){
    int i,j,span;
    j = pos-1;
    while(j>0){
        if (pos==0)
        return 1;
        else if(arr[j]>=arr[pos])
        return pos - j; 
        else
        j--;
    }
    return pos+1;
}

int main(){
    int ar[] = {12,45,23,55,60,34,77,89,20,100};
    int size = sizeof(ar)/sizeof(int);
    for(int i=0;i<size;i++)
    cout<<"Span for element "<<ar[i]<<" is :"<<span(ar,i,size)<<endl;

}