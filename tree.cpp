#include "tree.h"
    // ========== Private Helpers ==========
// Rotates right (Stepik 5.1.1)
Play* AVLTree::rotateRight(Play* node){
    Play* root = node->left;
    node->left = node->left->right;
    root->right = node;
    if(node == this->root)
        this->root = root;
    return root;
}
// Rotates left (Stepik 5.1.1)
Play* AVLTree::rotateLeft(Play* node){
    Play* root = node->right;
    node->right = node->right->left;
    root->left = node;
    if(node == this->root)
        this->root = root;
    return root;
}
// Returns the inorder successor to be removed (Smallest value in right subtree)
Play* AVLTree::getSuccessor(Play* root) {
    Play* curr = root;
    while(curr && curr->left) {
        curr = curr->left;
    }
    return curr;
}
// Returns vector of inorder traversal of student nodes
void AVLTree::fillInorderVec(Play* root) {
    if(root->left != nullptr) {
        fillInorderVec(root->left);
    }
    this->vec.push_back(root);
    if(root->right != nullptr) {
        fillInorderVec(root->right);
    }
}

 // ========== Public Functions ==========
// Inserts student object into tree and rotates if needed
Play* AVLTree::insert(Play* root, Play* toInsert){
    float currInfluence = toInsert->getInfluence();
    // Standard BST Insertion (Stepik 4.3.2)
    if(searchID(this->getRoot(), currInfluence))
        return nullptr;
    if(root == nullptr) {
        root = toInsert;
        if(this->root == nullptr)
            this->root = root;
    }
    else if(currInfluence < root->getInfluence()) {
        root->left = insert(root->left, toInsert);
    }
    else if(currInfluence > root->getInfluence()) {
        root->right = insert(root->right, toInsert);
    }
    // Set root's bf using helper function
    root->setBF();
    // Check 4 cases and perform rotations
    if(root->bf > 1 && currInfluence < root->left->getInfluence())    // LL
        return rotateRight(root);
    if(root->bf < -1 && currInfluence > root->right->getInfluence())  // RR
        return rotateLeft(root);
    if(root->bf > 1 && currInfluence > root->left->getInfluence()) {  // LR
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }
    if(root->bf < -1 && currInfluence < root->right->getInfluence()) { // RL
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }
    return root;
}

// Traversals
std::string AVLTree::printInorder(Play* root, std::string s) {
    if(root->left != nullptr) {
        s = printInorder(root->left, s);
    }
    s += to_string(root->getInfluence()) + " " + root->getDescription() + "\n";
    if(root->right != nullptr) {
        s = printInorder(root->right, s);
    }
    return s;
}


// Searches for student with given influence
Play* AVLTree::searchID(Play* root, int key) {
    if(!root)
        return nullptr;
    if(key == root->getInfluence()) {
        return root;
    }
    // Go left
    if(key < root->getInfluence() && root->left != nullptr)
        return searchID(root->left, key);
    // Go right
    if(key > root->getInfluence() && root->right != nullptr)
        return searchID(root->right, key);
    return nullptr;
}