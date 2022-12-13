#ifndef SINGLYLINKEDLIST_CPP
#define SINGLYLINKEDLIST_CPP
#include "Node.cpp"
using namespace std;
class singlyll{

    Node *head;
    Node *tail;
    public:
    singlyll(){
        head = NULL;
        tail = NULL;
    }
    int insertatBegin(int x){
        Node* temp = new Node(x);
        if(temp==NULL)
        return -1;
        if(head==NULL){
            head = temp;
            tail=temp;
        }
        else{
            temp->next = head;
            head = temp;
        }
        return 0;
    }

    int insertatEnd(int x){
        Node *temp = new Node(x);
        if(temp==NULL)
        return -1;
        if(tail==NULL){
            head = temp;
            tail = temp;
        }
        else{
            tail->next = temp;
            tail = temp;
        }
        return 0;
    }
    
    int insertatPos(int pos,int x){
        Node* temp = new Node(x);
        if(head==NULL&&pos>1)
        return 0;
        if(pos==1){
            temp->next = head;
            head = temp;
            return 0;
        }
        else{
            Node* curr = head;
            for(int i=0;i<pos-2 && curr!=NULL;i++){
                curr = curr->next;
            }
            if(curr==NULL)
            return -1;
            temp->next = curr->next;
            curr->next = temp;
            return 0;
        }
    }

    int deleteatpos(int p){
        if(head==NULL&& p>1)
        return 0;
        Node* curr = head;
        if(p==1){
            Node* temp = curr;
            head = curr->next;
            delete temp;
            return 1;
        }
        else{
            for(int i=0;i<p-2 && curr!=NULL;i++){
                curr = curr->next;
            }
            if(curr==NULL)
            return 0;
            Node* temp = curr->next;
            curr->next = temp->next;
            delete temp;
            return 1;
        }

    }
    
    int delhead(){
        if(head==NULL)
        return -1;
        else if(tail==head){
            delete head;
            head = NULL;
            tail = NULL;
            return 0;
        }
        else{
            Node *temp = head;
            delete head;
            head = temp->next;
            return 0;
        }
    }


    int deltail(){
        if(tail==NULL)
        return -1;
        else if(tail==head){
            delete head;
            head = NULL;
            tail = NULL;
            return 0;
        }
        else{
            Node* temp = head;
            while(temp->next->next!=NULL)
            temp = temp->next;

            delete temp->next;
            temp->next = NULL;
            tail = temp;
            return 0;
        }
    }
    void display(){
        Node *p = head;
        while(p!=NULL){
            cout<<p->data<<"->";
            p = p->next;
        }
        cout<<endl;
    }
    
    int concatenate(Node* h2){
        if(h2==NULL)
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
#endif