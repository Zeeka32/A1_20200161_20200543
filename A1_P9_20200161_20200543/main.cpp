#include <iostream>
#include<algorithm>
#include<chrono>
using namespace std;

class Sorter{
public:
    virtual void Sort(int array[], int size) = 0;
};

class SelectionSorter : public Sorter{
public:
    void Sort(int array[], int size){
            for(int i = 0, j, least = i; i < size; i++){

            for(j = i+1, least = i; j < size; j++)
                if(array[j] < array[least])
                    least = j;

            swap(array[i], array[least]);
        }
    }
};

class QuickSorter : public Sorter{
public:

    int Partition(int array[], int left, int right){
        int pivot = array[left], i = left;
        for(int j = left + 1; j <= right; j++){
            if(array[j] < pivot){
                swap(array[++i], array[j]);
            }
        }
        swap(array[i], array[left]);
        return i;
    }

    void QuickSort(int array[], int left, int right){

        if(left < right){

            int middle = Partition(array, left, right);
            QuickSort(array, left, middle - 1);
            QuickSort(array, middle + 1, right);
        }
    }

    void Sort(int array[], int size){
        QuickSort(array, 0, size - 1);
    }
};

class Testbed{
public:
    int* GenerateRandomList(int min, int max, int size){

        int* randomList = new int[size];

        for(int i = 0; i < size; i++)
            randomList[i] = min + rand() % (max - min + 1);

        return randomList;
    }

    int* GenerateReverseOrderedList(int min, int max, int size){
        int* reverseSortList = new int[size];

        for(int i = 0; i < size; i++)
            reverseSortList[i] = min + rand() % (max - min + 1);

        //bubble sort to reverse sort the list.
        for(int i = 0; i < size; i++)
            for(int j = size - 1 ; j > i; j--)
                if(reverseSortList[i] > reverseSortList[j])
                    swap(reverseSortList[i], reverseSortList[j]);

        return reverseSortList;
    }

    double RunOnce(Sorter *sorter, int data[], int size){

        auto time_start1 = chrono::high_resolution_clock::now();
        sorter->Sort(data, size);
        auto time_stop1 = chrono::high_resolution_clock::now();
        auto duration1 = chrono::duration_cast<chrono::microseconds>(time_stop1 - time_start1);

        return duration1.count();
    }

    double RunAndAverage(Sorter *sorter, int type, int min, int max, int size, int sets_num){

        double average = 0;
        if(type == 0){

            for(int i = 0; i <= sets_num; i++){
                int *data = GenerateRandomList(min, max, size);
                average += RunOnce(sorter, data, size);
                delete [] data;
            }

        }else{
            for(int i = 0; i <= sets_num; i++){
                int *data = GenerateReverseOrderedList(min, max, size);
                average += RunOnce(sorter, data, size);
                delete [] data;
            }
        }

        average /= sets_num;

        return average;

    }

    void RunExperiment(Sorter *sorter, int type, int min, int max, int min_val, int max_val, int sets_num, int step){

        cout << "\tsize\taverage time\n";
        double averageTime = 0;
        for(int i = min_val; i <= max_val; i+= step){
            averageTime = RunAndAverage(sorter, type, min, max, i, sets_num);
            cout << "\t" << i << "\t" << averageTime << "\n";
        }

    }

};

int main(void){
    Testbed tester;
    Sorter *sorter1 = new SelectionSorter;
    Sorter *sorter2 = new QuickSorter;

    cout << "Selection Sort random data test (in microseconds)\n";
    tester.RunExperiment(sorter1, 0, 100, 1000000, 1000, 10000, 50, 1000);
    cout << "\n";
    

    cout << "Selection Sort reversed sorted data test (in microseconds)\n";
    tester.RunExperiment(sorter1, 1, 200, 1000000, 1000, 10000, 50, 1000);
    cout << "\n";

    cout << "Quick Sort random data test (in microseconds)\n";
    tester.RunExperiment(sorter2, 0, 200, 1000000, 1000, 10000, 50, 1000);
    cout << "\n";

    cout << "Quick Sort reversed sorted data test (in microseconds)\n";
    tester.RunExperiment(sorter2, 1, 200, 1000000, 1000, 10000, 50, 1000);
    cout << "\n";

    cout << "Test complete.";
    return 0;
}
