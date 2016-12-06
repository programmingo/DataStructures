/*
 * bubble sort
 */

#include<algorithm>

void bubble(int *arr, const int n)
{
 for (int i=1; i<n; i++) // execution times
   for (int j=0; j<(n-1); j++) // compare neighbor index
     if (arr[j]>arr[j+1])
       std:: swap(arr[j], arr[j+1]);
}
