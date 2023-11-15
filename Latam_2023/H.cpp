#include <bits/stdc++.h>
#define M_PI           3.14159265358979323846  /* pi */

#define ll long double

using namespace std;

struct Region{
    ll x_izq;
    ll y_izq;
    ll x_der;
    ll y_der;
};

void obtenerPuntos(ll m, ll D){
    ll sol_x1, sol_x2, sol_y1, sol_y2;

    sol_x1 = D*sqrt(1/(m*m + 1));
    sol_x2 = 0 - D*sqrt(1/(m*m + 1));
    sol_y1 = D*m*sqrt(1/(m*m + 1));
    sol_y2 = 0 - D*m*sqrt(1/(m*m + 1));
    
    ll coordX1, coordX2, coordY1, coordY2;

    if(m == (sol_y1-sol_y2)/(sol_x1-sol_x2) ){
        coordX1 = sol_x1;
        coordX2 = sol_x2;
        coordY1 = sol_y1;
        coordY2 = sol_y2;
    }
    else{
        coordX1 = sol_x1;
        coordX2 = sol_x2;
        coordY1 = sol_y2;
        coordY2 = sol_y1;
    }
}

void solve(){
    int n;
    ll D;
    cin >> n >> D;
    
    ll x1,y1,x2,y2;

    Region up_left, up_rigth, down_left, down_right;

    for(int i=1; i<=n; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        ll m = (y2-y1)/(x2-x1);
        ll c = y2 - m*x2;
        cout << "f(x)= " << m << " * x + " << c << endl;
        
        if( m*m*D*D + D*D < c*c ) continue;
        ll sol_x1 = (sqrt(m*m*D*D + D*D - c*c) - m*c)/(m*m+1);
        
    }

}

int main(){
    int t=1;
    while (t--)
    {
        /* code */
        solve();
    }
    
}