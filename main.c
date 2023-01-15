#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
//#include <stdbool.h>
//#include <time.h>
#include "heapsort.h"
#include "taskNode.h"
#include "selection.h"

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

    //need to find out how many tasks are in tasknode with input from csv
    //and replace "10" with the #
    tasks = ( struct taskNode* )malloc( 100 * sizeof( struct taskNode ) );

    //else begin program while loop
    int selection = -1;

    struct taskNode t1 = buildNode( 1, 12, 12, "Laundry", "This is the description me thinks", "01/25/2023" );
    insertNode( t1 );

    while( selection != 0 ) 
    {
        printf("________________________________\n");
        printf("--------------------------------\n");
        printf("Welcome to TaskMachine3000Turbo!\n");
        printf("--------------------------------\n");
        printf("1 - All tasks.\n");
        printf("2 - High priority.\n");
        printf("3 - Medium priority.\n");
        printf("4 - Low priority.\n");
        printf("5 - Add task.\n");
        printf("0 - Exit TaskMachine3000Turbo.\n");

        scanf(" %d", &selection);

        switch(selection) 
        {
            case 1:
                printf("\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
                showAllTasks( );
                break;
            case 2:
                printf("you selected 2\n");
                break;
            case 3:
                printf("you selected 3\n");
                break;
            case 4:
                printf("you selected 4\n");
                break;
            case 5:
                printf("\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
                addTask( );
                break;
            case 6:
                printf("you selected 6\n");
                break;
            case 0:
                printf("________________________________\n");
                printf("--------------------------------\n");
                printf("        <3 Goodbye! <3\n");
                printf("--------------------------------\n");
        }
    }
    //free memory in task objects
    free( tasks );
    tasks = NULL;
    fclose( f );
    return 0;
}