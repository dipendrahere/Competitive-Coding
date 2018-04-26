#include <iostream>
using namespace std;
int min(int a,int b){return a>b?b:a;}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		int k;
		cin>>n>>k;
		int v[k+1];
		
		for(int i=1;i<=k;i++){
			cin>>v[i];
		}
		int dp[n+1][k+1];
		for(int i=0;i<=n;i++)for(int j=0;j<=k;j++)dp[i][j]=INT_MAX;
		for(int i=0;i<=n;i++){
			dp[i][0] = 0;
		}
		for(int i=0;i<=k;i++){
			dp[0][i] = 0;
		}
		for(int j=1;j<=k;j++){
			dp[1][j]=v[j];
		}
		for(int i=2;i<=n;i++){
			for(int j=1;j<=k;j++){
				for(int u=1;u<=j;u++){
					if(v[u] > 0){
						//printf("%s\n","l" );
						dp[i][j] = min(dp[i][j], dp[i-1][j-u]+v[u]);
					}
				}
			}
		}
		int minn = INT_MAX;
		for(int i=1;i<=n;i++){
			if(minn > dp[i][k]){
				minn = dp[i][k];
			}
		}
		if(minn<0){
			printf("-1\n");
		}else
		printf("%d\n",minn);
	}
}