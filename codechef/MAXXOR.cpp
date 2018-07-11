#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	string s[n+2];
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	vector<int> a;
	for(int i=0;i<n;i++){
		int v= 0;
		for(auto j : s[i]){
			v+=(j-'a'+1);
		}
		a.push_back(v);
	}
	int max= -1000;
	int st;
	map<int, set<pair<int, int>, greater<pair<int, int> >    >   > m;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i==j)continue;
			m[i].insert(make_pair(a[i]^a[j], j));
			m[j].insert(make_pair(a[j]^a[i], i));
			if(a[i]^a[j]>max){
				max = a[i]^a[j];
				st=i;
			}
		}
	}
	int vis[n+1];
	int ans[n+1];
	memset(vis, 0, sizeof(vis));
	for(int i=0;i<n;i++){
		if(i == 0){
			ans[i] = a[st];
			vis[st] = 1;
			continue;
		}
		for(auto j: m[st]){
			if(vis[j.second] == 0){
				vis[j.second] = 1;
				ans[i] = a[j.second];
				st = j.second;
				break;
			}
		}
	}
	int fi = 0;
	for(int i=1;i<n;i++){
		fi += (ans[i]^ans[i-1]);
	}
	cout<<fi<<endl;
}
