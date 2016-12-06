/*
 *  quick sort
 */

#include<algorithm>

void quick_sort(int *arr, int left, int right)
{
 if (left < right){
   int i=left, j=right+1, pivot=arr[left];
   do{
     do i++; while (arr[i] < pivot);
     do j--; while (arr[j] > pivot);
     if (i < j) std:: swap(arr[i], arr[j]);
   } while (i < j);
 std:: swap(arr[left], arr[j]);

 quick_sort(arr, left, j-1);
 quick_sort(arr, j+1, right);
 }
}

