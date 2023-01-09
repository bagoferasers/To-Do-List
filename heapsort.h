#ifndef _heapsort_h
#define _heapsort_h
#include "taskNode.h"

void heapSort( struct taskNode s[ ], int n );
void maxHeapify( struct taskNode s[ ], int i );
void buildMaxHeap( struct taskNode s[ ], int n );

void insertNode( struct taskNode s[ ], struct taskNode t );
struct taskNode buildNode( int p, int tM, int tH, char* n, char* d, char* dD );
//void deleteNode( struct taskNode s[ ], struct taskNode t );
//void updateNode( struct taskNode s[ ], struct taskNode t );

#endif