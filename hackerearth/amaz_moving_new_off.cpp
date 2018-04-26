#include<bits/stdc++.h>
using namespace std;
int dp[1000][1000];
int rec(int start, int end,int st, int len, int x, int y, vector<int> cuts){
	if(dp[start][end]!=0){
		return dp[start][end];
	}
	if(start > end){
		return 0;
	}
	if(start == end){
		int val =  (cuts[start]-st)*x+(len-cuts[end])*y;
		//cout<<"starts: "<<st<<" ends: "<<len<<"when from "<<cuts[end]<<" val: "<<val<<endl;
		return val;
	}
	int minn = INT_MAX;
	int i;
	int ind;
	for(int i = start; i<=end;i++){
		int val = (cuts[i]-st)*x + (len - cuts[i])*y;
		ind = i;
		
		val += (rec(start, ind-1, st, cuts[ind], x, y, cuts)+rec(ind+1, end, cuts[ind], len, x, y, cuts));
		//cout<<"starts: "<<st<<" ends: "<<len<<"when from "<<cuts[i]<<" val: "<<val<<endl;
		if(val < minn){
			minn = val;
		}
	}
	dp[start][end]=minn;
	//cout<<"ye mila "<<minn<<endl;
	return minn;
	//cout<<"Kaata: "<<cuts[ind]<<endl;
	//return minn+rec(start, ind-1, st, cuts[ind], x, y, cuts)+rec(ind+1, end, cuts[ind], len, x, y, cuts);
}
int main(){
	int t;
	cin>>t;
	while(t--){
		memset(dp, 0, sizeof(dp));
		int x, y;
		cin>>x>>y;
		int n;
		cin>>n;
		vector<int> cuts;
		int temp;
		for(int i= 0;i<n;i++){
			cin>>temp;
			cuts.push_back(temp);
		}
		int len = temp;
		cout<<rec(1, n-2,1, len, x, y, cuts)<<endl;
	}
}
