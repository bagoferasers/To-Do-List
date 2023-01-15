#include "taskNode.h"
#include "heapsort.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/*
    printNodes function recursively prints out the different taskNodes.
    @param j : The starting index.
*/
void printNodes( j )
{
    if( j >= count )
        return;
    printf("%d - %s ( priority %d ) is due %s\n", j, tasks[ j ].name, tasks[ j ].priority, tasks[ j ].dateDue );
    printNodes( ++j );
}
/*
    insertNode function inserts a taskNode into the heap.
    @param s : array of taskNode structures.
    @param t : taskNode to be inserted.
*/
void insertNode( struct taskNode t ) 
{
    tasks[ count++ ] = t;
    printf("%s\n", tasks[count-1].dateDue);
    if( count > 1 )
        heapSort( );
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

/*
    freeTaskObjects function recursively frees the memory allocated for 
    dateDue, description, and name within a taskNode.
    @param j : The starting index.
*/
void freeTaskObjects( int j )
{
    printf("freeing objects\n");
    printf("j = %d\n", j);
    printf("count = %d\n", count);
    if( j != count-1 )////////////////////// just count?????
        return;
    freeTaskObjects( j+1 );
    printf("freeing object\n");
    free(tasks[j].dateDue);
    free(tasks[j].description);
    free(tasks[j].name);
}

void deleteNode( int j )
{
    free(tasks[j].dateDue);
    free(tasks[j].description);
    free(tasks[j].name);
    while( j < count-1)//////////// just count????
    {
        tasks[j] = tasks[j+1];
        j++;
    }
    count--;
}

void addTask( )
{
    printf("\nEnter name : ");
    char* name = (char*)malloc(sizeof(char));
    scanf(" %[^\n]%*c", name);

    printf("Enter date due ( DDMMYYYY ) : ");
    char* dateDue = (char*)malloc(sizeof(char));
    scanf(" %[^\n]%*c", dateDue);

    printf("Enter priority : ");
    int priority;
    scanf( " %d", &priority );

    printf("Enter time in hours : ");
    int timeInHours;
    scanf(" %d", &timeInHours);

    printf("Enter time in minutes : ");
    int timeInMinutes;
    scanf(" %d", &timeInMinutes);

    printf("Enter description : ");
    char* description = (char*)malloc(sizeof(char));
    scanf(" %[^\n]%*c", description);

    struct taskNode taskToAdd = buildNode( priority, timeInMinutes, timeInHours, name, description, dateDue );
    insertNode( taskToAdd );
    count++;
}