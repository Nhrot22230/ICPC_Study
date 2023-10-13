#include <bits/stdc++.h>

using namespace std;

int lengthOfLastWord(string &s) {
    int lastIndex = s.find_last_not_of(' ');
    s.resize(lastIndex + 1);
    int lastSep = s.find_last_of(' ');
    return lastIndex-lastSep;
}

int main(){
    string s = "Hello World ";
    
    cout << lengthOfLastWord(s) << "  " << s.size() - 1 << "  " << s << endl;

    return 0;
}