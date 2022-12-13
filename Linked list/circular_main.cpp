#include "circular_list.cpp"
int main(){
    circular_list d;
   int op;
   int ele;
   bool flag =true;
   while(flag){
        cout<<"1.to add at head\n2.add at tail\n3.delete head\n4.delete tail\n5.display linked list\n6.search element\n7.to exit\n Enter the choice: ";
        cin>>op;
        cout<<endl;
        switch(op){
            case 1:
            cout<<"Enter the element to be addded at head: ";
            cin>>ele;
            d.addHead(ele);
            break;

            case 2:
            cout<<"Enter the element to be added at tail: ";
            cin>>ele;
            d.addTail(ele);
            break;

            case 3:
            if(d.deleteHead())
            cout<<"Head node deleted"<<endl;
            else
            cout<<"error deleting node"<<endl;
            break;

            case 4:
            if(d.deleteTail())
            cout<<"tail node deleted"<<endl;
            else
            cout<<"Erroe deleting tail"<<endl;
            break;

            case 5:
            d.display();
            cout<<"\n";
            break;

            case 6:
            cout<<"Enter the element to be searched: ";
            cin>>ele;
            if(d.search(ele))
            cout<<"Element found"<<endl;
            else
            cout<<"Element not found"<<endl;
            break;

            case 7:
            flag = false;
            break;

            default:
            cout<<"Enter valid choice"<<endl;
        }
        cout<<endl;
   }
   

}