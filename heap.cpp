#include <iostream>
#include "print.h"
using namespace std;
void heapify(int arr[], int size, int i)
{
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * + 2;

  if(left < size && arr[left] > arr[largest])
    largest = left;

  if(right < size && arr[right] > arr[largest])
    largest = right;
  
  if(largest != i)
  {
    swap(arr[i], arr[largest]);
    heapify(arr, i , 0);
  }
}
void sort(int arr[], int size)
{
  for (int i = size / 2 - 1; i >= 0; i--)
    heapify(arr, size, i);

  for (int i = size - 1; i > 0; i--)
  {
    swap(arr[0], arr[i]);
    heapify(arr, i, 0);
  }
}
int main()
{
  int arr[] = {12, 11, 13, 5, 6, 7};
  sort(arr, 6);
  print(arr, 6);
  return 0;
}