//Selection Sort
#include <stdio.h>
 
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
 
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;
 
        // Swap the found minimum element with the first element
           if(min_idx != i)
            swap(&arr[min_idx], &arr[i]);
    }
}
 
/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
 
// Driver program to test above functions
int main()
{
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}

Average case time complexity: O(n2)

Worst-case time complexity: O(n2)

Best case time complexity: O(n2)

// Bubble Sort

// Optimized implementation of Bubble sort
#include <stdbool.h>
#include <stdio.h>

void swap(int* xp, int* yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

// An optimized version of Bubble Sort
void bubbleSort(int arr[], int n)
{
	int i, j;
	bool swapped;
	for (i = 0; i < n - 1; i++) {
		swapped = false;
		for (j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(&arr[j], &arr[j + 1]);
				swapped = true;
			}
		}

		// If no two elements were swapped by inner loop,
		// then break
		if (swapped == false)
			break;
	}
}

// Function to print an array
void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
}

// Driver program to test above functions
int main()
{
	int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
	int n = sizeof(arr) / sizeof(arr[0]);
	bubbleSort(arr, n);
	printf("Sorted array: \n");
	printArray(arr, n);
	return 0;
}
Average case time complexity: O(n2)

Worst-case time complexity: O(n2)

Best case time complexity: O(n)

//Insertion Sort

#include<iostream>
using namespace std;
int main ()
{
   int myarray[5] = { 12,4,3,1,15};
   cout<<"\nInput list is \n";
   for(int i=0;i<5;i++)
   {
      cout <<myarray[i]<<"\t";
   }
   for(int k=1; k<5; k++)
   {
      int temp = myarray[k];
      int j= k-1;
      while(j>=0 && temp <= myarray[j])
      {
         myarray[j+1] = myarray[j];
         j = j-1;
      }
   myarray[j+1] = temp;
   }
cout<<"\nSorted list is \n";
for(int i=0;i<5;i++)
   {
   cout <<myarray[i]<<"\t";
   }
}
Best case time complexity: O(n)

Average and worst-case time complexity: O(n2)
//Quick Sort

#include <iostream>
using namespace std;
// Swap two elements - Utility function
void swap(int* a, int* b)
{
   int t = *a;
   *a = *b;
   *b = t;
}
// partition the array using last element as pivot
int partition (int arr[], int low, int high)
{
   int i = (low - 1);
   for (int j = low; j <= high- 1; j++)
  {
      //if current element is smaller than pivot, increment the low element
      //swap elements at i and j
      if (arr[j] <= pivot)
      {
         i++; // increment index of smaller element
         swap(&arr[i], &arr[j]);
      }
   }
swap(&arr[i + 1], &arr[high]);
return (i + 1);
}

Best and Average time complexity: O(n log n)

Worst-case time complexity: (n2)
 
//quicksort algorithm
void quickSort(int arr[], int low, int high)
{
if (low < high)
   {
   //partition the array 
    int pivot = partition(arr, low, high);
   //sort the sub arrays independently
   quickSort(arr, low, pivot - 1);
   quickSort(arr, pivot + 1, high);
   }
}
void displayArray(int arr[], int size)
  {
   int i;
   for (i=0; i < size; i++)
   cout<<arr[i]<<"\t";
   }
int main()
{
   int arr[] = {12,23,3,43,51};
   int n = sizeof(arr)/sizeof(arr[0]);
   cout<<"Input array"<<endl;
   displayArray(arr,n);
   cout<<endl;
   quickSort(arr, 0, n-1);
   cout<<"Array sorted with quick sort"<<endl;
   displayArray(arr,n);
   return 0;
}

Worse case: O(n2)

Average case and best case: O(n log n)

//Merge Sort 
#include <iostream>
using namespace std;
void merge(int *,int, int , int );
void merge_sort(int *arr, int low, int high)
{
   int mid;
   if (low < high){
      //divide the array at mid and sort independently using merge sort
      mid=(low+high)/2;
      merge_sort(arr,low,mid);
      merge_sort(arr,mid+1,high);
      //merge or conquer sorted arrays
      merge(arr,low,high,mid);
   }
}
// Merge sort
void merge(int *arr, int low, int high, int mid)
{
   int i, j, k, c[50];
   i = low;
   k = low;
   j = mid + 1;
   while (i <= mid && j <= high) {
   if (arr[i] < arr[j]) {
   c[k] = arr[i];
   k++;
   i++;
}
else {
   c[k] = arr[j];
   k++;
   j++;
   }
}
  
while (i <= mid) {
   c[k] = arr[i];
   k++;
   i++;
}
while (j <= high) {
   c[k] = arr[j];
   k++;
   j++;
}
for (i = low; i < k; i++) {
   arr[i] = c[i];
}
}
// read input array and call mergesort
int main()
{
int myarray[30], num;
cout<<"Enter number of elements to be sorted:";
cin>>num;
cout<<"Enter "<<num<<" elements to be sorted:";
for (int i = 0; i < num; i++) { cin>>myarray[i];
}
merge_sort(myarray, 0, num-1);
cout<<"Sorted array\n";
for (int i = 0; i < num; i++)
{
   cout<<myarray[i]<<"\t";
}
}
Best and Average time complexity: O(n log n)

Worst-case time complexity: O(n log n)

//Heap Sort

#include <iostream>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
int largest = root; // root is the largest element
int l = 2*root + 1; // left = 2*root + 1
int r = 2*root + 2; // right = 2*root + 2
  
   // If left child is larger than root
if (l < n && arr[l] > arr[largest])
largest = l;
  
   // If right child is larger than largest so far
if (r < n && arr[r] > arr[largest])
largest = r;
  
   // If largest is not root
if (largest != root)
   {
      //swap root and largest
swap(arr[root], arr[largest]);
     
      // Recursively heapify the sub-tree
heapify(arr, n, largest);
   }
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap
for (int i = n / 2 - 1; i >= 0; i--)
heapify(arr, n, i);
 
   // extracting elements from heap one by one
for (int i=n-1; i>=0; i--)
   {
      // Move current root to end
swap(arr[0], arr[i]);
  
      // again call max heapify on the reduced heap
heapify(arr, i, 0);
   }
}
  
/* print contents of array - utility function */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main program
int main()
{
int heap_arr[] = {4,17,3,12,9};
int n = sizeof(heap_arr)/sizeof(heap_arr[0]);
cout<<"Input array"<<endl;
displayArray(heap_arr,n);
 
heapSort(heap_arr, n);
 
cout << "Sorted array"<<endl;
displayArray(heap_arr, n);
}

Worst case = Average Case = Best Case = O(n log n)
