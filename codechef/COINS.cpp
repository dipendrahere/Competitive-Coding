#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
    	int n, m;
    	cin>>n>>m;
    	int a[n+2][m+2];
    	for(int i=0;i<n;i++){
    		for(int j=0;j<m;j++){
    			cin>>a[i][j];
    		}
    	}
    	int old[m];
    	int dp[m];
    	for(int i=0;i<m;i++){
    		dp[i] = a[n-1][i];
    		old[i] = dp[i];
    	}
    	for(int i = n-2;i>=0;i--){
    		for(int k=0;k<m;k++){
    				old[k] = dp[k];
    		}
    		for(int j = 0; j<m;j++){
    			if(j == 0){
    				dp[j] = a[i][j]+old[j+1];
    			}
    			else if(j == m-1){
    				dp[j] = a[i][j]+old[j-1];
    			}
    			else dp[j] = a[i][j]+max(old[j-1], old[j+1]);
    		}
    	}
    	cout<<*max_element(dp, dp+m)<<endl;
    }
}
