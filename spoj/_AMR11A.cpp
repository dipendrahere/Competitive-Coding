#include<bits/stdc++.h>
using namespace std;
long long  a[700][700];
long long cal(long long  r, long long  c, long long  mid){
	long long dp[r+2][c+2];
	memset(dp, 0, sizeof(dp));
	for(long long  i = 0 ;i  < r;i++){
		for(long long  j=0;j<c;j++){
			if(i == 0 && j == 0){
				dp[i][j] = mid;
			}
			else if(i == 0){
				dp[i][j] = dp[i][j-1]+a[i][j];
				if(dp[i][j] <=0){
					dp[i][j] = INT_MIN;
				}
			}
			else if(j==0){
				dp[i][j] = dp[i-1][j]+a[i][j];
				if(dp[i][j] <=0){
					dp[i][j] = INT_MIN;
				}
			}
			else{
				if(dp[i-1][j] + a[i][j] <=0 && dp[i][j-1] + a[i][j] <=0){
					dp[i][j] = INT_MIN;
				}
				else{
					dp[i][j] = max(dp[i][j-1], dp[i-1][j])+a[i][j];
				}
			}
		}
	}
	// cout<<endl;
	// for(int i = 0;  i< r;i++){
	// 	for(int j=0;j<c;j++){
	// 		cout<<dp[i][j]<<"\t";
	// 	}
	// 	cout<<endl;
	// }

	return dp[r-1][c-1];
}
int main(){
	long long  t;
	cin>>t;
	long long  ans;
	while(t--){
		long long  r,c;
		cin>>r>>c;
		memset(a, 0, sizeof(a));
		for(long long  i=0;i<r;i++)for(long long  j=0;j<c;j++)cin>>a[i][j];
		long long low = 1;
		long long high = INT_MAX;
		while(high>=low){
			long long mid = (high+low)/2;
			long long val = cal(r, c, mid);
			//cout<<"at mid = "<<mid<<" got: "<<val<<endl;
			if(val >= 1){
				ans = mid;
				high = mid-1;
			}
			else{
				low = mid+1;
			}
		}
		cout<<ans<<endl;
	}
}
