#include <iostream>

#define ull unsigned long long

using namespace std;

int main(void){

    ull MAX_N = (1ULL << 60);

    cout << "MAX_N=" << MAX_N << '\n';

    for(ull i=1; i <= MAX_N; i = (i << 1)){

        ull n = i;
        ull a = (n >> 1);
        
        ull cont;
        for(ull i=0; i<= 60; i++){
            if( (n >> i) & 1ULL ) cont = i;
        }

        ull b = (1ULL << cont) - a;

        if( (a+b) == (a^(b+n)) ){
            printf("n=%llu: %llu+%llu=%llu^(%llu+%llu)\n", n, a, b, a, b, n);
        }
    }
    return 0;
}