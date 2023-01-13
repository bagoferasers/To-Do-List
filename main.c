#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "heapsort.h"
#include "taskNode.h"

int main( ) 
{

    // find file path and open file
    FILE* f = fopen( "data.csv", "r+" );

    // if can't find file, output and return
    if( f == NULL ) 
    {
        printf( "Can't open file\n" );
        return -1;
    }

    //check to see how many tasks
    char line[1000];
    int count = 0;
    while(fgets( line, 1000, f ) != NULL )
    {
        count++;
        printf("line %d - %s\n", count, line );
    }

    //else begin program
    printf("Welcome to TaskMachine3000Turbo!\n");
    printf("________________________________\n\n");
    printf("What would you like to do?\n");
    printf("1 - view tasks.\n");
    printf("2 - add task.\n\n");
    
    int selection = -1;
    scanf("%d", &selection);
    printf("\n\nselection = %d\n\n", selection);

    //need to find out how many tasks are in tasknode with input from csv
    //and replace "10" with the #
    struct taskNode* tasks = ( struct taskNode* )malloc( 10 * sizeof( struct taskNode ) );
    printf("allocated memory for tasks array.\n");
    struct taskNode t1 = buildNode( 1, 12, 12, "i", "x", "k" );
    //printf("built node.\n");
    insertNode( &tasks, &t1 );
    //printf("inserted Node.\n");

    struct taskNode t2 = buildNode( 2, 12, 12, "i", "x", "k" );
    insertNode( &tasks, &t2 );

    struct taskNode t3 = buildNode( 3, 12, 12, "i", "x", "k" );
    insertNode( &tasks, &t3 );

    struct taskNode t4 = buildNode( 4, 12, 12, "i", "x", "k" );
    insertNode( &tasks, &t4 ); 

    struct taskNode t5 = buildNode( 2, 12, 12, "i", "x", "k" );
    insertNode( &tasks, &t5 );

    struct taskNode t6 = buildNode( 5, 12, 12, "i", "x", "k" );
    insertNode( &tasks, &t6 );

    struct taskNode t7 = buildNode( 7, 12, 12, "i", "x", "k" );
    insertNode( &tasks, &t7 );

    struct taskNode t8 = buildNode( 9, 12, 12, "i", "x", "k" );
    insertNode( &tasks, &t8 );

    printNodes( &tasks );
    printf("printNodes complete.\n");
    heapSort( &tasks, sizeof(tasks) );
    printf("heapsort complete.\n");
    printNodes( &tasks );

    //free memeory
    freeNodes( &tasks );
    free( &tasks );
    fclose( f );
    return 0;
}