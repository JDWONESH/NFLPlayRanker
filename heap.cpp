#include "heap.h"

Heap::Heap()
{
    size = 0;
}

Play* Heap::top()
{
    return playHeap[0];
}

void Heap::insert(Play* play)
{
    int child = size;
    int parent = (child - 1) / 2;
    playHeap[child] =  play;
    size++;
    while (parent >= 0 && (playHeap[child]->getInfluence() > playHeap[parent]->getInfluence()))
    {
        Play* temp = playHeap[parent];
        playHeap[parent] = playHeap[child];
        playHeap[child] = temp;
        child = parent;
        parent = (child - 1) / 2;
    }
}

void Heap::remove()
{
   size--;
   if (size > 0)
   {
       int parent = 0; 
       int child = 1;
       playHeap[parent] = playHeap[size];
       while (child < size)
       {
           if (child + 1 != size)
           {
               if (playHeap[child + 1]->getInfluence() > playHeap[child]->getInfluence())
               {
                   child++;
               }
               if (playHeap[child]->getInfluence() > playHeap[parent]->getInfluence())
               {
                   Play* temp = playHeap[parent];
                   playHeap[parent] = playHeap[child];
                   playHeap[child] = temp;
                   parent = child;
                   child = (2 * parent) + 1;
               }
               else
               {
                   break;
               }
           }
           else
           {
               if (playHeap[child]->getInfluence() > playHeap[parent]->getInfluence())
               {
                   Play* temp = playHeap[parent];
                   playHeap[parent] = playHeap[child];
                   playHeap[child] = temp;
                   parent = child;
                   child = (2 * parent) + 1;
               }
               else
               {
                   break;
               }
           }
       }
   }
}