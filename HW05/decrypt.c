#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

#include "functions.h"


int main (int argc, char **argv) {

  //declare storage for an ElGamal cryptosytem
  unsigned int n, p, g, h, x;
  unsigned int Nints;

  //get the secret key from the user
  printf("Enter the secret key (0 if unknown): "); fflush(stdout);
  char stat = scanf("%u",&x);

  printf("Reading file.\n");

  /* Q3 Complete this function. Read in the public key data from public_key.txt
    and the cyphertexts from messages.txt. */
  FILE * m = fopen("message.txt", "r");
  FILE * pk = fopen("public_key.txt", "r");

  fscanf(pk, "%d\n%d\n%d\n%d\n", &n, &p, &g, &h);
  fscanf(m, "%d\n", &Nints);

  unsigned int charsPerInt = (n - 1) / 8;
  unsigned int *Zmessage =
      (unsigned int *) malloc(Nints*sizeof(unsigned int));
  unsigned int *a =
      (unsigned int *) malloc(Nints*sizeof(unsigned int));
  unsigned int i;
  for (i = 0; i<Nints; i++) {
    fscanf(m, "%d %d\n", &Zmessage[i], &a[i]);
  }

  fclose(pk);
  fclose(m);
  // find the secret key
  if (x==0 || modExp(g,x,p)!=h) {
    printf("Finding the secret key...\n");
    double startTime = clock();
    unsigned int i;
    for (i=0;i<p-1;i++) {
      if (modExp(g,i+1,p)==h) {
        printf("Secret key found! x = %u \n", i+1);
        x=i+1;
      } 
    }
    double endTime = clock();

    double totalTime = (endTime-startTime)/CLOCKS_PER_SEC;
    double work = (double) p;
    double throughput = work/totalTime;

    printf("Searching all keys took %g seconds, throughput was %g values tested per second.\n", totalTime, throughput);
  }

  /* Q3 After finding the secret key, decrypt the message */
  int bufferSize = 1024;
  unsigned char *message = (unsigned char *) malloc(bufferSize*sizeof(unsigned char));
  ElGamalDecrypt(Zmessage, a, Nints, p, x);
  convertZToString(Zmessage, Nints, message, Nints * charsPerInt );
  printf("%s\n", message);
  return 0;
}
