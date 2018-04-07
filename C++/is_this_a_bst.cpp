/*
For the purposes of this challenge, we define a binary search tree to be a binary tree with the following ordering properties:

    1.The data value of every node in a node's left subtree is less than the data value of that node.
    2.The data value of every node in a node's right subtree is greater than the data value of that node.

Given the root node of a binary tree, can you determine if it's also a binary search tree?

Complete the function in your editor below, which has 1 parameter: a pointer to the root of a binary tree. It must return a boolean denoting whether or not the binary tree is a binary search tree. You may have to write one or more helper functions to complete this challenge.

Link: https://www.hackerrank.com/challenges/ctci-is-binary-search-tree/problem
*/


vector <int> nodes;

void traverseNodes(Node* root){
    if(root->left != NULL){
            traverseNodes(root->left);
    }
    nodes.push_back(root->data);
    if(root->right != NULL){
            traverseNodes(root->right);
    }
} 

bool checkBST(Node* root){
    traverseNodes(root);
    for(int i = 0; i < nodes.size()-1; i++){
        if(nodes[i] >= nodes[i+1]){
            return false;
        }
    } 
    return true;
}