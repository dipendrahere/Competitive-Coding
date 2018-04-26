#include<bits/stdc++.h>
using namespace std;
int dists(vector<int> a){
	int ret = 0;
	int s = a.size()-1;
	for(int i =0 ;i <= s-1;i++ ){
		ret+=abs(a[i]-a[i+1]);
	}
	return ret;
}
void sh(vector<int> s){
	for(auto i :s)cout<<i<<" ";
	cout<<endl;
}
int main(){
	vector<int> s;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)s.push_back(i);
	int mx=0;
	vector<int> ans;
	do{
		//cout<<s;
		int dist = dists(s);
		//cout<<" "<<dist<<endl;
		if(dist>=mx){
			mx = dist;
			ans = s;
			cout<<mx<<" ";
			sh(ans);
		}
	}while(next_permutation(s.begin(), s.end()));
	
}
