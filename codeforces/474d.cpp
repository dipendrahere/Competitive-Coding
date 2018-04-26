#include<bits/stdc++.h>
using namespace std;
int dp[100006];
long long sum[100006];
void cal(int k){
	dp[0]=1;
	sum[0] = 1;
	for(int i =1 ; i<k;i++){
		dp[i] = 1;
		sum[i] = sum[i-1]+dp[i];
	}
	dp[k] = 2;
	sum[k] = sum[k-1]+dp[k];
	for(int i = k+1;i<100006;i++){
		dp[i] = (dp[i-1]%1000000007+dp[i-k]%1000000007)%1000000007;
		sum[i] = (sum[i-1]%1000000007+dp[i]%1000000007)%1000000007;
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
		long ans=0;
		// for(int i = a; i <=b;i++){
		// 	ans= (ans%1000000007+dp[i]%1000000007)%1000000007;
		// }
		ans = (sum[b]%1000000007-sum[a-1]%1000000007)%1000000007;
		if(ans < 0){
			cout<<1000000007+ans<<endl;
		}
		else
		cout<<ans<<endl;
	}
	return 0;
}
