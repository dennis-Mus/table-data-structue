//-----------------------------------------
// Aurthor: Dennis Musanje
//
// REMARKS: Testing frame work for table
//
//-----------------------------------------


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "table.h"

// FUNCTION PROTOTYPES
void testInsertItem();
void testRemoveItem();
void testclearTable();
void testSearch();
void testFirstItem();
void testTraversal_Size();
void testnextItem();
void testnextItem();

//Testing Vars
static int testsPased = 0;
static int testsFailed = 0;



int main(int argc, const char * argv[]) {
    
    printf("Testing framework for the table! \n");
    testInsertItem();
    testRemoveItem();
    testclearTable();
    testSearch();
    testFirstItem();
    testnextItem();
    testTraversal_Size();
    
    printf("\nTotal tests passed: %d \n",testsPased);
    printf("Total tests failed: %d \n",testsFailed);
    
    return EXIT_SUCCESS;
}

//***************************************************************************
// testInsertItem
//
//Checks to ensure that the insertItem method has the expected return
//when int items are inserted and also when duplicate items are inserted.
//***************************************************************************
void testInsertItem(){
    
    printf( "\n\t\tTesting insertItem \n" );
    
    Boolean expected = false;
    int numFailed = 0;
    
    //TEST1 inserting items
    for( int i = 0; i < 10; i++ )
    {

       expected = insertItem(i*2);
        if( expected == false )
        {
            numFailed++;
        }
    }
    if(numFailed == 0 )
    {
        printf("Test 1: inserting items - passed\n");
        testsPased++;
    }
    else
    {
        printf("Test 1: inserting items - failed %d times \n",numFailed);
        testsFailed++;
    }
    numFailed = 0;
    
    
    //TEST2 inserting Duplicate items
    for( int i = 0; i < 10; i++ )
    {
        expected = insertItem(i*2);
        if( expected == true )
        {
            numFailed++;
        }
    }
    if( 0 == numFailed )
    {
        printf("Test 2: inserting duplicate items - passed\n");
        testsPased++;
    }
    else
    {
        printf("Test 2: inserting duplicate items - failed %d times \n",numFailed);
        testsFailed++;
    }
    numFailed = 0;
    
    //End of InsertTest
    clearTable();

}



void testRemoveItem()
{
    printf( "\n\t\tTesting RemoveItem \n" );
    
    Boolean inserted = false;
    Boolean expected;
    int numFailed = 0;
    for( int i = 0; i < 10; i++ )
    {
        inserted = insertItem(i*2);
    }
    
    //TEST1 try removing integer that is not in the table
    expected = removeItem(1);
    if(expected == true)
    {
        printf("Test 1: removing integer that is not in the table - failed \n");
        testsFailed++;
    }
    else
    {
        printf("Test 1: removing integer that is not in the table - passed \n");
        testsPased++;
    }
    
    //TEST2 removing inserted items
    for( int i = 0; i < 10; i++ )
    {
        expected = removeItem(i*2);
        if( expected == false )
        {
            numFailed++;
        }
    }
    if( 0 == numFailed)
    {
        printf("Test 2: removing integers that are in the table - passed\n");
        testsPased++;
    }
    else
    {
        printf("Test 2: removing integers that are in the table - failed %d times \n",numFailed);
        testsFailed++;
        
    }
    numFailed =0;
    clearTable();
    
    //TEST3 removing int from empty table
    expected = removeItem(4);
    if(expected == true)
    {
        printf("Test 3: removing integer from empty table - failed \n");
        testsFailed++;
    }
    else
    {
        printf("Test 3: removing integers from empty table - passed \n");
        testsPased++;
    }
    
    
    //TEST4 attempt to removing the same item twice
    inserted = insertItem(5);
    expected = removeItem(5);
    expected = removeItem(5);
    if(expected == true)
    {
        printf("Test 4: attempt to removing the same item twice - failed \n");
        testsFailed++;
    }
    else
    {
        printf("Test 4: attempt to removing the same item twice - passed \n");
        testsPased++;
    }
    clearTable();
    
}


void testclearTable()
{
    printf( "\n\t\tTesting clearTable \n" );
    //ensure the list is empty
    clearTable();
    Boolean inserted;
    Boolean expected;
    
    int numFAILED = 0;
    
    //TEST1 clear a table with odd numbers
    //insert odd numbers
    for( int i = 0; i < 10; i++ )
    {
        inserted = insertItem(i+2);
    }
    clearTable();
    
    for( int i = 0; i < 10; i++ )
    {
        expected = search(i+2);
        if(expected == true)
        {
            numFAILED++;
        }
    }
    
    if(numFAILED == 0)
    {
        printf("Test 1: clear a table with odd numbers - passed \n");
        testsPased++;
    }
    else
    {
        printf("Test 1: clear a table with odd numbers - failed %d times \n",numFAILED);
        testsFailed++;
    }
    
    //TEST2 empty a table with one element
    inserted = insertItem(3);
    clearTable();
    expected = search(3);
    if(expected == true)
    {
        printf("Test 2: empty a table with one element - failed \n");
        testsFailed++;
    }
    else
    {
        printf("Test 2: empty a table with one element - passed \n");
        testsPased++;
    }
}

void testSearch()
{
    printf( "\n\t\tTesting testSearch \n" );
    Boolean inserted;
    Boolean expected;
    int numFAILED = 0;
    clearTable();
    
    //insert odd numbers
    for( int i = 0; i < 10; i++ )
    {
        inserted = insertItem(i+2);
    }
    
    //TEST1 search for elements in the table
    for( int i = 0; i < 10; i++ )
    {
        expected = search(i+2);
        if(expected == false)
        {
            numFAILED++;
        }
    }
    
    
    if(numFAILED == 0)
    {
        printf("Test 1: search for elements in the table - passed \n");
        testsPased++;
    }
    else
    {
        printf("Test 1: search for elements in the table- failed %d times \n",numFAILED);
        testsFailed++;
    }
    clearTable();
    
    //TEST2 searching empty table
    expected = search(6);
    if(expected == true)
    {
        printf("Test 2: searching empty table - failed \n");
        testsFailed++;
    }
    else
    {
        printf("Test 2: searching empty table - passed \n");
        testsPased++;
    }
    
    //TEST3 searching for elements not in the table
    clearTable(); //ensure that the table is empty
    for( int i = 0; i < 10; i++ )
    {
        inserted = insertItem(i+2);
    }
    
    expected = search(13);
    if(expected == true)
    {
        printf("Test 3: searching for elements not in the table - failed \n");
        testsFailed++;
    }
    else
    {
        printf("Test 3: searching for elements not in the table - passed \n");
        testsPased++;
    }
}

void testFirstItem()
{
    
    
    printf( "\n\t\tTesting FirstItem \n" );
    Boolean expected;
    Boolean inserted;
    
    //TEST1 check if insert item returns right number
    inserted = insertItem(5);
    int first = 5;
    expected =  firstItem(&first);
    if(expected == false)
    {
        printf("Test 1: check if insert item returns right number - failed \n");
        testsFailed++;
    }
    else
    {
        printf("Test 1: check if insert item returns right number - passed \n");
        testsPased++;
    }
    
    clearTable();
    
    //TEST2 try  first item from empty table
    expected = firstItem(&first);
    if(expected == true)
    {
        printf("Test 1: try get first item from empty table - failed \n");
        testsFailed++;
    }
    else
    {
        printf("Test 1: try get first item from empty table - passed \n");
        testsPased++;
    }
    clearTable();
    
    
    //TEST3 try to check first item twice, must retrun the same true twice
    for( int i = 0; i < 5; i++ )
    {
        expected = insertItem(i);
    }
    int item;
    expected = firstItem(&item);
    expected = firstItem(&item);

    if(item != 0)
    {
        printf("Test 3:try to check first item twice, must retrun the same value- failed \n");
        testsFailed++;
    }
    else
    {
        printf("Test 3: try to check first item twice, must retrun the same value - passed \n");
        testsPased++;
    }
    clearTable();

}

void testnextItem()
{
    printf( "\n\t\tTesting nextItem \n" );

    Boolean inserted;
    
    //Test 1: next int assigns value all the way to the end of the table
    int size = 5;
    for( int i = 0; i < size; i++ )
    {
        inserted = insertItem(i);
    }
    int counter = 0;
    int nextInt;
    
    if(firstItem(&nextInt))
    {
        counter++;
        while(nextItem(&nextInt))
        {
        counter++;
        }
    }
    
    if(counter != size)
    {
        printf("Test 1: next int assigns value all the way to the end of the table - failed \n");
        testsFailed++;
    }
    else
    {
        printf("Test 1: next int assigns value all the way to the end of the table - passed \n");
        testsPased++;
    }
    clearTable();
    
}
    



void testTraversal_Size()
{
    printf( "\n\t\tTesting traversal \n" );

    //Testing table traversal
    clearTable();
    Boolean inserted;
    int value;
    int size =5;
    for( int i = 0; i < size; i++ )
    {
        inserted = insertItem(i);
    }
    int count = 0;
    int expected = 0;
    
    if ( firstItem( &value ) )
    {
        do
        {
            if(value != expected)
            {
                printf("Testing table traversal - failed  expected %d and got %d \n",expected,value);
                testsFailed++;
            }
            else
            {
                printf("Testing table traversal - passed expected %d and got %d \n",expected,value);
                testsPased++;
            }
            count++;
            expected++;
        } while ( nextItem( &value ) );
    }
    
    printf( "\n\t\tTesting size \n" );

    if( count < 5 )
    {
        printf("Testing table size - failed  expected %d and got %d \n",size,count);
        testsFailed++;
    }
    else
    {
        printf("Testing table size - passed expected %d and got %d \n",size,count);
        testsPased++;
    }
    
}


