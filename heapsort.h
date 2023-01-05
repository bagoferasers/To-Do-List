#include "taskNode.h"
#ifndef heapsort
#define heapsort

void heapSort( struct taskNode s[ ], int i );
void maxHeapify( struct taskNode s[ ], int i );
void insertNode( struct taskNode s[ ], struct taskNode t );
void deleteNode( struct taskNode s[ ], struct taskNode t );
void updateNode( struct taskNode s[ ], struct taskNode t );

#endif