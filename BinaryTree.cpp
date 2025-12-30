#include "../Leetcode/includer.hpp"

class Node
{
    public: 
        int key;
        Node* left; 
        Node* right; 
        Node* p; 
    
        Node(int x)
        {
            key = x; 
            left = nullptr; 
            right = nullptr; 
        }
}; 

class BinaryTree
{
    public: 
        Node* root = nullptr; 
        BinaryTree(Node* root_) : root(root_) {}

        void inorder(Node* x)
        {
            if(x != nullptr)
            {
                inorder(x->left); 
                std::cout << x->key << std::endl; 
                inorder(x->right); 
            }
        }
        void postorder(Node* x)
        {
            if(x != nullptr)
            {
                postorder(x->left); 
                postorder(x->right); 
                std::cout << x->key << std::endl; 
            }
        }
        void preorder(Node* x)
        {
            if(x != nullptr)
            {
                std::cout << x->key << std::endl; 
                preorder(x->left); 
                preorder(x->right); 
            }
        }

        void walk(int mode)
        {
            if(mode == -1)
            {
                std::cout << "=== INORDER TREE WALK ===" << std::endl; 
                inorder(root);
                printf("\n"); 
            }
            else if(mode == 0) 
            {
                std::cout << "=== POSTORDER TREE WALK ===" << std::endl; 
                postorder(root); 
                printf("\n");  
            }
            else if(mode == 1)
            {
                std::cout << "=== PREORDER TREE WALK ===" << std::endl; 
                preorder(root); 
                printf("\n"); 
            }
            else std::cerr << "Wrong input number for 'walk' call" << std::endl; 
        }

        bool search(Node* x, int toFind)
        {
            if(x != nullptr)
            {
                if(x->key == toFind)
                {
                    std::cout << "Number: " << toFind << " found!" << std::endl; 
                    return true; 
                }
                if(x->key < toFind)
                    return search(x->right, toFind); 
                else return search(x->left, toFind);
            }
            std::cout << "Number: " << toFind << " NOT found!" << std::endl; 
            return false; 
        }

        void maximum(Node* x)
        {
            if(x->right == nullptr)
                std::cout << "Maximum: " << x->key << std::endl << std::endl; 
            else maximum(x->right); 
        }
        void minimum(Node* x)
        {
            if(x->left == nullptr)
                std::cout << "Minimum: " << x->key << std::endl << std::endl; 
            else minimum(x->left); 
        }
        
        void tree_insert(BinaryTree T, Node* z)
        {
            Node* y = nullptr; 
            Node* x = T.root;
            if(x == nullptr)
            {
                T.root = z; 
                return; 
            }

            while(x != nullptr)
            {
                y = x; 
                if(z->key < x->key)
                    x = x->left; 
                else x = x->right; 
            }

            z->p = y; 
            if(z->key < y->key)
                y->left = z; 
            else y->right = z; 
        }
}; 

BinaryTree build_BST(vector<int>& A)
{
    Node* root = new Node(A[0]); 
    BinaryTree T1(root); 
    for(int i = 1; i < A.size(); ++i)
    {
        Node* newNode = new Node(A[i]); 
        T1.tree_insert(T1, newNode); 
    }
    return T1; 
}

int main()
{
    vector<int> A = {5, 4, 7, 2, 3, 8}; 
    BinaryTree T1 = build_BST(A); 
    T1.minimum(T1.root); 
    T1.maximum(T1.root); 
}