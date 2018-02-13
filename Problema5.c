/*
  Jesus Antonio Gonzalez Quevedo - a00399890
  Alberto Oliart Ros - Analysis & Design of Algorithms

  Apply the Subarray Maximum Sum algorithm using the divide & conquer
   system implementation. C Language version.
*/
#include <stdio.h>
#include <limits.h>

// Fucntion definitions
int max2(int x, int y);
int max3(int x, int y, int z);
int maximumLR(int *array, int il, int im, int ir);
int maximumSum(int *array, int il, int ir);

// Functions
int max2(int x, int y){
  return (x>y) ? x:y;
}
int max3(int x, int y, int z){
  return max2( max2(x, y), z );
}

int maximumLR(int *a, int il, int im, int ir){
  // Attributes
  int i, j, sum;
  int lsum, rsum;

  // Initialize each sum, then search for the highest sum, left and right.
  // Due to the nature of the input having negative values, the left side search
  //  has to start from the middle to the left, as it may change the output.
  lsum = INT_MIN;
  sum = 0;
  for (i=im; i>=il; i--){
    sum += a[i];
    if (sum > lsum)
      lsum = sum;
  }

  rsum = INT_MIN;
  sum = 0;
  for (i=im+1; i<=ir; i++){
    sum += a[i];
    if (sum > rsum)
      rsum = sum;
  }

  //  Return the total sum of the search.
  return lsum + rsum;
}

int maximumSum(int *a, int il, int ir){
  // One element in the array, size one.
  if (il == ir)
    return a[il];

  int im, lsum, msum, rsum;
  im = (il + ir)/2;

  // Obtain the left side of the array, then the right, and combine them.
  // Further, obtain the highest sum of the three.
  lsum = maximumSum(a, il, im);
  rsum = maximumSum(a, im+1, ir);
  msum = maximumLR(a, il, im, ir);

  return max3(lsum, msum, rsum);
}

int main(){
  int i, n;

  // Array size obtainment.
  scanf("%d", &n);
  int a[n];

  // Value filling.
  for (i=0; i<n; i++)
    scanf("%d", &a[i]);

  // Printing the result.
  printf("Maximum sum is : %d\n", maximumSum(a, 0, n-1) );

  return 0;
}
