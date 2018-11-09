/*
===========================================================
Author: Brandon West
Class: PROG 20025
Assignemnt 2: Fun with Sorting!
Date: Oct 19, 2018
Description: This program utilizes the Heap Sorting method

===========================================================
*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stddef.h>

 // method prototypes
void maxHeapAdjust (int heapArray[], int index, int inputSize);
void buildMaxHeap ( int heapArray[], int inputSize );
void adjustHeap( int heapArray[], int inputSize );

int main()
{
 // varibales for user input size
  int inputSize = 0, counter = 1;
  FILE *filePtr; // for reading from the file
 
 // opens file pointer for specific text
  filePtr = fopen ("Reverse.txt", "r" );

  FILE *newPtr;// for wiriting to a new file
  newPtr = fopen ( "HeapSorted.txt", "w" );

  // if the files fail to open
  if( filePtr == NULL || newPtr == NULL )
  {
    printf ( "Error opening file or creating file" );
    fclose(filePtr);
    exit(1);
  } //end of failure
 
  // else if the file is successful
  else
  {
    // user input for input size
    printf ( "Please enter an input size: " );
    scanf ( "%d", &inputSize );
    // initalize array with size of input from user
    int heapArray [ inputSize ];

    // for loop to add the numbers to the array from filePtr
    for (int index= 0; index < inputSize; index++)
    {
      fscanf ( filePtr, "%d", &heapArray [ index ] );
    }

    // time counter to clock how long the heap build, sort takes
    clock_t start = clock();
    // heap sort method
    adjustHeap(heapArray, inputSize);
   // calucation for how long the sort took
    double timeElapsed = ((double)clock() - start) / CLOCKS_PER_SEC;
    printf ( "Sort time: %.4f\n", timeElapsed );

    // writes to the file "HeapSorted" through the newPtr
    for (int index = 0; index < inputSize; index++)
    {
      fprintf ( newPtr, "%d\n", heapArray [ index ] );
    }

    // closes the pointers for the files
    fclose ( newPtr );
    fclose ( filePtr );
  }// end of else statement
  return 0;
} // end of main

// Max heap adjust is used to recurisvely adust to get a max heap
void  maxHeapAdjust (int heapArray[], int index, int inputSize)
{
    // variables used in building the heap from heapArray [0]
    int larger = 0, smaller = 0, leftChild = (2 * index) + 1,
        rightChild = (2 * index) + 2;
    // if the left child is bigger than input and leftchild in heap is bigger than index in heap
    if ( ( leftChild <= inputSize ) && ( heapArray [ leftChild] > heapArray[ index ] ) )
         larger = leftChild;
    // set larger to the index for compairison
    else
         larger = index;
    // if the right child is bigger than input and right Child in heap is bigger than index in heap
    if (( rightChild <= inputSize) && (heapArray[rightChild] > heapArray[larger]))
         larger = rightChild ;

    // if larger doesnt equal the index, continue
    if (larger != index)
    {
      // swap smaller with index nd larger with index, smaller with larger
        smaller = heapArray [ index ];
        heapArray[ index ] = heapArray[larger];
        heapArray[larger] = smaller;
        // call the max heap Adjust recursively
        maxHeapAdjust( heapArray, larger, inputSize);
    }// end if
}// end max heap adjust function

// adjustHeap to give the index of the current variables for the max heap adjust
void adjustHeap( int heapArray[], int inputSize )
{
    int temp;
    // for each index /2 call max heap adjust for the children/parent
    for ( int index = inputSize / 2; index >= 0; index--)
    {
         maxHeapAdjust(heapArray, index, inputSize);
    }
    // buildMaxHeap(heapArray, inputSize);
    // for loop to work backwards through heap array, replacing largest with smallest
    for (int index = inputSize; index > 0; index--)
    {
        temp = heapArray[index];
        heapArray[index] = heapArray[0];
        heapArray[0] = temp;
        // subtract the inputsize by 1 to go through the array
        inputSize--;
        // adjust whats left of the heap array
        maxHeapAdjust(heapArray, 0, inputSize);
    }// end for loop
}// end adjust heap function
