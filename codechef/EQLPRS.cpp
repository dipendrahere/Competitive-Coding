#include<bits/stdc++.h>
using namespace std;
#define ll long long
map<ll, ll> mp;
int main(){
	int t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		mp[n]++;
	}
	ll ans = 0;
	for(auto i:mp){
		ans += (i.second * (i.second-1))/2;
	}
	cout<<ans<<endl;
}
