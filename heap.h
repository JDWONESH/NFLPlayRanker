#pragma once
#include "play.h"
#include <iostream>
#include <string>

class Heap
{
    //Keeps track of the amount of plays in the heap
    int size;
    //Array to store all of the plays in
    Play* playHeap[449000];
    public:
    //Default constructor
    Heap();
    //Returns the current top ranked play
    Play* top();
    //Max heap insertion
    void insert(Play* play);
    //Max heap deletion
    void remove();
};