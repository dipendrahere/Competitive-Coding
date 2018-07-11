#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long 
long long pow(ll a, ll b, ll m){
	a = a%m;
	ll res = 1;
	while(b > 0){
		if(b%2 == 1){
			b--;
			res = (a*res)%mod;
		}
		else{
			b = b/2;
			a = (a*a)%mod;
		}
	}
	return res;
}
int main(){
	int x;
	cin>>x;
	for(long long i=1;i<1000;i++){
		for(long long j = 1; j < 1000;j++){
			if((i*pow(j, mod-2, mod))%mod == x){
				cout<<i<<" "<<j<<endl;
				break;
			}
		}
	}
}
