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

int partition(int *arr, int hi, int low) {
     int div = arr[low];
     while (hi > low) {
          if (arr[low] < div) {
               low++;
          }
          else {
               int temp = arr[hi];
               arr[hi] = arr[low];
               arr[low] = temp;
               hi--;
          }
     }
     if (arr[low] < div) {
          low++;
     } else {
          int temp = arr[end];
          arr[end] = arr[low];
          arr[low] = temp;
     }
     return low;
}

void quick_sort(int *arr, int hi, int low) {
     if (hi > low) {
          int p = partition(arr, hi, low);
          quick_sort(arr, p-1, low);
          quick_sort(arr, hi, p+1);
     }
}

int* merge(int *arr, int *leftArr, int *rightArr, int size) {
     int *arr = new int[size];
     int i = 0,
         j = 0,
         k = 0;
     for (; j < size/2 && k < size-size/2; i++) {
          if (leftArr[j] < rightArr[k]) {
               arr[i] = leftArr[j];
               j++;
          }
          else {
               arr[i] = rightArr[k];
               k++;
          }
     }

     if (j == size/2) {
          for(; i < size; i++, k++) {
               arr[i] = rightArr[k];
          }
     }
}

void merge_sort(int *arr, int size) {
     if (size <= 1) {
          return;
     } else {
          int *leftArr = new int[size/2]
          // size-size/2 rounds up instead of down
          int *rightArr = new int[size - size/2];
          for(int i = 0; i < size/2; i++) {
               leftArr[i] = arr[i];
          }
          for(int i = size/2; i < size; i++) {
               rightArr[i-size/2-1] - arr[i];
          }
          merge_sort(leftArr, size/2);
          merge_sort(rightArr, size-size/2);
          merge(arr, leftArr, rightArr, size);
          delete leftArr;
          delete rightArr;
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
