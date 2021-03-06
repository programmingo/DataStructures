/*
 * Binary search with macro preprocessor of comaprison of two integers
 * Return its position if found. Othewise return -1;
 */

#ifndef COMPARE
#define COMPARE(x,y) ((x) < (y)) ? -1:((x)==(y)? 0:1)
#endif

int BinarySearch(int *arr, int find, int left, int right)
{
 while (left<=right)
 {
  int mid=(left+right)/2;
  switch (COMPARE(arr[mid], find))
  {
   case -1: left=mid+1;  break;
   case  0: return mid;  break;
   case  1: right=mid-1; break;
  }
 }
 return -1;
}
