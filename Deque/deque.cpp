#include "Node.cpp"
template <typename T>
class Deque{
    Node<T> *front;
    Node<T> *rear;
    int size;
    public:
    Deque(){
        size = 0;
        front = NULL;
        rear = NULL;
    }
    int insertfront(int x);
    int insertrear(int x);
    int removefront();
    int removerear();
    T getfront();
    T getrear();
    bool empty();
    int getsize();

};

template <typename T>
int Deque<T>::getsize(){
    return size;
}

template <typename T>
int Deque<T>::insertfront(int x){
    Node<T> *ele = new Node<T>(x);
    if(front==NULL){
        front = rear = ele;
        size++;
        return 1;
    }
    else{
        ele->next = front;
        front  = ele;
        size++;
        return 1;
    }
}

template <typename T>
int Deque<T>::insertrear(int x){
    Node<T> *ele = new Node<T>(x);
    if(rear==NULL){
        front  = rear = ele;
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
int Deque<T>::removefront(){
    if(front==NULL) return 0;
    else{
        Node<T> *temp = front;
        front = front->next;
        delete temp;
        if(front==NULL) rear = NULL;
        size--;
        return 1;
    }
}

template <typename T>
int Deque<T>::removerear(){
    if(rear==NULL) return 0;
    else{
        Node<T> *temp = rear;
        rear = rear->prev;
        delete temp;
        if(rear==NULL) front = NULL;
        size--;
        return 1;
    }
}

template <typename T>
T Deque<T>::getfront(){
    if(front==NULL) return NULL;
    else
    return front->data;
}

template <typename T>
T Deque<T>::getrear(){
    if(rear==NULL) return NULL;
    else
    return rear->data;
}

template <typename T>
bool Deque<T>::empty(){
    if(rear==NULL)
    return true;
    else
    return false;
}

int main(){
    Deque<int> d;
    int op;
    bool flag = true;
    while(flag){
        cout<<"1.enque at front \n2.enque at rear \n3.deque at front \n4.deque at rear \n5.getfront \n6.getrear \n7.isempty \n8.getsize \n9.exit\n";
        cin>>op;
        switch (op)
        {
            int val;
            case 1:
            cout<<"Enter the value: ";
            cin>>val;
            d.insertfront(val);
            break;

            case 2:
            cout<<"Enter the value: ";
            cin>>val;
            d.insertrear(val);
            break;

            case 3:
            if(!d.removefront())cout<<"Queue is empty"<<endl;
            break;

            case 4:
            cout<<d.removerear()<<endl;
            break;

            case 5:
            cout<<d.getfront()<<endl;
            break;

            case 6:
            cout<<d.getrear()<<endl;
            break;

            case 7:
            cout<<d.empty()<<endl;
            break;

            case 8:
            cout<<d.getsize()<<endl;
            break;

            case 9:
            flag = false;
            break;

            default:
            cout<<"Enter a valid value"<<endl;

        }
        cout<<"\n";
    }
}