#include "Node.cpp"
using namespace std;
template <typename T>
class Queue_ll{
    Node<T> *front;
    Node<T> *rear;
    int size;
    public:
    Queue_ll(){
        front = NULL;
        rear = NULL;
        size = 0;
    }
    int enque(T x);
    int deque();
    int get_size();
    T getfront();
    T getrear();
    bool isempty();
};
template <typename T>
int Queue_ll<T>::enque(T x){
    Node <T> *ele = new Node<T>(x);
    if(rear==NULL){
        front = rear = ele;
        size++;
        return 1;
    }
    else{
        rear->next = ele;
        rear = ele;
         size++;
         return 1;
    }
}

template <typename T>
int Queue_ll<T>::deque(){
    if(front==NULL) return 0;
    else{
        Node <T> *temp  = front;
        front = front->next;
        temp->next = NULL;
        size--;
        delete temp;
        if(front==NULL) rear=NULL;
        return 1;
    }
}

template <typename T>
int Queue_ll<T>::get_size(){
    return size;
}

template <typename T>
T Queue_ll<T>::getfront(){
    if(front==NULL) return NULL;
    return front->data;
}

template <typename T>
T Queue_ll<T>::getrear(){
    if(rear==NULL) return NULL;
    return rear->data;
}

template <typename T>
bool Queue_ll<T>::isempty(){
    if(front==NULL)
    return true;
    else
    return false;
}

int main(){
    Queue_ll<int>q;
    int op;
    bool flag = true;
    while(flag){
        cout<<"1.enque an element \n2.deque an element \n3.getfront \n4.getrear \n5.isempty \n6.getsize \n7.exit\n";
        cin>>op;
        switch (op)
        {
            case 1:
            int val;
            cout<<"Enter the value: ";
            cin>>val;
            q.enque(val);
            break;

            case 2:
            if(!q.deque())cout<<"Queue is empty"<<endl;
            break;

            case 3:
            cout<<q.getfront()<<endl;
            break;

            case 4:
            cout<<q.getrear()<<endl;
            break;

            case 5:
            cout<<q.isempty()<<endl;
            break;

            case 6:
            cout<<q.get_size()<<endl;
            break;

            case 7:
            flag = false;
            break;

            default:
            cout<<"Enter a valid value"<<endl;

        }
        cout<<"\n";
    }
}