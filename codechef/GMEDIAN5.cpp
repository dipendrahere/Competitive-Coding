#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mod 1000000007
ll C[1010][1010];
ll dp[1010][1010];
ll dp2[1010][1010][2];
map<ll, map<ll, ll> > dpp;
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
	// for(int i = 1; i < 10; i++){
	// 	for(int j = 1; j < 10; j++){
	// 		cout<<i<<" "<<j<<": "<<C[i][j]<<endl;
	// 	}
	// }
}
ll rec(vector<int>& v, int l, int L, int id){
	if(l == 0){
		// for(auto i: o){
		// 	cout<<i<<" ";
		// }cout<<endl;
		return 1;
	}
	if(l < 0){
		return 0;
	}
	if(id >= v.size()){
		return 0;
	}
	int flag = 0;
	if(L%2 == 0){
		// if(l == L/2){
		// 	flag = 1;
		// 	return 0;
		// }
	}
	if(dp[l][id] != -1){
		return dp[l][id];
	}
	ll vr = 0;
	for(int i = 0; i <= v[id]; i++){
		// for(int u=0;u<i;u++){
		// 	o.pb(id);
		// }
		vr = (vr+(rec(v, l-i, L, id+1)*C[v[id]][i])%mod)%mod;
		// for(int u=0;u<i;u++){
		// 	o.pop_back();
		// }
	}
	return dp[l][id]=vr;
}
ll recmap(vector<int>& v, int l, int L, int id){
	if(l == 0){
		// for(auto i: o){
		// 	cout<<i<<" ";
		// }cout<<endl;
		return 1;
	}
	if(l < 0){
		return 0;
	}
	if(id >= v.size()){
		return 0;
	}
	int flag = 0;
	if(L%2 == 0){
		if(l == L/2){
			flag = 1;
			return 0;
		}
	}
	if(dpp.find(l) != dpp.end() && dpp[l].find(id)!=dpp[l].end()){
		return dpp[l][id];
	}
	ll vr = 0;
	for(int i = 0; i <= v[id]; i++){
		// for(int u=0;u<i;u++){
		// 	o.pb(id);
		// }
		vr = (vr+(recmap(v, l-i, L, id+1)*C[v[id]][i])%mod)%mod;
		// for(int u=0;u<i;u++){
		// 	o.pop_back();
		// }
	}
	return dpp[l][id]=vr;
}
ll frec(vector<int> &v, int l, int e, int id){
	if(id == e){
		if(l > v[id]){

		}
	}
}
// ll rec2(vector<int>& v, int l, int L, int id, int f){
// 	if(l == 0){
// 		// for(auto i: o){
// 		// 	cout<<i<<" ";
// 		// }cout<<endl;
// 		if(f == 0)
// 			return 1;
// 		else return 0;
// 	}
// 	if(l < 0){
// 		return 0;
// 	}
// 	if(id >= v.size()){
// 		return 0;
// 	}
// 	int flag = 0;
// 	if(L%2 == 0){
// 		if(l == L/2){
// 			flag = 1;
// 		}
// 	}
// 	if(flag == 1 || f == 1){
// 		flag = 1;
// 	}
// 	if(dp2[l][id][flag] != -1){
// 		return dp2[l][id][flag];
// 	}
// 	ll vr = 0;
// 	for(int i = 0; i <= v[id]; i++){
// 		// for(int u=0;u<i;u++){
// 		// 	o.pb(id);
// 		// }
// 		vr = (vr+(rec2(v, l-i, L, id+1, flag)*C[v[id]][i])%mod)%mod;
// 		// for(int u=0;u<i;u++){
// 		// 	o.pop_back();
// 		// }
// 	}
// 	return dp2[l][id][flag]=vr;
// }
// ll rec2(vector<int>& v, int l, int L, int id){
// 	if(l == 0){
// 		// for(auto i: o){
// 		// 	cout<<i<<" ";
// 		// }cout<<endl;
// 		return 1;
// 	}
// 	if(l < 0){
// 		return 0;
// 	}
// 	if(id >= v.size()){
// 		return 0;
// 	}
	
// 	if(L%2 == 0){
// 		if(l == L/2){
// 			return 0;
// 		}
// 	}
// 	if(dp2[l][id] != -1){
// 		return dp2[l][id];
// 	}
// 	ll vr = 0;
// 	for(int i = 0; i <= v[id]; i++){
// 		// for(int u=0;u<i;u++){
// 		// 	o.pb(id);
// 		// }
// 		vr = (vr+(rec2(v, l-i, L, id+1)*C[v[id]][i])%mod)%mod;
// 		// for(int u=0;u<i;u++){
// 		// 	o.pop_back();
// 		// }
// 	}
// 	return dp2[l][id]=vr;
// }
int main(){
	pre();
	memset(dp, -1, sizeof(dp));
	memset(dp2, -1, sizeof(dp2));
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n+2];
		map<int, int> mp;
		for(int i = 0; i < n; i++){
			cin>>a[i];
			mp[a[i]]++;
		}
		vector<int> v;
		for(auto i: mp){
			v.pb(i.second);
		}
		ll ans = 0;
		for(int i = 1; i <= n; i++){
			dpp.clear();
			// if(n%2  == 0){
			// 	rec2(v, i, i, 0, 0);
			// 	ans =  (ans + dp2[i][0][0])%mod;
			// }
			// else {
			 	ans =  (ans + recmap(v, i, i, 0))%mod;
			//}
		}
		ans = ans%mod;
		// for(int i = 2; i <= n; i+=2){
		// 	for(int j = 0; j < v.size(); j++){
		// 		ans = ans - (frec(v, i, j, 0)*srec(v, i, j+1, 0))%mod;
		// 		if(ans < 0){
		// 			ans = ans + mod;
		// 		}
		// 	}
		// }
		cout<<ans%mod<<endl;
	}
}
