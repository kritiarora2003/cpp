#include <bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;
        int height;
};

// List of functions used below
// Utility functions
node* makeNode(int val);
int height(node* n);
int max (int a, int b);
int getBalance(node* n);
node* minValueNode(node* node);
// Rotations
node* leftRotate(node* x);
node* rightRotate(node* x);
// Operations
node* insert_in_avl(node* root, int val);
node* delete_in_avl(node* root, int val);
// Printing
void preorder(node* root);
int level_order_traversal(node* root);



// Create a new node
node* makeNode(int val){
    node* temp = new node();
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    temp->height = 1;
    return (temp);
}

// Find height of node
int height(node* n){
    if(n == NULL)
        return 0;
    //else
        return n->height;
}

int max (int a, int b){
    return ((a>b)? a : b);
}

// Balance factor of node n
int getBalance(node* n){
    if(n == NULL)
        return 0;
    else
        return (height(n->left) - height(n->right));
}

// Finding the node with minimum value by traversing to the far left of the BST
node* minValueNode(node* root){
    node* temp = root;
    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp;
}

// When insertion is done on the right side of right subtree
node* leftRotate(node* x){
    cout<<x->data<<" pe left rotate kar rahe"<<endl;
    node* y = x->right;
    node* subtree = y->left;

    // performing rotation
    y->left = x;
    x->right = subtree;

    // since only x and y is changed, we will updae their heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

// When insertion is done on the left side of left subtree
node* rightRotate(node* x){
        cout<<x->data<<" pe right rotate kar rahe"<<endl;

    node* y = x->left;
    node* subtree = y->right;

    // performing rotation
    y->right = x;
    x->left = subtree;

    // updating heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

// Function to insert node in a tree and balance it
node* insert_in_avl(node* root, int val){
    if(root == NULL)
        return (makeNode(val));

    if(val < root->data)
        root->left = insert_in_avl(root->left, val);
    else if (val > root->data)
        root->right = insert_in_avl(root->right, val);
    // Equal not allowed in BST
    else
        return root;

    // Update height of root node
    root->height = max(height(root->right), height(root->left)) + 1;
    cout<<"height of "<<root->data<<" is "<<root->height<<endl;

    // Get balance factor to check if balanced or not
    int balance = getBalance(root);
    cout<<root->data<<" ka balance factor hai "<<balance<<endl;
    //cout<<"balance factor of "<<root->data<<" is "<<balance<<endl;

    // Four cases LL, RR, LR, RL
    if (balance > 1 && val < root->left->data)
        return rightRotate(root);

    if (balance < -1 && val > root->right->data)
        return leftRotate(root);

    if (balance > 1 && val > root->left->data){
        cout<<root->data<<" pe lr kar rhe"<<endl;
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && val < root->right->data){
        cout<<root->data<<" pe rl kar rhe"<<endl;
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    // If tree is balanced then return the unchanged root node
    return root;    
}

node* delete_in_avl(node* root, int val){
    cout<<'\n'<<root->data<<" delete kar rhe"<<endl;
    // Normal BST delete
    if(root == NULL)
        return root;
    if (val < root->data){
        root->left = delete_in_avl(root->left, val);
    }
    else if ( val > root->data){
        root->right = delete_in_avl(root->right, val);
    }
    // Found the node
    else{
        // Base case is a node with only one child or no child
        if( (root->left == NULL) || (root->right == NULL) ){
            node* temp = root->left ? root->left : root->right;

            if(temp == NULL){
                temp = root;
                root = NULL;
            }
            else
            *root = *temp;
            //root->data = temp->data;

            free(temp);
        }

        else {
            node* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = delete_in_avl(root->right, temp->data);
        }
    }

    if(root == NULL)
        return root;

    root->height = max(height(root->left), height(root->right)) + 1;

    int balance = getBalance(root);

    if(balance > 1 && getBalance(root->left) >= 0)
    return rightRotate(root);

    if(balance > 1 && getBalance(root->left) < 0){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);
 
    if (balance < -1 && getBalance(root->right) > 0){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Printing the tree in level order
// And finding the height
int level_order_traversal(node* root){
    queue <node*> q;
    q.push(root);

    int height = 0;

    while(!q.empty()){
        height++;
        int size = q.size();

        while(size--){
            struct node* temp = q.front();
            cout<<temp->data<<'\t';

            if(temp->left)
            q.push(temp->left);
            if(temp->right)
            q.push(temp->right);

            q.pop();
        } 
        cout<<endl;
    }

    return height;
}

void preorder(node* root){
    if( root != NULL){
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

int main(){
    node* root = NULL;
    root = insert_in_avl(root, 9);
    root = insert_in_avl(root, 5);
    root = insert_in_avl(root, 10);
    root = insert_in_avl(root, 0);
    root = insert_in_avl(root, 6);
    root = insert_in_avl(root, 11);
    root = insert_in_avl(root, -1);
    root = insert_in_avl(root, 1);
    root = insert_in_avl(root, 2);

    // root = insert_in_avl(root, 10);
    // cout<<"ek node ghusa diya"<<endl;
    // root = insert_in_avl(root, 5);
    //     cout<<"ek node ghusa diya"<<endl;

    // root = insert_in_avl(root, 2);
    // cout<<"ek node ghusa diya"<<endl;


    // root = insert_in_avl(root, 1);

    // cout<<"ek node ghusa diya"<<endl;
    // root = insert_in_avl(root, 8);

    // cout<<"ek node ghusa diya"<<endl;
    // root = insert_in_avl(root, 15);

    // cout<<"ek node ghusa diya"<<endl;
    // root = insert_in_avl(root, 12);

    // cout<<"ek node ghusa diya"<<endl;
    // root = insert_in_avl(root, 11);

    // cout<<"ek node ghusa diya"<<endl;
    // root = insert_in_avl(root, 20);
    // root = insert_in_avl(root, 16);
    // root = insert_in_avl(root, 18);
    cout<<endl<<endl;


    cout<<"before"<<endl;
    preorder(root);
    //int h = level_order_traversal(root);

    

    root = delete_in_avl(root, 10);
    cout<<"after"<<endl;
    preorder(root);
}