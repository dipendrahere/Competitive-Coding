#include<bits/stdc++.h>
using namespace std;
#define pb push_back
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n, m;
		cin>>n>>m;
		vector<string> g;
		for(int i = 0; i < n; i++){
			string y;
			cin>>y;
			g.pb(y);
		}
		int o[600][600] = {0};
		int e[600][600] = {0};
		for(int i = 0; i < m; i++){
			int x = 0;
			int y = i;
			o[x][y] = g[x][y] - '0';
			x++;
			y--;
			while(y >= 0 && x < n){
				o[x][y] += (o[x-1][y+1] + g[x][y] - '0');
				x++;
				y--;	
			}
			int xx = 0;
			int yy = i;
			e[xx][yy] = g[xx][yy] - '0';
			xx++;
			yy++;
			while(xx < n  && yy < m){
				e[xx][yy] += (e[xx-1][yy-1] + g[xx][yy] - '0');
				xx++;
				yy++;
			}
		}
		for(int i = 1; i < n; i++){
			int x = i;
			int y = m-1;
			o[x][y] = g[x][y] - '0';
			x++;
			y--;
			while(y >= 0 && x < n){
				o[x][y] += (o[x-1][y+1] + g[x][y] - '0');
				x++;
				y--;
			}
			int xx = i;
			int yy = 0;
			e[xx][yy] = g[xx][yy] - '0';
			xx++;
			yy++;
			while(xx < n && yy < m){
				e[xx][yy] += (e[xx-1][yy-1] + g[xx][yy] - '0');
				xx++;
				yy++;
			}
		}
		int dis[1000] = {0};
		for(int j = 0; j < m; j++){
			for(int i = 0; i < n; i++){
				if(g[i][j] != '1'){
					continue;
				}
				
				for(int x = 1; x <= n-i-1; x++){
					int dx = i+x;
					int dy = j;
					int rx = i;
					int ry = j+x;
					int dv;
					int rv;
					if(dx < n && dy < m){
						dv = o[dx][dy];
					}
					else{
						dv = 0;
					}
					if(rx-1 < n && ry+1 < m && rx - 1 >= 0 && ry+1>=0){
						rv = o[rx-1][ry+1];
					}
					else{
						rv = 0;
					}
					dis[x] += abs(dv - rv);
				}
				for(int x = 1; x <= m-j-1; x++){
					if(i == n-1){
						for(int l = j+1; l < m; l++){
							dis[l-j] += g[i][l]-'0';
						}
						break;
					}
					int dx = n-1;
					int dy = j+x;
					int rx = i;
					int ry = j+abs(dx-i)+abs(dy-j);
					int dv;
					int rv;
					if(dx < n && dy < m){
						dv = o[dx][dy];
					}
					else{
						dv = 0;
					}
					if(rx-1 < n && ry+1 < m && rx-1>=0 && ry+1>=0){
						rv = o[rx-1][ry+1];
					}
					else{
						rv = 0;
					}
					dis[dx-i + dy-j] += abs(dv - rv);
				}
				for(int x = 1; x <= m-j-1; x++){
					int ux = i-x;
					int uy = j;
					int rx = i;
					int ry = j+x;
					int uv;
					int rv;
					if(rx < n && ry < m && rx >= 0 && ry >= 0){
						rv = e[rx][ry];
					}
					else{
						rv = 0;
					}
					if(ux >= 0 && uy >= 0 && ux < n && uy < m){
						uv = e[ux][uy];
					}
					else{
						uv = 0;
					}
					dis[x] += abs(rv - uv);
				}
				for(int x = 1; x <=  i; x++){
					int rx = i-x;
					int ry = m-1;
					int ux = i-abs(rx-i)-abs(ry-j);
					int uy = j;
					int uv;
					int rv;
					if(rx < n && ry < m && rx >= 0 && ry >= 0){
						rv = e[rx][ry];
					}
					else{
						rv = 0;
					}
					if(ux >= 0 && uy >= 0 && ux < n && uy < m){
						uv = e[ux][uy];
					}
					else{
						uv = 0;
					}
					dis[i - ux + uy - j] += abs(rv - uv);
				}
				for(int l = j+1; l < m; l++){
					if(g[i][l] == '1'){
						dis[l-j]--;
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
