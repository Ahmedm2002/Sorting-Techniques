#include <iostream>
#include "print.h"
using namespace std;
void merge(int arr[], int left, int right, int mid)
{
  int size1 = mid - left + 1;
  int size2 = right - mid;

  int arr1[size1], arr2[size2];

  for (int i = 0; i < size1; i++)
    arr1[i] = arr[left + i];

  for (int i = 0; i < size2; i++)
    arr2[i] = arr[mid + 1 + i];

  int i = 0, j = 0, k = left;

  while (i < size1 && j < size2)
  {
    if (arr1[i] < arr2[j])
    {
      arr[k] = arr1[i];
      arr1[i] = arr[k];
      i++;
    }
    else
    {
      arr[k] = arr2[j];
      j++;
    }
    k++;
  }
  while (i < size1)
  {
    arr[k] = arr1[i];
    i++;
    k++;
  }
  while (j < size2)
  {
    arr[k] = arr2[j];
    j++;
    k++;
  }
}
void sort(int arr[], int left, int right)
{
  if (left < right)
  {
    int mid = (left + right) / 2;
    sort(arr, left, mid);
    sort(arr, mid + 1, right);
    merge(arr, left, right, mid);
  }
}
int main()
{
  int arr[10] = {0, 5, 3, 2, 9, 12, 34, 65, 43, 50};
  sort(arr, 0, 9);
  print(arr, 10);
  return 0;
}