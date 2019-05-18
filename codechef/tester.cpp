#include<bits/stdc++.h>
using namespace std;
#define pb push_back
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		vector<string> g;
		for(int i=0;i<n;i++){
			string y;
			cin>>y;
			g.pb(y);
		}
		int dis[1000]={0};
		for(int i =0;i<n;i++){
			for(int j = 0;j<m;j++){
				for(int x = 0;x<n;x++){
					for(int y =0;y<m;y++){
						if(y == j && x <= i){
							continue;
						}
						if(y >= j)
						if(g[i][j] == '1'&&g[x][y]=='1')
						dis[abs(x-i)+abs(y-j)]++;
					}
				}
			}
		}
		for(int i = 1; i <= n+m-2;i++){
			cout<<dis[i]<<" ";
		}
		cout<<endl;
	}
}
