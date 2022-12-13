#include "Node.cpp"
template <typename T>
class Stack{
  Node* top;
  public:
  Stack();
  T pop();
  int push(T data);
  T topE();
  bool isempty();
};

template <typename T>
Stack<T>::Stack(){
    top = NULL;
}

template <typename T>
int Stack<T>::push(T data){
    if(top==NULL){
        Node* temp = new Node(data);
        top = temp;
    }
    else{
        Node* temp = new Node(data);
        temp->next = top;
        top = temp;
    }
    return 1;
}

template <typename T>
T Stack<T>::pop(){
    if(top==NULL){
        throw underflow_error("Stack Underflow");
    }
    else{
        Node* temp = top;
        top = top->next;
        return temp->data;
    }
}

template <typename T>
T Stack<T>::topE(){
    if(top==NULL){
        throw underflow_error("Stack is empty");
    }
    else{
        return top->data;
    }
}

template <typename T>
bool Stack<T>::isempty(){
    if(top==NULL)
        return true;
    else
        return false;
}

int main(){
    Stack<int> s;
    int op;
    bool flag = true;
    while(flag){
        cout<<"\n";
        cout<<"Enter the choice \n1.push an element \n2.pop an element \n3.top of stack \n4.check for empty stack \n5.exit\n";
        cin>>op;
        switch (op){
            case 1:
                int val;
                cout<<"Enter the value: ";
                cin>>val;
                s.push(val);
            break;
            case 2:
                try{
                    int data = s.pop();
                    cout<<data<<endl;
                }
                catch(underflow_error& e){
                    cout<<e.what()<<endl;
                }
            break;
            case 3:
                try{
                    cout<<s.topE()<<endl;
                }
                catch(underflow_error& e){
                    cout<<e.what()<<endl;
                }
            break;
            case 4:
                if(s.isempty())
                cout<<"Stack is empty"<<endl;
                else
                cout<<"Stack is not empty"<<endl;
            break;
            case 5:
                flag = false;
            break;
            default:
            break;
        }
       
    }
}
