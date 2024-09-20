    #include<bits/stdc++.h>
    #define endl '\n'
    #define ll long long
     
    using namespace std;
     
     
     
    int main(){
    	int k,s;
    	cin>>k>>s;
    	int suma;
    	int cant = 0;
    	if(k*3 == s){
    		 cout<<1<<endl;
    		 return 0;
    	}
    	if(k*3 < s){
    		cout<<0<<endl;
    		return 0;
    	}
    	for(int i=0; i<=k; i++){
    		suma = i;
    		if(suma > s)break;
    		for(int j=0; j<=k; j++){
    			if(suma + j >s) break;
    			suma += j;
    			if(suma + k >= s) cant++;
    				suma -= j;
    		}
    	}
    	cout<<cant<<endl;
    	return 0;
    }