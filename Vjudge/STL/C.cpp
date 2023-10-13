#include <bits/stdc++.h>

using namespace std;

int main()
{
    /* code */
    long long num;
    cin >> num;
    long long cont=1;
    
    for(long long i=1; i<=num; i++){
        if( (num+i) == (num^i) ) cont++;
    }
    cout << cont << endl;
    return 0;
}
