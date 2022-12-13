#include "Node.cpp"
class Double{
    public:
    Node* head;
    Node* tail;
    Double(){
        head = NULL;
        tail = NULL;
    }

    int addHead(int x){
        Node* temp = new Node(x);
        if(head==NULL){
            head = temp;
            tail = temp;
        }
        else{
            head->prev = temp;
            temp->next = head;
            head = temp;
        }
        return 1;
    }

    int addTail(int x){
        Node* temp = new Node(x);
        if(tail==NULL){
            tail = temp;
            head = temp;
        }
        else{
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
        return 1;
    }

    int insertatpos(int x,int pos){
        if(head==NULL && pos!=1)
            return 1;
        else if(pos==1){
            Node* temp = new Node(x);
            temp->next = head;
            head = temp;
            return 0;
        }
        else{
            Node* temp = new Node(x);
            Node* curr = head;
            for(int i=0;i<pos-2 && curr!=NULL;i++){
                curr= curr->next;
            }
            if(curr==NULL)
            return 1;
            
            temp->next = curr->next;
            curr->next->prev = temp;
            temp->prev = curr;
            curr->next = temp;
            return 1;  
        }
    }

    int delatpos(int pos){
        if(head==NULL && pos!=1)
        return 0;
        else if(pos==1){
            Node* temp = head;
            head = head->next;
            delete temp;
            head->prev = NULL;
            return 1;
        }
        else{
            Node* curr = head;
            for(int i=0;i<pos-2 && curr!=NULL; i++){
                curr = curr->next;
            }
            if(curr==NULL)
            return 1;
            Node* temp = curr->next;
            curr->next = temp->next;
            temp->next->prev = curr;
            delete temp;
            return 1;
        }
    }

    int delHead(){
        Node* temp = head;
        if(head==NULL)
        return -1;
        else if(head==tail){
            delete temp;
            head = NULL;
            tail = NULL;
            return 1;
        }
        else{
            head = temp->next;
            head->prev = NULL;
            delete temp;
            return 1;
        }
    }

    int delTail(){
        Node* temp = tail;
        if(tail==NULL){
            return -1;
        }
        else if(tail==head){
            delete tail;
            tail = NULL;
            head = NULL;
        }
        else{
            tail = temp->prev;
            tail->next = NULL;
            delete temp;
        }
        return 1;
    }

    int search(int x){
        int pos = 0;
        Node* curr = head;
        while(curr!=NULL){
            if(curr->data==x)
            return pos;
            pos++;
            curr = curr->next;
        }
        return -1;
    }

    void display(){
        if(head==NULL){
        cout<<"No node present in the linked list"<<endl;
        return;
        }
        cout<<"Linked list :"<<endl;
        Node* curr = head;
        while(curr!=NULL){
            cout<<curr->data<<" ";
            curr = curr->next;
        }
        cout<<endl;
    }
    int sortedinsert(Node* head,int x){
         Node* temp = new Node(x);
        if(head==NULL){
         temp->next = NULL;
         head = temp;
         return 1;
         }
        if(x<head->data){
            temp->next = head;
            head = temp;
            return 0;
        }
    
        Node* curr = head;
        while(curr->next!=NULL && curr->next->data<x){
            curr = curr->next;
        }
        temp->next = curr->next;
        curr->next = temp;
        return 0;
    }

    int concatenate(Node* h2){
        if(h2==NULL || head==NULL)
        return 1;
        else{
            Node* curr = head;
            while(curr->next!=NULL){
                curr = curr->next;
            }
            curr->next = h2;
            return 0;
        }
    }
};