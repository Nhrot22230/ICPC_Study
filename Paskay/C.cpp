    #include<iostream>
    typedef long long Long;
    using namespace std;
     
    int main(){
     
    	Long a, k;
    	cin >> a >>k;
    	Long p = (a+k)/2;
    	if(p*2 == a+k) cout<<p<<endl;
    	else cout<<"IMPOSIBLE"<<endl;
     
    	return 0;
    }