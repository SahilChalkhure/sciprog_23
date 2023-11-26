#include <stdio.h>
#include <math.h>

int main(void) {

/* Declare variables */
   int i,inum,tmp,numdigits;
   float fnum;
   char binnum[60];

/* Intialise 4-byte integer */
   inum = 33554431;
/* Convert to 4-byte float */
   fnum = (float) inum;


/* Convert to binary number (string)*/
   i = 0; tmp = inum;
   while (tmp > 0) {
     sprintf(&binnum[i],"%1d",tmp%2);
     tmp = tmp/2;
     i++;
   }

/* Terminate the string */
   binnum[i] = '\0';
       

/* fabs is used to calculate the log of the magnitude of the number */
    numdigits = ceil( logf(fabs(inum)) + 1); // i used +1 for the sign bit
    printf("The number of binary digits for %d is %d\n", inum, numdigits);



   printf("inum=%d,  fnum=%f, inum in binary=%s\n",
      inum,fnum,binnum);

}
