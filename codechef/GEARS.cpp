#include<bits/stdc++.h>
using namespace std;
long long maxx(long long a, long long b){return a>b?a:b;}
long long minn(long long a, long long b){return a<b?a:b;}
long long __gcd(long long a , long long b)
{
   if(b==0) return a;
   a%=b;
   return __gcd(b,a);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	map<long long, long long> stop;
	long long n, m;
	cin>>n>>m;
	long long a[n+2];
	vector<long long> col[n];
	long long motion[n];
	long long parent[n];
	for(long long i=0;i<n;i++){
		cin>>a[i];
		parent[i] = i;
		motion[i] = 0;
		col[i].push_back(i);
	}
	for(long long i=0;i<m;i++){
		long long t;
		cin>>t;
		if(t == 1){
			long long x,c;
			cin>>x>>c;
			x--;
			a[x] = c;
		}
		else if(t == 2){
			long long x, y;
			cin>>x>>y;
			x--;
			y--;
			if(stop.find(parent[x])!=stop.end() || stop.find(parent[y])!=stop.end()){
				stop[parent[x]]=1;
				stop[parent[y]]=1;
				continue;
			}
			if(motion[x] == 0 && motion[y]==0){
				motion[x] = 1;
				motion[y] = -1;
				parent[y] = parent[x];
				col[parent[x]].push_back(y);
				col[y].clear();
			}
			else if(motion[x] == 0 && motion[y]!=0){
				motion[x] = -1*motion[y];
				parent[x] = parent[y];
				col[parent[y]].push_back(x);
				col[x].clear();
			}
			else if(motion[y]==0 && motion[x]!=0){
				motion[y] = -1*motion[x];
				parent[y] = parent[x];
				col[parent[x]].push_back(y);
				col[y].clear();
			}
			else{
				if(parent[x] == parent[y]){
					if(motion[x]*motion[y]!=-1){
						stop[parent[x]]=1;
						col[parent[x]].clear();
					}
				}
				else{
					long long change, pparent, off;
					if(motion[x] == -1*motion[y]){
						if(col[parent[x]].size() < col[parent[y]].size()){
							pparent = parent[y];
							off = parent[x];
							change = 1;
						}
						else{
							pparent = parent[x];
							off = parent[y];
							change = 1;
						}
					}
					else{
						if(col[parent[x]].size() < col[parent[y]].size()){
							pparent = parent[y];
							off = parent[x];
							change = -1;
						}
						else{
							pparent = parent[x];
							off = parent[y];
							change = -1;
						}
					}
					for(auto y: col[off]){
						parent[y] = pparent;
						motion[y] = change*motion[y];
					}
					col[pparent].insert(col[pparent].end(), col[off].begin(), col[off].end());
					if(stop.find(pparent)!=stop.end() || stop.find(off)!=stop.end()){
						stop[pparent] = 1;
						stop[off] = 1;
						col[off].clear();
						col[pparent].clear();
					}
					col[off].clear();
				}
			}
		}
		else if(t == 3){
			long long x, y, v;
			cin>>x>>y>>v;
			x--;
			y--;
			if(parent[x]!=parent[y]){
				cout<<"0\n";
			}
			else{
				if(stop.find(parent[x]) != stop.end()){
					cout<<"0\n";
				}
				else{
					long long num = a[x]*v;
					long long dem = a[y];
					long long gg = __gcd(maxx(num, dem), minn(num, dem));
					num = num/gg;
					dem = dem/gg;
					num = num*motion[x]*motion[y];
					cout<<num<<"/"<<dem<<endl;
				}
			}
		}
	}
}
