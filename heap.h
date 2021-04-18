#pragma once
#include "play.h"
#include <iostream>
#include <string>

class Heap
{
    int size;
    Play* playHeap[415000];
    public:
    Heap();
    Play* top();
    void insert(Play* play);
    void remove();
};