#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll max(ll a, ll b){return a>b?a:b;}
ll dp[32][32][32][3];
ll rec(bitset<32> &bc, int an, int bn, int i, int c){
	if(an < 0){
		return 0;
	}
	if(bn < 0){
		return 0;
	}
	if(i >= 32){
		if(c == 1 || an != 0 || bn != 0){
			return 0;
		}
		else{
			return 1;
		}
	}
	if(dp[an][bn][i][c]!=-1)return dp[an][bn][i][c];
	ll ans = 0;
	if(bc[i] == 0 && c == 0){
		ans = rec(bc, an, bn, i+1, 0) + rec(bc, an-1, bn-1, i+1, 1);
	}
	else if(bc[i] == 0 && c == 1){
		ans = rec(bc, an, bn-1, i+1, 1) + rec(bc, an-1, bn, i+1, 1);
	}
	else if(bc[i] == 1 && c == 0){
		ans = rec(bc, an, bn-1, i+1, 0) + rec(bc, an-1, bn, i+1, 0);
	}
	else{
		ans = rec(bc, an, bn, i+1, 0) + rec(bc, an-1, bn-1, i+1, 1);
	}
	return dp[an][bn][i][c] = ans;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		memset(dp, -1, sizeof(dp));
		int a, b, c;
		cin>>a>>b>>c;
		int an = __builtin_popcount(a);
		int bn = __builtin_popcount(b);
		bitset<32> bc(c);
		cout<<max(rec(bc, an, bn, 0, 0), 0)<<endl;
	}
}
