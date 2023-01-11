#include "heapsort.h"
#include <ctype.h>
#include <stdio.h>

/*
    maxHeapify function used to maintain the max-heap property.
    After maxHeapify, subtree rooted at i is a max-heap.
    @param s : array of taskNode structures.
    @param i: subtree rooted at i.
*/
void maxHeapify( struct taskNode* s, int i )
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;
    // if left child is largest, set as largest
    if( left < sizeof(s) && s[ left ].priority > s[ largest ].priority ) {
        largest = left;
    }
    // if right child is largest, set as largest
    if( right < sizeof(s) && s[ right ].priority > s[ largest ].priority ) {
        largest = right;
    }
    // if largest isn't i, exchange root with i and maxHeapify
    if( largest != i ) {
        struct taskNode temp;
        temp = s[ i ];
        s[ i ] = s[ largest ];
        s[ largest ] = temp;
        maxHeapify( s, largest );
    }
}

/*
    buildMaxHeap function takes an unordered array and produces
    a max-heap of n elements in s.
    @param s : array of taskNode structures.
    @param n : size of heap.
*/
void buildMaxHeap( struct taskNode* s, int n ) 
{
    n = sizeof( s );
    int last = ( n / 2 ) - 1;
    for( int i = last; i >= 0; i-- ) {
        maxHeapify( s, i );
    }
}

/* 
    heapSort function builds a max-heap from the array. It then
    starts with the root and places the maximum element in the correct
    place by swapping the last element in the array. Then it discards the
    last node ( being in the correct place ) and calls upon the 
    maxHeapify( ) on the new root. Repeats this process until only one node
    is left. 
    @param s : array of taskNode structures.
    @param n : size of heap.
*/
void heapSort( struct taskNode* s, int n ) 
{
    buildMaxHeap( s, n );
    for( int i = n / 2 - 1; i >= 0; i-- ) 
    {
        struct taskNode temp;
        temp = s[ i ];
        s[ i ] = s[ 0 ];
        s[ 0 ] = temp;
        maxHeapify( s, i );
    }
}

/*
    insertNode function inserts a taskNode into the heap.
    @param s : array of taskNode structures.
    @param t : taskNode to be inserted.
*/
void insertNode( struct taskNode* s, struct taskNode t ) 
{
    //check to see how many tasks are in s
    int j = 0;
    while( s[ j ].dateDue != NULL && isalpha( s[ j ].name[0] ) )
        j++;
    //insert node at position after j
    s[ j ] = t;
}

/*
    buildNode function takes in variables for a taskNode object and
    returns the built node.
    @param s : array of taskNode structures.
    @param p : priority.
    @param tM : time in minutes.
    @param tH : time in hours.
    @param n : name.
    @param d : description.
    @param dD : date due.
*/
struct taskNode buildNode( int p, int tM, int tH, char* n, char* d, char* dD ) 
{
    struct taskNode t;
    t.priority = p;
    t.timeInMinutes = tM;
    t.timeInHours = tH;
    t.name = n;
    t.description = d;
    t.dateDue = dD;
    return t;
}