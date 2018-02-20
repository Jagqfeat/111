/*
  Jesus Antonio Gonzalez Quevedo - a00399890
  Alberto Oliart Ros - Analysis & Design of Algorithms

  Optional code for the obtain Maximum Frequency element algorithm.
*/
#include <stdio.h>
#include <limits.h>

#define EMPTY INT_MIN

int main(){
  int i, j;

  // Input values, hardcoded for efficiency.
  int n = 12;
  int values[] = {1, 2, 3, 1, 2, 2, 3, 2, 2, 1, 2, 2};
  int numbers[n];
  int counter[n];

  for (i=0; i<n; i++)
    numbers[i] = EMPTY;

  // i being the Index for the values array.
  // j being the Index for the numbers & counter auxiliar arrays.
  for (i=0; i<n; i++){
    for (j=0; j<n; j++){
      // An empty auxiliar reached. The number seen is placed and then
      //  will be used to count how many instances of it exists.
      if (numbers[j] == EMPTY){
        numbers[j] = values[j];
        counter[j] = 1;
      }

      // If there is an existing number to count, compares it to the number at
      //  position j. If it does not match, it moves on to the next j.
      //  the value not maching any number causes the above situation.
      else if (numbers[j] == values[i]){
        counter[j] ++;
        if (counter[j] > n/2){
          printf("\nFrecuencia Maxima: %d con %d repeticiones\n\n",
            numbers[j], counter[j]);
          return 0;
        }
      }
    }
  }

  printf("\nNo se encontro Frecuencia Maxima.\n\n");
  return 1;
}
