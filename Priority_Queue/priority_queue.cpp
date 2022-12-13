#include <iostream>
using namespace std;
template <typename T>
class priority_queue{
    T *arr;
    int size;
    int capacity;
    public:
    priority_queue(int c){
        arr = new T[c];
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

    int push(T x){
        if(size==capacity) return 0;
        arr[size] = x;
        size++;
        for(int i=size-1;i!=0 && arr[parent(i)]>arr[i];){
            swap(arr[parent(i)],arr[i]);
            i = parent(i);
        }
        return 1;
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

    T extract(){
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

    void decreasekey(int i,T x){
        arr[i] = x;
        while(i!=0 && arr[parent(i)]>arr[i]){
            swap(arr[i],arr[parent(i)]);
            i = parent(i);
        }
    }


    bool empty(){
        return size==0;
    }

    int get_size(){
        return size;
    }

    T top(){
        return arr[0];
    }
    
};

int main(){
    int s;
    cout<<"Enter the capacity of priority queue";
    cin>>s;
    priority_queue<int> pq(s);
    int op;
    bool flag = true;
    while(flag){
        cout<<"1.push an element \n2.pop an element \n3.get size \n4.get top \n5.check empty "<<endl;
        cout<<"Enter the choice: ";
        cin>>op;
        switch(op){
            case 1:
            int val;
            cout<<"Enter the value to be pushed: ";
            cin>>val;
            pq.push(val);
            break;

            case 2:
            pq.extract();
            break;

            case 3:
            cout<<pq.get_size()<<endl;
            break;

            case 4:
            cout<<pq.top()<<endl;
            break;

            case 5:
            cout<<pq.empty()<<endl;
            break;
            
            case 6:
            flag = false;
            break;
        }
    }
}