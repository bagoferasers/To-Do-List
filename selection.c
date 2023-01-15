#include <stdio.h>
#include <stdlib.h>
#include "selection.h"
#include "taskNode.h"

void showAllTasks( ) 
{
    //show all tasks
    printNodes( 0 );
    //while selection
    int selection = -1;
    while( selection != 0 ) 
    {
        printf( "1 - Select task.\n" );
        printf( "0 - Go back.\n" );
        printf("--------------------------------\n");
        printf("Select number : ");

        scanf( "%d", &selection );

        switch( selection ) 
        {
            case 1:
                selectTask( );
                break;
            case 0:
                printf("\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
        }
    }
}

void selectTask( ) 
{
    printf("Which task would you like to see?\n");
    int selectedTask = -1;
    scanf("%d", &selectedTask);
    printf("\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n");
    printf("%s ( priority %d ) is due %s%s\n %dh %dm\n\n", tasks[selectedTask].name, tasks[selectedTask].priority, 
            tasks[selectedTask].dateDue, tasks[selectedTask].description, tasks[selectedTask].timeInHours, tasks[selectedTask].timeInMinutes );

    int selection = -1;
    while(selection != 0)
    {
        printf("1 - Complete task.\n");
        printf("0 - Go back.\n");

        scanf( "%d", &selection );

        switch( selection ) 
        {
            case 1:
                completeTask( selectedTask );
                break;
            case 0:
                printf("\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n");
                printNodes( 0 );
                printf("\n");
        }
    }
}

int i = 0;
void completeTask( int selectedTask ) 
{
    while( i < count )
    {
        if( i == selectedTask )
            break;
        i++;
    }
    printf("i == selected task\n%d == %d\n", i, selectedTask);
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
    FILE* f = fopen("data.csv", "r+");
    char* buffer = ( char* )malloc( sizeof( char ) );
    fgets( buffer, 1000, f );
    fprintf(f,"%d, %d, %d, %s, %s, %s\n", taskToAdd.priority, taskToAdd.timeInMinutes, taskToAdd.timeInHours,
        taskToAdd.name, taskToAdd.description, taskToAdd.dateDue);
    fclose(f);
    free(buffer);
}