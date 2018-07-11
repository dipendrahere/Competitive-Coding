#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
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
	long long n,k;
	cin>>n>>k;
	ll num = (pow(2, n-1, mod) - n%mod)%mod;
	if(num < 0){
		num+=mod;
	}
	ll dem = pow(pow(2, n-1, mod), mod-2, mod)%mod;
	ll ans = (num * dem)%mod;
	cout<<ans<<endl;
}
