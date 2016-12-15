#include<stdlib.h>

int binary_search(int *arr, int N, int find)
{
 int left=0;
 int right=N-1;
 int mid;

 while (left<=right)
 {
  mid=(left+right)/2;
  if (find < arr[mid] )
    right=mid-1;
  else if (find > arr[mid])
    left=mid+1;
  else
    return mid;
 }
 printf("Not found.\n");
 exit(1);
}
