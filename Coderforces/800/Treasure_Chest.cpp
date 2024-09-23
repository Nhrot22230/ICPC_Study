#include <iostream>

using namespace std;



void solve(){
    int x, y, k;
    cin >> x >> y >> k;
    
    if(y > x && (y - x) < k) k = y - x;

    if(x > y) cout << x << endl;
    else cout << y + (y - x - k) << endl;
}

int main(int argc, char const *argv[])
{
    int t=1;
    cin >> t;
    while (t--)
    {
        /* code */
        solve();
    }
    
    return 0;
}
