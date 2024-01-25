#include <iostream>
#include "print.h"
using namespace std;
void sort(int arr[], int size)
{
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size - 1 - i; j++)
    {
      if (arr[j + 1] < arr[j])
        swap(arr[j + 1], arr[j]);
    }
  }
}
int main()
{
  int arr[10] = {0, 5, 3, 2, 9, 12, 34, 65, 43, 50};
  sort(arr, 10);
  print(arr, 10);
  return 0;
}