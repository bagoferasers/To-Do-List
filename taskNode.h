#ifndef _taskNode_h
#define _taskNode_h
#include "stdio.h"

extern int count;
extern struct taskNode* tasks;

struct taskNode
{
    int priority;
    int timeInMinutes;
    int timeInHours;
    char* name;
    char* description;
    char* dateDue;
} taskNode;

void insertNode( struct taskNode t );

struct taskNode buildNode( int p, int tM, int tH, char* n, char* d, char* dD );

void printNodes( );

void swap( int a, int b );

void deleteNode( int j );

void addTask( );

void writeToFile( FILE* fW, int j );

//void updateNode( struct taskNode s[ ], struct taskNode t );

#endif