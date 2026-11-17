#include <iostream>
using namespace std;

class Node
{
public:
    char data;   // the value stored in this node
    Node *left;  // pointer to the left child (nullptr if none)
    Node *right; // pointer to the right child (nullptr if none)
    Node(char value)
    {
        data = value;
        left = nullptr; // a new node starts with no children
        right = nullptr;
    }
};
class BinaryTree
{
private:
    Node *tree;
    // private recursive helpers
    void preorderHelper(Node *node)
    {
        // node left right
        if (node == nullptr)
        {
            return;
        }
        cout << node->data << " ";
        preorderHelper(node->left);
        preorderHelper(node->right);
    }

    void inorderHelper(Node *node)
    {
        // left node right
        if (node == nullptr)
        {
            return;
        }
        inorderHelper(node->left);
        cout << node->data << " ";
        inorderHelper(node->right);
    }
    void postorderHelper(Node *node)
    {
        // left right node
        if (node == nullptr)
            return;
        postorderHelper(node->left);
        postorderHelper(node->right);
        cout << node->data << " ";
    }
    // Double order Q4: node, left, node , right
    void doubleOrderHelper(Node *node)
    {
        if (node == nullptr)
            return;
        cout << node->data << " ";
        doubleOrderHelper(node->left);
        cout << node->data << " ";
        doubleOrderHelper(node->right);
    }

    // i have used preorder, this can be any type of standard travesal
    Node *findNode(Node *current, char value)
    {
        if (current == nullptr)
            return nullptr;
        if (current->data == value)
            return current;

        Node *leftSearch = findNode(current->left, value);
        if (leftSearch != nullptr)
            return leftSearch; // found on the left

        return findNode(current->right, value); // if not on left then either on right, or return nullptr
    }

public:
    BinaryTree()
    {
        tree = nullptr; // empty tree
    }
    // Traverse the tree in preorder traversal method
    void preorder()
    {
        preorderHelper(tree);
    }
    // traverse the tree in Inorder Traversal method
    void inorder()
    {
        inorderHelper(tree);
    }
    // traverse the tree in Postorder Traversal method
    void postorder()
    {
        postorderHelper(tree);
    }
    // int treeSize();
    // void clearTree();
    // Question 4...
    void doubleOrder()
    {
        doubleOrderHelper(tree);
    }
    // Question 5...
    void insertNode(char parentValue, char toBeInsertedNode, char side)
    {

        // Empty tree
        if (tree == nullptr)
        {
            tree = new Node(toBeInsertedNode);
            cout << toBeInsertedNode << " inserted as  the root of tree." << endl;
            return;
        }

        // find parent
        Node *parent = findNode(tree, parentValue);
        if (parent == nullptr)
        {
            cout << "Parent " << parentValue << " was not found." << endl;
            return;
        }

        // connect on give side only if the space is free ( nullptr)
        if (side == 'L' || side == 'l')
        {
            if (parent->left != nullptr)
            {
                cout << parentValue << " node  already has a left child." << endl;
                return;
            }
            parent->left = new Node(toBeInsertedNode);
            cout << toBeInsertedNode << " node  inserted as left child of " << parentValue << "." << endl;
            return;
        }

        if (side == 'R' || side == 'r')
        {
            if (parent->right != nullptr)
            {
                cout << parentValue << " node already has a right child." << endl;
                return;
            }
            parent->right = new Node(toBeInsertedNode);
            cout << toBeInsertedNode << " node inserted as right child of " << parentValue << "." << endl;
            return;
        }

        cout << "Enter correct side either L,l or R,r" << endl;
    }
};
int main()
{
    BinaryTree tree;

    tree.insertNode('-', 'A', 'L'); // This is parent node so it has no
    tree.insertNode('A', 'B', 'L');
    tree.insertNode('A', 'C', 'R');
    tree.insertNode('B', 'D', 'L');
    tree.insertNode('B', 'E', 'R');
    tree.insertNode('C', 'F', 'L');
    tree.insertNode('C', 'G', 'R');

    cout << endl;
    cout << "Preorder:     ";
    tree.preorder();
    cout << endl;
    cout << "Inorder:      ";
    tree.inorder();
    cout << endl;
    cout << "Postorder:    ";
    tree.postorder();
    cout << endl;
    cout << "Double order: ";
    tree.doubleOrder();

    return 0;
}