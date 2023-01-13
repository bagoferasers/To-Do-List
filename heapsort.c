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
void maxHeapify( struct taskNode** s, int i )
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    // if left child is largest, set as largest
    if( ( left < sizeof(s) ) && ( s[ left ]->priority > s[ largest ]->priority ) ) 
        largest = left;
    // if right child is largest, set as largest
    if( ( right < sizeof(s) ) && ( s[ right ]->priority > s[ largest ]->priority ) ) 
        largest = right;
    // if largest isn't i, exchange root with i and maxHeapify
    if( largest != i ) 
    {
        printf("largest != i\n");
        printf("s[largest] = %d\n", s[largest]->priority);
        printf("s[i] = %d\n", s[i]->priority);
        swap( s[ largest ], s[ i ] );
        printf("s[largest] = %d\n", s[largest]->priority);
        printf("s[i] = %d\n", s[i]->priority);
        maxHeapify( s, i );
    }
}

/*
    buildMaxHeap function takes an unordered array and produces
    a max-heap of n elements in s.
    @param s : array of taskNode structures.
    @param n : size of heap.
*/
void buildMaxHeap( struct taskNode** s, int n ) 
{
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
void heapSort( struct taskNode** s, int n ) 
{
    printf("entered heapsort.\n");
    buildMaxHeap( s, n );
    for( int i = n - 1; i >= 0; i-- ) 
    {
        swap( s[ i ], s[ 0 ] );
        printf("done swapping.\n");
        maxHeapify( s, i );
    }
}

/*
    swap funtion swaps the position of the two taskNodes.
    @param a : taskNode to be swapped.
    @param b : taskNode to also be swapped. WOW!
*/
void swap( struct taskNode* a, struct taskNode* b )
{
    printf("entered swap.\n");
    struct taskNode temp = *a;
    *a = *b;
    *b = temp;
}