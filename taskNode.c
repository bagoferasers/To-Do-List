#include "taskNode.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/*
    printNodes function prints out the different taskNodes.
    @param tasks : taskNode* that stores all the taskNode
    structures.
*/
void printNodes( )
{
    printf( "\nLIST OF TASKS\n" );
    printf("________________________________\n\n");
    int j = 0;
    while( j < count )
    {
        printf("%d - %s ( priority %d ) is due %s\n", j, tasks[ j ].name, tasks[ j ].priority, tasks[ j ].dateDue );
        j++;
    }
        
}
/*
    insertNode function inserts a taskNode into the heap.
    @param s : array of taskNode structures.
    @param t : taskNode to be inserted.
*/
void insertNode( struct taskNode t ) 
{
    tasks[ count++ ] = t;
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

/*
    swap funtion swaps the position of the two taskNodes.
    @param a : taskNode to be swapped.
    @param b : taskNode to also be swapped. WOW!
*/
void swap( struct taskNode* a, struct taskNode* b )
{
    struct taskNode temp = *a;
    *a = *b;
    *b = temp;
}