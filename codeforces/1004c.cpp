#include<bits/stdc++.h>
using namespace std;
map<int, int> mp;
int main(){
	mp.clear();
	int n;
	cin>>n;
	int a[n+2];
	for(int i=0;i<n;i++){
		cin>>a[i];
		mp[a[i]]++;
	}
	long long diff[n+2];
	memset(diff, 0, sizeof(diff));
	for(int i=0;i<n;i++){
		mp[a[i]]--;
		if(mp[a[i]] == 0){
			mp.erase(a[i]);
		}
		diff[i] = mp.size();
	}
	mp.clear();
	long long ans=0;
	for(int i=0;i<n;i++){
		if(mp.find(a[i]) == mp.end()){
			ans+=diff[i];
			mp[a[i]]++;
		}
	}
	cout<<ans<<endl;
}
