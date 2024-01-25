#include <iostream>
#include "print.h"
using namespace std;
void sort(int arr[], int size)
{
  for (int i = 1; i < size; i++)
  {
    int curr = arr[i];
    int j = i - 1;
    while (arr[j] > curr && j >= 0)
    {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = curr;
  }
}
int main()
{
  int arr[10] = {0, 5, 3, 2, 9, 12, 34, 65, 43, 50};
  sort(arr, 10);
  print(arr, 10);
}