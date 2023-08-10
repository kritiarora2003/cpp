#include <bits/stdc++.h>
using namespace std;

// Declaring node
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// List of all funcitons made below
// Making tree
struct node* makeNode(int val);
struct node* insertLeft(struct node* root, int value);
struct node* insertRight(struct node* root, int value);
struct node* build_tree(struct node* root);
struct node* build_from_level_order(struct node* root);
// Printing tree
void inorder(struct node* root);
void preorder(struct node* root);
void postorder(struct node* root);
int level_order_traversal(struct node* root);
// BT opertions
int height_r(struct node* root);
int height_i(struct node* root);
// BST operations
struct node* insert(struct node* root, int val);
struct node* search(struct node* root, int val);
struct node* delete_recursive(struct node* root, int val);



// Create a new node
struct node* makeNode(int val) {
    struct node* temp;
    temp = (struct node*) malloc(sizeof(struct node));
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL; 
    return temp;
}

// Insert on the left of the node.
struct node* insertLeft(struct node* root, int value) {
  root->left = makeNode(value);
  return root->left;
}

// Insert on the right of the node.
struct node* insertRight(struct node* root, int value) {
  root->right = makeNode(value);
  return root->right;
}

// Inorder traversal (recursive)
void inorder(struct node* root){
    if(root == NULL)
    return;
    inorder(root->left);
    //printf("%d ", root->data);//
    cout<<root->data<<" ";
    inorder(root->right);
}

// Preorder traversal (recursive)
void preorder(struct node* root){
    if(root == NULL)
    return;
    //printf("%d ", root->data);
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

// Postorder traversal (recursive)
void postorder(struct node* root){
    if(root == NULL)
    return;
    postorder(root->left);
    postorder(root->right);
    //printf("%d ", root->data);
    cout<<root->data<<" ";
}

// Insertion in BST (recursive)
struct node* insert(struct node* root, int val){
    if(root == NULL)
    return makeNode(val);
    else if (val > root->data){
        root->right = insert(root->right, val);
    }
    else if (val < root->data){
        root->left = insert(root->left, val);
    }
    return root;
}

// Searching in BST (recursive)
struct node* search(struct node* root, int val) {
    if(root == NULL)
    return NULL;
    
    if(val == root->data)
    return root;
    else if (val > root->data)
    return search(root->right, val);
    else if (val < root->data)
    return search(root->left, val);
}

// Deletion of node in BST (recursive)
struct node* delete_recursive(struct node* root, int val) {
    if(root == NULL)
    return root;
    
    if(val > root->data) {
        root->right = delete_recursive(root->right, val);
        return root;
    }
    else if (val < root->data){
        root->left = delete_recursive(root->left, val);
        return root;
    }
    
    // agar left null hai to right subtree return kar
    if(root->left == NULL){
        struct node* temp = root->right;
        free(root);
        return temp;
    }
    // agar right null hai toh left subtree return kar
    else if(root->right == NULL){
        struct node * temp = root->left;
        free(root);
        return temp;
    }
    // agar dono null nahi hai toh inorder successor se replace kar
    else{
        struct node* temp = root->right;
        struct node* parent = root;
        
        // inorder successor right subtree ka left most element
        while(temp->left){
            parent = temp;
            temp = temp->left;
        }
        
        // agar inorder successor just right subtree a pehele node hai
        // toh bas usko upar dedo, yani rorate kardo
        if(parent == root)
            parent->right = temp->right;
        // agar nahi hai
        // toh to_remove node ki value ki jaga successor ki value
        // aur successor ka right subtree uske baap ka left
        else
            parent->left = temp->right;
            
        root->data = temp->data;
        free(temp);
        return root;
    }
}

// Finding height of a BST (recursive)
// Height is the maximum number of edges from root to deepest leaf
int height_r(struct node* root){
    int l, r;
    if(root){
        l = height_r(root->left);
        r = height_r(root->right);
        if(l > r)
        return (l+1);
        else
        return (r+1);
    }
}

// Finding height of BST (iterative using queue)
int height_i(struct node* root){
    if(root == NULL)
    return 0;

    int height = 0;
    
    queue <node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        struct node* temp = q.front();
        q.pop();
        
        if(!temp){
            height++;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            if(temp->left)
            q.push(temp->left);
            if(temp->right)
            q.push(temp->right);
        }   
    }
    return height;
}

// Building a tree using recursion
struct node* build_tree(struct node* root){
    int data;
    //printf("Enter the data: \n");
    //scanf("%d", &data);
    cout<<"Enter the data: "<<endl;
    cin>>data;

    root = makeNode(data);
    
    // We define -1 as NULL
    if(data == -1){
        return NULL;
    }
    
    // printf("Enter data for inserting on the left of %d \n", data);
    cout<<"Enter data for inserting on the left of "<< data << endl;
    root->left = build_tree(root->left);
    // printf("Enter data for inserting on the right of %d \n", data);
    cout<<"Enter data for inserting on the right of "<< data << endl;
    root->right = build_tree(root->right);
    
    return root;
}

// Printing the tree in level order
// And finding the height
int level_order_traversal(struct node* root){
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

// Building from level order
struct node* build_from_level_order(struct node* root){
    queue <node*> q;

    cout << "Enter root data: " << endl;
    int root_data;
        cin>>root_data;


    if(root_data == -1){
        root = NULL;
        return root;
    }

    root = makeNode(root_data);

    q.push(root);

    while(!q.empty()){
        struct node* temp = q.front();
        q.pop();

        cout << "Enter left data for: " << temp->data << endl;
        int left;
        cin>>left;
        if(left != -1){
            temp->left = makeNode(left);
            q.push(temp->left);
        }

        cout << "Enter right data for: " << temp->data << endl;
        int right;
        cin >> right;
        if(right != -1){
            temp->right = makeNode(right);
            q.push(temp->right);
        }
    }
    return root;
}



int main()
{
    struct node* root;
    //root = makeNode(10);
    //// Making the tree
    // root->left = makeNode(2);
    // root->right= makeNode(3);
    // root->left->left = makeNode(4);
    // root->left->right = makeNode(5);
    // root->right->left = makeNode(6);
    // root->right->right = makeNode(7);
    
    // // Making the tree
    // root = makeNode(10);
    // insertLeft(root, 5);
    // insertRight(root, 15);
    // insertLeft(root->left, 2);
    // insertRight(root->left, 8);
    // insertLeft(root->right, 12);
    // insertRight(root->right, 20);
    
    // // Making tree
    // // But every time i run the program i will have to enter the tree again and again
    // // so there are times where insertRight and insertLeft are usefel
    // // and there are times where build_tree is useful
    // root = build_tree(root);
    // inorder(root);
    // cout<<endl;
    
    //// Traversals
    // inorder(root);
    // printf("\n");
    // preorder(root);
    // printf("\n");
    // postorder(root);
    // printf("\n");
    
    // // Insertion
    // root = insert(root, 6);
    // //inorder(root);
    // printf("\n");

    //// Searching
    // struct node* ptr;
    // ptr = search(root, 6);
    // if(ptr != NULL){
    //     printf("%d ", ptr->data);
    //     printf("mil gaya\n");
    // }
    // return 0;
    
    // // Deletion
    // root = delete_recursive(root, 12);
    // inorder(root);
    // printf("\n");
    
    // // Height
    // int h = height_r(root);
    // printf("height is: %d \n", h);
    
    // // Level order traversal
    // int h = level_order_traversal(root);

    // // Level order input
    // root = build_from_level_order(root);

    //// Finding height of tree
    //int h = level_order_traversal(root);
    // int hi = height_i(root);
    // cout<<"iterative height is : "<< hi<<endl;
}



