/*
====================================================
Author: Brandon West
Class: PROG 20025
Assignemnt 2: Fun with Sorting!
Date: Oct 19, 2018
Description: This program utilizes Insertion Sorting
             method where inserting the variable is
             sorted during the insertion process

====================================================
*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void insertionSort (FILE *filePtr, int inplaceInsertArray[], int inputSize );


int main()
{
  // variables 
  int inputSize = 0, counter = 1;

  // file pointers to look in the file specified and write to the file specified
  FILE *filePtr, *tempPtr;
  filePtr = fopen ("AlmostSorted.txt", "r" );
  FILE *newPtr;
  newPtr = fopen ( "InsertionSorted.txt", "w" );
  
  // variables to hold the max and min values of the insert sort
  int max = 0;
  int min = 0;
  // if the file fails to open closes filePtr and exits the program
  if( filePtr == NULL )
  {
    printf ( "Error opening file" );
    fclose(filePtr);
    exit(1);
  }
  
  // else the file is successful
  else
  {
    printf( "Enter inputSize: " );
    scanf ( "%d", &inputSize );
    // inputSize = 200000; // input siez
    int inplaceInsertArray[ inputSize ]; // array size
    counter = 1;
    // tracks time for the sort
    clock_t start = clock();
    // calls the insert sort method with filePtr, array and inputsize as arguments
    insertionSort ( filePtr, inplaceInsertArray, inputSize );
    // calculates the time taken from clock start to finish
    double timeElapsed = ( (double) clock () - start ) / CLOCKS_PER_SEC;
    printf ( "The %d run at %d is %2.f\n", counter, inputSize, timeElapsed );
    // writes sorted list to the file
    for ( int index = 0; index < inputSize; index++ )
    {
        fprintf ( newPtr, "%d\n", inplaceInsertArray [ index ] );
    }
  }// end of  else
  
  // clsoes both file pointers
  fclose ( filePtr );
  fclose ( newPtr );
  return 0;
}// end of main

// function to perform the insertion sort
void insertionSort (FILE *filePtr, int inplaceInsertArray[], int inputSize )
{
  // variables
  int temp1 = 0, counter = 0;

  // for loop to control insertion from file to inplaceInsertArray
  for (int index = 0; index < inputSize; index++)
  {
    //fscanf to input the information from the file into inplaceInsertArray
    fscanf ( filePtr, "%d", &inplaceInsertArray [ index ] );
    // holds the current index number
    temp1 = inplaceInsertArray [ index ];
    // counter checks the previous number
    counter = index - 1;

    // While counter is greater than or equal to 0 and, counters variable is bigger than indexs variable
    while ( counter >= 0 && inplaceInsertArray [ counter ] > temp1 )
    {
      // move the counter forward 1 spot and place the counter varaible there
      inplaceInsertArray[ counter + 1] = inplaceInsertArray [ counter ];
      // change the counter to the previous then check to see if its bigger
      counter = counter - 1;
    }
    // set the counter variable to temp1.
    inplaceInsertArray [ counter + 1  ] = temp1;
  }// end of for loop
} // end of insertionSort function
