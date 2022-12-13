#include "binary_tree.cpp"
int main(){
    binary_tree bt;
    int op;
    cout<<"enter the choice \n1.to insert an element \n2.to print the tree\n";
    cin>>op;
    while(true){
    switch(op){
        case 1:
        int ele;
        cout<<"Enter the element: ";
        cin>>ele;
        bt.insert(ele);
        break;
        
        case 2:
        bt.level_order_traversal();
    }
    }
}