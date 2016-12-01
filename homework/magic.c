/*
 * Data Structures
 * HW 1.1
 * magic matrix for N=3 or N=5
 */

#include<stdio.h>
#define N 5

int main(void)
{
 int magic[N][N]={0};
 int i=0;
 int j=N/2;
	
 for (int k=1; k<=N*N; k++)
 {
  // judge is there an element exist.
  // true, shift original (i,j) to next row and hold the same colum
  // false, sign on
  // also remember cyclic relation of (i,j)
  if (magic[i][j]){
    i+=2; j+=1;
    if (i == N) i=0;
    else if (i > N) i=1;
    else i=i*1;
		    
    if (j == N) j=0;
      magic[i][j]=k;
  }
  else{
    magic[i][j]=k;
  }
  
  // row and column index decrement (i-1, j-1)
  // remember cyclic relation of (i,j)
  i--; j--;
  if (i < 0) i=N-1;
  if (j < 0) j=N-1;
 }
	
 for (int p=0; p<N; p++){
   for (int q=0; q<N; q++){
     printf("%2d ", magic[p][q]);
   }
   printf("\n");
 }
    
 return 0;
}
