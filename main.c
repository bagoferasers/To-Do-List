#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include "heapsort.h"
#include "taskNode.h"
#include "selection.h"

int count = 0;
struct taskNode* tasks = NULL;

int main( ) 
{
    tasks = ( struct taskNode* )malloc( 100 * sizeof( struct taskNode ) );
    // find file path and open file
    FILE* f = fopen( "data.csv", "r" );

    // if can't find file, output and return
    if( f == NULL ) 
    {
        printf( "Can't open file\n" );
        return -1;
    }

    //check to see how many tasks
    char* buffer = ( char* )malloc( sizeof( char ) );
    fgets( buffer, 1000, f );
    while( !feof(f) && fgets( buffer, 1000, f ) != NULL && strcmp(buffer,"\n") != 0 )
    {
        int priority = atoi( strtok( buffer, ","));
        int timeInMinutes = atoi(strtok(NULL,","));
        int timeInHours = atoi(strtok(NULL, ","));
        char* name = strtok( NULL, "," );
        char* description = strtok( NULL, "," );
        char* dateDue = strtok( NULL, ";" );
        struct taskNode t = buildNode( priority, timeInMinutes, timeInHours, name, description, dateDue);
        insertNode( t );
    }
    printf("\n");
    fclose( f );
    //printNodes( 0 );
    //begin program while loop
    int selection = -1;

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
        printf("--------------------------------\n");
        printf("Select number : ");

        scanf("%d", &selection);

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
                printf("\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
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
    //write to file
    FILE* fW = fopen("data.csv", "w");
    fprintf(fW, "priority,timeInMinutes,timeInHours,name,description,dateDue");
    writeToFile( fW, 0 );
    fclose(fW);

    //free memory in task objects
    free(buffer);
    free( tasks );
    tasks = NULL;

    //end TaskMachine3000Turbo :(
    return 0;
}