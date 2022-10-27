#include <bits/stdc++.h>
using namespace std;
  

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
  
int heightOfTreeUtil(Node* root, bool isEven)
{
    // Base Case
    if (!root)
        return 0;
  
    if (!root->left && !root->right) {
        if (isEven)
            return 1;
        else
            return 0;
    }
  
    
    int left = heightOfTreeUtil(root->left, !isEven);
    int right = heightOfTreeUtil(root->right, !isEven);
  
    
    if (left == 0 && right == 0)
        return 0;
  
    return (1 + max(left, right));
}
  

struct Node* newNode(int data)
{
    struct Node* node = 
              (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
  
    return (node);
}
  
int heightOfTree(Node* root)
{
    return heightOfTreeUtil(root, false);
}
  

int main()
{
   
    struct Node* root = newNode(1);
  
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->right->left = newNode(6);
    cout <<"Height of tree is"<<heightOfTree(root);
    return 0;
}