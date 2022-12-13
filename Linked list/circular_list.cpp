#include "Node.cpp"
#include <iostream>
class circular_list{
    public:
    Node* tail;
    circular_list(){
        tail=NULL;
    }

    int addTail(int x){
        Node* temp = new Node(x);
        if(tail==NULL){
            tail = temp;
            tail->next = temp;
            return 1;
        }
        else{
            temp->next = tail->next;
            tail->next = temp;
            tail = temp;
            return 1;
        }
    }

    int addHead(int x){
        Node* temp = new Node(x);
        if(tail==NULL){
            tail = temp;
            tail->next = temp;
            return 1;
        }
        else{
            temp->next = tail->next;
            tail->next = temp;
            return 1;
        }
    }

    int insertafterele(int x,int y){
        if(tail==NULL)
        return 1;
        int flag = 0;
        Node* temp = tail->next;
        do{
            if(temp->data==x){
                flag=1;
                break;
            }
            else
            temp = temp->next;
        }while(temp!=tail->next);
        if(flag==0){
            return 1;
        }
        else{
            Node* ele = new Node(y);
            ele->next = temp->next;
            temp->next->prev = ele;
            temp->next = ele;
            ele->prev = temp;
            return 0;
        }

    }

    int deleteHead(){
        if(tail==NULL)
        return 0;
        else if(tail->next == tail){
            delete tail;
            tail = NULL;
            return 0;
        }
        else{
            Node* temp = tail->next;
            tail->next = tail->next->next;
            delete temp;
            return 1;
        }
    }

    int deleteTail(){
        if(tail==NULL)
        return 0;
        else if(tail->next == tail){
            delete tail;
            tail = NULL;
            return 0;
        }
        else{
            Node* curr = tail->next;
            do{
                curr = curr->next;
            }while(curr->next->next!=tail->next);
            Node* temp = curr->next;
            curr->next = tail->next;
            delete temp;
            tail = curr;
            return 1;
        }
    }

    int delele(int x){
        if(tail==NULL)
        return 0;
        int flag=0;
        Node* curr = tail->next;
        do{
            if(curr->next->data==x){
                flag = 1;
                break;
            }
            else{
                curr = curr->next;
            }
        }while(curr!=tail->next);
        if(flag==0){
            return 1;
        }
        else{
            Node* temp = curr->next;
            curr->next = temp->next;
            temp->next->prev = curr;
            delete temp;
            return 0;
        }
    }

    bool search(int x){
        if(tail==NULL){
            return false;
        }
        else{
            Node* curr = tail->next;
            do{
                if(curr->data==x)
                return true;
                curr = curr->next;
            }while(curr!=tail->next);
            return 0;
        }
    }

    int concatenate(Node* t2){
        if(t2==NULL || tail==NULL)
        return 1;
        else{
            Node* curr = tail->next;
            tail->next = t2->next;
            t2->next = curr;
            tail = t2;
            return 1;
        }
    }

    void display(){
        Node* curr = tail->next;
        do{
            cout<<curr->data<<" ";
            curr = curr->next;
        }while(curr!=tail->next);
        cout<<"\n";
    }
};