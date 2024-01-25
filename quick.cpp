#include <iostream>
#include "print.h"
using namespace std;
int partition(int arr[], int left, int right)
{
  int pivot = arr[right];
  int i = left - 1;
  for (int j = left; j < right; j++)
  {
    if (arr[j] < pivot)
    {
      i++;
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[i + 1], arr[right]);
  return (i + 1);
}
void sort(int arr[], int left, int right)
{
  if (left < right)
  {
    int pi = partition(arr, left, right);
    sort(arr, left, pi - 1);
    sort(arr, pi + 1, right);
  }
}
int main()
{
  int arr[10] = {0, 5, 3, 2, 9, 12, 34, 65, 43, 50};
  sort(arr, 0, 9);
  print(arr, 10);
  return 0;
}