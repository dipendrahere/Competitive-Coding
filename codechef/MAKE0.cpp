#include<bits/stdc++.h>
using namespace std;
#define ll long long 
vector<int> f[1000002];
int dp[1000006];
int minn(int a, int b, int c){
	return min(a, min(b,c));
}
void sieve(){
	for(ll i = 2; i < 1000001; i++){
		for(ll j = i+i;j <= i*i && j < 1000001; j+=i){
			f[j].push_back((int)i);
		}
	}
}
int rec(int n){
	if(dp[n] >= 0){
		return dp[n];
	}
	int ans = rec(n-1);
	for(int i = 0; i < f[n].size(); i++){
		ans = min(ans, rec(f[n][i]));
	}
	dp[n] = ans + 1;
	return dp[n];
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	sieve();
	int t;
	cin>>t;
	memset(dp, -1, sizeof(dp));
	dp[0]=0;
	dp[1]=1;
	rec(1000000);
	while(t--){
		int n;
		cin>>n;
		cout<<rec(n)<<endl;
	}
}
