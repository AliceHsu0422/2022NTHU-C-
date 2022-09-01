#include <iostream>
#include <stdlib.h>
#define N 9
using namespace std;
void reverse_array(int a[]);
void swap(int &x, int &y);
int main(void)
{
    int a[N]={0};
    for (int i = 0; i < N; i++)
    {
        int x;
        x = rand()%20;
        a[i] = x;
    }
    for (int i = 0; i < N; i++)
    {
        printf("%2d ",a[i]);
    }
    cout << endl;
    reverse_array(a);
    return 0;
}

void reverse_array(int a[])
{
    int i = 0;
    int j = N-1;
    while(i < j)
    {
        swap(a[i],a[j]);
        i++;
        j--;
        
    }
    for (int i = 0; i< N; i++)
    {
        printf("%2d ",a[i]);
    }
    printf("\n");
} 

void swap(int &x, int &y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}