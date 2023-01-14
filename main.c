#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "heapsort.h"
#include "taskNode.h"

int count = 0;
struct taskNode* tasks;

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
    fgets( line, 1000, f );
    while(fgets( line, 1000, f ) != NULL )
    {
        count++;
        printf("line %d - %s\n", count, line );
    }

    //else begin program
    printf("\nWelcome to TaskMachine3000Turbo!\n");
    printf("________________________________\n\n");
    printf("What would you like to do?\n");
    printf("1 - view tasks.\n");
    printf("2 - add task.\n\n");
    
    int selection = -1;
    scanf("%d", &selection);
    printf("\n\nselection = %d\n\n", selection);

    //need to find out how many tasks are in tasknode with input from csv
    //and replace "10" with the #
   
   
    tasks = ( struct taskNode* )malloc( 100 * sizeof( struct taskNode ) );
    
    struct taskNode t1 = buildNode( 1, 12, 12, "i", "x", "k" );
    insertNode( t1 );
    struct taskNode t2 = buildNode( 2, 12, 12, "i", "x", "k" );
    insertNode( t2 );
    struct taskNode t3 = buildNode( 3, 12, 12, "i", "x", "k" );
    insertNode( t3 );
    struct taskNode t4 = buildNode( 4, 12, 12, "i", "x", "k" );
    insertNode( t4 ); 
    struct taskNode t5 = buildNode( 2, 12, 12, "i", "x", "k" );
    insertNode( t5 );
    struct taskNode t6 = buildNode( 5, 12, 12, "i", "x", "k" );
    insertNode( t6 );
    struct taskNode t7 = buildNode( 7, 12, 12, "i", "x", "k" );
    insertNode( t7 );
    struct taskNode t8 = buildNode( 9, 12, 12, "i", "x", "k" );
    insertNode( t8 );
    struct taskNode t9 = buildNode( 1, 12, 12, "i", "x", "k" );
    insertNode( t9 );
    struct taskNode t10 = buildNode( 25, 12, 12, "i", "x", "k" );
    insertNode( t10 );

    printNodes( );
    heapSort( );
    printNodes( );

    //free memeory
    //freeNodes( &tasks );
    free( tasks );
    tasks = NULL;
    fclose( f );
    return 0;
}