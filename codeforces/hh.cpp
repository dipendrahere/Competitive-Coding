#include<bits/stdc++.h>
using namespace std;
int main(){
	int vis[1000005];
	memset(vis, 0, sizeof(vis));
	int t;
	cin>>t;
	vector<int> v;
	int n;
	for(int i=0;i<t;i++){
		cin>>n;
		v.push_back(n);
	}
	sort(v.begin(), v.end());
	int ans = 0;
	for(int i=0;i<t;i++){
		auto it = upper_bound(v.begin(), v.end(), v[i]);
		int idc =it-v.begin();
		while(vis[idc])idc++;
		if(idc==t||it==v.end())break;
		vis[idc]++;
		ans++;
	}
	cout<<ans<<endl;
}
