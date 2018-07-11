#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
int dp[5000][5000];
int pow(ll a, ll b, ll m){
	a = a%m;
	long res = 1;
	while(b > 0){
		if(b%2){
			res = (a*res)%m;
			b--;
		}
		else{
			a = (a*a)%m;
			b = b/2;
		}
	}
	return res%m;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		memset(dp, 0, sizeof(dp));
		int n,k;
		cin>>n>>k;
		vector<int> v;
		vector<long> pre;
		ll pro = 1;
		for(int i=0;i<n;i++){
			int temp;
			cin>>temp;
			v.push_back(temp);
			pro *= temp;
			pro = pro%temp;
			pre.push_back(pro);
		}
		sort(v.begin(), v.end());
		for(int i=0;i<5000;i++){
			for(int j = 0; j < 5000;j++){
				dp[i][j] = 1;
			}
		}
		dp[3]
	}
}
