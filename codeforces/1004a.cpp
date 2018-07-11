#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	ll n,d;
	cin>>n>>d;
	vector<int> v;
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		v.push_back(t);
	}
	sort(v.begin(), v.end());
	ll ans = 2;
	for(int i = 1;i < v.size(); i++){
		int st = v[i-1]+d;
		int end = v[i]-d;
		if(st == end){
			ans++;
		}
		else if(end>st){
			ans+=2;
		}
	}
	cout<<ans<<endl;
}
