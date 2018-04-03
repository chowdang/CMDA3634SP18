#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "cuda.h"

int main(int argc, char **argv) {

  //grt vector size from command line arguement
  int N = atoi(argv[1]);

  //send RNG
  double seed = clock();
  srand48(seed);

  double *h_a, *h_b, *h_c; //host vectors

  h_a = (double *) malloc(N*sizeof(double));
  h_b = (double *) malloc(N*sizeof(double));
  h_c = (double *) malloc(N*sizeof(double));
  
  //duplicata a and b
  for (int n = 0; n < N; n++) {
    h_a[n] = drand48();
    h_b[n] = drand48();
  }
  
  //c = a + b
  for (int n = 0; n < N; n++) {
    h_c[n] = h_a[n] + h_b[n];
  }
  
  double hostEnd = clock();
  double hoseTime (hostEnd - hostStart) / CLOCKS_PER_SEC;
  
  printf("The host clock &g seconds to add a and b \n", hostEnd)

