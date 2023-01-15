#include "heapsort.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

/*
    maxHeapify function used to maintain the max-heap property.
    After maxHeapify, subtree rooted at i is a max-heap.
    @param s : array of taskNode structures.
    @param i: subtree rooted at i.
*/
void maxHeapify( int i )
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    // if left child is largest, set as largest
    if( ( left < count ) && ( tasks[ left ].priority > tasks[ largest ].priority ) ) 
        largest = left;
    // if right child is largest, set as largest
    if( ( right < count ) && ( tasks[ right ].priority > tasks[ largest ].priority ) ) 
        largest = right;
    // if largest isn't i, exchange root with i and maxHeapify
    if( largest != i ) 
    {
        swap( largest, i );
        maxHeapify( largest );
    }
}

/*
    buildMaxHeap function takes an unordered array and produces
    a max-heap of n elements in s.
    @param s : array of taskNode structures.
    @param n : size of heap.
*/
void buildMaxHeap( ) 
{
    for( int i = count / 2 - 1; i >= 0; i-- )
        maxHeapify( i );
}

/* 
    heapSort function builds a max-heap from the array. It then
    starts with the root and places the maximum element in the correct
    place by swapping the last element in the array. Then it discards the
    last node ( being in the correct place ) and calls upon the 
    maxHeapify( ) on the new root. Repeats this process until only one node
    is left. 
*/
void heapSort( ) 
{
    buildMaxHeap( );
    for( int i = count - 1; i >= 0; i-- ) 
    {
        swap( i, 0 );
        maxHeapify( i );
    }
}