#include <iostream>
#include <stdlib.h>
#include <algorithm>

using namespace std; 
  
template<class T> 
int binarySearch(T* arr, T* left, T* right, T x) 
{ 

    int result = -1;
    if (*left > *right){
        return result;
    }

    T* mid = left + (right - left) / 2;
    if (*mid==x){
        return mid-arr;
    }

    if (x <* mid){
        return binarySearch(arr, left, mid - 1, x);
    }

    else if (x > *mid){
        return binarySearch(arr, mid + 1, right, x);
    }
    
    return result;


}

   /* if (right >= left) { 
    int mid = left + (right - left) / 2; 

    if (arr[mid] == x) {
        return mid; 
    }
     //[,,,,,x,,,,,mid,,,,,,,,,]

    if (arr[mid] > x) {
        return binarySearch(arr, left, mid - 1, x); 
    }
    //[,,,,,,,,,,,mid,,,,,x,,,]

        return binarySearch(arr, mid + 1, right, x); 
    }
  
  return -1; 
    */

  
int main() 
{   
    int size = 6;
    int* arr = new int [size];
    for (int i=0; i<size; i++)    //random array values
    {
        arr[i]= {rand() %100};
    }

    sort(arr,arr+size); //array sorter  
    for (int i=0; i<size; i++) {  
        cout << arr[i] << ", ";  
    }

    int x = 24; 
    


    int result = binarySearch(arr, arr, arr + size -1, x); 
    if (result == -1) 
    {
        cout << " Number is not found in array search";
    }
    else 
    {
        cout << " Number is found in position (starting from 0) " << result; 
    }
    return 0; 
} 
