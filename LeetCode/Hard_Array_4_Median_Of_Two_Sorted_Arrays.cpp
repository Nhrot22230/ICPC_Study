#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> nums1;
    vector<int> nums2 {1, 3};
    int n = nums1.size(),m = nums2.size();
    int maxIndex = n + m - (n+m)%2;
    int indexI=0, indexJ=0;
    double ultimo=0, penultimo=0;
    while ((indexI + indexJ)*2 <= maxIndex)
    {   
        if(indexI == n) break;
        if(indexJ == m) break;
        
        if(nums1[indexI] > nums2[indexJ]){
            penultimo = ultimo;
            ultimo = nums2[indexJ];
            indexJ++; 
        } 
        else{
            penultimo = ultimo;
            ultimo = nums1[indexI];
            indexI++; 
        }
    }
    while ((indexI + indexJ)*2 <= maxIndex)
    {   
        if(indexI == n) break;
        penultimo = ultimo;
        ultimo = nums1[indexI];
        indexI++; 
    }
    while ((indexI + indexJ)*2 <= maxIndex)
    {
        if(indexJ == m) break;
        penultimo = ultimo;
        ultimo = nums2[indexJ];
        indexJ++; 
    }
    if((n+m)%2 == 0){
        cout << (penultimo + ultimo)/2 << endl;
    }
    else cout << ultimo << endl;
    return 0;
}