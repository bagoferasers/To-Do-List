#include <stdio.h>
#include <stdlib.h>
#include "selection.h"
#include "taskNode.h"

void showAllTasks( ) 
{
    //show all tasks
    printf("\n");
    printNodes( 0 );
    printf("\n");
    //while selection
    int selection = -1;
    while( selection != 0 ) 
    {
        printf( "1 - Select task.\n" );
        printf( "0 - Go back.\n" );

        scanf( "%d", &selection );
        getchar( );

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
    getchar( );
    printf("\n%s ( priority %d ) is due %s\n", tasks[selectedTask].name, tasks[selectedTask].priority, tasks[selectedTask].dateDue);
    printf("%s\n", tasks[selectedTask].description);
    printf("%d h %d m\n\n", tasks[selectedTask].timeInHours, tasks[selectedTask].timeInMinutes);

    int selection = -1;
    while(selection != 0)
    {
        printf("1 - Complete task.\n");
        printf("0 - Go back.\n");

        scanf( "%d", &selection );
        getchar( );

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
}