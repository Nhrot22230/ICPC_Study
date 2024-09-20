#include <bits/stdc++.h>

using namespace std;

vector<int> plusOne(vector<int>& digits) {
    int lastIndex = digits.size() - 1 - 1;
    digits.back() ++;
    int exceso = digits.back()/10;
    digits.back() = digits.back()%10;
    
    while(exceso){
        if(lastIndex < 0){
            digits.insert(digits.begin(), 1);
            break;
        }
        digits[lastIndex] ++;
        exceso = digits[lastIndex]/10;
        digits[lastIndex] = digits[lastIndex]%10;
        lastIndex--;
    }
    return digits;
}