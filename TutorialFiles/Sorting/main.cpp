// Demonstration of different sorting methods of arrays
#include <iostream>

// SELECTION SORT METHOD
// The selection sort algorithm sorts an array by repeatedly finding the minimum
// element (considering ascending order) from unsorted part and putting it at
// the beginning. The algorithm maintains two subarrays in a given array: the
// subarray which is already sorted and the remaining subarray which is
// unsorted. In every iteration of selection sort, the minimum element
// (considering ascending order) from the unsorted subarray is picked and moved
// to the sorted subarray.
// Description from GeeksforGeeks.org
void selection_sort(int *arr, int size) {
     for (int i = 0; i < size; i++) {
          // Assume the smallest number is at the start of the array.
          int minIndex = i;
          for (int j = i + 1; j < size; j++) {
               // If the next number is smaller than our assumed smallest number...
               if (arr[j] < arr[minIndex]) {
                    // Set the index of the smaller number as our new assumed
                    // index of the smallest number in the array
                    minIndex = j;
               }
          }
          // Swap the new smallest number with the first element
          int temp = arr[i];
          arr[i] = arr[minIndex];
          arr[minIndex] = temp;
          // Print each step of the sort
          print_array(arr,size);
     }
}

// INSERTION SORT METHOD
// Typically used for sorting linked lists, but this function is showing how to
// implement it into an array. The difference is that we put the smallest number
// at the beginning, but the rest of the list stays the same.
void insertion_sort(int *arr, int size) {
     for (int i = 0; i < size; i++) {
          int minIndex = i;
          for (int j = i; j < size; j++) {
               if (arr[j] < arr[minIndex]) {
                    minIndex = j;
               }
          }
          int temp = arr[minIndex];
          // Shift everything down
          for (int j = minIndex; j > i; j--) {
               arr[j] = arr[j - 1];
          }
          arr[i] = temp;
          // Print each step of the sort
          print_array(arr,size);
     }
}

// BUBBLE SORT METHOD
// Bubble Sort is the simplest sorting algorithm that works by repeatedly
// swapping the adjacent elements if they are in wrong order.
// Description from GeeksforGeeks.org
void bubble_sort(int *arr, int size) {
     for (int i = 0; i < size - 1; i++) {
          for (int j = size - 1; j > i; j--) {
               if (arr[j - 1] > arr[j]) {
                    // Swap
                    int temp = arr[j - 1];
                    arr[j - 1] = arr[j];
                    arr[j] = temp;
               }
          }
          print_array(arr,size);
     }
}

void print_array(int *arr, int size) {
     std::cout << "{ " << arr[0];
     for(int i = 1; i < size; i++) {
          std::cout << ", " << arr[i];
     }
     std::cout << " }" << std::endl;
}

int main() {
     int arr[] = {5, 3, 2, 8, 0, 7, 13};
     std::cout << "Original Array:\n";
     // Print unsorted array
     print_array{arr,7};
     std::cout << "Selection Sort:\n";
     selection_sort(arr,7);
     std::cout << "Final Selection Sorted Array:\n";
     // Print selection sorted array
     print_array{arr,7};
}