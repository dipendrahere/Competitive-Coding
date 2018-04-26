#include<bits/stdc++.h>
using namespace std;
int dp[100006];
void cal(int k){
	for(int i =0 ; i<k;i++){
		dp[i] = 1;
	}
	dp[k] = 2;
	for(int i = k+1;i<100006;i++){
		dp[i] = (dp[i-1]%1000000007+dp[i-k]%1000000007)%1000000007;
	}
}
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	int k;
	cin>>k;
	cal(k);
	while(t--){
		int a,b;
		cin>>a>>b;
		int ans=0;
		for(int i = a; i <=b;i++){
			ans= (ans%1000000007+dp[i]%1000000007)%1000000007;
		}
		cout<<ans<<endl;
	}
	return 0;
}
