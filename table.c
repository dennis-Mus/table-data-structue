//-----------------------------------------
// NAME: Dennis Musanje
//
// REMARKS: Implementation of Table using a linked list
//
//-----------------------------------------


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "table.h"


// Linked list node definition
typedef struct Node node;

struct Node
{
  int   number;
  node  *next;
};


//beginning of the odered list
static node *top = NULL;
 
// used to track where we are for the list traversal methods
static node *traverseNode = NULL;

static int numNodes = 0;

//***************************************************************************
// invariantChecker
//
// Ensure the list always ordered
//***************************************************************************
void invariantChecker()
{
    
    if(top == NULL)
    {
        assert(numNodes == 0);
    }
    
#ifndef NDEBUG
    node *curr = top;
    int counter = 0;
    node *prev;

#endif
    
    if ( numNodes == 0 )
    {
        assert( top == NULL );
    }
    else if ( numNodes == 1 )
    {
        assert( top->next == NULL );
    }
    else
    {
        assert( top != NULL && top->next != NULL );
    }
    
    
#ifndef NDEBUG
    
    //Confirming that the list is always ordered
    while (curr != NULL)
    {
        counter++;
        assert(curr != NULL);
        prev = curr;
        curr = curr->next;
        if(curr != NULL)
        {
            //also checks for duplicates
            assert(prev->number < curr->number);
        }
    }
    
    assert(numNodes == counter);
#endif
}


//***************************************************************************
// insertItem
//
// add an element to the table
// Return TRUE if the item is in the table
// Return FALSE if the item is *not* in the table
//***************************************************************************
Boolean insertItem( int item )
{
    invariantChecker();
    node *prev = NULL;
    node *curr = top;
    node *newNode = NULL;
    Boolean  result = search(item);// checks if item was found
    newNode = malloc( sizeof( node ) );
    
    assert(newNode);// checking that malloc actually allocated memory
    if(newNode){
        newNode->number = item;
        if(!result){
            while( (curr != NULL) && curr->number < item){
                assert( item > curr->number );
                prev = curr;
                curr = curr->next;
                
            }
            
            if(prev != NULL){
                newNode->next = curr;
                prev->next=newNode;
            }
            
            else{
                newNode->next = top;
                top = newNode;
            }
            numNodes++;
            invariantChecker();
            
            
        }
    }
    
    
    return !result;
}


//***************************************************************************
// removeItem
//
// removes the int from the table
// RETRUN TRUE if item is removed
// RETURN FALSE if the itme is not removed
//***************************************************************************
Boolean removeItem( int item )
{
    invariantChecker();

    Boolean removed =  false;
    Boolean exsist = search( item );
    node *curr;
    node *prev = NULL;
    
    if( exsist == true )
    {
        assert(search( item ) == true);
        curr = top;
        
        //Find the node to be removed;
        while( curr != NULL && curr->number != item )
        {
            prev = curr;
            curr = curr->next;
        }
        
        if(prev == NULL)
        {
            assert(curr);
            top = top->next;
        }
        else
        {
            prev->next = curr->next;
        }
        free( curr );
        removed = true;
        numNodes--;
    }
    
    invariantChecker();
    
    return removed;
}


//***************************************************************************
// clearTable
//
// empty the table so that we clear all memory and can start a fresh table
//***************************************************************************
void clearTable()
{
    
    invariantChecker();
    
    node *curr = top;
    node *temp = NULL;
    
    while ( curr != NULL )
    {
        // flip order to see it blow up...
        temp = curr;
        curr = curr->next;
        numNodes--;
        free( temp );
    }
    
    top = NULL;
    invariantChecker();
    
}


//***************************************************************************
// clearTable
//
// tells us whether or not the given item is in the table
// RETURN TRUE if item is in the table
// RETURN FALSE if item is not in the table
//***************************************************************************
Boolean search( int item )
{
    invariantChecker();

    node *curr = top;
    Boolean found = false;
    
    while ( curr != NULL && !found )
    {
        
        if(item == curr->number)
            found =true;
        
        curr = curr->next;
        
    }
    
    invariantChecker();
    
    return found;
}


//***************************************************************************
// firstItem
//
// starts a list traversal by getting the data at top.
// RETURN FALSE if top == NULL.
// RETURN TRUE  when item pointer is initalized
//***************************************************************************
Boolean firstItem( int * const item )
{
    invariantChecker();

    Boolean result = false;
    
    if ( top )
    {
        *item = top->number;
        
        traverseNode = top->next;
        
        result = true;
    }
    invariantChecker();
    
    return result;
}


//***************************************************************************
// nextItem
//
// gets the data at the current traversal node and increments the traversal.
// RETURN FALSE if we're at the end of the list.
// RETURN TRUE  when item pointer is given the next value
//***************************************************************************
Boolean nextItem( int * const item )
{
    invariantChecker();

    Boolean result = false;
    
    if ( traverseNode )
    {
        *item = traverseNode->number;
        
        traverseNode = traverseNode->next;
        
        result = true;
    }
    invariantChecker();
    
    return result;
}


