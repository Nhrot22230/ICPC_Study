#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int n; cin >> n;
    map<string, int> words;
    words["*****"] = 1;
    string target; cin >> target;
    int letters[30] = {0};

    for(char c: target) {
        int idx = c - 'a';
        letters[idx]++;
    }

    for(int i=1; i<n; i++) {
        string guess; cin >> guess;
        for(int k=0; k < (int)guess.length(); k++) {
            int idx = guess[k] - 'a';
            if(guess[k] == target[k]) {
                guess[k] = '*';
            }
            else if(letters[idx] != 0) {
                guess[k] = '!';
            }
            else {
                guess[k] = 'X';
            }
        }
        words[guess];
        words[guess]++;
    }

    int q; cin >> q;
    while (q--) {
        string guess; cin >> guess;
        cout << words[guess] << endl;
    }

	return 0;
}
