#include <iostream>
#include <chrono>
#include <array>

using namespace std;  
  
void swap(int* a, int* b)  
{  
    int temp = *a;  
    *a = *b;  
    *b = temp;  
}  
  
int partition(int arr[], int low, int high)  
{  
    int pivot = arr[high]; 
    int i = (low - 1); 
  
    for (int j = low; j <= high - 1; j++)  
    {  
        if (arr[j] < pivot)  
        {  
            i++;   
            swap(&arr[i], &arr[j]);  
        }  
    }  
    swap(&arr[i + 1], &arr[high]);  
    return (i + 1);  
}  

void quickSort(int arr[], int low, int high)  
{  
    if (low < high)  
    {  
        int pindex = partition(arr, low, high);  
  
        //sort left of pivot and right of pivot
        quickSort(arr, low, pindex - 1);  
        quickSort(arr, pindex + 1, high);  
    }  
}  

void bubbleSort(int arrcomp[], int n)  
{  
    int i, j;  
    for (i = 0; i < n-1; i++)      

    for (j = 0; j < n-i-1; j++)  
        if (arrcomp[j] > arrcomp[j+1])  
            swap(&arrcomp[j], &arrcomp[j+1]);  
}  

void printArray(int arr[], int size)  
{  
    int i;  
    for (i = 0; i < size; i++)  
        cout << arr[i] << " ";  
    cout << endl;  
}  

int main()  
{  
    int arr[] = {5, 7, 11, 10, 4, 8, 22, 24, 27, 50, 2, 15, 6, 29, 31, 38, 45, 1}; 
    int arrcomp[] = {5, 7, 11, 10, 4, 8, 22, 24, 27, 50, 2, 15, 6, 29, 31, 38, 45, 1};  
    int n = sizeof(arr) / sizeof(arr[0]); 

    ///
    auto start = chrono::high_resolution_clock::now();
    quickSort(arr, 0, n - 1);  
    auto finish = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = finish - start;
    cout << "Time for quicksort: " << elapsed.count() * 1000 << " ms\n";

    ///
    auto startbubble = chrono::high_resolution_clock::now();
    bubbleSort(arrcomp, n);
    auto finishbubble = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsedbubble = finishbubble - startbubble;
    cout << "Time for bubblesort: " << elapsedbubble.count() * 1000 << " ms\n";

    if (elapsedbubble.count() > elapsed.count())
    {
        cout << "Quicksort is faster \n";
    }
    
    cout << "Sorted Array: \n";  
    printArray(arr, n);  
    return 0;  
}  


