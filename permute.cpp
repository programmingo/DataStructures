#include<iostream>

using namespace std;

void permutations(char *arr, int k, int m);

int main(void)
{
 char letter[]="abc"; // letter is a character array
 permutations(letter, 0, 2); //permute from letter[0] to letter[2]

 return 0;
}

void permutations(char *arr, const int k, const int m)
{
 if (k == m){ // when k=m, it doesn't need permute, output
   for (int i=0; i<=m; i++)
     cout << arr[i] << " ";
   cout << endl;
 }
 else{
   for (int i=k; i<=m; i++)
   {
    swap(arr[k], arr[i]); // exchange
    permutations(arr, k+1, m); // permute 
    swap(arr[k], arr[i]); // recovery
   }
 }
}
