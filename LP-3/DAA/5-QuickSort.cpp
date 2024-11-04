#include <bits/stdc++.h>
using namespace std;

/* ################# QUICK SORT ################# */

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for(int j=low; j<high; j++) {
        if(arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i+1], arr[high]);
    return i+1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if(low < high) {
        int q = partition(arr, low, high);
        quickSort(arr, low, q-1);
        quickSort(arr, q+1, high);
    }
}

/* ################# RANDOMISED QUICK SORT ################# */

int randomPartition(vector<int>& arr, int low, int high) {
    int idx = rand() % (high - low + 1) + low;

    swap(arr[idx], arr[high]);

    int pivot = arr[high];
    int i = low-1;

    for(int j=low; j<high; j++) {
        if(arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i+1], arr[high]);
    return i+1;
}

void randomQuickSort(vector<int>& arr, int low, int high) {
    if(low < high) {
        int q = randomPartition(arr, low, high);
        randomQuickSort(arr, low, q-1);
        randomQuickSort(arr, q+1, high);
    }
}

int main() {
    vector<int> arr1 = {3, 2, 5, 1, 4};
    
    cout<<"Given array is: ";
    for(auto i : arr1)
        cout<<i<<" ";
    cout<<endl;

    quickSort(arr1, 0, arr1.size()-1);

    cout<<"Array after qucik sort: ";
    for(auto i : arr1)
        cout<<i<<" ";
    cout<<endl;

    vector<int> arr2 = {3, 2, 5, 1, 4};

    cout<<"Given array is: ";
    for(auto i : arr2)
        cout<<i<<" ";
    cout<<endl;

    randomQuickSort(arr2, 0, arr2.size()-1);

    cout<<"Array after qucik sort: ";
    for(auto i : arr2)
        cout<<i<<" ";
    cout<<endl;
}