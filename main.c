/*
Name: Angela Shao
Date: 11/8/16
Lab 8, COEN 11L
*/

// Header File
#include "lab9.h"

// Declare and intialize global variables
struct node *array[26];


// Main Function
int main( int argc, char *argv[])
   {
    // Declare and initialize variables
    int doContinue = 1;
    int userInput;
    char inName[20], inNum[20];
    
    for( int i = 0; i < 26; i++ )
       {
        array[i] = NULL;
       }
    
    // read in preexisting data
    if( argc < 3 )
       {
        printf( "ERROR: program is missing a file name!\n" );
        return 1;
       }
    
    
    read_file( argv[1] );
      
    // print title
    printf( "Welcome to the COEN 11L Phone Book!\n" );
    printf( "===================================\n\n" );
       
     
    // implement menu system with while loop
    while( doContinue == 1 )
       {
        // print menu
        printf( "Would you like to:\n" );
        printf( "Create a new contact?                           enter 1\n" );
        printf( "Delect a contact?                               enter 2\n" );
        printf( "See your full contact list?                     enter 3\n" );
        printf( "See your contact list by letter?                enter 4\n" );
        printf( "See your full contact list in reverse order?    enter 5\n" );
        printf( "Save your contact list?                         enter 6\n" );
        printf( "See your binary save list?                      enter 7\n" );
        printf( "Save to your binary file?                       enter 8\n" );
        printf( "Quit?                                           enter 9\n\n" );
        
        
        // enter user choice
        printf( "Please enter your selection here: " );
        scanf( "%d", &userInput );
        printf("\n\n\n" );
        
        // switch for user input
        switch ( userInput )
           {
            // Create a new contact
            case 1:
               
               // input name
               printf( "You have chosen to input a new contact.\n\n" );
               printf( "Please enter the new name: " );
               scanf( "%s", inName );
               printf( "Please enter %s's number: ", inName );
               scanf( "%s", inNum );
    
               // convert string to lower case
               for( int i = 0; i < strlen(inName); i++ )
                  {
                   inName[i] = tolower( inName[i] );
                  }
      
               insert( inName, inNum );
               break;
               
            // Delete a contact
            case 2:
               delete();
               break;
            
            // Print full Phone Book
            case 3:
               show();
               break;
               
            // Print Phone Book by letter
            case 4:
               show_letters();
               break;
               
            case 5:
               showRecursive( array );
               break;
               
            // Save Phone Book
            case 6:
               printf( "You have chosen to save. Your previous file will be overwritten.\n" );
               save_file( argv[1] );
               printf( "Save sucessful!\n\n" );
               
               break;

            // Print binary file
            case 7:
               printf( "You have chosen to print your binary file.\n" );
               show_binary( argv[2] );
                   
               break;
            
            // Save Phone Book (binary)
            case 8:
               printf( "You have chosen to save to your binary file. Your previous file will be overwritten.\n" );
               save_binary( argv[2] );
               printf( "Save sucessful!\n\n" );
                   
               break;
                   
            // Quit
            case 9:
               printf( "You have chosen to quit.\nHave a good day! \n\n" );
               save_file( argv[1] );
               save_binary( argv[2] );
               doContinue = 0;

               break;
                 
            // Error
            default:
               printf( "ERROR: incorrect input. Please re-enter your selection.\n\n\n" );
               break;
           }
       }
    
    //end program
    return 0;
   }


