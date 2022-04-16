#include <iostream>
#include <vector>

using namespace std;


int partitioning (vector <string>& array, int first, int last) {
    std::swap (array [(first+last)/2], array [last]);
    int cursor = first;
    for (int i = first; i < last; i++) {
        if (array [i] < array [last])
            std::swap (array [i], array [cursor++]);
    }
    std::swap (array [cursor], array [last]);
    return cursor;
}

void quick_sort (vector <string>& array, int first, int last) {
    if (first >= last)
        return;
    int pivot = partitioning (array, first, last);
    quick_sort (array, pivot+1, last);
    quick_sort (array, first, pivot-1);
}

int binary_search (vector <string>& sortedArray, string target) {
    int left = 0, right = sortedArray.size() - 1, middle;
    while(left <= right){
        middle = left + (right - left) / 2;
        if(sortedArray[middle] == target){
            if ( middle == 0)
                return middle;
            if (sortedArray [middle - 1] != target)
                return middle;
        }
        if(sortedArray[middle] >= target)
            right = middle - 1;
        else
            left = middle + 1;
    }
    return -1;
}

void biasedSort (vector <string>& songList) {
    quick_sort (songList, 0, songList.size() - 1);
    int place = binary_search (songList, "Untitled");
    int left_pointer = 0;
    for (int i = place; songList [i] == "Untitled"; i++)
        std::swap (songList [i], songList [left_pointer++]);
    quick_sort (songList, left_pointer, songList.size() - 1);
}



int main (void) {
    vector <string> songList;
    songList.push_back ("Untitled");
    songList.push_back ("zsong");
    songList.push_back ("asong");
    songList.push_back ("Lsong");
    songList.push_back ("fsong");
    songList.push_back ("Asong");
    songList.push_back ("Untitled");
    songList.push_back ("bsong");
    songList.push_back ("Untitled");
    songList.push_back ("msong");
    songList.push_back ("HsOng");
    songList.push_back ("hsong");
    songList.push_back ("Untitled");
    cout << "song list before biased sort\n";
    for (int i = 0; i < songList.size(); i++){
        cout << i+1 << '-' <<songList [i] << '\n';
    }
    biasedSort (songList);
    cout << "\nsong list after biased sort\n";
    for (int i = 0; i < songList.size(); i++){
        cout << i+1 << '-' <<songList [i] << '\n';
    }
    return 0;
}
