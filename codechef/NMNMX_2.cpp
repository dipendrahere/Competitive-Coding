#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
unordered_map<int, int> mp;
long long rec(int a[], int id, int n, int k, int actk, long ans, int key){
	if(k == 0){
		return ans%mod;
	}
	if(id >= n){
		return 1;
	}
	auto ele = make_pair(ans, make_pair(id, k));
	if(mp.size() > 100000007){
		mp.clear();
	}
	if(mp.find(key) != mp.end()){
		return mp[key];
	}
	int ret = 1;
	if(k == actk || k == 1){
		long long x = rec(a, id+1, n, k-1, actk, ans, ((key * 4991)%mod + (a[id]*4991)%mod)%mod);
		long long y = rec(a, id+1, n, k, actk, ans, key);
		ret = ((x%mod) * (y%mod))%mod;
	}
	else{
		long long x = rec(a, id+1, n, k-1, actk, (ans*a[id])%mod, ((key * 4991)%mod + (a[id]*4991)%mod)%mod);
		long long y = rec(a, id+1, n, k, actk, ans, key);
		ret = ((x%mod) * (y%mod))%mod;
	}
	return mp[key] = ret%mod;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		mp.clear();
		int n, k;
		cin>>n>>k;
		int a[n+2];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		sort(a, a+n);
		long long ans = rec(a, 0, n, k, k, 1, 1);
		cout<<ans<<endl;
	}
}
