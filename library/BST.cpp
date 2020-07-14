#include<bits/stdc++.h>
using namespace std;

template<typename T>
class BST {
    class Node {
        public:
        T val;
        Node *left, *right;

        Node(T _val): val(_val), left(nullptr), right(nullptr) {}
    };

    Node* tree_root;

    void inorder_helper(Node* root) {
        if (root) {
            inorder_helper(root->left);
            cout << root->val << " ";
            inorder_helper(root->right);
        }
    }

    Node* insert_helper(Node* node, T key) {
        if (!node) return new Node(key);
        if (key < node->val)
            node->left = insert_helper(node->left, key);
        else
            node->right = insert_helper(node->right, key);
        return node;
    }  

    Node* minValueNode(Node* node) {
        Node* current = node;
        while(current && current->left)
            current = current->left;
        return current;
    }

    Node* deleteNode_helper(Node* root, T key) {
        if (!root) return root;
        
        if (key < root->val)
            root->left = deleteNode_helper(root->left, key);
        else if (key > root->val)
            root->right = deleteNode_helper(root->right, key);
        else {
            if (!root->left) 
                return root->right;
            else if (!root->right)
                return root->left;
            Node* temp = minValueNode(root->right);
            root->val = temp->val;
            root->right = deleteNode_helper(root->right, temp->val);
        }
        return root;
    }

    public:
    BST() { }   

    void inorder() {
        inorder_helper(tree_root);
    }
    
    void insert (T key) {
        tree_root = insert_helper(tree_root, key);
    }

    void deleteNode(T key) {
        tree_root = deleteNode_helper(tree_root, key);
    }
};

int main() {
    BST<int> *my_bst = new BST<int>();
    my_bst->insert(10);
    my_bst->insert(50); 
    my_bst->insert(30); 
    my_bst->insert(20); 
    my_bst->insert(40); 
    my_bst->insert(70); 
    my_bst->insert(60); 
    my_bst->insert(80);

    my_bst->inorder();
    cout << endl;

    my_bst->deleteNode(50);
    
    my_bst->inorder();

    return 0;
}