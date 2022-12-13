#include <iostream>
using namespace std;
class sorts{
    int* arr;
    int size;
    public:
        sorts(){
            cout<<"Enter the size: ";
            cin>>size;
            arr = new int[size];
            cout<<"Enter the array: "<<endl;
            for(int i=0;i<size;i++)
            cin>>arr[i];
            cout<<endl;
        }

        void selection(){
           int i,j;
           for(i=0;i<size-1;i++){
            for(j=0;j<size-i-1;j++){
                 if (arr[j] > arr[j + 1])
                 swap(arr[j], arr[j + 1]);
                }
            }
        
           
            for(int i=0;i<size;i++)
            cout<<arr[i]<<' ';
            cout<<endl;
    
        }
        
    
};
int main(){
    sorts s;
    s.selection();
}