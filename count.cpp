#include <iostream>
#include "print.h"
using namespace std;
int maximum(int arr[], int size)
{
  int max = arr[0];
  for (int i = 0; i < size; i++)
  {
    if (arr[i] > max)
      max = arr[i];
  }
  return max;
}
void sort(int arr[], int size)
{
  int max = maximum(arr, size);
  int *count = new int[max + 1]();

  for (int i = 0; i < max + 1; i++)
    count[arr[i]]++;

  int index = 0;
  for (int i = 0; i < size; i++)
  {
    while (count[i] > 0)
    {
      arr[index++] = i;
      count[i]--;
    }
  }
}
int main()
{
  int arr[10] = {3, 2, 5, 1, 4, 9, 7, 6, 3, 9};
  print(arr, 10);
  cout << endl;
  sort(arr, 10);
  print(arr, 10);
}