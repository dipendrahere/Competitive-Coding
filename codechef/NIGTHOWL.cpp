#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll min(ll a, ll b){
	return a>b?b:a;
}
ll cal(ll x, ll k){
	ll v = 1;
	ll sum = 0;
	while(x!=0){
		sum += x;
		v = v*k;
		x = x/k;
	}
	return sum;
}
int main(){
	ll t;
	cin>>t;
	while(t--){
		ll n,k;
		cin>>n>>k;
		ll low = 0;
		ll ans = 1e18;
		ll high = 1e18;
		while(high >= low){
			ll mid = (high - low)/2 + low;
			ll v = cal(mid, k);
			if(v >= n){
				ans = min(ans, mid);
				high = mid-1;
			}
			else{
				low = mid+1;
			}
		}
		cout<<ans<<endl;
	}
}
