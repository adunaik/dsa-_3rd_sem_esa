#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
        return root;
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    }
    else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
    return root;
}

void inorderTraversal(struct Node* root, FILE* file) {
    if (root != NULL) {
        inorderTraversal(root->left, file);
        fprintf(file, "%d ", root->data);
        inorderTraversal(root->right, file);
    }
}

void preorderTraversal(struct Node* root, FILE* file) {
    if (root != NULL) {
        fprintf(file, "%d ", root->data);
        preorderTraversal(root->left, file);
        preorderTraversal(root->right, file);
    }
}

void postorderTraversal(struct Node* root, FILE* file) {
    if (root != NULL) {
        postorderTraversal(root->left, file);
        postorderTraversal(root->right, file);
        fprintf(file, "%d ", root->data);
    }
}

int main() {
    // Generate random number of 5 elements
    int elements[5];
    srand(time(NULL));
    for (int i = 0; i < 5; i++) {
        elements[i] = rand() % 100 + 1;
    }

    // Create a binary tree
    struct Node* root = NULL;
    for (int i = 0; i < 5; i++)
        {
        root = insertNode(root, elements[i]);
    }

    // Store the elements in text file 1
    FILE* file1 = fopen("trees1.txt", "w");
    if (file1 != NULL) {
        for (int i = 0; i < 5; i++) {
            fprintf(file1, "%d ", elements[i]);
        }
        fclose(file1);
    }

    // Store the inorder traversal in text file 2
    FILE* file2 = fopen("trees2.txt", "w");
    if (file2 != NULL) {
        inorderTraversal(root, file2);
        fclose(file2);
    }

    // Store the preorder traversal in text file 3
    FILE* file3 = fopen("trees3.txt", "w");
    if (file3 != NULL) {
        preorderTraversal(root, file3);
        fclose(file3);
    }

    // Store the postorder traversal in text file 4
    FILE* file4 = fopen("trees4.txt", "w");
    if (file4 != NULL) {
        postorderTraversal(root, file4);
        fclose(file4);
    }

       // Print the elements and the generated binary tree for reference
    printf("Elements: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", elements[i]);
    }
    printf("\n");

    printf("Inorder Traversal: ");
    inorderTraversal(root, stdout);
    printf("\n");

    printf("Preorder Traversal: ");
    preorderTraversal(root, stdout);
    printf("\n");

    printf("Postorder Traversal: ");
    postorderTraversal(root, stdout);
    printf("\n");

    return 0;
}
