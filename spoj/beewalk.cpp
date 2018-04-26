#include<bits/stdc++.h>
using namespace std;
int dp[200][200][15];
int n;
int cal(int d, int i, int j){
	if(dp[i][j][d]!=0){
		return dp[i][j][d];
	}
	if(d==0 && (i!=100 || j!=100))return 0;
	if(i == 100 && j == 100 && d == 0){
		return 1;
	}
	else{
		int v =  cal(d-1, i-1, j+1)+cal(d-1, i-1, j)+cal(d-1, i, j+1)+cal(d-1, i, j-1)+cal(d-1, i+1, j)+cal(d-1, i+1, j-1);
		dp[i][j][d] = v;
		return v;
	}
	return 0;
}
int main(){
	memset(dp,0,sizeof(dp));
	int t;
	cin>>t;
	while(t--){
	cin>>n;
	cout<<cal(n,100,100)<<endl;}
}

