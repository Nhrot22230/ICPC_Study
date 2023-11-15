#include <bits/stdc++.h>

using namespace std;

vector< vector < string > > dictionary;

int main(){
    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        vector <string> group;
        int temp;
        cin >> temp;
        while (temp--)
        {
            string cad;
            cin >> cad;
            group.push_back(cad);
        }
        dictionary.push_back(group);
    }
    int p;
    cin >> p;
    while(p--){
        string p1, p2;
        cin >> p1 >> p2;
        bool flag = false, flag2 = false;
        int index = 0;
        int jndex = 0;
        for(int i=0; i<n; i++){
            for(int j = 0; j< dictionary[i].size(); j++){
                index = p1.find(dictionary[i][j]);
                if(index != 1){
                    flag = true;
                    for(string word: dictionary[i]){
                        jndex = p2.find(word);
                        if(jndex == index) {
                            flag2 = true;
                            break;
                        }
                    }
                    break;
                }

            }
        }
        for(int i=0; i<index; i++){
            if(p1[i] != p2[i]){
                flag = false; break;
            }
        }


        if(flag){
            cout << "REJECT" << endl;
        }
        else cout << "OK" << endl;

    }
    return 0;
}