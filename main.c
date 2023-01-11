#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include "heapsort.h"
#include <time.h>

int main( ) 
{

    for ( int loop = 0; loop < 1; ++loop ) {
        for ( int each = 0; each <= 3; ++each ) {
            printf ( "\rLOADING%.*s   \b\b\b", each, "..." );
            fflush ( stdout );//force printing as no newline in output
            sleep ( 1 );
        }
    }
    printf( "\n" );

    // find file path and open file
    FILE* f = fopen( "data.csv", "r+" );

    // if can't find file, output and return
    if( f == NULL ) 
    {
        printf( "Can't open file\n" );
        return -1;
    }

    //check to see how many tasks
    //int numTasks = 0;
    char line[1000];
    int count = 0;
    //fgets(line, 1000, f);
    //printf("header = %s\n", line);
    while(fgets( line, 1000, f ) != NULL )
    {
        count++;
        printf("line %d - %s\n", count, line );
    }

    // else begin program
    //need a repeat menu
    printf("\n\n\n\nWelcome to TaskMachine3000Turbo!\n");
    printf("________________________________\n\n");
    printf("What would you like to do?\n");
    printf("1 - view tasks.\n");
    printf("2 - add task.\n");
    printf("3 - remove task.\n\n");
    
    int selection = -1;
    scanf("%d", &selection);
    printf("\n\nselection = %d\n\n", selection);

    //need to find out how many tasks are in tasknode with input from csv
    //and replace "10" with the #
    struct taskNode* tasks = malloc( 10 * sizeof( struct taskNode ) );




    //free memeory
    free( tasks );
    fclose( f );
    return 0;
}