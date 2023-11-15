#include <bits/stdc++.h>

using namespace std;

void non_increasing_insertionSort(int A[], int n){
    for(int i=1; i<n; i++){
        int key = A[i];
        int j=i-1;
        while(j>=0 && key > A[j]){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
    }
}

void increasing_insertionSort(int A[], int n){
    for(int i=1; i<n; i++){
        int key = A[i];
        int j=i-1;
        while(j>=0 && key < A[j]){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
    }
}

int main(int argc, char const *argv[])
{
    int A[6] {31, 41, 59, 26, 41, 58};

    for(int i=0; i<6; i++) cout << A[i] << "\t";
    cout << endl;
    non_increasing_insertionSort(A, 6);

    for(int i=0; i<6; i++) cout << A[i] << "\t";
    cout << endl;

    increasing_insertionSort(A, 6);

    for(int i=0; i<6; i++) cout << A[i] << "\t";
    cout << endl;
    return 0;
}
