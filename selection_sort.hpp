/*
 * Remember call this function with <data_type> after function name
 */

#include<algorithm>

template <class T>
void selection_sort(T *arr, const int n)
{
 for (int i=0; i<n; i++){
   int min_index=i;
   for (int k=i+1; k<n; k++){
     if (arr[k]<arr[min_index])
       min_index=k;
   }
   std::swap(arr[i],arr[min_index]);
 }
}
