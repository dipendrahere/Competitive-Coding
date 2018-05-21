#include<bits/stdc++.h>
using namespace std;
vector<int> g[1000000];
long long n;
vector<int> st;
#define pb push_back
int dfs(int s, int d, int vis[], int count){
	if(s == d){
		return count;
	}
	vis[s] = 1;
	int max = 99999999;
	for(auto i: g[s]){
		if(vis[i] == 1){
			continue;
		}
		else{
			int v = dfs(i, d, vis, count+1);
			if(v < max){
				st.pb(i);
				return v;
			}
		}
	}
	return 99999999;
}
int count(int s, int vis[], int c){
	if(vis[s] == 1){
		return 0;
	}
	int v = 0;
	vis[s] = 1;
	for(auto i : g[s]){
		v+=count(i, vis, c+1);
	}
	return v+1;
}
int main(){
	cin>>n;
	int x, y;
	cin>>x>>y;
	for(int i=0;i<n-1;i++){
		int a, b;
		cin>>a>>b;
		g[a].pb(b);
		g[b].pb(a);
	}
	int vis[n+2];
	memset(vis, 0, sizeof(vis));
	int btw = dfs(x, y, vis, 0);
	if(st.size() == 1 || st.size() == 2){
		if(st.size() == 1){
			auto yn = find(g[x].begin(), g[x].end(), y);
			g[x].erase(yn);
			yn = find(g[y].begin(), g[y].end(), x);
			g[y].erase(yn);
			memset(vis, 0, sizeof(vis));
			long long cnt1 = count(x,vis, 0);
			memset(vis, 0, sizeof(vis));
			long long cnt2 = count(y,vis, 0);
			cout<<(n*(n-1)) - cnt1*cnt2<<endl;

		}
		else if(st.size() == 2){
			int o = st[1];
			g[o].clear();
			for(int i = 0; i <= n;i++){
				auto pl = find(g[i].begin(), g[i].end(), o);
				if(g[i].size() >= 1 && pl!=g[i].end()){
					g[i].erase(pl);
				}
			}
			memset(vis, 0, sizeof(vis));
			long long cnt1 = count(x,vis, 0);
			memset(vis, 0, sizeof(vis));
			long long cnt2 = count(y,vis, 0);
			cout<<(n*(n-1)) - cnt1*cnt2<<endl;
		}
	}
	else{
		int o = st[1];
		int uo = st[st.size()-1];
		g[o].clear();
		g[uo].clear();
		for(int i = 0; i <= n;i++){
			auto pl = find(g[i].begin(), g[i].end(), o);
			if(g[i].size() >= 1 && pl!=g[i].end()){
				g[i].erase(pl);
			}
			pl = find(g[i].begin(), g[i].end(), uo);
			if(g[i].size() >= 1 && pl!=g[i].end()){
				g[i].erase(pl);
			}
		}
		memset(vis, 0, sizeof(vis));
		long long cnt1 = count(x,vis, 0);
		memset(vis, 0, sizeof(vis));
		long long cnt2 = count(y,vis, 0);
		cout<<(n*(n-1)) - cnt1*cnt2<<endl;
	}
}
