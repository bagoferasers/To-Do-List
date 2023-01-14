#ifndef _heapsort_h
#define _heapsort_h
#include "taskNode.h"

extern int count;
extern struct taskNode* tasks;

void heapSort( );
void maxHeapify( int i );
void buildMaxHeap( );

#endif