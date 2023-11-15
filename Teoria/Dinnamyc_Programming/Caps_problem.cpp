#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;

bitset<100> used_caps(0);

void recursion(vector<vector<int>>& personas, vector<int> &caps_disp_persona, int index_person, int index_person_cap, 
        int max_persons, int max_person_caps){
    
    cout << index_person << "->" << caps_disp_persona[index_person_cap] << endl;

    if(index_person >= max_persons) return;
    if(index_person_cap >= max_person_caps){
        recursion(personas, personas[index_person + 1], index_person + 1, 
            0, max_persons, max_person_caps);
        return;
    }
    
    recursion(personas, personas[index_person], index_person, 
        index_person_cap + 1, max_persons, max_person_caps);
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<vector<int>> personas(n);
    for(int i=0; i<n; i++){
        int num;
        cin >> num;
        personas[i].push_back(num);
    }

    recursion(personas, personas[0], 0, 0, n, personas[0].size());

    return 0;
}
