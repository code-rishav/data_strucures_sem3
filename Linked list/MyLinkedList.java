public class MyLinkedList {
    
    int val;
    static int size = 0;
    MyLinkedList head;
    MyLinkedList tail;
    MyLinkedList next;
    public MyLinkedList() {
        next = null;
        val = 0;
        head = null;
    }
    
    public MyLinkedList(int x){
        val = x;
        next = null;
    }
    
    public int get(int index) {
        if(head==null){
            return -1;
        }
        MyLinkedList curr = head;
        for(int i=0;i<index && curr!=null;i++){
            curr = curr.next;
        }
        if(curr!=null)
            return curr.val;
        else
            return -1;
    }
    
    public void addAtHead(int val) {
         MyLinkedList temp = new MyLinkedList(val);
        if(head==null){
            head = tail = temp;
        }
        else{
            temp.next = head;
            head = temp;     
        }   
        size++;
    }
    
    public void addAtTail(int val) {
        MyLinkedList temp = new MyLinkedList(val);
        if(tail==null){
            tail = head = temp;
        }
        else{
            tail.next = temp;
            temp.next = null;
            tail = temp;
        }
        size++;
    }
    
    public void addAtIndex(int index, int val) {
        MyLinkedList curr = head;
        if(index>size)
        return;
        MyLinkedList temp = new MyLinkedList(val);
        if(index==0){
          temp.next = curr;
            head = temp;
        }
        for(int i=0;i<index-1;i++){
            curr = curr.next;
        }
       
        temp.next = curr.next;
        curr.next = temp;
        size++;
    }

    public void deleteAtIndex(int index) {
        MyLinkedList curr = head;
        if(head==null)
            return;
        if(index>size)
            return;
        if(curr.next==null && index==0){
            head=curr=null;
            return;
        }
        for(int i=0;i<index-1;i++){
            curr = curr.next;
        }
        curr.next = curr.next.next;
        size--;
    }
    public void display(){
        MyLinkedList curr= head;
        while(curr!=null){
            System.out.print(curr.val+"->");
            curr = curr.next;
        }
        System.out.println();
    }
    public static void main(String[] args) {
        MyLinkedList obj = new MyLinkedList();
        obj.addAtHead(7);
        obj.addAtHead(2);
        obj.addAtHead(1);
        obj.addAtIndex(3,0);
        obj.display();
        obj.deleteAtIndex(2);
        obj.display();
        obj.addAtHead(6);
        obj.display();
        obj.addAtTail(4);
        obj.display();
        System.out.println(obj.get(4));
        obj.addAtHead(4);
        obj.addAtIndex(5, 0);
        obj.addAtHead(6);
        obj.display();

    }
}