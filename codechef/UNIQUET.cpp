#include<bits/stdc++.h>
using namespace std;
vector<int> tree[51000];
int val[51000];
int curr[51000];
int vis[61000];
map<int, int> mp;
void dfs(int i, int cur){
	if(vis[i]==1)return;
	vis[i] = 1;
	if(mp.find(val[i])!=mp.end()){
		mp[val[i]]++;
		curr[i]=1;
		cur = 1;
	}
	else{
		mp[val[i]] = 1;
	}
	curr[i] = cur;
	for(auto x:tree[i]){
		dfs(x,cur);
	}
	vis[i]=0;
	mp[val[i]]--;
	if(mp[val[i]] == 0){
		mp.erase(mp.find(val[i]));
	}
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>val[i];
	}
	for(int i=0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		tree[a-1].push_back(b-1);
		tree[b-1].push_back(a-1);
	}
	dfs(0,0);
	int count = 0;
	for(int i=0;i<50060;i++){
		if(curr[i] == 1){
			count++;
		}
	}
	cout<<n-count<<endl;
}
