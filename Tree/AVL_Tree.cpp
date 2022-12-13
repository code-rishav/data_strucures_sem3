#include "Node.cpp"
class AVL{
    BST_Node* root;
    public:
    AVL(){
        root = NULL;
    }

    int getheight(BST_Node* root){
        if(root==NULL)
            return 0;
        return max(getheight(root->left),getheight(root->right))+1;
    }

    int balancefactor(BST_Node* node){
        if(node==NULL)
        return 0;
        else
        return getheight(node->left)-getheight(node->right);
    }

    BST_Node* leftrotate(BST_Node* node){
        if(node==NULL)
        return NULL;
        BST_Node* x = node->left;
        BST_Node* T2 = x->right;

        x->right = node;
        node->left = T2;
        return x;
    }

    BST_Node*  rightrotate(BST_Node* node){
        if(node==NULL)
        return NULL;
        BST_Node* x = node->right;
        BST_Node* T2 = x->left;

        node->left = x;
        x->right = T2;
        return x;
    }

    int insert_element(int x){
        root = insert(root,x);
        return 1;
    }

    BST_Node* insert(BST_Node* node,int x){
        BST_Node* ele = new BST_Node(x);
        if(node==NULL) return ele;

        if(x< node->key)
            node->left = insert(node->left,x);
        if(x>node->key)
            node->right = insert(node->right,x);
        return node;

        int bf = balancefactor(node);

        //Left Left Case
        if(bf>1 && x<node->left->key){
            leftrotate(node);
        }
        //Right Right Case
        if(bf<-1 && x>node->right->key){
            rightrotate(node);
        }
        //Left Right Case
        if(bf>1 && x>node->left->key){
            node->left = rightrotate(node->left); 
            leftrotate(node);
        }
        //Right Left Case
        if(bf<-1 && x<node->right->key){
            node->right = leftrotate(node->right);
            rightrotate(node);
        }
        return node;
    }
};
int main(){
    AVL bt;
    int op;
    cout<<"enter the choice \n1.to insert an element \n2.to print the tree\n";
    cin>>op;
    while(true){
    switch(op){
        case 1:
        int ele;
        cout<<"Enter the element: ";
        cin>>ele;
        bt.insert_element(ele);
        break;
    }
    }
}