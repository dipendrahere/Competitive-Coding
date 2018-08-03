#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int x;
	map<int, int> mp;
	int mx = -10;
	for(int i=0;i<n;i++){
		cin>>x;
		mp[x]++;
		mx = max(mx, mp[x]);
	}
	cout<<n-mx<<endl;
}
