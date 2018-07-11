#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
map<pair<long long, pair<long long, long long> >, long long> mp;
long long rec(int a[], int id, int n, int k, int actk, long long ans){
	if(k == 0){
		return ans%mod;
	}
	if(id >= n){
		return 1;
	}
	long long ret = 1;
	if(k == actk || k == 1){
		long long x = rec(a, id+1, n, k-1, actk, ans);
		long long y = rec(a, id+1, n, k, actk, ans);
		ret = ((x%mod) * (y%mod))%mod;
	}
	else{
		long long x = rec(a, id+1, n, k-1, actk, (ans*a[id])%mod);
		long long y = rec(a, id+1, n, k, actk, ans);
		ret = ((x%mod) * (y%mod))%mod;
	}
	return ret%mod;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n, k;
		cin>>n>>k;
		int a[n+2];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		sort(a, a+n);
		long long ans = rec(a, 0, n, k, k, 1);
		cout<<ans<<endl;
	}
}
