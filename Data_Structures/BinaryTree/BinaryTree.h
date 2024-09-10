#ifndef BINARYTREE_H
#define BINARYTREE_H


class BinaryTree{
    private:
        struct TreeNode{
            int value;
            TreeNode *left;
            TreeNode *right;
        };
        TreeNode *root;
        //Private member functions
        //Takes root node and new Node as argument
        void insert(TreeNode *&,TreeNode *&);
        void makeDeletion(TreeNode *&);   
        void deleteNode(int, TreeNode *&);
        void destroySubTree(TreeNode*);
        void destroy(int,TreeNode*);
        void displayPreOrder(TreeNode*) const;
        void displayInOrder(TreeNode*) const;
        void displayPostOrder(TreeNode*) const;
    public:
        //Constructor
        BinaryTree(){
            root = nullptr;
        }
        //Destructor
        ~BinaryTree(){
            destroySubTree(root);
        }
        void insertNode(int);
        bool searchNode(int);
        void displayInOrder() const{
            displayInOrder(root);
        }
        void displayPreOrder() const{
            displayPreOrder(root);
        }
        void displayPostOrder() const{
            displayPostOrder(root);
        }
        void remove(int num){
            deleteNode(num,root);
        }
        void deleteSubTree(int num){
            destroy(num,root);
        }
};

#endif