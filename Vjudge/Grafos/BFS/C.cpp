#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main(){
    //inicio
    char l_ini, l_end;
    int row_ini, row_end;
    int col_ini, col_end;

    cin >> l_ini >> row_ini;
    cin >> l_end >> row_end;

    col_ini = l_ini - 'a';
    col_end = l_end - 'a';

    int cur_x = col_ini, cur_y = row_ini;


    int cont = 0;
    while (true)
    {
        if(cur_x == col_end && cur_y == row_end) break;

        if(cur_x == col_end){
            if(cur_y < row_end){
                //cout << "U" << endl;
                cur_y++;
            }
            else{
                //cout << "D" << endl;
                cur_y--;
            }
        }
        else if (cur_y == row_end)
        {
            if(cur_x < col_end){
                //cout << "R" << endl;
                cur_x++;
            }
            else{
                //cout << "L" << endl;
                cur_x--;
            }
        }
        else if (cur_x < col_end)
        {
            if(cur_y < row_end){
                //cout << "RU" << endl;
                cur_y++;
            }
            else{
                //cout << "RD" << endl;
                cur_y--;
            }
            cur_x++;
        }
        else if (cur_x > col_end)
        {
            if(cur_y < row_end){
                //cout << "LU" << endl;
                cur_y++;
            }
            else{
                //cout << "LD" << endl;
                cur_y--;
            }
            cur_x--;
        }
        cont++;
    }
    cout << cont << endl;

    cur_x = col_ini; cur_y = row_ini;
    while (true)
    {
        if(cur_x == col_end && cur_y == row_end) break;

        if(cur_x == col_end){
            if(cur_y < row_end){
                cout << "U" << endl;
                cur_y++;
            }
            else{
                cout << "D" << endl;
                cur_y--;
            }
        }
        else if (cur_y == row_end)
        {
            if(cur_x < col_end){
                cout << "R" << endl;
                cur_x++;
            }
            else{
                cout << "L" << endl;
                cur_x--;
            }
        }
        else if (cur_x < col_end)
        {
            if(cur_y < row_end){
                cout << "RU" << endl;
                cur_y++;
            }
            else{
                cout << "RD" << endl;
                cur_y--;
            }
            cur_x++;
        }
        else if (cur_x > col_end)
        {
            if(cur_y < row_end){
                cout << "LU" << endl;
                cur_y++;
            }
            else{
                cout << "LD" << endl;
                cur_y--;
            }
            cur_x--;
        }
        cont++;
    }
    

    return 0;
}