#include<bits/stdc++.h>
using namespace std;
#define pb push_back
bool check(vector<int> v){
	for(int i = 1; i < v.size(); i++){
		if(v[i] - v[i-1] < 0){
			return false;
		}
	}
	return true;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		vector<int> v;
		cin>>n;
		while(n--){
			int y;
			cin>>y;
			v.pb(y);
		}
		if(check(v)){
			cout<<"YES\n";
			continue;
		}
		int c = 0;
		for(int i = 1; i < v.size();i++){
			if(v[i] - v[i-1] < 0){
				c++;
			}
			if(c > 1){
				break;
			}
		}
		if(c > 1 || v[0] < v[v.size()-1]){
			cout<<"NO\n";
		}
		else{
			cout<<"YES\n";
		}
	}
}
