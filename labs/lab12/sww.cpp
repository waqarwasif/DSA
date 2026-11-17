#include<iostream>
using namespace std;
class Node
{
public:
    char data;
    Node *left;
    Node *right;
    Node(char value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};
class BinaryTree
{
private:
    Node *root;

    void preorderHelper(Node *node){
        if(node == nullptr){
            return;
        }
        cout << node->data << " ";
        preorderHelper(node->left);
        preorderHelper(node->right);
    }
    void inorderHelper(Node *node){

        if(node == nullptr){
            return;
        }
        inorderHelper(node->left);
        cout << node->data << " ";
        inorderHelper(node->right);
    }
    void postorderHelper(Node *node){

        if(node == nullptr){
            return;
        }
        postorderHelper(node->left);
        postorderHelper(node->right);
        cout << node->data << " ";
    }
    int treeSizeHelper(Node *node){
        if(node == nullptr){
            return 0;
        }
        int size = 1;
        size += treeSizeHelper(node->left);
        size += treeSizeHelper(node->right);
        return size;
    }
    void clearTreeHelper(Node *ptr)
    {
        if (ptr != nullptr)
        {
            clearTreeHelper(ptr->left);
            clearTreeHelper(ptr->right);
            delete ptr;
        }
    }

public:
    BinaryTree()
    {
        root = nullptr;
    }
    
    // Member functions
    void preorder();
    void inorder();
    void postorder();
    int treeSize();
    void clearTree();
    void setRoot(Node *newRoot);


};
void BinaryTree::preorder(){
    preorderHelper(root);
    cout<< endl;
   }
void BinaryTree::inorder(){
    inorderHelper(root);
    cout<< endl;
   }
void BinaryTree::postorder(){
        postorderHelper(root);
        cout<< endl;    }

int BinaryTree::treeSize(){
    return treeSizeHelper(root);
}

void BinaryTree::clearTree(){
    clearTreeHelper(root);
    root = nullptr;
}
void BinaryTree::setRoot(Node *newRoot)
{
    root = newRoot;
}



int main()
{
    BinaryTree tree;

    Node *rootNode = new Node('A');
    Node *nodeB = new Node('B');
    Node *nodeC = new Node('C');
    Node *nodeD = new Node('D');
    Node *nodeE = new Node('E');

    rootNode->left = nodeB;
    rootNode->right = nodeC;
    nodeB->left = nodeD;
    nodeB->right = nodeE;

    tree.setRoot(rootNode);

    tree.preorder();

    tree.inorder();

    tree.postorder();

    cout << tree.treeSize() << endl;

    tree.clearTree();

    cout << tree.treeSize() << endl;

    return 0;
}