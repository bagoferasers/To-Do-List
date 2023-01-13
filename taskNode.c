#include "taskNode.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*
    printNodes function prints out the different taskNodes.
    @param tasks : taskNode* that stores all the taskNode
    structures.
*/
void printNodes( struct taskNode** s )
{
    printf( "LIST OF TASKS" );
    printf("________________________________\n\n");
    int j = 0;
    while( s[ j ] != NULL )
    {
        printf("%d - %s ( priority %d ) is due %s\n", j, s[ j ]->name, s[ j ]->priority, s[ j ]->dateDue );
        j++;
    }
        
}
/*
    insertNode function inserts a taskNode into the heap.
    @param s : array of taskNode structures.
    @param t : taskNode to be inserted.
*/
void insertNode( struct taskNode** s, struct taskNode* t ) 
{
    printf("entered insertNode.\n");
    int size = 0;
    while( size < sizeof(s) )
    {
        printf("entered while loop.\n");
        size++;
    }
    printf("size = %d\n", size);
    *s[ size ] = *t;
    printf("s[size]->priority = %d\n", s[size]->priority);
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
    freeNodes function frees the taskNodes within the array.
    @param s : array of taskNode structures.
*/
void freeNodes( struct taskNode** s ) 
{
    int size = sizeof(s);
    printf("entered freeNodes.\n");
    for(int i = 0; i < size; i++ )
    {
        free( &s[ i ] );
        printf("freed taskNode\n");
    }
}