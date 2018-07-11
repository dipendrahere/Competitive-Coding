#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
long long ytr;
long long dp[5010][5010];
void pre(){
	memset(dp, 0, sizeof(dp));
	for(int i = 0;i<5008;i++){
		dp[i][0]=1;
	}
	for(int i=1;i<5004;i++){
		for(int j=1;j<=i;j++){
			dp[i][j] = (dp[i-1][j]+dp[i-1][j-1])%(mod-1);
		}
	}
}
inline long long rec(ll a, ll b, ll m){
	a=a%m;
	long long res = 1;
	while(b>0){
		if(b&1){
			b--;
			res = (a*res)%m;
		}
		else{
			b>>=1;
			a=(a*a)%m;
		}
	}
	return res;
}

ll pow(ll x,ll n,ll k)
{
	if(n < 0){
		return 1;
	}
	if(k < 0){
		return 1;
	}
	if(n < k){
		return 1;
	}
	if(x == 1){
		return 1;
	}
	if(n < k){
		return 1;
	}
	return rec(x, dp[n][k], mod);
}

int main(){
	pre();
	long long t;
	cin>>t;
	while(t--){
		long long n, k;
		cin>>n>>k;
		ll ans = 1;
		long long aa[n+2];
		for(long long i=0;i<n;i++){
			cin>>aa[i];
		}
		sort(aa, aa+n);
		for(long long i =1;i<n/2;i++){
			ll val;
			val=aa[i]*aa[n-i-1];
			ans = (ans * (pow(val, n-1, k-1)))%mod;
			long long div = (pow(val,n-i-1, min(k-1, n-i-1-k+1)) * pow(val,i, min(k-1, i-k+1)))%mod;
			ans = (ans * rec(div, mod-2, mod))%mod;
		}
		if(n%2){
			ll val;
			val=aa[n/2];
			int i = n/2;
			ans = (ans * (pow(val, n-1, k-1)))%mod;
			long long div = (pow(val,n-i-1, min(k-1, n-i-1-k+1)) * pow(val,i, min(k-1, i-k+1)))%mod;
			ans = (ans * rec(div, mod-2, mod))%mod;
		}
		cout<<ans<<endl;
	}
	
}
