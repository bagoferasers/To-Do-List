#include "taskNode.h"
#include "heapsort.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/*
    printNodes function recursively prints out the different taskNodes.
    @param j : The starting index.
*/
void printNodes( )
{
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
void swap( int a, int b )
{
    struct taskNode t = tasks[a];
    tasks[a] = tasks[b];
    tasks[b] = t;
}

/*
    deleteNode function deletes a taskNode from list of tasks.
    @param j : index of taskNode to be deleted.
*/
void deleteNode( int j )
{
    while( j < count)
    {
        tasks[j] = tasks[j+1];
        j++;
    }
    count--;
}

/*
    addTask function asks the user to input values into taskNode struct and 
    adding that struct to the list of tasks.
*/
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

    insertNode( buildNode( priority, timeInMinutes, timeInHours, name, description, dateDue ) );
}

void writeToFile( FILE* fW, int j )
{
    if( j >= count )
        return;
    fprintf(fW, "\n%d,%d,%d,%s,%s,%s", tasks[j].priority, tasks[j].timeInMinutes, tasks[j].timeInHours, tasks[j].name, tasks[j].description, tasks[j].dateDue);
    j++;
    writeToFile( fW, j );
}