#include <iostream>
using namespace std;
class min_heap{
    int *arr;
    int size;
    int capacity;

    min_heap(int c){
        arr = new int[c];
        size = 0;
        capacity = c;
    }
    int left(int i){
        return (2*i+1);
    }
    int right(int i){
        return (2*i+2);
    }
    int parent(int i){
        return (i-1)/2;
    }

    int insert(int x){
        if(size==capacity) return 0;
        size++;
        arr[size] = x;
        for(int i=size-1;i!=0 && arr[parent(i)]>arr[i];){
            swap(arr[parent(i)],arr[i]);
            i = parent(i);
        }
    }
    void minheapify(int i){
        int lt = left(i);
        int rt = right(i);
        int smallest = i;
        if(lt<size && arr[lt]<arr[smallest])
        smallest = lt;
        if(rt<size && arr[rt]<arr[smallest])
        smallest = rt;
        if(smallest!=i){
            swap(arr[smallest],arr[i]);
            minheapify(smallest);
        }
    }

    int extract(){
        if(size==0)
        return INT16_MAX;
        if(size==1){
            size--;
            return arr[0];
        }
        swap(arr[0],arr[size-1]);
        size--;
        minheapify(0);
        return arr[size];

    }

    void decreasekey(int i,int x){
        arr[i] = x;
        while(i!=0 && arr[parent(i)]>arr[i]){
            swap(arr[i],arr[parent(i)]);
            i = parent(i);
        }
    }

    void delete_(int i){
        decreasekey(i,INT16_MIN);
        extract();
    }
    
};