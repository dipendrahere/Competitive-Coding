#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long int
#define mod 1000000007
void f(ll * fib){
	fib[0] = 1;
	fib[1] = 0;
	fib[2] = 1;
	for(int i = 3; i < 100500; i++){
		fib[i] = (fib[i-1]+fib[i-2])%mod;
	}
}
int main(){
	int t;
	ll fib[100500];
	f(fib);
	cin>>t;
	while(t--){
		ll m,n;
		cin>>m>>n;
		ll suma = 0;
		ll sumb = 0;
		ll temp;
		for(int i = 0;i < m;i++){
			cin>>temp;
			suma += temp;
			suma = suma%mod;
		}
		for(int i = 0; i < m;i++){
			cin>>temp;
			sumb += temp;
			sumb = sumb%mod;
		}
		ll ans = (m * ((fib[n-1] * suma)%mod + (fib[n] * sumb)%mod)%mod)%mod;
		cout<<ans<<endl;
	}
}
