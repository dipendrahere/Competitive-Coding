#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
ll power(ll x, ll y, ll p)
{
    ll res = 1;
    x = x % p;  
    while (y > 0)
    {if (y & 1)
            res = (res*x) % p;   y = y>>1;
        x = (x*x) % p;
    }
    return res;
}
ll fact(ll m){
	ll ans = 1;
	for(ll i=1;i<=m;i++){ans=(ans%mod*i%mod)%mod;}
		return ans%mod;
}
ll modInverse(ll n, ll p)
{
    return power(n, p-2, p);
}
ll ncr(ll n, ll r)
{
	ll p= mod;
   if (r==0)
      return 1;
    ll fac[n+1];
    fac[0] = 1;
    for (ll i=1 ; i<=n; i++)
        fac[i] = fac[i-1]*i%p;
 
    return (fac[n]* modInverse(fac[r], p) % p *
            modInverse(fac[n-r], p) % p) % p;
}
int main(){
	ll n,m;
	cin>>n>>m;
	for(ll i=0;i<m;i++){
		ll temp;
		cin>>temp;
	}
	long long ans = 1;
	if(n-m+1 >= m){
		ans = (ncr(n-m+1, m)%mod * fact(n-m)%mod)%mod;
	}
	else{
		for(ll i = m+m-n+1+1; i <= m+1; i++){
			ans = (ans%mod * i%mod)%mod;
		}
	}
	cout<<ans<<endl;
}
