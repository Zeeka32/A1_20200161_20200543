#include <iostream>
#include<vector>
using namespace std;

int Binary_Search(int arr[], int target, int size){

        int L = 0, R = size, mid;
        while(L <= R){
            mid = L + (R - L) / 2;
            if(arr[mid] == target)
                return mid;
            if(arr[mid] > target)
                R = mid - 1;
            else
                L = mid + 1;
        }
        if(arr[mid] < target)
            return mid + 1;
        return mid;
}

void Binary_Insertion_Sort(int arr[], int size){

    for(int i = 1; i < size; i++){
        int tempElement = arr[i];

        int insertIndex = Binary_Search(arr, tempElement, i - 1);

        for(int j = i; j >= insertIndex && j - 1 >= 0; j--){
            arr[j] = arr[j - 1];
        }

        arr[insertIndex] = tempElement;

    }
}  

void Insertion_Sort(int arr[], int size){

    for(int i = 1, j = 0; i < size; i++){
        int tempElement = arr[i];

        for(j = i; j > 0 && tempElement < arr[j - 1]; j--)
            arr[j] = arr[j - 1];
        arr[j] = tempElement;
    }
}

int* Generate_Array(int size, int range){
    int* array = new int[size];
    for(int i = 0; i < size; i++){
        array[i] = rand() % range;
    }

    return array;
}

int main(){   
    int* array1 = Generate_Array(1000, 10000);
    int* array2 = Generate_Array(1000, 10000);
    
    Binary_Insertion_Sort(array1, 1000);
    Insertion_Sort(array2, 1000);

    return 0;
}