#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    while(n--){
        int shift;
        cin >> shift;
        cin.ignore();
        bool flag = false;
        char text [320] {};
        cin.getline(text, 300);
        int longitud = strlen(text);
        
        if(text[0] == 't' && text[1] == 'h' && text[2] == 'e' && text[3] == ' '){
            flag = true;
        }
        else if(text[0] == 't' && text[1] == 'h' && text[2] == 'e' && longitud == 3){
            flag = true;
        }
        else if(text[longitud - 1] == 'e' && text[longitud - 2] == 'h' && text[longitud - 3] == 't' && text[longitud - 4] == ' '){
            flag = true;
        }
        else{
            for(int i=0; text[i]; i++){
                if(text[i] == ' ' && text[i+1] == 't' && text[i+2] == 'h' && text[i+3] == 'e' && text[i+4] == ' '){
                    flag = true;
                    break;
                }
                
            }
        }
        if(flag){
            shift = (0-1)*shift;
        }
        for(int i=0; text[i]; i++){
            if(text[i] == ' ') continue;
            if(text[i] + shift > 'z'){
                text[i] = 'a' + (shift - 'z' + text[i]) - 1;
            }
            else if(text[i] + shift < 'a'){
                text[i] = 'z' + (shift - 'a' + text[i]) + 1;
            }
            else{
                text[i] = text[i] + shift;
            }
        }
        cout << text << endl;
    }
    return 0;
}