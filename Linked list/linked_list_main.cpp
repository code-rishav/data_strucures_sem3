#include "single_list.cpp"
int main(){
    singlyll l1;
    int s = l1.insertatBegin(10);
    l1.insertatBegin(22);
    l1.insertatBegin(32);
    l1.insertatEnd(100);
    l1.display();
    l1.insertatPos(5,4);
    l1.display();
    l1.deleteatpos(5);
    l1.display();

}