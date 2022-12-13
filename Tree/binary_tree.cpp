#include "Node.cpp"
#include <queue>
#include <stack>
class binary_tree{
    public:
    BST_Node* root;
    binary_tree(){
        root = NULL;
    }

    int insert(int x){
        BST_Node* ele = new BST_Node(x);
        if(root==NULL){
            root = ele;
            return 1;
        }
        BST_Node* curr = root;
        while(curr!=NULL){
            if(x<curr->key){
                if(curr->left==NULL){
                    curr->left = ele;
                    return 1;
                }
                else
                curr = curr->left;
            }
            else if(x>curr->key){
                if(curr->right==NULL){
                    curr->right = ele;
                    return 1;
                }
                else
                curr = curr->right;
            }
            else
            return 0;
        }
        return 1;
    }

    int height(BST_Node* root){
    if(root==NULL)
    return 0;
    else
    return max(height(root->left),height(root->right))+1;
    }

    void level_order_traversal(){
        queue<BST_Node*> q;
        q.push(root);
        while(q.empty()==false){
            BST_Node* curr = q.front();
            q.pop();
            cout<<curr->key<<" ";
            if(curr->left!=NULL)
            q.push(curr->left);
            if(curr->right!=NULL)
            q.push(curr->right);
        }
        cout<<endl;
    }
    void inorder(BST_Node* root){
        if(root!=NULL){
            inorder(root->left);
            cout<<root->key<<" ";
            inorder(root->right);
        }
    }

    void preorder(BST_Node* root){
    if(root!=NULL){
        cout<<root->key<<" ";
        preorder(root->left);
        preorder(root->right);
    }
    }

    void postorder(BST_Node* root){
        if(root!=NULL){
            postorder(root->left);
            postorder(root->right);
            cout<<root->key<<" ";
        } 
    }

    BST_Node *getSuccessor(BST_Node *curr){
    curr=curr->right;
    while(curr!=NULL && curr->left!=NULL)
        curr=curr->left;
    return curr;
    }

BST_Node* delNode( BST_Node* root,int x){
    if(root==NULL)
        return 0;
    if(root->key>x)
        root->left=delNode(root->left,x);
    else if(root->key<x)
        root->right=delNode(root->right,x);
    else{
        if(root->left==NULL){
            BST_Node *temp=root->right;
            delete root;
            return temp;
        }
        else if(root->right==NULL){
            BST_Node *temp=root->left;
            delete root;
            return temp;
        }
        else{
            BST_Node *succ=getSuccessor(root);
            root->key=succ->key;
            root->right=delNode(root->right,succ->key);
        }
    }
    return root;
} 

BST_Node *prevv=NULL,*first=NULL,*second=NULL;
void fixBST(BST_Node* root)  
{  
    if (root == NULL)  
        return;  
    fixBST(root->left);
    if(prevv!=NULL && root->key<prevv->key){
        if(first==NULL)
            first=prevv;
        second=root;
    }
    prevv=root;
    
    fixBST(root->right);
}

BST_Node* search(BST_Node* root, int key)
{
    if (root == NULL || root->key == key)
       return root;

    if (root->key < key)
       return search(root->right, key);

    return search(root->left, key);
}

void inorder_t(){
    stack<BST_Node*> s;
    BST_Node* curr = root;
    BST_Node* 
    bool traverse = true;
    while(traverse){
        while(curr->left!=NULL){
            s.push(curr);
            curr = curr->left;
        }
        

        
        
    }
}


};