#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

void swap (int *i, int *j) {
    int temp = *i;
    *i = *j;
    *j = temp;
}
int cnt;
void permute(int index, int* arr, int n) {
   if (index == n-1) {
       cnt++;
       printf("The %d-th Pattern: ( ",cnt);
       for (int k = 0; k < n; ++k) {
            printf ("%d ", arr[k]);
       }
       printf(")");
       printf ("\n");
       return;
   }
   for (int i = index; i < n; i++) {
       swap (arr + index, arr + i);
       permute (index+1, arr, n);
       swap (arr + i, arr + index);
   }
   return;
}

int main()
{
   int n;
   cin >> n;
   int arr[n];
   for (int i = 0; i < n; ++i) arr[i] = i;
   
   permute(0, arr, n);
   printf("There are %d permutations in total!\n",cnt);
   return 0;
}