#include<bits/stdc++.h>
using namespace std;
long long dp[101001][30];
long long max(long long a, long long b){
	return a>b?a:b;
}
bool comp(string a, int b){
	long long cnt[10]={0};
	for(auto i : a){
		if(i == '0'+b){
			return true;
		}
	}
	return false;
}
long long rec(string s[], long long n, long long i, long long last){
 	if(i>=n){
 		return 0;
 	}
 	if(dp[10+i][last]!=-1){
 		return dp[10+i][last];
 	}
 	bool res;
 	if(last != -1)
 		res = comp(s[i], last);
 	if(last == -1 || res){
 		long long v = rec(s, n, i+1, last);
 		for(auto r: s[i]){
 			v = max(v, 1+rec(s, n, i+1, r-'0'));
 		}
 		return dp[10+i][last]=v;
 	}
 	else{
 		return dp[10+i][last] = rec(s, n, i+1, last);
 	}
}
int main(){
	long long n;
	memset(dp, -1, sizeof(dp));
	cin>>n;
	
	string s[n+2];
	for(long long i=0;i<n;i++){
		cin>>s[i];
	}
	cout<<rec(s, n, 0, -1)<<endl;
}
