#include <iostream>
template <typename T>
class Queue{
    int size,front,cap;
    T* arr;
    public:
    Queue(int capacity){
        cap = capacity;
        arr = new int[cap];
        size = 0;
        front = 0;
    }
    int deque();
    bool isempty();
    bool isfull();
    int enque(int x);
    T getfront();
    T getrear();
};

//implementation of isempty()
template <typename T>
bool Queue<T>:: isempty(){
    if(size==0)
    return true;
    else
    return false;
}

//implementation of isfull()
template <typename T>
bool Queue<T>:: isfull(){
    if(size==cap) return true;
    else return false;
}

//implementation of deque()
template <typename T>
int Queue<T>:: deque(){
    if(isempty()) return 0;
    else{
        front = (front+1)%cap;
        size--;
        return 1;
    }
}

//implementation of enque
template <typename T>
int Queue<T>:: enque(int x){
    if(isfull()) return 0;
    else{
        int rear = (front+size-1)%cap;
        rear = (rear+1)%cap;
        arr[rear] = x;
        size++;
        return 1;
    }
}

template <typename T>
T Queue<T>::getfront(){
    return arr[front];
}

template <typename T>
T Queue<T>::getrear(){
    return arr[(front+size-1)%cap];
}

int main(){
    int s;
    std::cout<<"Enter the capacity of the queue: ";
    std::cin>>s;
    Queue <int>q(s);
    int op;
    bool flag = true;
    while(flag){
        std::cout<<"1.enque an element \n2.deque an element \n3.getfront \n4.getrear\n5.exit\n";
        std::cin>>op;
        switch (op)
        {
            case 1:
            int val;
            std::cout<<"Enter the value: ";
            std::cin>>val;
            if(!q.enque(val)) std::cout<<"Queue is full"<<std::endl;
            break;

            case 2:
            if(!q.deque()) std::cout<<"Queue is empty"<<std::endl;
            break;

            case 3:
            std::cout<<q.getfront()<<std::endl;
            break;

            case 4:
            std::cout<<q.getrear()<<std::endl;
            break;

            case 5:
            flag = false;
            break;

            default:
            std::cout<<"Enter a valid value"<<std::endl;

        }
        std::cout<<"\n";
    }

}