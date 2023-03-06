#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct studentNode {
  char name[20] ;
  int age ;
  char sex ;
  float gpa ;
  struct studentNode *next ;
} ;

void ShowAll( struct studentNode **walk ) ;
void InsNode( struct studentNode **walk, const char *name,int age, char sex, float gpa ) ;
void GoNext( struct studentNode ***walk ) ;
void DelNode( struct studentNode **walk ) ;

int main() {
  struct studentNode *start, **now ;
  start = NULL ; now = &start ;
  InsNode( now, "one", 6, 'M', 3.11 ) ; ShowAll( &start ) ;
  InsNode( now, "two", 8, 'F', 3.22 ) ; ShowAll( &start ) ;
  GoNext( &now ) ;
  InsNode( now, "three", 10, 'M', 3.33 ) ; ShowAll( &start ) ;
  InsNode( now, "four", 12, 'F', 3.44 ) ; ShowAll( &start ) ;
  GoNext( &now ) ;
  DelNode( now ) ; ShowAll( &start ) ;
  return 0 ;
} // End main()

void ShowAll( struct studentNode **walk ) {
  while(*walk != NULL) { 
    printf( "%s ", (*walk)->name );
    walk = &(*walk)->next ;
  }
  printf( " " ) ;
} // End ShowAll()

void InsNode( struct studentNode **walk, const char *name,int age, char sex, float gpa ) {
  struct studentNode *newNode = ( struct studentNode * )malloc( sizeof( struct studentNode ) ); 
  strcpy( newNode->name, name ) ;
  newNode->age = age ;
  newNode->sex = sex ;
  newNode->gpa = gpa ;
  newNode->next = *walk ;
  *walk = newNode ;
} // End InsNode()

void GoNext( struct studentNode ***walk ) {
	if ( (**walk) ->next != NULL) *walk = &(**walk)->next ;
} // End GoNext()

void DelNode( struct studentNode **walk ) {
  struct studentNode *current, *temp ;
  current = *walk ;
  while( current->next != NULL ) {
    temp = current->next ;
    current->next = current->next->next ;
    free( temp ) ;
  }
} // End DelNode() 

