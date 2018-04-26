#include<bits/stdc++.h>
using namespace std;
int dp[100005];
int rec(int n){
	//cout<<n<<endl;
	if(n < 0){
		return 0;
	}
	if(n == 0){
		return 1;
	}
	if(dp[n] != -1){
		return dp[n]==0?0:1;
	}
	else{
		int a =  rec(n-3);
		int b =  rec(n-7);
		int ret;
		if(a==1 || b==1){

			dp[n] = 1;
			return 1;

		}
		else{
			dp[n]=0;
			ret= 0;
			return 0;
		}
		cout<<"returning "<<ret<<endl;
		return ret;
	}
	return 0;
}
int main(){
	int t;
	cin>>t;

	while(t--){
		for(int i=0;i<10000;i++){
			dp[i] = -1;
		}
		int n;
		cin>>n;
		if(rec(n) == 1){
			cout<<"YES\n";
		}
		else{
			cout<<"NO\n";
		}
	}
}
