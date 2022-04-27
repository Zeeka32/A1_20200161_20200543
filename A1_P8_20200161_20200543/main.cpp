#include <bits/stdc++.h>
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

        for(int j = i; j > insertIndex; j--){
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

int* GenerateRandomList(int min, int max, int size){

    int* randomList = new int[size];

    for(int i = 0; i < size; i++)
        randomList[i] = min + rand() % (max - min + 1);

    return randomList;
}

void Run_Test_Binary_Insertion(int n){

    int* ptr; int average = 0;
     
    //comparing complexities
    for(int i = 0; i < 10; i++){

        ptr = GenerateRandomList(0, 10000, n);

        auto time_start1 = chrono::high_resolution_clock::now();

        Binary_Insertion_Sort(ptr, n);

        auto time_stop1 = chrono::high_resolution_clock::now();

        auto duration1 = chrono::duration_cast<chrono::microseconds>(time_stop1 - time_start1);

        average += duration1.count();

        delete [] ptr;
    }
    cout << "\t" << average/10 << "\t\tmicroseconds\n";

}

void Run_Test_Insertion(int n){

    int* ptr; int average = 0;
    
    //comparing complexities
    for(int i = 0; i < 100; i++){
        
        ptr = GenerateRandomList(0, 10000, n);

        auto time_start1 = chrono::high_resolution_clock::now();

        Insertion_Sort(ptr, n);

        auto time_stop1 = chrono::high_resolution_clock::now();

        auto duration1 = chrono::duration_cast<chrono::microseconds>(time_stop1 - time_start1);

        average += duration1.count();

        delete [] ptr;
    }
    cout << "\t" << average/100 << "\t\tmicroseconds\n";

}


int main(void){   

    //comparing complexities by running them through a test
    //this test generates 100 random arrays and then sorts them and takes the average
    //time for those 100 sorts. the test is done again but each time the array size 
    //increases by 1000. the results are then taken and plotted into an excel sheet.

    cout << "normal insertion sort\n";

    cout << "\tsize\taverage time\tunit\n";
    for(int i = 1000; i <= 15000; i+= 1000){
        cout << "\t" << i;
        Run_Test_Insertion(i);

    }

    cout << "\nbinary insertion sort\n";
    cout << "\tsize\taverage time\tunit\n";
    for(int i = 1000; i <= 15000; i+= 1000){
        
        cout << "\t" << i;
        Run_Test_Binary_Insertion(i);

    }

    return 0;
}