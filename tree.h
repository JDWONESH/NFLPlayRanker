#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "play.h"

class AVLTree {
private:
    // Data
    Play* root;
    std::vector<Play*> vec;
    // Private helper functions
    Play* rotateRight(Play* node);
    Play* rotateLeft(Play* node);
    Play* getSuccessor(Play* root);
    void fillInorderVec(Play* root);
public:
    // Constructor
    AVLTree() : root(nullptr) {}
    // Public functions
    Play* getRoot() { return this->root; }
    Play* insert(Play* root, Play* toInsert);
    //Play* remove(Play* parent, int key);
    Play* searchID(Play* root, int key);
    //void searchName(Play* root, std::string key);
    std::string printInorder(Play* root, std::string s);
    //void printLevelCount(Play* root);
    //bool removeInorder(int pos); 
};