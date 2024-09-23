#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int alphabet[26]{};

int main(){
    int n;
    cin >> n;
    while(n--){
        char c;
        cin >> c;
        c = tolower(c);
        alphabet[c - 'a'] = 1;
    }
    bool all_complete = true;
    
    for(int i=0; i<26; i++){
        all_complete = all_complete && alphabet[i];
        //cout << alphabet[i] <<" ";
    }
    //cout << endl;
    if(all_complete){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
    return 0;
}