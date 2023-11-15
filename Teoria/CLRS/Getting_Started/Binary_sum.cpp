#include <bits/stdc++.h>

using namespace std;

void binary_sum(int a[], int b[], int c[], int n){
    int carry = 0;
    for(int j=n-1; j>=0; j--){
        int temp = (a[j] + b[j] + carry);
        c[j + 1] = temp%2;
        carry = temp/2;
    }
    c[0] = carry;
}


int main(int argc, char const *argv[])
{
    int A[4] {1,0,1,0};
    int B[4] {1,1,1,1};
    int C[5] {};

    cout << 0;
    for(int i=0; i<4; i++)
        cout << A[i];
    cout << endl;

    cout << 0;
    for(int i=0; i<4; i++)
        cout << B[i];
    cout << endl;

    binary_sum(A, B, C, 4);
    for(int i=0; i<5; i++)
        cout << C[i];
    cout << endl;
    return 0;
}
