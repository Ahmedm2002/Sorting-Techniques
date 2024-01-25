#include <iostream>
#include "print.h"
using namespace std;
void sort(int arr[], int size)
{
  for (int i = 0; i < size - 1; i++)
  {
    int minIndex = i;
    for (int j = i + 1; j < size; j++)
    {
      if (arr[j] < arr[minIndex])
        minIndex = j;
    }
    swap(arr[i], arr[minIndex]);
  }
}
int main()
{
  int arr[10] = {0, 5, 3, 2, 9, 12, 34, 65, 43, 50};
  sort(arr, 10);
  print(arr, 10);
  return 0;
}