#include <bits/stdc++.h>
using namespace std;
void merge(int A[], int l, int med, int r){
    int n_l = med - l + 1;
    int n_r = r - med;
    int L[n_l + 1], R[n_r + 1];
    
    for(int i=0; i<n_l; i++) L[i] = A[l + i];
    for(int i=0; i<n_r; i++) R[i] = A[med + i + 1];
    
    int i=0, j=0, k=l;
    while(i<n_l && j<n_r)
        if(L[i] < R[j]) A[k++] = L[i++];
        else            A[k++] = R[j++];

    while(i<n_l) A[k++] = L[i++];
    while(j<n_r) A[k++] = R[j++];
}

void merge_sort(int A[], int  l, int r){
    if(l >= r) return;
    int med = (l+r)/2;
    merge_sort(A, l, med);
    merge_sort(A, med + 1, r);
    merge(A, l, med,  r);
}

int main(int argc, char const *argv[])
{
    /* code */
    int A[12] {5, 7, 2, 7 ,9, 4, 8, 2, 10, 2, 1, 5};
    
    for(int i=0; i<12; i++) cout << A[i] << "\t";
    cout << endl;
    
    merge_sort(A, 0, 11);

    for(int i=0; i<12; i++) cout << A[i] << "\t";
    cout << endl;
    return 0;
}
