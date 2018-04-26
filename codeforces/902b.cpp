#include<bits/stdc++.h>
using namespace std;
vector<int> ch[10006];
int now[10006];
void dfs(int i, int col){
	now[i] = col;
	if(ch[i].size() == 0){
		return;
	}
	
	for(auto r : ch[i]){
		dfs(r, col);
	}
}
int main(){
	int n;
	cin>>n;
	
	int temp;
	for(int i =2 ; i <= n; i++){
		cin>>temp;
		ch[temp].push_back(i);
	}
	int col[10006];
	for(int i=1;i<=n;i++){
		cin>>col[i];
	}
	int ans=0;
	memset(now, 0, sizeof(now));
	vector<int> exp;
	exp.push_back(1);
	while(exp.size()!=0){
		int i=*exp.begin();
		exp.erase(exp.begin());
		if(now[i] == col[i]){
			for(auto k: ch[i]){
				//	dfs(k, col[i]);
			exp.push_back(k);
			}
			continue;
		}
		now[i] = col[i];
		ans++;
		for(auto k: ch[i]){
			dfs(k, col[i]);
			exp.push_back(k);
		}
	}
	cout<<ans<<endl;;
}
