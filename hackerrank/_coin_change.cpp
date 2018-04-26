#include<bits/stdc++.h>
using namespace std;
long dp[1000][1000];
long rec(int c[], int n, int m, int i){
	
	if(m == 0){
		return 1;
	}
	if(i >= n){
		return 0;
	}
	if(m < 0){
		return 0;
	}

	if(dp[m][i] != -1){
		return dp[m][i];
	}
	int rr = m;
	long ans = rec(c, n, m, i+1);
	dp[m][i+1] = ans;
	while(m - c[i] >= 0){
		long val;	
		val = rec(c, n, m-c[i], i+1);
		//dp[m-c[i]][i+1] = val;
		m = m-c[i];
		ans+=val;
	}
	dp[rr][i] = ans;
	return ans;
}
int main(){
	int n, m;
	cin>>m>>n;
	int c[n+2];
	long ans = 0;
	for(int i=0;i<1000;i++)for(int j=0;j<1000;j++)dp[i][j]=-1;
	for(int i=0;i<n;i++)cin>>c[i];
	//for(int i=0;i<n;i++){
	ans = ans +rec(c, n, m, 0);
	cout<<ans<<endl;
}
