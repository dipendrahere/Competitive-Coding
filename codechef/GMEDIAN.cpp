#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mod 1000000007
ll C[1010][1010];
ll fdp[1010][1010];
ll sdp[1010][1010];
void pre(){
	memset(C, 0, sizeof(C));
	for(int i = 0 ;i < 1010; i++){
		C[i][0] = 1;
	}
	C[1][0] = C[1][1] = 1;
	for(int i = 2; i < 1010; i++){
		for(int j = 1; j < 1010; j++){
			C[i][j] = (C[i-1][j]+C[i-1][j-1])%mod;
		}
	}
}
ll frec(vector<int> &v, int l, int id){
	if(l == 0){
		return 1;
	}
	if(l < 0){
		return 0;
	}
	if(id < 0){
		return 0;
	}
	if(fdp[l][id]!=-1){
		return fdp[l][id];
	}
	ll val = 0;
	for(int i = 0; i <= v[id]; i++){
		val = (val + (frec(v, l-i, id-1)*C[v[id]][i])%mod)%mod;
	}
	return fdp[l][id] = val;
}
ll srec(vector<int> &v, int l, int id){
	if(l == 0){
		return 1;
	}
	if(l < 0){
		return 0;
	}
	if(id >= v.size()){
		return 0;
	}
	if(sdp[l][id] != -1){
		return sdp[l][id];
	}
	ll val = 0;
	for(int i = 0; i <= v[id]; i++){
		val = (val + (srec(v, l-i, id+1)*C[v[id]][i])%mod)%mod;
	}
	return sdp[l][id] = val;
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	pre();
	int t;
	cin>>t;	
	while(t--){
		memset(fdp, -1, sizeof(fdp));
		memset(sdp, -1, sizeof(sdp));
		int n;
		cin>>n;
		int temp;
		map<int, int> mp;
		for(int i = 0; i < n; i++){
			cin>>temp;
			mp[temp]++;
		}
		vector<int> v;
		for(auto i: mp){
			v.pb(i.second);
		}
		ll ans = 0;
		for(int i = 1; i <= n; i++){
			ans =  (ans + srec(v, i, 0))%mod;
		}
		ans = ans%mod;
		for(int i = 2; i <= n; i+=2){
			for(int j = 0; j < v.size(); j++){
				ll ff = frec(v, i/2, j) - frec(v, i/2, j-1);
				if(ff < 0){
					ff += mod;
				}
				ll ss = srec(v, i/2, j+1);
				if(ss < 0){
					ss += mod;
				}
				ans = ans - (ff*ss)%mod;
				if(ans < 0){
					ans = ans + mod;
				}
			}
		}
		cout<<ans%mod<<endl;
	}
}
