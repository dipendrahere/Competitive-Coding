#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
ll arr[10005];
vector<int> pa;
ll dp[10001][101][32];
bool check(int form){
	bool i = (form==((1<<pa.size())-1));
	return i;
}

ll rec(ll s, ll n,ll m, int form,ll init){
	if((m == 0 || m == init)&& s >= n && check(form)){
		return 1;
	}
	else if(s>=n)return 0;
	if(dp[s][m][form] >= 0){
		return dp[s][m][form]%MOD;
	}
	ll ans = 0;
	for(ll i = s; i <=s; i++){
		int lap=-10;
		for(int lo=0;lo<pa.size(); lo++){
			if(arr[i] == pa[lo] && (form&(1<<lo))==0){
				lap = lo;
			}
		}
		ll reqm;
		reqm = (m + arr[i])%init;
		if(lap == -10){
			ans+= (rec(s+1, n, reqm, form,init)%MOD + rec(s+1, n, m, form,init)%MOD)%MOD;
		}
		else ans += (rec(s+1, n, reqm, form|(1<<lap),init)%MOD + rec(s+1, n, m, form,init)%MOD)%MOD;
	}
	dp[s][m][form] = ans%MOD;
	return ans%MOD;
}
int main(){
	memset(dp, -1, sizeof(dp));
	ll n;
	cin>>n;
	ll m;
	cin>>m;
	for(ll i = 0; i < n;i++){
		cin>>arr[i];
	}
	ll p;
	cin>>p;
	ll temp;
	for(ll i=0;i<p;i++){
		cin>>temp;
		pa.push_back(temp);
	}
	ll ans = rec(0, n, 0, 0,m);
	if(p == 0){
		ans = ans-1;
	}
	cout<<ans<<endl;
}
