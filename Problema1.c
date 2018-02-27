Estoy solito
No hay nadie a mi lado
/*
  Jesus Antonio Gonzalez Quevedo  a00399890
  Analysis & Design of Algorithms

  Problem 1. Compare the amount of arithmethic comparison executed
   of multiple sorting algorithms. Specifically, only the comparison
   of two elements in an array, initialization or assignment are not
   to be counted.
  The algorithms are as follows.
   1. BubbleSort
   2. MergeSort
   3. QuickSort
   4. Heapsort
*/
// Inclusions
#include <stdio.h>
//#include <stdlib.h> // REMOVE AFTER TESTING ARRAYS

//Definitions
#define ASIZE 10
#define BSIZE 100
#define CSIZE 1000
#define DSIZE 10000

// Global attributes
int mergePoll;
int quickPoll;
int heapyPoll;

// Function definitions
void fillForward(int *a, int *b, int *c, int *d, int *sizes);
void fillReverse(int *a, int *b, int *c, int *d, int *sizes);
void fillShuffle(int *a, int *b, int *c, int *d, int *sizes);

int bubbleSort(int *arr, int size);

void merge(int *arr, int leftIndex, int middleIndex, int rightIndex);
void mergeSort(int *arr, int lowIndex, int rightIndex);

int part(int *arr, int lowIndex, int rightIndex);
void quickSort(int *arr, int lowIndex, int rightIndex);

void heap(int *arr, int size, int index);
void heapSort(int *arr, int size);

void printArray(int *a, int size);
void printBubble(int *a, int *b, int *c, int *d, int *sizes);
void printMerge(int *a, int *b, int *c, int *d, int *sizes);
void printQuick(int *a, int *b, int *c, int *d, int *sizes);
void printHeapy(int *a, int *b, int *c, int *d, int *sizes);

// Main function
int main(){
  // Attributes
  int a[ASIZE];
  int b[BSIZE];
  int c[CSIZE];
  int d[DSIZE];
  int sizes[4] = {ASIZE, BSIZE, CSIZE, DSIZE};

  // Printing of each sorting method with three types of arrays,
  //  forward ordered, reverse ordered, and shuffled.
  printf("\n\tBubble Sort.");
  printf("\nSorted Forward");
  fillForward(a, b, c, d, sizes); printBubble(a, b, c, d, sizes);
  printf("\nSorted Reverse");
  fillReverse(a, b, c, d, sizes); printBubble(a, b, c, d, sizes);
  printf("\nSorted Shuffle");
  fillShuffle(a, b, c, d, sizes); printBubble(a, b, c, d, sizes);

  printf("\n\n");
  printf("\n\tMerge Sort.");
  printf("\nSorted Forward");
  fillForward(a, b, c, d, sizes); printMerge(a, b, c, d, sizes);
  printf("\nSorted Reverse");
  fillReverse(a, b, c, d, sizes); printMerge(a, b, c, d, sizes);
  printf("\nSorted Shuffle");
  fillShuffle(a, b, c, d, sizes); printMerge(a, b, c, d, sizes);

  printf("\n\n");
  printf("\n\tQuick Sort.");
  printf("\nSorted Forward");
  fillForward(a, b, c, d, sizes); printQuick(a, b, c, d, sizes);
  printf("\nSorted Reverse");
  fillReverse(a, b, c, d, sizes); printQuick(a, b, c, d, sizes);
  printf("\nSorted Shuffle");
  fillShuffle(a, b, c, d, sizes); printQuick(a, b, c, d, sizes);

  printf("\n\n");
  printf("\n\tHeap Sort.");
  printf("\nSorted Forward");
  fillForward(a, b, c, d, sizes); printHeapy(a, b, c, d, sizes);
  printf("\nSorted Reverse");
  fillReverse(a, b, c, d, sizes); printHeapy(a, b, c, d, sizes);
  printf("\nSorted Shuffle");
  fillShuffle(a, b, c, d, sizes); printHeapy(a, b, c, d, sizes);

  return 0;
}

// Functions
// Fills arrays -a,b,c,d with values from 0 to their array size.
void fillForward(int *a, int *b, int *c, int *d, int *sizes){
  int i, max;

  // Index -i keeps increasing, leaving the arrays whose array sizes
  //  do not support higher numbers.
  max = sizes[0];
  for (i=0; i<max; i++)
    a[i] = b[i] = c[i] = d[i] = i;
  max = sizes[1];
  for (i=i; i<max; i++)
    b[i] = c[i] = d[i] = i;
  max = sizes[2];
  for (i=i; i<max; i++)
    c[i] = d[i] = i;
  max = sizes[3];
  for (i=i; i<max; i++)
    d[i] = i;
}

// Fills arrays -a,b,c,d with values from their array size down to 0.
void fillReverse(int *a, int *b, int *c, int *d, int *sizes){
  int i, max;

  // Unlike fillForward, every array is ordered separately for an easier
  //  time handling each array size.
  max = sizes[0];
  for (i=0; i<max; i++)
    a[i] = max-i-1;
  max = sizes[1];
  for (i=0; i<max; i++)
    b[i] = max-i-1;
  max = sizes[2];
  for (i=0; i<max; i++)
    c[i] = max-i-1;
  max = sizes[3];
  for (i=0; i<max; i++)
    d[i] = max-i-1;
}

// Shuffles filled arrays -a,b,c,d with their own values. No value is lost.
void fillShuffle(int *a, int *b, int *c, int *d, int *sizes){
  int i, s, max, auxs;

  // Requires previously inserted values to shuffle.
  fillForward(a, b, c, d, sizes);

  // Uses +fillForward()'s ordered values and shuffles them around.
  max = sizes[0];
  for (i=0; i<max; i++){
    s = rand() % (max+1);
    auxs = a[i];
    a[i] = a[s];
    a[s] = auxs;
  }
  max = sizes[1];
  for (i=0; i<max; i++){
    s = rand() % (max+1);
    auxs = b[i];
    b[i] = b[s];
    b[s] = auxs;
  }
  max = sizes[2];
  for (i=0; i<max; i++){
    s = rand() % (max+1);
    auxs = c[i];
    c[i] = c[s];
    c[s] = auxs;
  }
  max = sizes[3];
  for (i=0; i<max; i++){
    s = rand() % (max+1);
    auxs = d[i];
    d[i] = d[s];
    d[s] = auxs;
  }
}

// The simplest sorting method, compares values starting from an index
//  one by one, swapping them if necessary.
int bubbleSort(int *arr, int size){
  int i, j;
  int auxs;   // Integer used for swapping.
  int poll;   // Count of array comparisons performed.

  for (poll=i=0; i<size; i++){
    for (j=i; j<size; j++){
      poll ++;
      if (arr[j] < arr[i]){
        auxs = arr[i];
        arr[i] = arr[j];
        arr[j] = auxs;
      }
    }
  }

  return poll;
}

// Recursive sorting method, dividing the arrays into halves until
//  it reaches one/two piece halves. It then sorts them from the middle of
//  each half to the edges accordingly.
void merge(int *arr, int il, int im, int ir){
  int lenL, lenR;   // Lengths for the new arrays. Each has half of the values.
  int i, j, k;      // Indexes for sorting the original and new arrays.
  extern int mergePoll;

  // Lengths given by the positions of the recursive methods.
  lenL = (im - il)+1;
  lenR = (ir - im);

  // Fill both halves into different arrays for swap facilitation.
  int arrL[lenL];
  int arrR[lenR];

  for (i=0; i < lenL; i ++)
    arrL[i] = arr[il + i];
  for (i=0; i < lenR; i++)
    arrR[i] = arr[im+1 + i];

  // Inserts the values from lowest to highest into the indexex -il to -ir
  //  of the original array. The algorithm assumes the halves were sorted
  //  in deeper recursions.
  i = j = 0;
  k = il;

  while (i<lenL && j<lenR){
    mergePoll ++;
    if (arrL[i] < arrR[j]){
      arr[k] = arrL[i];
      i ++;
    } else {
      arr[k] = arrR[j];
      j ++;
    }
    k ++;
  }

  // Then proceeds to either array that was not depleted.
  while (i < lenL){
    arr[k] = arrL[i];
    i ++;
    k ++;
  }
  while (j < lenR){
    arr[k] = arrR[j];
    j ++;
    k ++;
  }
}
void mergeSort(int *arr, int il, int ir){
  if (il >= ir)
    return;

  int im;                 // Middle index.
  im = il + (ir - il)/2;  // Overflow considered division.

  // Sorts the left side first, then the right.
  mergeSort(arr, il, im);
  mergeSort(arr, im+1, ir);

  // Due to recursiveness, every instance calls to +merge() and sorts
  //  two halves, assuming th   at they're already sorted. The last recursion
  //  (one piece halves) is already sorted by definition.
  merge(arr, il, im, ir);
}

// Recursive sorting method, selects a random value (in this case, the
//  first element) as a pivot, and places it where the values to its left
//  are lower and visceversa. The end result is hereby sorted.
int part(int *arr, int il, int ir){
  int piv, aux;
  extern int quickPoll;
  piv = arr[il];

  // Seeks values from the start to the end indexes, moving lower values
  //  to the left as it does so, in order to find the definite position of
  //  the pivot, which the position next to every lower value than the pivot.
  int i, j;
  i = j = (il+1);

  while (j <= ir){
    quickPoll ++;
    if (arr[j] <= piv){
      aux = arr[i];
      arr[i] = arr[j];
      arr[j] = aux;
      i ++;
    }
    j ++;
  }

  // Swaps the optimal position found with the pivot.
  aux = arr[i-1];
  arr[i-1] = arr[il];
  arr[il] = aux;

  return i-1;
}
void quickSort(int *arr, int il, int ir){
  if (il >= ir)
    return;

  // Accomodates the first pivot, and returns where it was placed.
  int ip;
  ip = part(arr, il, ir);

  // Sorts the left side, then the first. Note that the -ip pivot is not
  //  included, as its position is correct (all lowers to the left
  //  and highers to the right) after partition.
  quickSort(arr, il, ip-1);
  quickSort(arr, ip+1, ir);
}

// Recursive sorting method, checks the values of a parent root's children
//  in order to find a discrepancy, and swap the parent with a child. This
//  process is executed from right to left.
void heap(int *arr, int size, int ind){
  int high, sonl, sonr, aux;
  extern int heapyPoll;

  high = ind;       // Index -i from heapSort will be taken as the root.
  sonl = 2*ind +1;  // Smaller child
  sonr = 2*ind +2;  // Bigger child

  // Checks if either of the children are bigger than the parent, and swaps.
  //  The condition also fails at attempting to check an out of bounds value.
  heapyPoll += 2;
  if (sonl < size && arr[sonl] > arr[high])
    high = sonl;
  if (sonr < size && arr[sonr] > arr[high])
    high = sonr;

  // Swaps if the original was changed for one of the sons, and does a heap
  //  check of the affected child.
  if (high != ind){
    aux = arr[ind];
    arr[ind] = arr[high];
    arr[high] = aux;

    heap(arr, size, high);
  }
}
void heapSort(int *arr, int size){
  int i, aux;

  // Heaps the array to correct wrong position of children.
  for (i=(size/2)-1; i >= 0; i--)
    heap(arr, size, i);

  // As Binary Trees start with the largest number, the array is reversed
  //  with heap checking backwards to assure the correct order.
  for (i=(size-1); i >= 0; i--){
    aux = arr[0];
    arr[0] = arr[i];
    arr[i] = aux;

    heap(arr, i, 0);
  }
}

void printArray(int *a, int size){
  int i;
  printf("\n\tArray Printing!\n");
  for (i=0; i<size; i++){
    if (i%14 == 0)
      printf("\n");
    printf("%5d, ", i);
  }
  printf("\n");
}

void printBubble(int *a, int *b, int *c, int *d, int *sizes){
  printf("\na[10]     = %d", bubbleSort(a, sizes[0]) );
  printf("\nb[100]    = %d", bubbleSort(b, sizes[1]) );
  printf("\nc[1000]   = %d", bubbleSort(c, sizes[2]) );
  printf("\nd[10000]  = %d", bubbleSort(d, sizes[3]) );
  printf("\n");
}

void printMerge(int *a, int *b, int *c, int *d, int *sizes){
  extern int mergePoll;
  mergePoll = 0;  mergeSort(a, 0, sizes[0]);
  printf("\na[10]     = %d", mergePoll);
  mergePoll = 0;  mergeSort(b, 0, sizes[1]);
  printf("\nb[100]    = %d", mergePoll);
  mergePoll = 0;  mergeSort(c, 0, sizes[2]);
  printf("\nc[1000]   = %d", mergePoll);
  mergePoll = 0;  mergeSort(d, 0, sizes[3]);
  printf("\nd[10000]  = %d", mergePoll);
  printf("\n\t");
}

void printQuick(int *a, int *b, int *c, int *d, int *sizes){
  extern int quickPoll;
  quickPoll = 0;  quickSort(a, 0, sizes[0]);
  printf("\na[10]     = %d", quickPoll);
  quickPoll = 0;  quickSort(b, 0, sizes[1]);
  printf("\nb[100]    = %d", quickPoll);
  quickPoll = 0;  quickSort(c, 0, sizes[2]);
  printf("\nc[1000]   = %d", quickPoll);
  quickPoll = 0;  quickSort(d, 0, sizes[3]);
  printf("\nd[10000]  = %d", quickPoll);
  printf("\n\t");
}

void printHeapy(int *a, int *b, int *c, int *d, int *sizes){
  extern int heapyPoll;
  heapyPoll = 0;  heapSort(a, sizes[0]);
  printf("\na[10]     = %d", heapyPoll);
  heapyPoll = 0;  heapSort(b, sizes[1]);
  printf("\nb[100]    = %d", heapyPoll);
  heapyPoll = 0;  heapSort(c, sizes[2]);
  printf("\nc[1000]   = %d", heapyPoll);
  heapyPoll = 0;  heapSort(d, sizes[3]);
  printf("\nd[10000]  = %d", heapyPoll);
  printf("\n\t");
}
