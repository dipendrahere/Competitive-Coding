#include<bits/stdc++.h>
using namespace std;
#define pb push_back
int vis[1000];
int __gcd(int a, int b) 
{ 
    if (b == 0) 
        return a; 
    return __gcd(b, a % b);  
} 
void dfs(int i, vector<vector<int> >&v){
	if(vis[i] == 1){
		return;
	}
	vis[i] = 1;
	for(auto y: v[i]){
		dfs(y, v);
	}
}
bool isconnected(vector<int> v){
	memset(vis, 0, sizeof(vis));
	vector<vector<int> > g;
	for(int i = 0; i < v.size(); i++){
		vector<int> t;
		g.pb(t);
	}
	int c = 0;
	for(int i = 0; i < v.size(); i++){
		for(int j = i; j < v.size(); j++){
			if(__gcd(v[i], v[j]) == 1){
				g[i].pb(j);
				g[j].pb(i);
			}
		}
	}
	// for(auto i: g){
	// 	for(auto j: i){
	// 		cout<<j<<" ";
	// 	}
	// 	cout<<endl;
	// }
	dfs(0, g);
	for(int i = 0; i < v.size(); i++){
		if(vis[i] == 1){
			c++;
		}
	}
	if(c == v.size())return true;
	return false;
}
int main(){
	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;
		vector<int> v;
		for(int i = 0; i < n; i++){
			int y;
			cin>>y;
			v.pb(y);
		}
		if(isconnected(v)){
			cout<<0<<endl;
			for(auto i: v){
				cout<<i<<" ";
			}
			cout<<endl;
		}
		else{
			map<int, int> mp;
			int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
			for(int i = 0; i < 15; i++){
				for(int j = 0; j < n; j++){
					if(v[j]%prime[i] == 0){
						mp[prime[i]]++;
					}
				}
			}
			for(int i = 0; i < 15; i++){
				if(mp.find(prime[i]) == mp.end()){
					v[0] = prime[i];
					break;
				}
			}
			cout<<1<<endl;
			for(auto i: v){
				cout<<i<<" ";
			}
			cout<<endl;
		}
	}
}
