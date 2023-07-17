#include <stdio.h>
#include <stdlib.h>

 typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    int height;
} Node;

// Function to get the height of a node
int getHeight(Node* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

// Function to get the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to create a new node with a given key
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1; // New node is initially added at leaf level
    return newNode;
}

// Function to right rotate subtree rooted with y
Node* rightRotate(Node* y)
{
    Node* x = y->left;
    Node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    // Return new root
    return x;
}

// Function to left rotate subtree rooted with x
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    // Return new root
    return y;
}

// Function to get the balance factor of a node
int getBalance(Node* node)
 {
    if (node == NULL)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}

// Function to insert a node into the AVL tree
Node* insertNode(Node* node, int data) {
    // Perform the normal BST insertion
    if (node == NULL)
        return createNode(data);

    if (data < node->data)
        node->left = insertNode(node->left, data);
    else if (data > node->data)
        node->right = insertNode(node->right, data);
    else // Duplicate keys are not allowed in AVL tree
        return node;

    // Update the height of the ancestor node
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    // Check the balance factor and perform necessary rotations
    int balance = getBalance(node);

    // Left Left case
    if (balance > 1 && data < node->left->data)
        return rightRotate(node);

    // Right Right case
    if (balance < -1 && data > node->right->data)
        return leftRotate(node);

    // Left Right case
    if (balance > 1 && data > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left case
    if (balance < -1 && data < node->right->data)
        {
        node->right = rightRotate(node->right);
             return leftRotate(node);
    }

    // Return the unchanged node pointer
    return node;
}

// Function to print the AVL tree in an inorder traversal
void inorderTraversal(Node* root)
 {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

void preorderTraversal(struct Node* root)
{
    if (root != NULL)
        {
        printf("%d ", root->data);

        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(struct Node* root) {
    if (root != NULL)
        {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);


    }
}

int main()
 {
    Node* root = NULL;
    int n, num;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        root = insertNode(root, num);
    }

    printf("Inorder traversal of the AVL tree: ");
    inorderTraversal(root);
    printf("\n");

     printf("preorder traversal of the AVL tree: ");
    preorderTraversal(root);
    printf("\n");


    printf("postorder traversal of the AVL tree: ");
    postorderTraversal(root);
    printf("\n");

    return 0;
}




