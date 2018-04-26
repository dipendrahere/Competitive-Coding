#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
ll power(ll a, ll b){
	a = a%MOD;
	ll res = 1;
	while(b > 0){
		if( b%2 == 0){
			b = b/2;
			a = (a*a)%MOD;
		}
		else{
			b--;
			res = (a*res)%MOD;
		}
	}
	return res;
}
int main(){
	ll n;
	ll k;
	cin>>n>>k;
	ll x;
	cin>>x;
	ll temp;
	for(int i = 0; i < x; i++){
		cin>>temp;
	}
	ll p = x*k;
	ll q = n;
	ll ans = ((p %MOD) * power(q, MOD-2))%MOD;
	cout<<ans<<endl;
}
