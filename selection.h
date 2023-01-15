#ifndef _selection_h
#define _selection_h

extern int count;
extern struct taskNode* tasks;

void showAllTasks( );

void selectTask( );

void completeTask( int selection );

#endif