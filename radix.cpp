// #include <iostream>
// #include "print.h"
// using namespace std;
// int maximum(int arr[], int size)
// {
//   int max = arr[0];
//   for (int i = 0; i < size; i++)
//   {
//     if (arr[i] > max)
//       max = arr[i];
//   }
//   return max;
// }
// void count(int arr[], int size, int place)
// {
//   int *count = new int[size]();
//   for (int i = 0; i < size; i++)
//     count[((arr[i]) / place) % 10]++;

//   for (int i = 0; i < size; i++)
//     count[i] += count[i - 1];

//   // int *sortedArr = new int[10];
//   for(int i = 9 ; i >=0 ; i--)
//     --count[(count[i]/place) % 10 ] = count[i];
// }
// void sort(int arr[], int size)
// {
//   int max = maximum(arr, size);
//   for (int place = 1; max / place > 0; place *= 10)
//   {
//     count(arr, size, place);
//   }
// }
// int main()
// {
//   int arr[10] = {0, 5, 3, 2, 9, 12, 34, 65, 43, 50};
//   sort(arr, 10);
//   print(arr, 10);
//   return 0;
// }

#include <iostream>
#include <cmath>
#include "print.h" // Assuming you have a print function for printing arrays
using namespace std;

// Function to find the maximum value in an array
int findMax(int arr[], int size)
{
  int max = arr[0];
  for (int i = 1; i < size; i++)
  {
    if (arr[i] > max)
      max = arr[i];
  }
  return max;
}

// Function to perform counting sort on the specified digit place
void countingSort(int arr[], int size, int place)
{
  const int radix = 10; // Assuming decimal numbers (0-9)

  int *output = new int[size];
  int count[radix] = {0};

  // Count occurrences of each digit at the specified place
  for (int i = 0; i < size; i++)
    count[(arr[i] / place) % radix]++;

  // Update count to store the actual position of each digit in the output array
  for (int i = 1; i < radix; i++)
    count[i] += count[i - 1];

  // Build the output array
  for (int i = size - 1; i >= 0; i--)
  {
    output[count[(arr[i] / place) % radix] - 1] = arr[i];
    count[(arr[i] / place) % radix]--;
  }

  // Copy the sorted elements back to the original array
  for (int i = 0; i < size; i++)
    arr[i] = output[i];

  delete[] output;
}

// Main function to perform Radix Sort
void radixSort(int arr[], int size)
{
  // Find the maximum number to determine the number of digits
  int max = findMax(arr, size);

  // Perform counting sort for every digit place
  for (int place = 1; max / place > 0; place *= 10)
  {
    // Step 1: Apply counting sort on the current digit place
    countingSort(arr, size, place);

    // Step 2: Print the array after sorting on the current digit place
    // cout << "Array after sorting on digit place " << place << ": ";
    // print(arr, size);
  }
}

// Driver's code
int main()
{
  int arr[10] = {170, 45, 75, 90, 802, 24, 2, 66, 78, 100};
  int size = sizeof(arr) / sizeof(arr[0]);

  // Step 0: Print the original array
  cout << "Original array: ";
  print(arr, size);

  // Perform Radix Sort
  radixSort(arr, size);

  // Step 3: Print the final sorted array
  cout << "Sorted array: ";
  print(arr, size);

  return 0;
}
