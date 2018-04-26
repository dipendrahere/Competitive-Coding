#include <iostream>
using namespace std;
int max(int a, int b){
	return a<b?a:b;
}
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--){
		int n, k;
		cin>>n>>k;
		int dp[200]={0};int v[200];
		for(int i=0;i<k;i++){
			cin>>v[i];
		}
		dp[0] = 0;int jj = 1;
		while(v[jj]<0){jj++;}
		dp[jj]=v[jj];
		for(int i=1;i<=k;i++){
			for(int j =1;j<=i;j++){
				if(v[j]==-1){
					continue;
				}
				else{
					if(dp[i-j]!=0){
					dp[i] = max(dp[i], dp[i-j]+v[j]);}else continue;
				}
			}
		}
		if(dp[k] == 0){
			printf("-1\n");
		}
		else
			printf("%d\n", dp[k]);
	}
	return 0;
}