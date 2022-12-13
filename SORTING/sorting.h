#ifndef SORTING_H 
#define SORTING_H
#include <iostream>
using namespace std;

template <typename T>
 class Sort {

public:
	void insertion(T ar[],int size);
    void selection(T ar[],int size);
    void bubble(T ar[],int size);
    void print(T arr[],int size,int c);
};

/*template <typename T> 
Sort<T>::Sort(int s,T ar[])
{
	arr = new T[s];
	size = s;
	for (int i = 0; i < size; i++)
		arr[i] = ar[i];
}*/

template <typename T>
void Sort<T>::insertion(T ar[],int size){
    int index,i,j,comp=0;
    T* arr = new T[size];
            for(int i=0;i<size;i++){
                arr[i] = ar[i];
            }
            for(int i=1;i<size;i++){
                index = arr[i];
                j = i-1;
                while(j>=0 && arr[j]>index){
                    arr[j+1] = arr[j];
                    j--;
                    comp++;
                }
                arr[j+1] = index;
            }
            cout<<"INSERTION SORT "<<endl;
            print(arr,size,comp);
}

template <typename T>
void Sort<T>::selection(T ar[],int size){
    T *arr = new T[size];
            for(int i=0;i<size;i++){
                arr[i] = ar[i];
            }
            int min,j,comp=0;
            for(int i=0;i<size;i++){
                min = i;
                j=i+1;
                while(j<size){
                    if(arr[j]<=arr[min])
                    min = j;
                    j++;
                    comp++;
                }
                swap(arr[i],arr[min]);
               
            }
            cout<<"\n";
            cout<<"SELECTION SORT"<<endl;
             print(arr,size,comp);
}

template <typename T>
void Sort<T>::bubble(T ar[],int size){
    T *arr = new T[size];
    for(int i=0;i<size;i++){
          arr[i] = ar[i];
    }
     int i,j,comp=0;
     for(i=0;i<size-1;i++){
        for(j=0;j<size-i-1;j++){
            comp++;
            if (arr[j] > arr[j + 1])
             swap(arr[j], arr[j + 1]);
           }
    }
    cout<<"\n";
    cout<<"BUBBLE SORT"<<endl;
    print(arr,size,comp);
}

template <typename T>
void Sort<T>::print(T arr[],int size,int c){
    for(int i=0;i<size;i++)
    cout<<arr[i]<<' ';
    cout<<endl;
    cout<<"No. of Comparisons: "<<c<<endl;
}


#endif